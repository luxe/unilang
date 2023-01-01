load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        "@emscripten//:hdrs",
    ],
    linkopts = [
        "-s WASM=1",
        "-s LLD_REPORT_UNDEFINED",
        ]
)

wasm_cc_binary(
    name = "main-wasm",
    cc_target = ":main",
)
