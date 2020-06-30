package(default_visibility = ["//visibility:public"])

################################
# these are headers and source files
# that are generated when doing the traditional autotools build
# we bring them all in with a giant patch
# and compile them to a single library

#glob the files we care about
sdl_gen_hdrs = glob(
    include = [
        "gen/**/*.h",
    ],
    exclude = [
    ],
)

sdl_gen_srcs = glob(
    include = [
        "gen/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "SDL2_gen_files",
    srcs = sdl_gen_srcs,
    hdrs = sdl_gen_hdrs,
    includes = [
        "gen",
        "include",
        "src",
        "src/events",
    ],
    deps = [
        "@debian_stretch_amd64_sysroot//:wayland_util",
    ]
)

################################
#all of the SDL2 headers as a single library

#glob the files we care about
sdl_hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "SDL2_hdrs",
    hdrs = sdl_hdrs,
    includes = [
        "include",
        "src",
        "src/events",
    ],
    deps = [
        "@debian_stretch_amd64_sysroot//:wayland_util",
        "@debian_stretch_amd64_sysroot//:wayland_cursor",
        "@debian_stretch_amd64_sysroot//:wayland_client_core",
        "@debian_stretch_amd64_sysroot//:wayland_client",
        "@debian_stretch_amd64_sysroot//:wayland_version",
        "@debian_stretch_amd64_sysroot//:wayland_egl",
        "@debian_stretch_amd64_sysroot//:alsa",
        "@debian_stretch_amd64_sysroot//:pulse_audio",
    ]
)
################################
# finish the SDL library by building all the sources and linking
# with all the headers and required dependencies

#glob the files we care about
sdl_srcs = glob(
    include = [
        "src/**/*.c",
        "src/**/*.h",
    ],
    exclude = [
        "src/haptic/windows/**",
        #"src/test/*.c",
        "src/locale/emscripten/**",
        "src/locale/windows/**",
        "src/locale/winrt/**",
        "src/locale/android/**",
        "src/locale/macosx/**",
        "src/locale/haiku/**",
        "src/locale/unix/**",
        #"src/core/linux/SDL_dbus.c",
        #"src/core/linux/SDL_fcitx.c",
        #"src/locale/**",
        "src/joystick/windows/**",
        "src/src/filesystem/windows/**",
        #"src/src/video/windows/**",
        "src/thread/generic/SDL_syscond.c",
        "src/thread/generic/SDL_sysmutex.c",
        "src/thread/generic/SDL_syssem.c",
        "src/thread/generic/SDL_systhread.c",
        "src/thread/generic/SDL_systls.c",
        "src/main/**",
        "src/thread/generic/**",
        "src/thread/windows/**",
        "src/thread/psp/**",
        # haptic/windows/

        #needs ibus and glib system headers
        #"src/core/linux/SDL_ibus.c",
        #"src/core/linux/SDL_ime.c",

        #"src/video/wayland/SDL_waylanddatamanager.c",
        #"src/video/wayland/SDL_waylandmouse.c",
        #"src/video/wayland/SDL_waylandvulkan.c",
        #"src/video/wayland/SDL_waylandclipboard.c",
        #"src/video/wayland/SDL_waylandevents.c",
        #"src/video/wayland/SDL_waylandvideo.c",
        #"src/video/wayland/SDL_waylanddyn.c",
        #"src/video/wayland/SDL_waylandopengles.c",
        #"src/video/wayland/SDL_waylandtouch.c",
        #"src/video/wayland/SDL_waylandwindow.c",

        #"src/video/x11/SDL_x11dyn.c",

        #QNX Blackberry Operating System
        "src/video/qnx/**/*.c",
    ],
)

cc_library(
    name = "sdl2",
    srcs = sdl_srcs,
    copts = [
        "-DHAVE_CONFIG_H",
        "-DUSING_GENERATED_CONFIG_H",
        "-DHAVE_PTHREAD_SETNAME_NP",
    ],
    #linkopts = ["-lpthread"],
    includes = [
        ".",
        "include",
        "src",
        "src/events",
        "gen",
        #"/usr/include",
        #"/usr/include/glib-2.0",
        "src/video/wayland",
        "src/video/x11",
    ],
    deps = [
        ":SDL2_gen_files",
        ":SDL2_hdrs",
        "@dbus",
        "@glib",
        "@ibus",
        "@libXxf86vm",
        "@libevent",
        "@libevent//:sys_event",
        "@mesa",
        "@sndio",
        "@x11",
        "@xcb",
        "@xorg_xorgproto",
        "@systemd//:libudev",
        "@debian_stretch_amd64_sysroot//:wayland_util",
        "@debian_stretch_amd64_sysroot//:wayland_cursor",
        "@debian_stretch_amd64_sysroot//:wayland_client_core",
        "@debian_stretch_amd64_sysroot//:wayland_client",
        "@debian_stretch_amd64_sysroot//:wayland_version",
        "@debian_stretch_amd64_sysroot//:wayland_egl",
        "@debian_stretch_amd64_sysroot//:alsa",
        "@debian_stretch_amd64_sysroot//:pulse_audio",
    ],
)
