// This example is not self-contained.
// It requres usage of the example driver specific to your platform.
// See the HAL documentation.

#include "bindings/hal_common.h"
#include "bindings/bricklet_voltage_current_v2.h"

#define UID "XYZ" // Change XYZ to the UID of your Voltage/Current Bricklet 2.0

void check(int rc, const char* msg);

void example_setup(TF_HalContext *hal);
void example_loop(TF_HalContext *hal);


// Callback function for current callback
static void current_handler(TF_VoltageCurrentV2 *device, int32_t current,
                            void *user_data) {
	(void)device; (void)user_data; // avoid unused parameter warning

	tf_hal_printf("Current: %d 1/%d A\n", current, 1000);
}

static TF_VoltageCurrentV2 vc;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_voltage_current_v2_create(&vc, UID, hal), "create device object");

	// Register current callback to function current_handler
	tf_voltage_current_v2_register_current_callback(&vc,
	                                                current_handler,
	                                                NULL);

	// Set period for current callback to 1s (1000ms) without a threshold
	tf_voltage_current_v2_set_current_callback_configuration(&vc, 1000, false, 'x', 0, 0);
}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
