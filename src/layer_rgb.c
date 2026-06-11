#include <zephyr/kernel.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/rgb_underglow.h>
#include <zmk/keymap.h>
#include <zmk/behavior.h>
#include <dt-bindings/zmk/rgb.h>

static int layer_color_listener_cb(const zmk_event_t *eh) {
    uint8_t active_layer = zmk_keymap_highest_layer_active();

    uint32_t h = 0, s = 100, b = 100;
    switch (active_layer) {
        case 1:
            /* Turn Green for Layer 1 */
            h = 119;
            break;
        case 2:
            /* Turn Orange for Layer 2 */
            h = 31;
            break;
        case 3:
            /* Turn Pink for Layer 3 */
            h = 344;
            break;
        default:
            /* Turn Blue for Default Base Layer */
            h = 193;
            break;
    }

    struct zmk_behavior_binding binding = {
        .behavior_dev = "RGB_UG",
        .param1 = RGB_COLOR_HSB_CMD,
        .param2 = RGB_COLOR_HSB_VAL(h, s, b)
    };

    struct zmk_behavior_binding_event event = {
        .position = 0,
        .timestamp = k_uptime_get()
    };

    zmk_behavior_queue_add(&event, binding, true, 0)

    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(layer_color_listener, layer_color_listener_cb);
ZMK_SUBSCRIPTION(layer_color_listener, zmk_layer_state_changed);
