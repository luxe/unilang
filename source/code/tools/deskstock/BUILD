package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

hcp(name = "deskstock_runner", deps = [
"//code/transcompilers/unilang/tokens:generic_token",
"//code/utilities/types/general:lib",
"//code/utilities/exits:lib",
"//code/utilities/locale:lib",
"//code/utilities/types/vectors/observers:lib",
"//code/utilities/types/vectors/operators:lib",
"//code/utilities/filesystem/files/creating:lib",
"//code/transcompilers/unilang/tokens:get_tokens",
"//code/utilities/filesystem/files/getting:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/upload:file_uploader",
"//code/transcompilers/unilang/compiler-frontends/dzslides:dzslides_exporter",
"//code/transcompilers/unilang/compiler-frontends/slidy:slidy_exporter",
"//code/utilities/chinese:chinese_translations",
"//code/utilities/time/date:lib",
"//code/utilities/time/sleeping:lib",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/types/strings/transformers/squeeze:lib",
"//code/utilities/screen:screen_tint_setter",
"//code/utilities/stock:stock_getter",
"//code/utilities/screen/good_bad:good_bad_screen_tint_settings",
"//code/tools/deskstock/settings:deskstock_settings",
"//code/utilities/locale:locale_setter",
"//code/utilities/web:lib",
"//code/tools/deskstock:default_settings_getter",
"//code/utilities/config:config_monitor",
"//code/utilities/config:config_monitor_settings",
"//code/utilities/types/strings/transformers/search_replace:lib",
"//code/utilities/shell:lib",
"//code/tools/deskstock/settings:deskstock_state",
"//code/utilities/system:installed_programs_checker",
"//code/utilities/terminal/good_bad:good_bad_terminal_changer",
"//code/utilities/math:math",
"//code/tools/deskstock:float_sourcer",
"//code/tools/deskstock:system_effecter",
"//code/tools/deskstock:meta_settings",
])

hcp(name = "float_sourcer", deps = [
    "//code/tools/deskstock/settings:deskstock_state",
    "//code/utilities/web:lib",
    "//code/utilities/shell:lib",
    "//code/utilities/types/strings/transformers/other:lib",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/mouse:mouse_controller",
])

hcp(name = "system_effecter", deps = [
    "//code/tools/deskstock/settings:deskstock_state",
    "//code/utilities/screen:screen_tint_setter",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/shell:lib",
    "//code/utilities/terminal/good_bad:good_bad_terminal_changer",
    "//code/utilities/terminal/mouse:mouse_terminal_changer",
])

hcp(name = "default_settings_getter", deps = [
"//code/tools/deskstock/settings:deskstock_settings",
"//code/utilities/stock:stock_getter",
"//code/utilities/web:lib",
])

hcp(name = "deskstock_documentation_getter", deps = [
    "//code/transcompilers/unilang/structure/model:structure",
    "//code/transcompilers/unilang/structure/model:inlined_structures",
    "//code/utilities/converters:lib",
    "//code/tools/deskstock/settings:startup_settings",
    "//code/utilities/json/functions:lib",
    "//code/tools/deskstock:default_settings_getter",
    "//code/utilities/documentation:common_documentation_getter",
])

hcp(name = "meta_settings", deps = [
])

distributable_cpp_main(
    name = "deskstock",
    deps = [
        "//code/tools/deskstock:deskstock_runner",
        "//code/tools/deskstock:meta_settings"
    ],
    description = "Feel the stock market while you work",
    depends = [
        "zlib1g-dev",
        "unzip",
        "redshift",
        "libxdo-dev"
    ],
)
