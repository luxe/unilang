package(default_visibility = ["//visibility:public"])

cc_library(
    name = "opengl",
    srcs = [
        #"lib/x86_64-linux-gnu/libGL.so",
        #"lib/x86_64-linux-gnu/libGLU.so",
        #"lib/x86_64-linux-gnu/libEGL_mesa.so.0",
        #"lib/x86_64-linux-gnu/libGLX_mesa.so.0"
    ],
    hdrs = glob(["include/GL/**"]),
    includes = ["include"],
    linkopts = ["-lglut", "-lGL"]
)

cc_library(
    name = "egl",
    srcs = ["lib/x86_64-linux-gnu/libEGL.so"],
    hdrs = glob(["include/EGL/**"]),
    includes = ["include"],
)

