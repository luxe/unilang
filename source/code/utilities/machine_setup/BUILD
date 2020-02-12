package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "keygen_refresher",deps=[
	"//code/utilities/program/call:lib"
])

cc_binary(
  name = "refresh_keygen",
  srcs = ["refresh_keygen.cpp"],
  deps = ["//code/utilities/machine_setup:keygen_refresher"]
)

hcp(name = "machine_provisioner",deps=[
	"//code/utilities/program/call:lib",
	"//code/utilities/machine_setup:keygen_refresher",
	"//code/utilities/program/wrappers/git:git_setuper"
])

cc_binary(
  name = "provision_machine",
  srcs = ["provision_machine.cpp"],
  deps = ["//code/utilities/machine_setup:machine_provisioner"]
)