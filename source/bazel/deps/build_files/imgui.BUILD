package(default_visibility = ["//visibility:public"])

cc_library(
    name = "main",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.h"]),
    linkopts = [],
    deps = [
        #"@SDL2",
        #"@opengl",
    ],
)


##############################################################################################
cc_library(
    name = "imgui_sdl_opengl3",
    srcs = [
        "examples/imgui_impl_opengl3.cpp",
        "examples/imgui_impl_sdl.cpp",
        "examples/libs/gl3w/GL/gl3w.c",
    ],
    hdrs = [
        "examples/imgui_impl_opengl3.h",
        "examples/imgui_impl_sdl.h",
        "examples/libs/gl3w/GL/gl3w.h",
        "examples/libs/gl3w/GL/glcorearb.h",
    ],
    includes = [
        ".",
        "examples",
        "examples/libs",
        "examples/libs/gl3w",
    ],
    deps = [
        ":main",
        
        "@sdl2",
        
        # "@sdl2//:sdl2_hdrs",
        # "@system//:SDL2",
        
        #"@SDL_image//:hdrs",
        #"@system//:SDL2_image",
        
        # "@mesa//:mesa_hdrs",
        #"@system//:GLX",
        
        #"@glib",
        #"@system//:glib",
        #"@system//:GLX_mesa",
        #"@system//:EGL_mesa",
    ],
)

cc_binary(
    name = "imgui_sdl_opengl3_main",
    srcs = ["examples/example_sdl_opengl3/main.cpp"],
    deps = [
        ":imgui_sdl_opengl3",
        "@GL",
    ],
)
##############################################################################################

cc_library(
    name = "imgui_sdl_opengl2",
    srcs = [
        "examples/imgui_impl_opengl2.cpp",
        "examples/imgui_impl_sdl.cpp",
        "examples/libs/gl3w/GL/gl3w.c",
    ],
    hdrs = [
        "examples/imgui_impl_opengl2.h",
        "examples/imgui_impl_sdl.h",
        "examples/libs/gl3w/GL/gl3w.h",
        "examples/libs/gl3w/GL/glcorearb.h",
    ],
    includes = [
        ".",
        "examples",
        "examples/libs",
        "examples/libs/gl3w",
    ],
    deps = [
        ":main",
       #"@sdl2",
       
        "@sdl2//:sdl2_hdrs",
        "@SDL_image//:hdrs",
        "@system//:SDL2",
        "@system//:SDL2_image",
        "@system//:GLX",
        "@mesa//:mesa_hdrs",
    ],
)

cc_binary(
    name = "imgui_sdl_opengl2_main",
    srcs = ["examples/example_sdl_opengl2/main.cpp"],
    deps = [
        ":imgui_sdl_opengl2",
        "@GL",
    ],
)
##############################################################################################

cc_library(
    name = "imgui_glfw_opengl3",
    srcs = [
        "examples/imgui_impl_opengl3.cpp",
        "examples/imgui_impl_glfw.cpp",
        "examples/libs/gl3w/GL/gl3w.c",
    ],
    hdrs = [
        "examples/imgui_impl_opengl3.h",
        "examples/imgui_impl_glfw.h",
        "examples/libs/gl3w/GL/gl3w.h",
        "examples/libs/gl3w/GL/glcorearb.h",
    ],
    copts = [
        "-DIMGUI_IMPL_OPENGL_LOADER_GL3W",
    ],
    includes = [
        ".",
        "examples",
        "examples/libs",
        "examples/libs/gl3w",
    ],
    deps = [
        ":main",
       "@system//:glfw",
       "@glfw//:hdrs",
       
       "@system//:GL_hdrs",
       #"@x11",
       "@system//:X11_hdrs",
       "@system//:KHR_hdrs",
       #"@mesa//:mesa_hdrs",
       
    ],
)

cc_binary(
    name = "imgui_glfw_opengl3_main",
    srcs = ["examples/example_glfw_opengl3/main.cpp"],
    copts = [
        "-DIMGUI_IMPL_OPENGL_LOADER_GL3W",
    ],
    deps = [
        ":imgui_glfw_opengl3",
        "@GL",
    ],
)








