*This project has been created as part of the 42 curriculum by jeongkim.*

## Description

**minitalk** is a small inter-process communication project that demonstrates how to transmit data between two processes using only UNIX signals (`SIGUSR1` and `SIGUSR2`).

The goal of this project is to understand low-level communication mechanisms in UNIX systems, including signal handling, bitwise operations, and process identification using PIDs. A server process waits for incoming signals and reconstructs characters bit by bit, while a client process encodes and sends a string to the server using signals only.

## Instructions

### Requirements
- macOS or Linux
- `make`
- `cc` or `clang`

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
- `man 2 kill`
- *Advanced Programming in the UNIX Environment* – W. Richard Stevens
- POSIX signal documentation

### AI Usage
AI was used to:
- Help structure and write this README file
- Clarify and document the signal-based communication logic

AI was not used to implement the final source code; it was only used for documentation and explanation purposes.
