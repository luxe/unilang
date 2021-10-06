package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lglut",
        "-lGL",
        "-lGLU",
    ],
    deps = [
        "//code/programs/examples/glut/mesh/Core:lib",
        "//code/programs/examples/glut/mesh/Math:lib",
        "@system//:GL",
        "@system//:GLU",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
        "@system//:glut",
        "@system//:glut_hdrs",
    ],
)
