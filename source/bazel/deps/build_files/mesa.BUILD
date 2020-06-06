

hdrs = glob(
    include = [
        "include/**/*.h",
        "build/**/*.h",
        "src/**/*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "src/mesa/main/**/*.c",
        "src/mesa/math/**/*.c",
        "src/mesa/x86-64/**/*.c",
    ],
    exclude = [
        "mesa/src/mesa/drivers/dri/nouveau/nouveau_scratch.c",
        "mesa/src/mesa/drivers/common/meta_blit.c",
        "mesa/src/mesa/drivers/common/driverfuncs.c",
        "mesa/src/mesa/drivers/dri/common/megadriver_stub.c",
        "mesa/src/mesa/drivers/common/meta_generate_mipmap.c",
        "mesa/src/mesa/drivers/dri/i915/i915_vtbl.c",
        "mesa/src/mesa/drivers/common/meta_blit.c",
        "mesa/src/mesa/drivers/dri/common/megadriver_stub.c",
        "mesa/src/mesa/drivers/common/meta_generate_mipmap.c",
        "mesa/src/mesa/drivers/dri/nouveau/nouveau_scratch.c",
        "mesa/src/mesa/main/objectlabel.c",
        "mesa/src/mesa/drivers/dri/common/megadriver_stub.c",
        "mesa/src/mesa/main/streaming-load-memcpy.c",
    ],
)

cc_library(
    name = "mesa",
    hdrs = hdrs,
    srcs = srcs,
    copts = ["-DHAVE_PTHREAD",
    "-DHAVE_TIMESPEC_GET",
    "-DHAVE_ENDIAN_H",],
    includes = [
        "include",
        "src",
        "src/mesa",
        "src/mapi",
        "mesa/include/drm-uapi",
        "build/src/mesa",
        "src/gallium/include",
        "src/mesa/main",
        "build/src",
        "build/src/mesa/main",
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
# -DPACKAGE_BUGREPORT="https://gitlab.freedesktop.org/mesa/mesa/-/issues"
# -DPACKAGE_VERSION="20.2.0-devel"
# -D__STDC_CONSTANT_MACROS
# -D__STDC_FORMAT_MACROS
# -D__STDC_LIMIT_MACROS
# -DUSE_ELF_TLS
# -DUSE_GCC_ATOMIC_BUILTINS
# -DUSE_SSE41
# -DUSE_X86_64_ASM