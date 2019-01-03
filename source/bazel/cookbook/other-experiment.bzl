load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/hcp:bootstrap.bzl", "bootstrap_hcp")
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/unilang:generate_unilang_token_files.bzl", "generate_unilang_token_files")


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