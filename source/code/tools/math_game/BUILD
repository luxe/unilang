package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
   name = "math_game",
   srcs = ["math_game.cpp"],
   deps = [
    "//code/utilities/keyboard/joycons:joycon_horizontal_state",
    "//code/utilities/json/functions:lib",
    "//code/utilities/keyboard/joycons:joycons",
    "//code/utilities/keyboard/joycons:joycon_state_getter",
    "//code/tools/math_game/assets:assets_loader",
    "@sfml//:sfml","@opengl//:opengl","@glfw//:glfw","@SDL2//:SDL2",],
   linkopts = ["-lX11", "-lGL", "-lXrandr","-ludev"],
)
