licenses(["notice"])  # MIT-style

cc_library(
    name = "expat",
    srcs = [
        "expat/lib/xmlparse.c",
        "expat/lib/xmlrole.c",
        "expat/lib/xmltok.c",
    ],
    hdrs = [
        "expat/expat_config.h",
        "expat/lib/ascii.h",
        "expat/lib/asciitab.h",
        "expat/lib/expat.h",
        "expat/lib/expat_external.h",
        "expat/lib/iasciitab.h",
        "expat/lib/internal.h",
        "expat/lib/latin1tab.h",
        "expat/lib/nametab.h",
        "expat/lib/siphash.h",
        "expat/lib/utf8tab.h",
        "expat/lib/xmlrole.h",
        "expat/lib/xmltok.h",
        "expat/lib/xmltok_impl.c",
        "expat/lib/xmltok_impl.h",
        "expat/lib/xmltok_ns.c",
    ],
    copts = [
        "-DHAVE_EXPAT_CONFIG_H",
        "-DXML_DEV_URANDOM",
    ],
    defines = ["XML_STATIC"],
    includes = [
        ".",
        "lib",
        "expat",
    ],
    visibility = ["//visibility:public"],
)
