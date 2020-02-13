def cpp_object(name,deps=[],data=[]):

    #implicit file names
    explicit_cpp_file = name + ".cpp"
    explicit_hpp_file = name + ".hpp"

    #compile object file
    native.cc_library(
        name = name,
        srcs = [explicit_cpp_file],
        hdrs = [explicit_hpp_file],
        data = data,
        deps = deps,
    )