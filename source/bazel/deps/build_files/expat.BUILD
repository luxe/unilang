licenses(["notice"])  # MIT-style

load("@//bazel/cookbook/system:mv_file.bzl", "mv_file")

mv_file("xmlparse_c", "expat/lib/xmlparse.c", "xmlparse.c")

mv_file("xmlrole_c", "expat/lib/xmlrole.c", "xmlrole.c")

mv_file("xmltok_c", "expat/lib/xmltok.c", "xmltok.c")

mv_file("ascii_h", "expat/lib/ascii.h", "ascii.h")

mv_file("asciitab_h", "expat/lib/asciitab.h", "asciitab.h")

mv_file("expat_h", "expat/lib/expat.h", "expat.h")

mv_file("expat_external_h", "expat/lib/expat_external.h", "expat_external.h")

mv_file("iasciitab_h", "expat/lib/iasciitab.h", "iasciitab.h")

mv_file("internal_h", "expat/lib/internal.h", "internal.h")

mv_file("latin1tab_h", "expat/lib/latin1tab.h", "latin1tab.h")

mv_file("nametab_h", "expat/lib/nametab.h", "nametab.h")

mv_file("siphash_h", "expat/lib/siphash.h", "siphash.h")

mv_file("utf8tab_h", "expat/lib/utf8tab.h", "utf8tab.h")

mv_file("xmlrole_h", "expat/lib/xmlrole.h", "xmlrole.h")

mv_file("xmltok_h", "expat/lib/xmltok.h", "xmltok.h")

mv_file("xmltok_impl_c", "expat/lib/xmltok_impl.c", "xmltok_impl.c")

mv_file("xmltok_impl_h", "expat/lib/xmltok_impl.h", "xmltok_impl.h")

mv_file("xmltok_ns_c", "expat/lib/xmltok_ns.c", "xmltok_ns.c")

cc_library(
    name = "expat",
    srcs = [
        "xmlparse.c",
        "xmlrole.c",
        "xmltok.c",
    ],
    hdrs = [
        "ascii.h",
        "asciitab.h",
        "expat.h",
        "expat/expat_config.h",
        "expat_external.h",
        "iasciitab.h",
        "internal.h",
        "latin1tab.h",
        "nametab.h",
        "siphash.h",
        "utf8tab.h",
        "xmlrole.h",
        "xmltok.h",
        "xmltok_impl.c",
        "xmltok_impl.h",
        "xmltok_ns.c",
    ],
    copts = [
        "-DHAVE_EXPAT_CONFIG_H",
        "-DXML_DEV_URANDOM",
    ],
    defines = ["XML_STATIC"],
    includes = [
        ".",
        "expat",
        "lib",
    ],
    visibility = ["//visibility:public"],
    deps = [
    ],
)
