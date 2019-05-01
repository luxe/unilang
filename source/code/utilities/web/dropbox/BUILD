package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name="dropbox_uploader", deps = [
	"//code/utilities/types/char:lib",
	"//code/utilities/shell:lib",
    "//code/utilities/streams/filestreams/read_all:lib",
        "@curl",
])

cc_binary(
  name = "upload",
  srcs = ["upload_to_dropbox.cpp"],
  deps = ["//code/utilities/web/dropbox:dropbox_uploader",
  "//code/utilities/secret:secret_getter"]
)