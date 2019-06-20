package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")

hcp(name = "meta_settings", deps = [
])

hcp(name = "noogle_running_stats", deps = [
])

hcp(name = "noogle_runner", deps = [
    "//code/tools/noogle:meta_settings",
    "//code/utilities/web/chrome/driver:chrome_driver_selector",
    "//code/utilities/web/automate/browser:browser_creator",
    "//code/utilities/web/automate/browser:browser_settings",
    "//code/tools/noogle:default_settings_getter",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/types/strings/transformers/squeeze:lib",
    "@pybind11//:pybind11",
    "@boost//:asio",
    "//code/tools/noogle/settings:noogle_settings",
    "//code/utilities/data_structures/queue:safe_queue",
    "//code/utilities/data_structures/queue:finishable_safe_queue",
    "//code/utilities/time/sleeping:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/web/google:google_search_url_deviser",
    "//code/utilities/web:lib",
    "//code/tools/noogle:noogle_running_stats",
])

hcp(name = "default_settings_getter", deps = [
    "//code/tools/noogle/settings:noogle_settings",
    "//code/utilities/web/chrome/driver:chrome_driver_selector",
])

distributable_data(name="chrome_drivers",
                   description="chrome drivers for automating google chrome with selenium",
                   file_groups=["@chrome_drivers//:chrome_drivers"]
                   )

distributable_cpp_main(
    name = "noogle",
    deps = [
        "//code/tools/noogle:noogle_runner",
        "//code/tools/noogle:meta_settings"
    ],
    data = ":debian-data",
    description = "google but numbers",
    depends = [],
)