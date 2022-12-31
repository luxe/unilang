load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "@imgui//:imgui_glew",
        "@imgui//:imgui_glfw_opengl3",
        "@system//:GLES3_hdrs",
        "@system//:KHR_hdrs",
        "@system//:GLFW_hdrs",
    ]
)

wasm_cc_binary(
    name = "main-wasm",
    cc_target = ":main",
)
