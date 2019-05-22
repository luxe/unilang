package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

hcp(name = "deskstock_state", deps = [
    "//code/games/deskstock/settings:deskstock_settings",
    "//code/utilities/config:config_monitor_settings",
])

hcp(name = "deskstock_settings", deps = [
    "//code/utilities/locale:locale_settings",
    "//code/games/deskstock/settings:value_get_settings",
    "//code/games/deskstock/settings:system_effect_settings",
    "//code/utilities/system:check_installed_program_settings",
])

hcp(name = "value_get_settings", deps = [
    "//code/utilities/web:web_json_extraction_settings",
    "//code/games/deskstock/settings:simulation_value_settings",
])

hcp(name = "simulation_value_settings", deps = [
])

hcp(name = "system_effect_settings", deps = [
    "//code/utilities/screen/good_bad:good_bad_screen_tint_settings",
    "//code/utilities/terminal:change_terminal_settings",
])