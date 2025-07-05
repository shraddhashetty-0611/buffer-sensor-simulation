>Sensor Buffer Simulation in C

This C project simulates a sensor generating random bytes every second and buffers them. Every 10 seconds, it prints the latest 50 bytes if available and deletes them.

> Features
- Simulates sensor generating 0–5 random bytes every second.
- Prints added bytes every second.
- Every 10s: prints and removes the latest 50 bytes if buffer has ≥50.

>How to Run
1. Go to: [Programiz C Online Compiler](https://www.programiz.com/c-programming/online-compiler/)
2. Paste the code from `main.c`
3. Click "Run"

> Files
- `main.c` — Main source code
- `README.md` — Project description

> Assumptions
- Loops simulate real-time operation
- `rand()` is used for byte and count generation
- No real-time clock or threading
- Max buffer: 1024 bytes


