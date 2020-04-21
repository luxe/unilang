package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(name = "sign_type",
values = [
"index"
,"icon"
,"symbol"
])

enum_cpp(name = "sign_reality",
values = [
"base"
,"copy"
,"new"
])

hcp(name = "dyadic_sign", deps = [
    "//code/utilities/semiotics:sign_type",
])

hcp(name = "triadic_sign", deps = [
    "//code/utilities/semiotics:sign_type",
])

hcp(name = "dyadic_knowledge", deps = [
    "//code/utilities/semiotics:dyadic_sign",
]) 

hcp(name = "triadic_knowledge", deps = [
    "//code/utilities/semiotics:triadic_sign",
]) 