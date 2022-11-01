load("@rules_cc//cc:defs.bzl", "cc_binary")
#load("@emsdk//emscripten_toolchain:wasm_rules.bzl", "wasm_cc_binary")

cc_binary(
    name = "hello-world",
    srcs = ["main.cpp"],
)

# Does not work with:
# build --incompatible_use_specific_tool_files=false
# build --incompatible_enable_cc_toolchain_resolution

# wasm_cc_binary(
#     name = "hello-world-wasm",
#     cc_target = ":hello-world",
# )
