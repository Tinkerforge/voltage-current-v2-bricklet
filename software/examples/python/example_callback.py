#!/usr/bin/env python
# -*- coding: utf-8 -*-

HOST = "localhost"
PORT = 4223
UID = "XYZ" # Change XYZ to the UID of your Voltage/Current Bricklet 2.0

from tinkerforge.ip_connection import IPConnection
from tinkerforge.bricklet_voltage_current_v2 import BrickletVoltageCurrentV2

# Callback function for current callback
def cb_current(current):
    print("Current: " + str(current/1000.0) + " A")

if __name__ == "__main__":
    ipcon = IPConnection() # Create IP connection
    vc = BrickletVoltageCurrentV2(UID, ipcon) # Create device object

    ipcon.connect(HOST, PORT) # Connect to brickd
    # Don't use device before ipcon is connected

    # Register current callback to function cb_current
    vc.register_callback(vc.CALLBACK_CURRENT, cb_current)

    # Set period for current callback to 1s (1000ms) without a threshold
    vc.set_current_callback_configuration(1000, False, "x", 0, 0)

    raw_input("Press key to exit\n") # Use input() in Python 3
    ipcon.disconnect()
