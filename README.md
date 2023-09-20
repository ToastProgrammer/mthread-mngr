# pdevice-mngr

Project for portfolio demonstrating lightweight, multithreaded, c++ application for device status and management.

## Simulator

The simulator is an application that maintains the current state of the system. It also reads and writes to serial buffers shared with the manager. It parses the input buffer for commands and writes response messages to the output buffer, typically in the form of command ACK messages.

### Structure

The simulator launches five threads: a thread for managing the state of the system, a thread for displaying the state of the system based on the state of the system, a thread for reading from the serial buffer, and a thread for writing to the serial buffer, and a thread for reading and processing user input commands.

![sim diagram](./images/sim-struct.jpg?raw=true)

## Device - Manager

TODO: Add description of the manager running on a remote device.
