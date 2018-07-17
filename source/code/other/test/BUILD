cc_test(
    name = "hello-test",
    srcs = ["hello-test.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@gtest//:main",
        "@imgui//:main",
        "@imgui//:imgui_sdl_opengl3",
    ],
)

#wget https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip;
#unzip glfw-3.2.1.zip && cd glfw-3.2.1;
