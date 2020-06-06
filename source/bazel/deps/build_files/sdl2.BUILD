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
)

################################
#all of the SDL2 headers as a single library

#glob the files we care about
sdl_hdrs = glob(
    include = [
        "include/**/*.h",
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
        "src/video/qnx/**",
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
        #"src/thread/generic/**",
        "src/thread/windows/**",
        "src/thread/psp/**",
        # haptic/windows/
        #"src/dynapi/SDL_dynapi_overrides.h",

        #needs ibus and glib system headers
        #"src/core/linux/SDL_ibus.c",
        #"src/core/linux/SDL_ime.c",
    ],
)

cc_library(
    name = "sdl2",
    srcs = sdl_srcs,
    copts = [
        "-DHAVE_CONFIG_H",
    ],
    includes = [
        ".",
        "include",
        "src",
        "src/events",
        "gen",
        #"/usr/include",
        #"/usr/include/glib-2.0",
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
        "@x11",
        "@xorg_xorgproto",
        "@sndio",
    ],
)
