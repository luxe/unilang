load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

package(
    default_visibility = ["//visibility:public"],
)

cpp_main(
    name = "main",
    deps = ["@SDL2"],
)

cpp_main(
    name = "arrows",
    deps = ["@SDL2"],
)

#hermetic attempt
# cc_binary(
#     name = "main_her",
#     srcs = ["main.cpp"],
#     deps = ["@sdl2//:SDL2"],
#     linkopts = [
#         "-lX11",
#         "-lGL",
#         "-lXaw",
#         "-lXaw7",
#         "-lXt",
#     ],
# )