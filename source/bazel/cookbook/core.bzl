load("//bazel/cookbook:make_symlink.bzl", "make_symlink_tag")


def cpp_object(name,deps=[]):

    #implicit file names
    explicit_cpp_file = name + ".cpp"
    explicit_hpp_file = name + ".hpp"

    #ccompile object file
    native.cc_library(
        name = name,
        srcs = [explicit_cpp_file],
        hdrs = [explicit_hpp_file],
        deps = deps,
    )  

#using the hcp compiler built from raw c++
def bootstrap_hcp(name,deps=[]):

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
        tools = ["//code/transcompilers/hcp-compiler/bootstrap:hcp-compiler"],
        cmd = """
    $(location //code/transcompilers/hcp-compiler/bootstrap:hcp-compiler) $(SRCS) -o $(@D) --no-utility-functions
                 """
    )
    
    #compiling hpp/cpp
    cpp_object(name,deps)

#using the hcp compiler built from hcp files
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
        tools = ["//code/transcompilers/hcp-compiler/official:hcp-compiler"],
        cmd = """
    $(location //code/transcompilers/hcp-compiler/official:hcp-compiler) $(SRCS) -o $(@D) --no-utility-functions
        """
    )
      
    #compiling hpp/cpp
    cpp_object(name,deps)
    

def derive_deps_from_hcp(name):
    deps = []
    # ???
    # https://stackoverflow.com/questions/51165886/is-there-any-way-to-generate-the-deps-list-for-particular-rules
    return deps

def hcp_derive(name):
    deps = derive_deps_from_hcp(name)
    hcp(name,deps)

def generate_unilang_token_files():

    native.genrule(
        name = "unilang_tokens",
        outs = ["global_token_table.hpp","global_token_table.cpp","token_group.hpp","token_group.cpp","token_name.hpp","token_name.cpp"],
        tools = ["//code/transcompilers/unilang/tokens:unilang_token_file_generator"],
        cmd = """
    $(location //code/transcompilers/unilang/tokens:unilang_token_file_generator) $(@D) 
        """
    )

    cpp_object(name="token_name")
    cpp_object(name="token_group")
    cpp_object(name="global_token_table",deps=["//code/transcompilers/unilang/tokens:generic_token",
      "//code/transcompilers/unilang/tokens:token_group",
      "//code/transcompilers/unilang/tokens:token_name"])