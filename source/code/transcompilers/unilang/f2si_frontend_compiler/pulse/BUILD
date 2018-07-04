package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "pulse_settings")
hcp(name = "pulse_transfer_action")
hcp(name = "pulse_transferer", deps = [
"pulse_settings","pulse_transfer_action","//code/utilities/shell:lib","//code/utilities/processes:lib"
])