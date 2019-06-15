licenses(["notice"])  # MIT-style

cc_library(
    name = "expat",
    srcs = [
        "lib/xmlparse.c",
        "lib/xmlrole.c",
        "lib/xmltok.c",
    ],
    hdrs = [
        "expat_config.h",
        "lib/ascii.h",
        "lib/asciitab.h",
        "lib/expat.h",
        "lib/expat_external.h",
        "lib/iasciitab.h",
        "lib/internal.h",
        "lib/latin1tab.h",
        "lib/nametab.h",
        "lib/siphash.h",
        "lib/utf8tab.h",
        "lib/xmlrole.h",
        "lib/xmltok.h",
        "lib/xmltok_impl.c",
        "lib/xmltok_impl.h",
        "lib/xmltok_ns.c",
    ],
    copts = [
        "-DHAVE_EXPAT_CONFIG_H",
        "-DXML_DEV_URANDOM",
    ],
    defines = ["XML_STATIC"],
    includes = [
        ".",
        "lib",
    ],
    visibility = ["//visibility:public"],
)
