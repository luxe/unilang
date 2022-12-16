package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp_hdrs_derive(
    name = "browser_creator",
    interface_deps = [
        "//code/utilities/web/automate/browser:browser_settings",
        "//code/utilities/web/chrome/driver:chrome_driver_selector",
        "//code/utilities/deps/external/pybind11:lib",
    ],
)

hcp_hdrs_derive(
    name = "browser_settings",
    interface_deps = [
        "//code/utilities/web/chrome/driver:chrome_driver_selection_settings",
    ],
)

hcp_hdrs_derive(
    name = "default_browser_settings_getter",
    interface_deps = [
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/types/vectors/operators:lib",
        "//code/utilities/web/automate/browser:browser_settings",
        "//code/utilities/web/chrome/driver:chrome_driver_selector",
    ],
)
