load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")

package(default_visibility = ["//visibility:public"])

# From this example: https://github.com/jnmaloney/WebGui
cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    copts = [
        "-D__EMSCRIPTEN__",
        "-Wno-error=unused-but-set-variable",
    ],
    deps = [
        "@imgui//:imgui_glew",
        "@imgui//:imgui_glfw_opengl3",
        "@system//:GLES3_hdrs",
        "@system//:KHR_hdrs",
        "@system//:GLFW_hdrs",
        "@emscripten//:hdrs",
    ],
    linkopts = [
        "-s USE_GLFW=3",
        "-s USE_WEBGPU=1",
        "-s WASM=1",
        "-s ALLOW_MEMORY_GROWTH=1",
        "-s NO_EXIT_RUNTIME=0",
        "-s ASSERTIONS=1",
        "-s EXCEPTION_CATCHING_ALLOWED=[..]",
        "-sERROR_ON_UNDEFINED_SYMBOLS=0",
    ],
)

wasm_cc_binary(
    name = "main-wasm",
    cc_target = ":main",
)
