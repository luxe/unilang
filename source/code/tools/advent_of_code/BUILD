package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "task_executer", deps = [
"//code/utilities/types/general:lib",
"//code/utilities/exits:lib",
"//code/utilities/web:lib",
"//code/utilities/printers:lib",
"//code/tools/advent_of_code:advent_of_code_input_getter",
"//code/utilities/web/automate/browser:default_browser_settings_getter",
"//code/utilities/web/automate/browser:browser_creator",
"//code/utilities/web/automate/navigation:browser_navigator",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/observers/converting:lib",
"//code/utilities/types/strings/transformers/removing:lib",
"//code/utilities/types/strings/observers/splitting:lib",
"//code/utilities/data_structures/compass_directions:compass_direction_diagnonal_movement",
"//code/utilities/json/functions:lib",
"//code/utilities/data_structures/point:point_line",
"//code/utilities/data_structures/point:point_mover",
"//code/utilities/data_structures/point:point",
])

hcp(name = "advent_of_code_input_getter", deps = [
"//code/utilities/types/general:lib",
"//code/utilities/exits:lib",
"//code/utilities/web:lib",
"//code/utilities/printers:lib",
"@pybind11//:pybind11",
"//code/utilities/web/automate/browser:default_browser_settings_getter",
"//code/utilities/web/automate/browser:browser_creator",
"//code/utilities/web/automate/navigation:browser_navigator",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/types/strings/observers/converting:lib",
"//code/utilities/types/strings/transformers/removing:lib",
])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = ["//code/tools/advent_of_code:task_executer"]
)
