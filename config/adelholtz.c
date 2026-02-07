// SPDX-License-Identifier: GPL-2.0-or-later
// ZMK behavior that mirrors the custom process_record_user logic from QMK.
// Note: This file provides weak integration hooks for string sending, host OS
// detection, layer switching, and RGB mode changes. Wire these hooks to your
// ZMK setup as needed.

#include <zephyr/kernel.h>
#include <drivers/behavior.h>
#include <zmk/behavior.h>

#define DT_DRV_COMPAT zmk_behavior_adelholtz_process_record_user

// ----- Custom key identifiers passed via binding parameter -----
// These values are behavior-specific and should match the values you use
// in your keymap bindings.
enum adelholtz_custom_keycode {
    ADELHOLTZ_RELOAD = 1,
    ADELHOLTZ_LCURLY,
    ADELHOLTZ_RCURLY,
    ADELHOLTZ_PIPE,
    ADELHOLTZ_BACKSLASH,
    ADELHOLTZ_LESS,
    ADELHOLTZ_GREATER,
    ADELHOLTZ_LBRACKET,
    ADELHOLTZ_RBRACKET,
};

// ----- Host OS detection shim -----
enum adelholtz_host_os {
    ADELHOLTZ_OS_UNKNOWN = 0,
    ADELHOLTZ_OS_MACOS,
    ADELHOLTZ_OS_IOS,
    ADELHOLTZ_OS_LINUX,
    ADELHOLTZ_OS_WINDOWS,
};

// Weak hooks to integrate with ZMK services.
// Override these in another compilation unit to integrate with your setup.
__attribute__((weak)) enum adelholtz_host_os adelholtz_get_host_os(void) {
    return ADELHOLTZ_OS_UNKNOWN;
}

__attribute__((weak)) int adelholtz_send_string(const char *str) {
    ARG_UNUSED(str);
    return -ENOTSUP;
}

static int send_os_string(const char *mac_ios, const char *linux_win, const char *fallback) {
    enum adelholtz_host_os os = adelholtz_get_host_os();
    if (os == ADELHOLTZ_OS_MACOS || os == ADELHOLTZ_OS_IOS) {
        return adelholtz_send_string(mac_ios);
    } else if (os == ADELHOLTZ_OS_LINUX || os == ADELHOLTZ_OS_WINDOWS) {
        return adelholtz_send_string(linux_win);
    }

    return adelholtz_send_string(fallback);
}

static int on_keymap_binding_pressed(struct zmk_behavior_binding *binding,
                                     struct zmk_behavior_binding_event event) {
    ARG_UNUSED(event);

    uint16_t keycode = (uint16_t)binding->param1;

    switch (keycode) {
        case ADELHOLTZ_RELOAD:
            // QMK: mac/ios => GUI+R; linux/windows => CTRL+R
            send_os_string("<GUI>r", "<CTRL>r", "");
            return ZMK_BEHAVIOR_OPAQUE;

        case ADELHOLTZ_LCURLY:
            // QMK: mac/ios => ALGR+8; linux/windows => ALGR+7
            send_os_string("<ALGR>8", "<ALGR>7", "");
            return ZMK_BEHAVIOR_OPAQUE;

        case ADELHOLTZ_RCURLY:
            // QMK: mac/ios => ALGR+9; linux/windows => ALGR+0
            send_os_string("<ALGR>9", "<ALGR>0", "");
            return ZMK_BEHAVIOR_OPAQUE;

        case ADELHOLTZ_PIPE:
            // QMK: mac/ios => ALGR+7; linux/windows => "|"
            send_os_string("<ALGR>7", "|", "");
            return ZMK_BEHAVIOR_OPAQUE;

        case ADELHOLTZ_LBRACKET:
            // QMK: mac/ios => ALGR+5; linux/windows => ALGR+8
            send_os_string("<ALGR>5", "<ALGR>8", "");
            return ZMK_BEHAVIOR_OPAQUE;

        case ADELHOLTZ_RBRACKET:
            // QMK: mac/ios => ALGR+6; linux/windows => ALGR+9
            send_os_string("<ALGR>6", "<ALGR>9", "");
            return ZMK_BEHAVIOR_OPAQUE;

        case ADELHOLTZ_BACKSLASH:
            // QMK: mac/ios => ALGR+SHIFT+7; linux/windows => "\\"
            send_os_string("<ALGR><LSHFT>7", "\\", "");
            return ZMK_BEHAVIOR_OPAQUE;

        case ADELHOLTZ_LESS:
            // QMK: mac/ios => "<"; linux/windows => "<"
            send_os_string("<", "<", "");
            return ZMK_BEHAVIOR_OPAQUE;

        case ADELHOLTZ_GREATER:
            // QMK: mac/ios => ">"; linux/windows => ">"
            send_os_string(">", ">", "");
            return ZMK_BEHAVIOR_OPAQUE;

        default:
            return ZMK_BEHAVIOR_OPAQUE;
    }
}

static int on_keymap_binding_released(struct zmk_behavior_binding *binding,
                                      struct zmk_behavior_binding_event event) {
    ARG_UNUSED(binding);
    ARG_UNUSED(event);
    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api behavior_adelholtz_process_record_user_driver_api = {
    .binding_pressed = on_keymap_binding_pressed,
    .binding_released = on_keymap_binding_released,
};

static int behavior_adelholtz_process_record_user_init(const struct device *dev) {
    ARG_UNUSED(dev);
    return 0;
}

BEHAVIOR_DT_INST_DEFINE(0, behavior_adelholtz_process_record_user_init, NULL, NULL, NULL,
                        POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,
                        &behavior_adelholtz_process_record_user_driver_api);
