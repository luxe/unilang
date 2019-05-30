package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

hcp(name = "mouse_binded_gama_slider",deps=[
    "//code/utilities/data_structures:two_d_coordinate_dimension",
    "//code/utilities/screen/good_bad:gama_slider",
])

hcp(name = "mouse_terminal_settings",deps=[
    "//code/utilities/terminal/mouse:mouse_binded_gama_slider",
])

hcp(name = "mouse_terminal_changer",deps=[
    "//code/utilities/terminal/mouse:mouse_terminal_settings",
    "//code/utilities/terminal:terminal_background_changer",
    "//code/utilities/math:math",
    "//code/utilities/shell:lib",
])