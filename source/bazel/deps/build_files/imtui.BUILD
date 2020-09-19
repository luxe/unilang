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
