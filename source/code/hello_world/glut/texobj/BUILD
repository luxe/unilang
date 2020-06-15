package(
    default_visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = [
        "-lGL",
        #"-lX11",
        #"-lglut",
        #"-lglut",
    ],
    copts = [
        #"-stdlib=libc++",
    ],
    deps = [
        "@x11",
        "@xorg_libXext",
        "@libXxf86vm",
        "@glut",
    ],
)
