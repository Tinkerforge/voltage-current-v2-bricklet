// This example is not self-contained.
// It requires usage of the example driver specific to your platform.
// See the HAL documentation.

#include "src/bindings/hal_common.h"
#include "src/bindings/bricklet_voltage_current_v2.h"

void check(int rc, const char *msg);
void example_setup(TF_HAL *hal);
void example_loop(TF_HAL *hal);

// Callback function for power callback
static void power_handler(TF_VoltageCurrentV2 *device, int32_t power, void *user_data) {
	(void)device; (void)user_data; // avoid unused parameter warning

	tf_hal_printf("power: %d 1/%d W\n", power, 1000);
}

static TF_VoltageCurrentV2 vc;

void example_setup(TF_HAL *hal) {
	// Create device object
	check(tf_voltage_current_v2_create(&vc, NULL, hal), "create device object");

	// Register power callback to function power_handler
	tf_voltage_current_v2_register_power_callback(&vc,
	                                              power_handler,
	                                              NULL);

	// Configure threshold for power "greater than 10 W"
	// with a debounce period of 1s (1000ms)
	tf_voltage_current_v2_set_power_callback_configuration(&vc, 1000, false, '>', 10*1000, 0);
}

void example_loop(TF_HAL *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
