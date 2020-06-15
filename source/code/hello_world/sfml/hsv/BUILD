package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
    ],
    deps = [
        "//code/utilities/colors:sfml_color_pick_grid",
        "//code/utilities/colors:sfml_color_pick_hue_changer",
        "@sfml",
    ],
)
