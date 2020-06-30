package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "src/**/*.h",
        "build/**/*.h",
    ],
    exclude = [
    ],
)

libudev_srcs = glob(
    include = [
        "src/libudev/**/*.c",

        #other files needed
        "src/basic/log.c",
        "src/libsystemd/sd-device/*.c",
        "src/libsystemd/sd-event/*.c",
        "src/libsystemd/sd-daemon/*.c",
        "src/libsystemd/sd-id128/*.c",
        "src/basic/*.c",
        "src/shared/*.c",
    ],
    exclude = [
        "src/libsystemd/sd-device/test-sd-device.c",
        "src/libsystemd/sd-device/test-sd-device-monitor.c",
        "src/basic/af-list.c",
        "src/basic/efivars.c",
        #"src/basic/random-util.c",
        #"src/basic/proc-cmdline.c",
        #"src/basic/xattr-util.c",
        "src/shared/acl-util.c",
        "src/shared/seccomp-util.c",
        "src/shared/mount-util.c",
        "src/shared/firewall-util.c",
        "src/shared/module-util.c",
        "src/basic/blockdev-util.c",
        "src/basic/mempool.c",
        "src/shared/vlan-util.c",
        "src/shared/id128-print.c",
        "src/basic/unit-name.c",
        "src/shared/apparmor-util.c",
        "src/basic/in-addr-util.c",
        "src/basic/alloc-util.c",
        "src/libudev/libudev-enumerate.c",
        "src/shared/xml.c",
        "src/basic/utf8.c",

        #"src/libsystemd/sd-daemon/sd-daemon.c,
    ],
)

cc_library(
    name = "libudev",
    srcs = libudev_srcs,
    hdrs = hdrs,
    copts = [
        "-include build/config.h",
    ],
    includes = [
        "build",
        "build/src/basic",
        "build/src/shared",
        "src/basic",
        "src/boot/",
        "src/journal",
        "src/libsystemd",
        "src/libsystemd/sd-bus",
        "src/libsystemd/sd-device",
        "src/libsystemd/sd-hwdb",
        "src/libsystemd/sd-id128",
        "src/libsystemd/sd-netlink",
        "src/libudev",
        "src/shared/",
        "src/systemd",
    ],
    linkopts = [
        #"-lrt",
    ],
    deps = [
        "@debian_stretch_amd64_sysroot//:security",
        "@debian_stretch_amd64_sysroot//:vm_sockets",
        "@openssl//:ssl",
    ],
)
