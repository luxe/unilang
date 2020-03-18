package(
    default_visibility = ["//visibility:public"],
)


cc_binary(
   name = "main",
   srcs = ["main.cpp"],
   deps = [
    "@sfml//:sfml",
    "@opengl//:opengl",
    "@glfw//:glfw",
    "@SDL2//:SDL2",
    "//code/utilities/colors:sfml_color_pick_grid",
    "//code/utilities/colors:sfml_color_pick_hue_changer",
   ],
   linkopts = ["-lX11", "-lGL", "-lXrandr","-ludev"],
)