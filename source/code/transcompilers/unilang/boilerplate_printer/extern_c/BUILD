package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "extern_wrap_printer", deps = [
"//code/transcompilers/unilang/structure/sections/meta:meta_section",
"//code/transcompilers/unilang/options/sections/extern_c:extern_c_guard_options",
"//code/transcompilers/unilang/boilerplate_printer/extern_c:macro_define_check_getter",
"//code/transcompilers/unilang/boilerplate_printer/extern_c:macro_endif_getter",
"//code/utilities/streams/filestreams:lib",
])

hcp(name = "macro_define_check_getter", deps = [
"//code/transcompilers/unilang/options/sections/extern_c/define_check:define_check_settings",
"//code/utilities/types/strings/creators:lib",
])

hcp(name = "macro_endif_getter", deps = [
"//code/transcompilers/unilang/options/sections/extern_c/define_check:define_check_end_comment_settings",
"//code/transcompilers/unilang/options/sections/macro:preprocessor_directives",
])