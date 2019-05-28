load("//bazel/cookbook/cpp:main.bzl", "cpp_main")

def distributable_cpp_main(name,deps=[]):

    cpp_main(name,deps)
