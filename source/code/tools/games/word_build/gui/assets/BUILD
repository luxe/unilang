package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")

hcp(
    name = "assets",
    deps = [
        "//code/tools/games/word_build/gui/assets:user_assets",
        "//code/utilities/graphics/sfml/data:moving_text",
        "//code/utilities/peripheral/sound/sfml:sound",
        "@sfml",
    ],
)

hcp(
    name = "assets_loader",
    deps = [
        "//code/tools/games/word_build/gui/assets",
        "//code/tools/games/word_build/gui/state:game_state",
        "//code/utilities/assets:puyo",
        "//code/utilities/fonts/font_files:droid_sans_mono",
        "//code/utilities/fonts/sfml:font_loader",
        "//code/utilities/peripheral/sound/sfml:sound_loader",
        "@sfml",
    ],
)

hcp(
    name = "user_assets",
    deps = [
        "//code/utilities/peripheral/sound/sfml:sound",
        "@sfml",
    ],
)
