load("@build_stack_rules_proto//cpp:cpp_proto_library.bzl", "cpp_proto_library")

def cpp_proto_object(name,deps=[]):

    #implicit file names
    pfile = name + ".proto"
    ptarget = name + "_proto"
    pobject = name + "_cpp_proto"

    #compile protobuf file
    native.proto_library(
        name = ptarget,
        srcs = [pfile],
    )

    #compile cpp file
    native.cc_proto_library(
        name = pobject,
        deps = [":" + ptarget],
    )