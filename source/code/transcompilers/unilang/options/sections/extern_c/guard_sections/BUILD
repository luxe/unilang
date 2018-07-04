package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name="define_guard_settings", deps = [
"//code/transcompilers/unilang/options/sections/extern_c/define_check:define_check_settings",
"//code/transcompilers/unilang/options/sections/extern_c/define_check:define_check_end_comment_settings",
])

hcp(name="begin_extern_c_guard_options", deps = [
"//code/transcompilers/unilang/options/sections/extern_c/guard_sections:define_guard_settings",
"//code/transcompilers/unilang/options/sections/macro:preprocessor_directives"
])

hcp(name="end_extern_c_guard_options", deps = [
"//code/transcompilers/unilang/options/sections/extern_c/guard_sections:define_guard_settings",
"//code/transcompilers/unilang/options/sections/macro:preprocessor_directives"
])