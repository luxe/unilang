package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
        "-lGLEW",
        "-lglut",
    ],
    deps = [
        # "@GL",
        # "@glut",
        # "@x11",
        "@system//:GL",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
        "@system//:glut",
        "@system//:X11",
        "@system//:GLEW",
        #"@system//:GLU",
        "@tinyobjloader",
        "@glm",
        "//code/utilities/image:stb_image",
    ],
)

#-lGLEW -lGL -lGLU -lglut
