package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/image:png_to_x11_artifacts.bzl", "png_to_x11_artifacts")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")

png_to_x11_artifacts("mario1")
png_to_x11_artifacts("mario2")
png_to_x11_artifacts("mario3")
png_to_x11_artifacts("mario4")


distributable_data(name="mario",
                   description="sprites for mario",
                   file_groups=[
                        ":mario1_data",
                        ":mario2_data",
                        ":mario3_data",
                        ":mario4_data",
                   ]
)