package(default_visibility = ["//visibility:public"])

#glob the files we care about
sdl_hdrs = glob(
    include = [
        "include/**/*.h",
    ],
    exclude = [
    ],
)

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
        "src/core/linux/SDL_dbus.c",
        "src/core/linux/SDL_fcitx.c",
        #"src/locale/**",
        "src/joystick/windows/**",
        "src/src/filesystem/windows/**",
        #"src/src/video/windows/**",
        "src/thread/generic/SDL_syscond.c",
        "src/thread/generic/SDL_sysmutex.c",
        "src/thread/generic/SDL_syssem.c",
        "src/thread/generic/SDL_systhread.c",
        "src/thread/generic/SDL_systls.c",
        #"src/thread/generic/**",
        "src/thread/windows/**",
        "src/thread/psp/**",
        # haptic/windows/
        #"src/dynapi/SDL_dynapi_overrides.h",
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
    visibility = ["//visibility:public"],
)

cc_library(
    name = "SDL2",
    srcs = sdl_srcs,
    copts = [
        "-I/usr/include/dbus-1.0/",
        "-I/usr/lib/x86_64-linux-gnu/dbus-1.0/include/",
    ],
    includes = [
        "include",
        "src",
        "src/events",
    ],
    #textual_hdrs = glob(["src/thread/generic/*.c"]),
    deps = [":SDL2_hdrs"],
)
