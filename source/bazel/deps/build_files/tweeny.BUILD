load("@//bazel/cookbook/system:mv_file.bzl", "mv_file")
load("@//bazel/cookbook/system:search_and_replace.bzl", "search_and_replace")

# hacks because the dev used .tcc as an extension..
# mv_file("tween_cpp","include/tween.tcc","include/tween.cpp")
# mv_file("tweennone_cpp","include/tweennone.tcc","include/tweennone.cpp")
# mv_file("tweenpoint_temp","include/tweenpoint.tcc","include/tweenpoint.temp")
# mv_file("tweeny_cpp","include/tweeny.tcc","include/tweeny.cpp")

cc_library(
    name = "tweeny",
    hdrs = glob([
        "include/*.h",
        "include/*.cpp",
    ]),
    includes = [
        "include/",
    ],
    visibility = ["//visibility:public"],
)