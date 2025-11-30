# Hydroponic-AFrame-DualControl-MCU

## Project Overview

A scalable, automated **A-Frame Hydroponic System** engineered for scale production and experimentation. This system utilizes a **dual-MCU architecture** to independently control two separate growth channels, enabling comparative testing of irrigation schedules and piping designs.

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

## How To Use This System

To run a test on this dual system, follow these steps:

1.  **Set Schedules:** Program **MCU #1** with the test schedule for Side A and **MCU #2** with the different test schedule for Side B.
2.  **Set Start Time:** Calibrate the time offset in the code so the day/night cycles match your local time.
3.  **Plant and Monitor:** Plant the same type of crop on both sides and track growth, water usage, and final yield.
4.  **Compare Data:** Use the results to decide which pipe design and watering schedule is most efficient.

---

## What I Learned

Building this system taught us important lessons in both hardware and software control:

* **Active LOW Relays:** I learned the hard way that most relays are **Active LOW** (LOW signal turns the pump ON). The code must be programmed to handle this inversion, otherwise the schedules will be backward.
* **Isolation is Key:** Using two fully separate MCUs (instead of one shared one) is necessary to ensure the watering schedules are truly independent and the comparison data is reliable.
* **Design for Stability:** The new A-frame structure offers much better stability and durability compared to the initial wooden prototype, proving that material choice matters for scaling up.
* **Future Focus:** The experiment will show us which design—linear or circular—is the better way to deliver nutrients to the roots.
