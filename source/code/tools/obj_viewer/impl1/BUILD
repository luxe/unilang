package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGLEW",
        "-GL",
        "-lGLU",
        "-lglut",
    ],
    deps = [
        # "@GL",
        # "@glut",
        # "@x11",
        "@system//:GLEW",
        "@system//:GL_hdrs",
        "@system//:GL",
        #"@system//OpenGL",
        "@system//:GLU",
        "@system//:KHR_hdrs",
        "@system//:glut",
        "@system//:X11",
        #"@system//:GLX_mesa",
        #"@mesa_glu",
        "@tinyobjloader",
        "@glm",
        "//code/utilities/image:stb_image",
        "//code/utilities/data_structures/vector:vector3f",
        "//code/utilities/data_structures/matrix:matrix4x4f",
    ],
)

#-lGLEW -lGL -lGLU -lglut
