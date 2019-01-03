package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook:cpp_object.bzl", "cpp_object")

hcp(name = "pulse_settings")
hcp(name = "pulse_transfer_action")
hcp(name = "pulse_transferer", deps = [
"pulse_settings","pulse_transfer_action","//code/utilities/shell:lib","//code/utilities/processes:lib",
"//code/utilities/colors:lib",
"//code/utilities/types/strings/observers/splitting:lib",
])

hcp(name = "transfer_account_settings", deps = [
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings"
])

hcp(name = "pulse_action_getter", deps = [
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_settings",
"//code/transcompilers/unilang/f2si_frontend_compiler/pulse:pulse_transfer_action",
"//code/utilities/types/strings/transformers/appending:lib",
"//code/utilities/types/vectors/transformers:lib",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/streams/filestreams:lib",
"//code/utilities/system:lib",
"//code/utilities/types/strings/transformers/removing:lib",
])