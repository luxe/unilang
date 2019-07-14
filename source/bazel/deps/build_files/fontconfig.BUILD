# Ref: https://github.com/googlecartographer/cartographer/blob/master/bazel/third_party/fontconfig/fontconfig.BUILD
# Description:
#   Fontconfig is a library for font customization and configuration.

licenses(["notice"])  # BSD-like

# genrule(
#     name = "config_h",
#     srcs = ["@//bazel/deps/build_files/fontconfig:config.h"],
#     outs = ["fontconfig_internal/config.h"],
#     cmd = "cp $< $@",
# )

# genrule(
#     name = "fcstdint_h",
#     srcs = ["@//bazel/deps/build_files/fontconfig:fcstdint.h"],
#     outs = ["fontconfig_internal/fcstdint.h"],
#     cmd = "cp $< $@",
# )

# genrule(
#     name = "fcobjshash_h",
#     srcs = ["@//bazel/deps/build_files/fontconfig:fcobjshash.h"],
#     outs = ["fontconfig_internal/fcobjshash.h"],
#     cmd = "cp $< $@",
# )

genrule(
    name = "fcalias",
    srcs = [
        "fontconfig/fontconfig.h",
        "src/fcdeprecate.h",
        "fontconfig/fcprivate.h",
    ] + glob(["src/*.c"]),
    outs = [
        "src/fcalias.h",
        "src/fcaliastail.h",
    ],
    cmd = """./$(location src/makealias) \
        $$(dirname $(location src/makealias)) \
        $(OUTS) \
        $(location fontconfig/fontconfig.h) \
        $(location src/fcdeprecate.h) \
        $(location fontconfig/fcprivate.h)""",
    tools = ["src/makealias"],
)

genrule(
    name = "fcftalias",
    srcs = ["fontconfig/fcfreetype.h"] + glob(["src/*.c"]),
    outs = [
        "src/fcftalias.h",
        "src/fcftaliastail.h",
    ],
    cmd = """./$(location src/makealias) \
        $$(dirname $(location src/makealias)) \
        $(OUTS) \
        $(location fontconfig/fcfreetype.h)""",
    tools = ["src/makealias"],
)

cc_library(
    name = "fontconfig",
    srcs = [
        #"fc-blanks/fcblanks.h",
        "fc-case/fccase.h",
        #"fc-glyphname/fcglyphname.hfcstdint_h",
        "fc-lang/fclang.h",
        "fontconfig/fcfreetype.h",
        "fontconfig/fcprivate.h",
        "src/fcarch.h",
        "src/fcatomic.c",
        "src/fcatomic.h",
        #"src/fcblanks.c",
        "src/fcstdint.h",
        "src/fccache.c",
        "src/fccfg.c",
        "src/fccharset.c",
        "src/fccompat.c",
        "src/fcdbg.c",
        "src/fcdefault.c",
        "src/fcdeprecate.h",
        "src/fcdir.c",
        "src/fcformat.c",
        "src/fcfreetype.c",
        "src/fcfs.c",
        "src/fcftint.h",
        "src/fcinit.c",
        "src/fcint.h",
        "src/fclang.c",
        "src/fclist.c",
        "src/fcmatch.c",
        "src/fcmatrix.c",
        "src/fcmutex.h",
        "src/fcname.c",
        "src/fcobjs.c",
        "src/fcobjs.h",
        "src/fcobjshash.h",
        "src/fcpat.c",
        "src/fcrange.c",
        "src/fcserialize.c",
        "src/fcstat.c",
        "src/fcstr.c",
        "src/fcweight.c",
        "src/fcxml.c",
        "src/fcptrlist.c",
        "src/ftglue.c",
        "src/ftglue.h",
        "config.h",
        "config-fixups.h",
        #":config_h",
        # ":fcstdint_h",
        # ":fcobjshash_h",
        ":fcalias",
        ":fcftalias",
    ],
    hdrs = ["fontconfig/fontconfig.h"],
    copts = [
        "-Iexternal/fontconfig/src",
        "-I$(GENDIR)/external/fontconfig/src",
        "-I$(GENDIR)/external/fontconfig/fontconfig_internal",
        "-DFC_CACHEDIR='\"/var/cache/fontconfig\"'",
        "-DFONTCONFIG_PATH='\"/etc/fonts\"'",
        "-DFC_TEMPLATEDIR='\"/WHAT_SHOULD_THIS_BE\"'",
        "-DHAVE_CONFIG_H",
        "-Wno-everything",
    ],
    includes = ["."],
    visibility = ["//visibility:public"],
    deps = [
        "@expat//:expat",
        "@freetype2//:freetype2",
        "@zlib//:zlib",
    ],
)
