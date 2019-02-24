package(default_visibility = ["//visibility:public"])

cc_library(
  name = "main",
  linkopts = [],
  srcs = glob(['*.cpp']),
  hdrs = glob(['*.h']),
  deps = ["@SDL2//:SDL2"],
)


cc_library(
 name = "imgui_sdl_opengl3",
 linkopts = ["-lGL"],
 copts = [],
 includes = [".","examples/libs/gl3w","examples/libs"],
 hdrs = [
     "examples/imgui_impl_opengl3.h",
     "examples/libs/gl3w/GL/gl3w.h",
     "examples/imgui_impl_sdl.h",
     "examples/libs/gl3w/GL/glcorearb.h",
 ],
 srcs = [
     "examples/imgui_impl_opengl3.cpp",
     "examples/imgui_impl_sdl.cpp",
     "examples/libs/gl3w/GL/gl3w.c",
 ],
 deps = [
     ":main",
 ],
)
