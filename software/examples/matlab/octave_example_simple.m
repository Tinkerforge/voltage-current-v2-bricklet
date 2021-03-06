function octave_example_simple()
    more off;

    HOST = "localhost";
    PORT = 4223;
    UID = "XYZ"; % Change XYZ to the UID of your Voltage/Current Bricklet 2.0

    ipcon = javaObject("com.tinkerforge.IPConnection"); % Create IP connection
    vc = javaObject("com.tinkerforge.BrickletVoltageCurrentV2", UID, ipcon); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Get current voltage
    voltage = vc.getVoltage();
    fprintf("Voltage: %g V\n", voltage/1000.0);

    % Get current current
    current = vc.getCurrent();
    fprintf("Current: %g A\n", current/1000.0);

    input("Press key to exit\n", "s");
    ipcon.disconnect();
end
