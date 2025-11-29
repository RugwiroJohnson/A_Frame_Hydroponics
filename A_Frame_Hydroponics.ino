#define relayPin 7 

// --- TIMING IN MILLISECONDS ---
const unsigned long dayOnTime   = 6UL * 60UL * 1000UL;          // 6 min ON
const unsigned long dayOffTime  = 2UL * 60UL * 60UL * 1000UL;   // 2 hr OFF

const unsigned long nightOnTime  = 6UL * 60UL * 1000UL;         // 6 min ON
const unsigned long nightOffTime = 4UL * 60UL * 60UL * 1000UL;  // 4 hr OFF

unsigned long previousMillis = 0;
bool pumpState = false;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Start with pump ON
  pumpState = true;
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  // --- DEFINE DAY/NIGHT CYCLE ---
  unsigned long cycle24hr = 24UL * 60UL * 60UL * 1000UL;   // 24 hours
  unsigned long dayStart  = 6UL * 60UL * 60UL * 1000UL;    // 6:00 AM
  unsigned long dayEnd    = 18UL * 60UL * 60UL * 1000UL;   // 6:00 PM

  unsigned long offset = (13UL * 60UL * 60UL * 1000UL) + (40UL * 60UL * 1000UL); // 13:40 PM

  unsigned long elapsedTime = (currentMillis + offset) % cycle24hr;

  bool isDay = (elapsedTime >= dayStart && elapsedTime < dayEnd);

  // Select ON/OFF times based on day or night
  unsigned long onTime  = isDay ? dayOnTime  : nightOnTime;
  unsigned long offTime = isDay ? dayOffTime : nightOffTime;

  // --- PUMP CONTROL LOGIC ---
  if (pumpState) {
    if (currentMillis - previousMillis >= onTime) {
      pumpState = false;
      digitalWrite(relayPin, HIGH); // Turn OFF pump
      previousMillis = currentMillis;
    }
  } else {
    if (currentMillis - previousMillis >= offTime) {
      pumpState = true;
      digitalWrite(relayPin, LOW); // Turn ON pump
      previousMillis = currentMillis;
    }
  }
}
