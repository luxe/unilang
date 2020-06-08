package(default_visibility = ["//visibility:public"])

hdrs = glob(
    include = [
        "include/**/*.h",
        "build/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

cc_library(
    name = "mesa_hdrs",
    hdrs = hdrs,
    copts = [
        "-DHAVE_PTHREAD",
        "-DHAVE_TIMESPEC_GET",
        "-DHAVE_ENDIAN_H",
        "-DPACKAGE_BUGREPORT=\\\"https://gitlab.freedesktop.org/mesa/mesa/-/issues\\\"",
        "-DPACKAGE_VERSION=\\\"20.2.0-devel\\\"",
        "-DUSE_SSE41",
        "-D_EGL_NATIVE_PLATFORM=_EGL_PLATFORM_X11",
        "-DDEFAULT_DRIVER_DIR=\\\"/usr/local/lib/x86_64-linux-gnu/dri\\\"",
        "-DMAPI_ABI_HEADER=\\\"mapi/shared-glapi/glapi_mapi_tmp.h\\\"",
        "-DMAPI_TABLE_NUM_STATIC=1611",
        "-DMAPI_TABLE_NUM_DYNAMIC=256",
        "-DMAPI_TMP_DEFINES",
        "-DMAPI_TMP_PUBLIC_ENTRIES_NO_HIDDEN",
    ],
    includes = [
        "build/src",
        "build/src/compiler/nir",
        "build/src/mapi/glapi/gen",
        "build/src/mapi/shared-glapi",
        "build/src/mesa",
        "build/src/mesa/main",
        "include",
        "include/GL",
        "mesa/include/drm-uapi",
        "mesa/src/mapi/glapi",
        "src",
        "src/egl/main",
        "src/gallium/auxiliary",
        "src/gallium/auxiliary/util",
        "src/gallium/include",
        "src/glx",
        "src/loader",
        "src/mapi",
        "src/mapi/glapi",
        "src/mapi/shared-glapi",
        "src/mesa",
        "src/mesa/main",
        "src/util",
    ],
    deps = [
        "@mesa_glu",
        "@x11",
        "@xcb",
        "@xorg_xorgproto",
    ],
)

srcs = glob(
    include = [
        "src/mesa/main/**/*.c",
        "src/mesa/math/**/*.c",
        "src/mesa/x86-64/**/*.c",
        "src/glx/*.c",
        #"src/glx/apple/*.c",
        "src/util/*.c",
        "src/mapi/glapi/gen/*.c",
        "src/mapi/*.c",
        "build/src/mapi/glapi/*.c",
        "build/src/mapi/glapi/gen/*.c",
        #"src/mesa/drivers/x11/*.c",
        "src/egl/main/*.c",
        #"src/egl/main/eglapi.c",
        #"src/egl/main/eglcurrent.c",
        #"src/egl/main/eglglobals.c",
        #"src/egl/drivers/dri2/egl_dri2.c",
        "src/loader/*.c",
        #"src/mapi/mapi_glapi.c",
        "src/egl/drivers/dri2/platform_device.c",
        "src/egl/main/egldriver.c",
        "src/egl/drivers/dri2/egl_dri2.c",
        #"src/mapi/glapi/glapi_getproc.c",
        "src/mapi/mapi_glapi.c",
        "src/mapi/glapi/glapi.c",
        "build/src/mapi/glapi/gen/api_exec.c",
        "build/src/mapi/glapi/gen/indirect_init.c",
        "src/mesa/main/get.c",
        "src/mesa/main/viewport.c",
        "src/mesa/drivers/x11/xm_dd.c",
        "src/mesa/drivers/x11/xm_api.c",
    ],
    exclude = [
        "src/mesa/main/objectlabel.c",

        #that is compiled without support for 'sse4.1'
        "src/mesa/main/streaming-load-memcpy.c",
        "src/mesa/main/sse_minmax.c",
        "src/mesa/main/sse_minmax.c",
        "src/glx/driwindows_glx.c",
        "src/glx/g_glxglvnddispatchfuncs.c",
        #"src/glx/glxext.c",
        #"src/glx/glxglvnd.c",
        "mesa/src/glx/glxglvnd.c",
        "src/egl/main/eglglvnd.c",
        "src/glx/glxglvnd.c",
        "src/egl/main/egldispatchstubs.c",
        "src/glx/glxext.c",

        #"os/os_thread.h"
        "src/util/u_debug_memory.c",
        "src/loader/loader_dri3_helper.c",
    ],
)

cc_library(
    name = "mesa",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
        "-DHAVE_PTHREAD",
        "-DHAVE_TIMESPEC_GET",
        "-DHAVE_ENDIAN_H",
        "-DPACKAGE_BUGREPORT=\\\"https://gitlab.freedesktop.org/mesa/mesa/-/issues\\\"",
        "-DPACKAGE_VERSION=\\\"20.2.0-devel\\\"",
        "-DUSE_SSE41",
        "-D_EGL_NATIVE_PLATFORM=_EGL_PLATFORM_X11",
        "-DDEFAULT_DRIVER_DIR=\\\"/usr/local/lib/x86_64-linux-gnu/dri\\\"",
        "-DMAPI_ABI_HEADER=\\\"mapi/shared-glapi/glapi_mapi_tmp.h\\\"",
        "-DMAPI_TABLE_NUM_STATIC=1611",
        "-DMAPI_TABLE_NUM_DYNAMIC=256",
        "-DMAPI_TMP_DEFINES",
        "-DMAPI_TMP_PUBLIC_ENTRIES_NO_HIDDEN",

        # "-DENABLE_SHADER_CACHE",
        # "-DENABLE_ST_OMX_BELLAGIO=0",
        # "-DENABLE_ST_OMX_TIZONIA=0",
        # "-D_FILE_OFFSET_BITS=64",
        # "-DGLX_DIRECT_RENDERING",
        # "-DGLX_INDIRECT_RENDERING",
        # "-DGLX_USE_DRM",
    ],
    includes = [
        "build/src",
        "build/src/compiler/nir",
        "build/src/mapi/glapi/gen",
        "build/src/mapi/shared-glapi",
        "build/src/mesa",
        "build/src/mesa/main",
        "include",
        "include/GL",
        "mesa/include/drm-uapi",
        "mesa/src/mapi/glapi",
        "src",
        "src/egl/main",
        "src/gallium/auxiliary",
        "src/gallium/auxiliary/util",
        "src/gallium/include",
        "src/glx",
        "src/loader",
        "src/mapi",
        "src/mapi/glapi",
        "src/mapi/shared-glapi",
        "src/mesa",
        "src/mesa/main",
        "src/util",
    ],
    deps = [
        "@mesa_glu",
        "@x11",
        "@xcb",
        "@xorg_xorgproto",
    ],
)

# Dumped from meson build
# -DARCHS=i386-linux-gnu;x86_64-linux-gnu
# -DCOMPS=
# -DENABLE_SHADER_CACHE
# -DENABLE_ST_OMX_BELLAGIO=0
# -DENABLE_ST_OMX_TIZONIA=0
# -D_FILE_OFFSET_BITS=64
# -DGLX_DIRECT_RENDERING
# -DGLX_INDIRECT_RENDERING
# -DGLX_USE_DRM
# -D_GNU_SOURCE
# -DHAVE___BUILTIN_BSWAP32
# -DHAVE___BUILTIN_BSWAP64
# -DHAVE___BUILTIN_CLZ
# -DHAVE___BUILTIN_CLZLL
# -DHAVE___BUILTIN_CTZ
# -DHAVE___BUILTIN_EXPECT
# -DHAVE___BUILTIN_FFS
# -DHAVE___BUILTIN_FFSLL
# -DHAVE___BUILTIN_POPCOUNT
# -DHAVE___BUILTIN_POPCOUNTLL
# -DHAVE___BUILTIN_UNREACHABLE
# -DHAVE_CET_H
# -DHAVE_DIRENT_D_TYPE
# -DHAVE_DLFCN_H
# -DHAVE_DRM_PLATFORM
# -DHAVE_ENDIAN_H
# -DHAVE_EXECINFO_H
# -DHAVE_FLOCK
# -DHAVE_FUNC_ATTRIBUTE_ALIAS
# -DHAVE_FUNC_ATTRIBUTE_CONST
# -DHAVE_FUNC_ATTRIBUTE_FLATTEN
# -DHAVE_FUNC_ATTRIBUTE_FORMAT
# -DHAVE_FUNC_ATTRIBUTE_MALLOC
# -DHAVE_FUNC_ATTRIBUTE_NORETURN
# -DHAVE_FUNC_ATTRIBUTE_PACKED
# -DHAVE_FUNC_ATTRIBUTE_PURE
# -DHAVE_FUNC_ATTRIBUTE_RETURNS_NONNULL
# -DHAVE_FUNC_ATTRIBUTE_UNUSED
# -DHAVE_FUNC_ATTRIBUTE_VISIBILITY
# -DHAVE_FUNC_ATTRIBUTE_WARN_UNUSED_RESULT
# -DHAVE_FUNC_ATTRIBUTE_WEAK
# -DHAVE_GETRANDOM
# -DHAVE_LINUX_FUTEX_H
# -DHAVE_MEMFD_CREATE
# -DHAVE_MKOSTEMP
# -DHAVE_POSIX_MEMALIGN
# -DHAVE_PROGRAM_INVOCATION_NAME
# -DHAVE_RANDOM_R
# -DHAVE_STRTOF
# -DHAVE_STRTOK_R
# -DHAVE_SURFACELESS_PLATFORM
# -DHAVE_SYS_SHM_H
# -DHAVE_SYS_SYSCTL_H
# -DHAVE_TIMESPEC_GET
# -DHAVE_UINT128
# -DHAVE_X11_PLATFORM
# -DLLVM_MESON_MODULES=bitwriter;engine;mcdisassembler;mcjit;core;executionengine;scalaropts;transformutils;instcombine;amdgpu;native;bitreader;ipo;asmparser;coroutines
# -DMAJOR_IN_SYSMACROS
# -DNAME=LLVM
# -DNDEBUG
# -D__STDC_CONSTANT_MACROS
# -D__STDC_FORMAT_MACROS
# -D__STDC_LIMIT_MACROS
# -DUSE_ELF_TLS
# -DUSE_GCC_ATOMIC_BUILTINS
# -DUSE_X86_64_ASM
