if (CONFIG_SHIELD_COSMOTYL_LEFT AND CONFIG_ZMK_RGB_UNDERGLOW)
    target_sources(app PRIVATE src/layer_rgb.c)
endif()
