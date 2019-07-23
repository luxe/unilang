package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")
load("//bazel/cookbook/cpp:main.bzl", "cpp_main")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar", "pkg_deb")



hcp(name = "mario_runner", deps = [
    "//code/utilities/sound:music_player",
    "//code/utilities/x11/main_state:x11_main_state_creator",
    "//code/utilities/x11/sprite:sprite_loader",
    "//code/utilities/x11/sprite:sprite_window_creator",
    "//code/utilities/x11/sprite:sprite_window_drawer",
    "//code/utilities/x11/loop:x11_looper",
    "//code/utilities/x11:lib",
    "//code/tools/mario/sprites:sprites_loader",
    "//code/utilities/x11/events:global_event_listener",
    "//code/utilities/types/booleans:lib",
    "//code/tools/mario/engine/user_input:user_action_getter",
    "//code/tools/mario/engine/user_input:user_action",
    "//code/tools/mario/sprites:sprites",
    "//code/tools/mario/sound:sounds_loader",
    "//code/tools/mario/engine:physics_state",
    "//code/utilities/sound/sdl:sdl_audio",
    "//code/utilities/x11/geometry:window_geometry_getter",
])

hcp(name = "mario_documentation_getter", deps = [
    "//code/transcompilers/unilang/structure/model:structure",
    "//code/transcompilers/unilang/structure/model:inlined_structures",
    "//code/utilities/converters:lib",
    "//code/utilities/json/functions:lib",
    "//code/utilities/documentation:common_documentation_getter",
])


#build main and deploy stuff
cc_binary(
    name = "mario",
    srcs = ["mario.cpp"],
    deps = [
        "//code/tools/mario:mario_runner",
    ]
)

package_binaries(name = "mario", binary_targets = [":mario"])

pkg_tar(
    name = "mario_all_deb_data",
    extension = "tar.gz",
    deps = [
        ":mario-data",
        "//code/tools/mario/assets:mario-data"
    ],
)

MAINTAINER = "Trevor Hickey <TrevorJamesHickey@gmail.com>"
DEFAULT_VERSION = "1.0"
DEFAULT_HOMEPAGE = "none"

pkg_deb(
    name = "mario-debian-amd64",
    data = ":mario_all_deb_data",
    package = "mario",
    architecture = "amd64",
    maintainer = MAINTAINER,
    version = DEFAULT_VERSION,
    description = "mario on your desktop",
    homepage = DEFAULT_HOMEPAGE,
    depends = [],
)