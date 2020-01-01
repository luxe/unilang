load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

#using the boot-strapped hcp compiler built from hcp files
def hcp(name,deps=[]):

    #the file names to use
    hcp_target_name = name + "_hcp"
    explicit_hcp_file = name + ".hcp"
    explicit_cpp_file = name + ".cpp"
    explicit_hpp_file = name + ".hpp"
    
    #converting hcp to hpp/cpp
    native.genrule(
        name = hcp_target_name,
        srcs = [explicit_hcp_file],
        outs = [explicit_cpp_file,explicit_hpp_file],
        tools = ["//code/tools/transcompilers/hcp-compiler/official:hcp-compiler"],
        cmd = """
    $(location //code/tools/transcompilers/hcp-compiler/official:hcp-compiler) $(SRCS) -o $(@D)
        """
    )
      
    #compiling hpp/cpp
    real_deps = list(deps)
    real_deps += ["@boost//:serialization"]
    real_deps += ["@nlohmann_json//:nlohmann_json"]
    cpp_object(name,real_deps)