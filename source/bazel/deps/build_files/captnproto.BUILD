package(default_visibility = ["//visibility:public"])


cc_library(
    name = "kj_headers",
    hdrs = [
        "c++/src/kj/common.h",
        "c++/src/kj/units.h",
        "c++/src/kj/memory.h",
        "c++/src/kj/refcount.h",
        "c++/src/kj/array.h",
        "c++/src/kj/vector.h",
        "c++/src/kj/string.h",
        "c++/src/kj/string-tree.h",
        "c++/src/kj/hash.h",
        "c++/src/kj/table.h",
        "c++/src/kj/map.h",
        "c++/src/kj/encoding.h",
        "c++/src/kj/exception.h",
        "c++/src/kj/debug.h",
        "c++/src/kj/arena.h",
        "c++/src/kj/io.h",
        "c++/src/kj/tuple.h",
        "c++/src/kj/one-of.h",
        "c++/src/kj/function.h",
        "c++/src/kj/mutex.h",
        "c++/src/kj/thread.h",
        "c++/src/kj/threadlocal.h",
        "c++/src/kj/filesystem.h",
        "c++/src/kj/time.h",
        "c++/src/kj/main.h",
        "c++/src/kj/windows-sanity.h",
        "c++/src/kj/miniposix.h",
        "c++/src/kj/test.h",
        
    ]
)

cc_library(
    name = "kj_parse_headers",
    hdrs = [
        "c++/src/kj/parse/common.h",
        "c++/src/kj/parse/char.h",
    ]
)

cc_library(
    name = "kj_std_headers",
    hdrs = [
        "c++/src/kj/std/iostream.h",
    ]
)


cc_library(
    name = "kj_sources_lite",
    srcs = [
        "c++/src/kj/array.c++",
        "c++/src/kj/common.c++",
        "c++/src/kj/debug.c++",
        "c++/src/kj/exception.c++",
        "c++/src/kj/io.c++",
        "c++/src/kj/memory.c++",
        "c++/src/kj/mutex.c++",
        "c++/src/kj/string.c++",
        "c++/src/kj/hash.c++",
        "c++/src/kj/table.c++",
        "c++/src/kj/thread.c++",
        "c++/src/kj/main.c++",
        "c++/src/kj/arena.c++",
        "c++/src/kj/test-helpers.c++",
        "c++/src/kj/units.c++",
        "c++/src/kj/encoding.c++"
    ],
    deps = [":kj_headers"],
    includes = ["."],
)

cc_library(
    name = "kj_sources_heavy",
    srcs = [
      "c++/src/kj/refcount.c++",
      "c++/src/kj/string-tree.c++",
      "c++/src/kj/time.c++",
      "c++/src/kj/filesystem.c++",
      "c++/src/kj/filesystem-disk-unix.c++",
      "c++/src/kj/filesystem-disk-win32.c++",
      "c++/src/kj/parse/char.c++",
    ],
    deps = [":kj_headers",":kj_parse_headers"],
    includes = ["."],
) 


