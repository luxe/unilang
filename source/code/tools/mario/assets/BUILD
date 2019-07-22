package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/image:png_to_x11_artifacts.bzl", "png_to_x11_artifacts")
load("//bazel/cookbook/sound:mp3_artifact.bzl", "mp3_artifact")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")

# https://downloads.khinsider.com/game-soundtracks/album/super-mario-bros.-1-3-anthology


png_to_x11_artifacts("mario-stand")
png_to_x11_artifacts("mario-walk1")
png_to_x11_artifacts("mario-walk2")
png_to_x11_artifacts("mario-walk3")
png_to_x11_artifacts("mario-duck")

mp3_artifact("main_theme")
mp3_artifact("mario_jump")


distributable_data(name="mario",
                   description="sprites for mario",
                   file_groups=[
                        ":mario-stand_image_data",
                        ":mario-walk1_image_data",
                        ":mario-walk2_image_data",
                        ":mario-walk3_image_data",
                        ":mario-duck_image_data",
                        ":main_theme_mp3_data",
                        ":mario_jump_mp3_data",
                   ]
)
