package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "ily",
    srcs = ["ily.cpp"],
    linkopts = [
        "-lX11",
        "-lGL",
        "-lXrandr",
        "-ludev",
    ],
    deps = [
        "//code/tools/games/ily3000/assets:assets_loader",
        "//code/tools/games/ily3000/core:frame_renderer",
        "//code/tools/games/ily3000/core:state_updater",
        "//code/tools/games/ily3000/state:game_state",
        "//code/tools/games/ily3000/state:game_state_getter",
        "//code/utilities/formats/json/functions:lib",
        "//code/utilities/graphics/sfml:game_loop",
        "//code/utilities/graphics/sfml:standard_sfml_game_loop",
        "//code/utilities/peripheral/keyboard/joycons",
        "//code/utilities/peripheral/keyboard/joycons:joycon_horizontal_state",
        "//code/utilities/peripheral/keyboard/joycons:joycon_state_getter",
        "@SDL2",
        "@glfw",
        "@opengl",
        "@sfml",
    ],
)
