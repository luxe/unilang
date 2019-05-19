package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")

pkg_tar(
    name = "deskstock",
    package_dir = "/usr/bin",
    srcs = ["//code/games/stock_game:main"],
    mode = "0755",
)

pkg_tar(
    name = "debian-data",
    extension = "tar.gz",
    deps = [
        ":deskstock",
    ],
)

pkg_deb(
    name = "deskstock-debian",
    architecture = "amd64",
    built_using = "unzip (6.0.1)",
    data = ":debian-data",
    depends = [
        "zlib1g-dev",
        "unzip",
    ],
    description = "hello",
    homepage = "none",
    maintainer = "none",
    package = "deskstock",
    version = "1.0",
)

hcp(name = "task_executer", deps = [
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
"//code/games/stock_game:deskstock_settings",
"//code/utilities/locale:locale_setter",
"//code/utilities/web:lib",
"//code/games/stock_game:default_settings_getter",
"//code/utilities/config:config_monitor",
"//code/utilities/config:config_monitor_settings",
"//code/utilities/types/strings/transformers/search_replace:lib",
"//code/utilities/shell:lib",
])

hcp(name = "default_settings_getter", deps = [
"//code/games/stock_game:deskstock_settings",
"//code/utilities/stock:stock_getter",
"//code/utilities/web:lib",
])

hcp(name = "deskstock_settings", deps = [
    "//code/utilities/locale:locale_settings",
    "//code/games/stock_game:value_get_settings",
    "//code/games/stock_game:system_effect_settings",
])

hcp(name = "value_get_settings", deps = [
    "//code/utilities/web:web_json_extraction_settings",
    "//code/games/stock_game:simulation_value_settings",
])

hcp(name = "simulation_value_settings", deps = [
])

hcp(name = "system_effect_settings", deps = [
    "//code/utilities/screen/good_bad:good_bad_screen_tint_settings",
])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/games/stock_game:task_executer"]
)
