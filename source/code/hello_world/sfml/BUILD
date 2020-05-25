package(
    default_visibility = ["//visibility:public"],
)

# Controller Implementations
cc_binary(
    name = "joycons",
    srcs = ["joycons.cpp"],
    linkopts = [
        "-lX11",
        "-lGL",
        "-lXrandr",
        "-ludev",
    ],
    deps = [
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "@glfw",
        "@opengl",
        "@sdl2//:SDL2",
        "@sfml",
    ],
)

cc_binary(
    name = "f310_gamepads",
    srcs = ["f310_gamepads.cpp"],
    linkopts = [
        "-lX11",
        "-lGL",
        "-lXrandr",
        "-ludev",
    ],
    deps = [
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/peripheral/keyboard/F310_gamepad/functions:f310_gamepads_state_getter",
        "@glfw",
        "@opengl",
        "@sdl2//:SDL2",
        "@sfml",
    ],
)

# SFML generic
cc_binary(
    name = "joystick",
    srcs = ["joystick.cpp"],
    linkopts = [
        "-lX11",
        "-lGL",
        "-lXrandr",
        "-ludev",
    ],
    deps = [
        "@glfw",
        "@opengl",
        "@sdl2//:SDL2",
        "@sfml",
    ],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lX11",
        "-lGL",
        "-lXrandr",
        "-ludev",
    ],
    deps = [
        "@glfw",
        "@opengl",
        "@sdl2//:SDL2",
        "@sfml",
    ],
)
