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
    name = "kj_async_headers",
    hdrs = [
        "c++/src/kj/async-prelude.h",
        "c++/src/kj/async.h",
        "c++/src/kj/async-inl.h",
        "c++/src/kj/async-unix.h",
        "c++/src/kj/async-win32.h",
        "c++/src/kj/async-io.h",
        "c++/src/kj/timer.h",
        "c++/src/kj/async-io-internal.h",
    ]
)

cc_library(
    name = "kj_async_sources",
    srcs = [
      "c++/src/kj/async.c++",
      "c++/src/kj/async-unix.c++",
      "c++/src/kj/async-win32.c++",
      "c++/src/kj/async-io-win32.c++",
      "c++/src/kj/async-io.c++",
      "c++/src/kj/async-io-unix.c++",
      "c++/src/kj/timer.c++",
    ],
    deps = [":kj_headers",":kj_async_headers"],
    includes = ["."],
)

cc_library(
    name = "kj_test_headers",
    srcs = [
        "c++/src/kj/test.h",
    ],
    includes = ["."],
)

cc_library(
    name = "kj_test_sources",
    srcs = [
        "c++/src/kj/test.c++",
    ],
    deps = [":kj_headers",":kj_test_headers"],
    includes = ["."],
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


cc_library(
    name = "kj_http_headers",
    hdrs = [
        "c++/src/kj/compat/url.h",
        "c++/src/kj/compat/http.h",
    ],
    deps = [":kj_headers"],
    includes = ["."],
)

cc_library(
    name = "kj_http_sources",
    srcs = [
        "c++/src/kj/compat/url.c++",
        "c++/src/kj/compat/http.c++",
    ],
    deps = [":kj_headers",":kj_http_headers",":kj_async_headers",":kj_parse_headers"],
    includes = [".","c++/src/"],
)

cc_library(
    name = "kj_gzip_headers",
    hdrs = [
        "c++/src/kj/compat/gzip.h",
    ],
    deps = [":kj_headers",":kj_http_headers",":kj_async_headers",":kj_parse_headers"],
    includes = [".","c++/src/"],
)

cc_library(
    name = "kj_gzip_sources",
    srcs = [
        "c++/src/kj/compat/gzip.c++",
    ],
    deps = [":kj_headers",":kj_gzip_headers",":kj_async_headers",":kj_parse_headers"],
    includes = [".","c++/src/"],
)

cc_library(
    name = "kj_test_compat_headers",
    hdrs = [
        "c++/src/kj/compat/gtest.h",
    ],
    deps = [":kj_headers"],
    includes = ["."],
)


cc_library(
    name = "kj",
    srcs = [],
    deps = [
        ":kj_headers",
        ":kj_parse_headers",
        ":kj_std_headers",
        ":kj_async_sources",
        ":kj_async_headers",
        ":kj_test_headers",
        ":kj_test_sources",
        ":kj_sources_lite",
        ":kj_sources_heavy",
        ":kj_http_headers",
        ":kj_http_sources",
        ":kj_gzip_headers",
        ":kj_gzip_sources",
        ":kj_test_compat_headers"
    ],
    includes = ["."],
)



cc_binary(
    name = "kj_tests",
    srcs = [
        "c++/src/kj/common-test.c++",
        "c++/src/kj/memory-test.c++",
        "c++/src/kj/array-test.c++",
        "c++/src/kj/string-test.c++",
        "c++/src/kj/table-test.c++",
        "c++/src/kj/map-test.c++",
        "c++/src/kj/exception-test.c++",
        "c++/src/kj/debug-test.c++",
        "c++/src/kj/io-test.c++",
        "c++/src/kj/mutex-test.c++",
        "c++/src/kj/threadlocal-test.c++",
        "c++/src/kj/test-test.c++",
        "c++/src/kj/std/iostream-test.c++",
    ],
    deps = [":kj"],
    includes = ["."],
)


