package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "bazel_conversion_test", deps = [
"//code/transcompilers/unilang/user-frontend/artifact_actions:artifact_type",
"//code/bazel_refresh/conversion_test:bazel_conversion_test_file_contents",
])

hcp(name = "bazel_conversion_tests", deps = [
"//code/bazel_refresh/conversion_test:bazel_conversion_test",
])

hcp(name = "bazel_conversion_test_file_contents", deps = [
])

hcp(name = "test_getter", deps = [
"//code/bazel_refresh/conversion_test:bazel_conversion_tests",
"//code/utilities/filesystem/paths:lib",
"//code/utilities/filesystem/files/creating:lib",
"//code/utilities/types/strings/transformers/appending:lib",
])