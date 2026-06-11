#include <zephyr/kernel.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/rgb_underglow.h>
#include <zmk/keymap.h>

static int layer_color_listener_cb(const zmk_event_t *eh) {
    uint8_t active_layer = zmk_keymap_highest_layer_active();

    switch (active_layer) {
        case 1:
            /* Turn Green for Layer 1 */
            zmk_rgb_underglow_set_hsb((struct zmk_led_hsb){119, 100, 100});
            break;
        case 2:
            /* Turn Orange for Layer 2 */
            zmk_rgb_underglow_set_hsb((struct zmk_led_hsb){31, 100, 100});
            break;
        case 3:
            /* Turn Pink for Layer 3 */
            zmk_rgb_underglow_set_hsb((struct zmk_led_hsb){344, 100, 100});
            break;
        default:
            /* Turn Blue for Default Base Layer */
            zmk_rgb_underglow_set_hsb((struct zmk_led_hsb){193, 100, 100});
            break;
    }
    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(layer_color_listener, layer_color_listener_c);
ZMK_SUBSCRIPTION(layer_color_listener, zmk_layer_state_changed);
