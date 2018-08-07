load("//bazel/cookbook:cpp_object.bzl", "cpp_object")
load("//bazel/cookbook:bootstrap_hcp.bzl", "bootstrap_hcp")
load("//bazel/cookbook:hcp.bzl", "hcp")
load("//bazel/cookbook:generate_unilang_token_files.bzl", "generate_unilang_token_files")


#attempting to derive dependencies
#this will probably need to be done as an external process before even running bazel
def derive_deps_from_hcp(name):
    deps = []
    # ???
    # https://stackoverflow.com/questions/51165886/is-there-any-way-to-generate-the-deps-list-for-particular-rules
    return deps

def hcp_derive(name):
    deps = derive_deps_from_hcp(name)
    hcp(name,deps)