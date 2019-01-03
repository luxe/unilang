package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")

hcp(
	name = "file_marker"
)

hcp(
	name = "file_marker_adjuster",
	deps = ["file_marker"]
)