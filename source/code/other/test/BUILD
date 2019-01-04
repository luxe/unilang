cc_test(
    name = "hello-test",
    srcs = ["hello-test.cc"],
    copts = ["-Iexternal/gtest/include"],
    deps = [
        "@com_google_googletest//:gtest_main",
    ],
)

#wget https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip;
#unzip glfw-3.2.1.zip && cd glfw-3.2.1;

cc_binary(
	name = "imgui-test",
	srcs = ["imgui-test.cpp"],
    copts = ["-Iexternal/imgui", "-Iexternal/imgui/examples","-I/usr/include/SDL"],
    deps = [
        "@imgui//:main",
        "@imgui//:imgui_sdl_opengl3",
	]
)