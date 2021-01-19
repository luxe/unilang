package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGLEW",
        "-lGL",
        #"-lGLU",
        "-lglut",
    ],
    deps = [
        # "@GL",
        # "@glut",
        # "@x11",
        #"@system//:GLU",
        "@system//:GL",
        "@system//:GL_hdrs",
        "@system//:KHR_hdrs",
        "@system//:glut",
        "@system//:X11",
        "@system//:GLEW",
        "@system//:GLX_mesa",
        #"@mesa_glu",
        "@tinyobjloader",
        "@glm",
        "//code/utilities/image:stb_image",
    ],
)

#-lGLEW -lGL -lGLU -lglut
