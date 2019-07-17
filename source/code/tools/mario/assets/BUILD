package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/image:png_to_x11_artifacts.bzl", "png_to_x11_artifacts")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")

png_to_x11_artifacts("mario-stand")
png_to_x11_artifacts("mario-walk1")
png_to_x11_artifacts("mario-walk2")
png_to_x11_artifacts("mario-walk3")


distributable_data(name="mario",
                   description="sprites for mario",
                   file_groups=[
                        ":mario-stand_data",
                        ":mario-walk1_data",
                        ":mario-walk2_data",
                        ":mario-walk3_data",
                   ]
)