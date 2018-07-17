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
 copts = ["-I/usr/include/SDL2"],
 includes = ["."],
 hdrs = [
     "examples/imgui_impl_opengl3.h",
 ],
 srcs = [
     "examples/imgui_impl_opengl3.cpp",
 ],
 deps = [
     ":main",
 ],
)