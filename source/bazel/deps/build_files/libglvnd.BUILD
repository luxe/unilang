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
    hdrs = egl_hdrs,
    srcs = egl_srcs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\""
    ],
    includes = [
        "include",
        "src/util",
        "src/GLdispatch",
        "include/glvnd",
        "include/GLdispatch",
        "src/util/uthash/src",
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
    ],
)

cc_library(
    name = "gl",
    hdrs = gl_hdrs,
    srcs = gl_srcs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\""
    ],
    includes = [
        "include",
        "src/util",
        "src/GLdispatch",
        "src/GLX",
        "src/GLdispatch/vnd-glapi",
        "include/glvnd",
        "include/GLdispatch",
        "src/util/uthash/src",
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
    hdrs = gles_hdrs,
    srcs = gles_srcs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\""
    ],
    includes = [
        "include",
        "src/util",
        "src/GLdispatch",
        "src/GLX",
        "src/GLdispatch/vnd-glapi",
        "include/glvnd",
        "include/GLdispatch",
        "src/util/uthash/src",
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
    ],
)

cc_library(
    name = "glx",
    hdrs = glx_hdrs,
    srcs = glx_srcs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\"",
        "-DUSE_X86_64_ASM",
    ],
    includes = [
        "include",
        "src/util",
        "src/GLdispatch",
        "src/GLX",
        "src/GLdispatch/vnd-glapi",
        "include/glvnd",
        "include/GLdispatch",
        "src/util/uthash/src",
    ],
    deps = [
        "@xorg_glproto",
    ]
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
    hdrs = opengl_hdrs,
    srcs = opengl_srcs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\"",
        "-DUSE_X86_64_ASM",
    ],
    includes = [
        "include",
        "src/util",
        "src/GLdispatch",
        "src/GLX",
        "src/GLdispatch/vnd-glapi",
        "include/glvnd",
        "include/GLdispatch",
        "src/util/uthash/src",
    ],
    deps = [
        "@xorg_glproto",
    ]
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
    hdrs = util_hdrs,
    srcs = util_srcs,
    copts = [
        "-include config.h",
        "-DDEFAULT_EGL_VENDOR_CONFIG_DIRS=\\\"/usr/local/etc/glvnd/egl_vendor.d:/usr/local/share/glvnd/egl_vendor.d\\\"",
        "-DUSE_X86_64_ASM",
    ],
    includes = [
        "include",
        "src/util",
        "src/GLdispatch",
        "src/GLX",
        "src/GLdispatch/vnd-glapi",
        "include/glvnd",
        "include/GLdispatch",
        "src/util/uthash/src",
    ],
    deps = [
        "@xorg_glproto",
    ]
)
######################################################################################################################################

#everything as a single library if that is possible
cc_library(
    name = "libglvnd",
    deps  = [
        ":egl",
        ":gl",
        ":gles",
        ":glx",
        ":opengl",
        ":util",
    ]
)




