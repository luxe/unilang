package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "include/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "src/**/*.cpp",
    ],
    exclude = [
        "src/imtui-impl-emscripten.cpp",
    ],
)

cc_library(
    name = "imtui",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
        "include/",
    ],
    #include_prefix = "sys",
    deps = [
        "@imgui//:imgui_glfw_opengl3",
        "@ncurses",
    ],
)

demo_hdrs = glob(
    include = [
        "examples/*.h",
    ],
    exclude = [
    ],
)

demo_srcs = glob(
    include = [
        "examples/*.cpp",
    ],
    exclude = [
    ],
)

cc_library(
    name = "demo",
    srcs = demo_srcs,
    hdrs = demo_hdrs,
    includes = ["examples"],
    deps = ["@imtui"],
)

cc_binary(
    name = "example",
    srcs = ["examples/ncurses0/main.cpp"],
    deps = ["@imtui//:demo"],
)
