def enum_cpp(name,values=[]):



    #implicit file names
    explicit_cpp_file = name + ".cpp"
    explicit_hpp_file = name + ".hpp"

    #converting bazel commands to c++ enum files
    native.genrule(
        name = name,
        srcs = [],
        outs = [explicit_cpp_file,explicit_hpp_file],
        tools = ["//code/transcompilers/enum_cpp:enum_cpp"],
        cmd = """
    $(location //code/transcompilers/enum_cpp:enum_cpp) --enum_name $name --enum_values $values -o $(@D)
        """
    )

    #compile object file
    native.cc_library(
        name = name,
        srcs = [explicit_cpp_file],
        hdrs = [explicit_hpp_file],
    )
