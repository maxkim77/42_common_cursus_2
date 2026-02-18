*This project has been created as part of the 42 curriculum by jeongkim.*

## Description

**minitalk** is a small inter-process communication project that demonstrates how to transmit data between two processes using only UNIX signals (`SIGUSR1` and `SIGUSR2`).

The goal of this project is to understand low-level communication mechanisms in UNIX systems, including signal handling, bitwise operations, and process identification using PIDs. A server process waits for incoming signals and reconstructs characters bit by bit, while a client process encodes and sends a string to the server using signals only.

## Instructions

### Compilation
```bash
make
```

### Execution

1. Start the server:
```bash
./server
```
The server will display its PID and wait for incoming signals.

2. Run the client in another terminal:
```bash
./client <server_pid> "<message>"
```

Example:
```bash
./client 12345 "hello minitalk"
```

## Resources

### References
- `man 2 sigaction`
- `man 7 signal`
- `man 7 signal-saftey`
- Sending and Handling Signals in C (kill, signal, sigaction) - youtube


### AI Usage
AI was used to:
- Help structure and write this README file
- Clarify and document the signal-based communication logic
- Provide guidance on organizing function structure for clean signal handling and communication flow
- Assist in designing the ACK mechanism using global variables
