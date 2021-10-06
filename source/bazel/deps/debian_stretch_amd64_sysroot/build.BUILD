package(default_visibility = ["//visibility:public"])

filegroup(
    name = "sysroot",
    srcs = glob(["*/**"]),
)

# various shard objects
cc_import(
    name = "GL",
    shared_library = "usr/lib/x86_64-linux-gnu/libGL.so",
)

cc_import(
    name = "udev",
    shared_library = "lib/x86_64-linux-gnu/libudev.so",
)

# various headers

#wayland
cc_library(
    name = "wayland_util",
    hdrs = ["usr/include/wayland-util.h"],
    includes = ["usr/include"],
)

cc_library(
    name = "wayland_cursor",
    hdrs = ["usr/include/wayland-cursor.h"],
    includes = ["usr/include"],
)

cc_library(
    name = "wayland_client_core",
    hdrs = ["usr/include/wayland-client-core.h"],
    includes = ["usr/include"],
)

cc_library(
    name = "wayland_client",
    hdrs = ["usr/include/wayland-client.h"],
    includes = ["usr/include"],
)

cc_library(
    name = "wayland_version",
    hdrs = ["usr/include/wayland-version.h"],
    includes = ["usr/include"],
)

cc_library(
    name = "wayland_egl",
    hdrs = [
        "usr/include/wayland-egl.h",
        "usr/include/wayland-egl-core.h",
    ],
    includes = ["usr/include"],
)

#sound
cc_library(
    name = "alsa",
    hdrs = glob(["usr/include/alsa/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "pulse_audio",
    hdrs = glob(["usr/include/pulse/**/*.h"]),
    includes = ["usr/include"],
)

#other
cc_library(
    name = "sys_hdrs",
    hdrs = glob(["usr/include/sys/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "linux_hdrs",
    hdrs = glob(["usr/include/linux/**/*.h"]),
    includes = ["usr/include"],
)

cc_library(
    name = "xf86drm",
    hdrs = [
        "usr/include/xf86drm.h",
        "usr/include/xf86drmMode.h",
    ],
    includes = ["usr/include"],
)

cc_library(
    name = "udev_hdrs",
    hdrs = ["usr/include/libudev.h"],
    includes = ["usr/include"],
)

cc_library(
    name = "ffi",
    hdrs = [
        "usr/include/x86_64-linux-gnu/ffi.h",
        "usr/include/x86_64-linux-gnu/ffitarget.h",
    ],
    includes = ["usr/include/x86_64-linux-gnu"],
)

cc_library(
    name = "vm_sockets",
    hdrs = ["usr/include/linux/vm_sockets.h"],
    includes = ["usr/include"],
)

cc_library(
    name = "security",
    hdrs = glob(["usr/include/security/**/*.h"]),
    includes = ["usr/include"],
)
