load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

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
      
      