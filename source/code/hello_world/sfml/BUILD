package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
   name = "main",
   srcs = ["main.cpp"],
   deps = ["@sfml//:sfml","@opengl//:opengl","@glfw//:glfw","@SDL2//:SDL2",],
   linkopts = ["-lX11", "-lGL", "-lXrandr","-ludev"],
)

cc_binary(
   name = "joystick",
   srcs = ["joystick.cpp"],
   deps = ["@sfml//:sfml","@opengl//:opengl","@glfw//:glfw","@SDL2//:SDL2",],
   linkopts = ["-lX11", "-lGL", "-lXrandr","-ludev"],
)
