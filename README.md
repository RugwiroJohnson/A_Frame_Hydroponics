# Hydroponic-AFrame-DualControl-MCU

## Project Overview

A scalable, automated **A-Frame Hydroponic System** engineered for agricultural research. This system utilizes a **dual-MCU architecture** to independently control two separate growth channels, enabling comparative testing of irrigation schedules and piping designs.

---

## Core Innovation: Dual Control Architecture

The project employs a completely segregated electronics setup, ensuring that each side of the A-frame functions as a truly independent experiment.

| Component | Side A (Experiment 1) | Side B (Experiment 2) |
| :--- | :--- | :--- |
| **Control Unit** | 1 x Microcontroller Unit (MCU #1) | 1 x Microcontroller Unit (MCU #2) |
| **Actuator** | 1 x **Active LOW** Relay Module | 1 x **Active LOW** Relay Module |
| **Pump** | 1 x Submersible Pump | 1 x Submersible Pump |
| **Test Variable** | Linear Channel Design | Circular Channel Design |

---

## Technical Implementation (Code Logic)

The irrigation code is based on non-blocking `millis()` timing. The logic explicitly handles the **Active LOW** nature of the relay modules to ensure variables like `dayOnTime` accurately reflect the physical duration the pump is running.

### Snippet: Irrigation Control (`main_controller.ino`)

```cpp
// --- TIMING CONFIGURATION (Values are corrected for flow) ---
const unsigned long dayOnTime   = 6UL * 60UL * 1000UL;  // 6 min ON
const unsigned long dayOffTime  = 2UL * 60UL * 60UL * 1000UL; // 2 hr OFF

// ... (night timing definitions) ...

void setup() {
  // ACTIVE LOW Relay Startup: LOW signal turns the pump ON.
  digitalWrite(relayPin, LOW); 
  pumpState = true; 
  // ...
}

void loop() {
  // ... (Day/Night Time Calculation & Duration Selection) ...

  // --- PUMP CONTROL LOGIC ---
  if (pumpState) { // Pump is currently ON
    if (currentMillis - previousMillis >= onTime) {
      pumpState = false;            
      digitalWrite(relayPin, HIGH); // Turn OFF pump (Active Low: HIGH = OFF)
      previousMillis = currentMillis;
    }
  } else { // Pump is currently OFF
    if (currentMillis - previousMillis >= offTime) {
      pumpState = true;             
      digitalWrite(relayPin, LOW);  // Turn ON pump (Active Low: LOW = ON)
      previousMillis = currentMillis;
    }
  }
}
