package(default_visibility = ["//visibility:public"])

cc_library(
  name = "main",
  linkopts = ["-lm", "-lGL", "-lSDL"],
  srcs = glob(['*.cpp']),
  hdrs = glob(['*.h']),
)


cc_library(
 name = "imgui_sdl_opengl3",
 linkopts = ["-ldl", "-lGL", "-L/usr/lib/x86_64-linux-gnu", "-lSDL2", "-lSDL"],
 copts = ["-I/usr/include/SDL2", "-I/usr/include/SDL", "-Iexamples/", "-D_REENTRANT"],
 includes = [".","examples/libs/gl3w"],
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