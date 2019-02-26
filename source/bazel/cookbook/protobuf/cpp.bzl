def cpp_proto_object(name,deps=[]):

    #implicit file names
    pfile = name + ".proto"
    ptarget = name + "_proto"
    pobject = name + "cpp_proto"

    #compile protobuf file
    proto_library(
        name = ptarget,
        srcs = [pfile],
    )

    #compile cpp file
    cc_proto_library(
        name = pobject,
        deps = [":" + ptarget],
    )