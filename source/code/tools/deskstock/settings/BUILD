package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "deskstock_state", deps = [
    "//code/tools/deskstock/settings:deskstock_settings",
    "//code/utilities/config:config_monitor_settings",
])

hcp(name = "deskstock_settings", deps = [
    "//code/tools/deskstock/settings:value_get_settings",
    "//code/tools/deskstock/settings:system_effect_settings",
    "//code/tools/deskstock/settings:startup_settings",
    "//code/tools/deskstock/settings:monitor_settings",
])

hcp(name = "value_get_settings", deps = [
    "//code/utilities/web:web_json_extraction_settings",
    "//code/tools/deskstock/settings:simulation_value_settings",
    "//code/tools/deskstock/settings:user_command_settings",
    "//code/tools/deskstock/settings:mouse_value_settings",
])

hcp(name = "simulation_value_settings", deps = [
])

hcp(name = "system_effect_settings", deps = [
    "//code/utilities/screen/good_bad:good_bad_screen_tint_settings",
    "//code/utilities/terminal/good_bad:good_bad_terminal_settings",
    "//code/tools/deskstock/settings:user_command_settings",
    "//code/utilities/terminal/mouse:mouse_terminal_settings",
])

hcp(name = "startup_settings", deps = [
    "//code/utilities/system:check_installed_program_settings",
    "//code/utilities/locale:locale_settings",
])

hcp(name = "user_command_settings", deps = [
])

hcp(name = "mouse_value_settings", deps = [
])

hcp(name = "monitor_settings", deps = [
])