package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "file_upload_settings")
hcp(name = "file_uploader", deps = [
"//code/utilities/upload:file_upload_settings",
"//code/utilities/web/dropbox:dropbox_uploader",
"//code/utilities/secret:secret_getter",
"//code/utilities/git-related:github_uploader",
])