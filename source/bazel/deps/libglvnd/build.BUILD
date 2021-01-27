package(default_visibility = ["//visibility:public"])

#llibglvnd is a vendor-neutral dispatch layer for arbitrating OpenGL API calls between multiple vendors.
#I've tried to build the components in terms of their folder layout- but its unclear to me if that is correct.
#the readme file provides much more information on the components.

######################################################################################################################################
egl_hdrs = glob(
    include = [
        "include/*.h",
        "include/EGL/**/*.h",
        "include/glvnd/**/*.h",
        "include/KHR/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

egl_srcs = glob(
    include = [
        "src/EGL/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "egl",
    srcs = egl_srcs,
    hdrs = egl_hdrs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\"",
        "-DUSE_X86_64_ASM",
        #"-Iinclude"
    ],
    includes = [
        "include",
        "include/GLdispatch",
        "include/glvnd",
        "src/GLdispatch",
        "src/util",
        "src/util/uthash/src",
    ],
    deps = [
        "@mesa//:mesa_hdrs",
        "@x11",
    ],
)
######################################################################################################################################

gl_hdrs = glob(
    include = [
        "include/*.h",
        "include/GL/**/*.h",
        "include/glvnd/**/*.h",
        "include/KHR/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

gl_srcs = glob(
    include = [
        "src/GL/**/*.c",
    ],
    exclude = [
        "src/GL/g_libglglxwrapper.c",
    ],
)

cc_library(
    name = "gl",
    srcs = gl_srcs,
    hdrs = gl_hdrs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\"",
        #"-Iinclude"
    ],
    includes = [
        "include",
        "include/GLdispatch",
        "include/glvnd",
        "src/GLX",
        "src/GLdispatch",
        "src/GLdispatch/vnd-glapi",
        "src/util",
        "src/util/uthash/src",
    ],
    deps = [
        "@mesa//:mesa_hdrs",
        "@x11",
    ],
)
######################################################################################################################################

gles_hdrs = glob(
    include = [
        "include/*.h",
        "include/GLES/**/*.h",
        "include/GLES2/**/*.h",
        "include/GLES3/**/*.h",
        "include/glvnd/**/*.h",
        "include/KHR/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

gles_srcs = glob(
    include = [
        #nothing here?
        "src/GLESv1/**/*.c",
        "src/GLESv2/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "gles",
    srcs = gles_srcs,
    hdrs = gles_hdrs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\"",
        #"-Iinclude"
    ],
    includes = [
        "include",
        "include/GLdispatch",
        "include/glvnd",
        "src/GLX",
        "src/GLdispatch",
        "src/GLdispatch/vnd-glapi",
        "src/util",
        "src/util/uthash/src",
    ],
    deps = [
        "@mesa//:mesa_hdrs",
        "@x11",
    ],
)
######################################################################################################################################

glx_hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

glx_srcs = glob(
    include = [
        "src/GLX/**/*.c",
    ],
    exclude = [
        "src/GLX/libglx.c",
    ],
)

cc_library(
    name = "glx",
    srcs = glx_srcs,
    hdrs = glx_hdrs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\"",
        "-DUSE_X86_64_ASM",
        #"-Iinclude"
    ],
    includes = [
        "include",
        "include/GLdispatch",
        "include/glvnd",
        "src/GLX",
        "src/GLdispatch",
        "src/GLdispatch/vnd-glapi",
        "src/util",
        "src/util/uthash/src",
    ],
    deps = [
        "@mesa//:mesa_hdrs",
        "@x11",
        "@xorg_glproto",
    ],
)
######################################################################################################################################

opengl_hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

opengl_srcs = glob(
    include = [
        "src/OpenGL/**/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "opengl",
    srcs = opengl_srcs,
    hdrs = opengl_hdrs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\"",
        "-DUSE_X86_64_ASM",
        #"-Iinclude"
    ],
    includes = [
        "include",
        "include/GLdispatch",
        "include/glvnd",
        "src/GLX",
        "src/GLdispatch",
        "src/GLdispatch/vnd-glapi",
        "src/util",
        "src/util/uthash/src",
    ],
    deps = [
        "@mesa//:mesa_hdrs",
        "@x11",
        "@xorg_glproto",
    ],
)
######################################################################################################################################

util_hdrs = glob(
    include = [
        "include/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

util_srcs = glob(
    include = [
        "src/util/*.c",
    ],
    exclude = [
    ],
)

cc_library(
    name = "util",
    srcs = util_srcs,
    hdrs = util_hdrs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\"",
        "-DUSE_X86_64_ASM",
        #"-Iinclude"
    ],
    includes = [
        "include",
        "include/GLdispatch",
        "include/glvnd",
        "src/EGL",
        "src/GLX",
        "src/GLdispatch",
        "src/GLdispatch/vnd-glapi",
        "src/util",
        "src/util/uthash/src",
    ],
    deps = [
        "@mesa//:mesa_hdrs",
        "@x11",
        "@xorg_glproto",
    ],
)
######################################################################################################################################

#everything as a single library if that is possible
cc_library(
    name = "libglvnd",
    deps = [
        ":egl",
        ":gl",
        ":gles",
        ":glx",
        ":opengl",
        ":util",
    ],
)
