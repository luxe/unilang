package(default_visibility = ["//visibility:public"])

#not sure if I should link -lGL -lopengl32
cc_library(
  name = "main",
  linkopts = ["-lm", "-lGL"],
  srcs = glob(['*.cpp']),
  hdrs = glob(['*.h']),
)

 
cc_library(
 name = "imgui_sdl_opengl3",
 linkopts = ["-ldl", "-lGL", "-L/usr/lib/x86_64-linux-gnu", "-lSDL2"],
 copts = ["-I/usr/include/SDL2", "-Iexamples/", "-D_REENTRANT"],
 includes = [".","examples/libs/gl3w"],
 hdrs = [
     "examples/imgui_impl_opengl3.h",
     "examples/libs/gl3w/GL/gl3w.h",
     "examples/libs/gl3w/GL/glcorearb.h",
 ],
 srcs = [
     "examples/imgui_impl_opengl3.cpp",
     "examples/libs/gl3w/GL/gl3w.c",
 ],
 deps = [
     ":main",
 ],
)