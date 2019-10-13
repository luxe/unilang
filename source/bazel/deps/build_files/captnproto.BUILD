package(default_visibility = ["//visibility:public"])


#Everything under c++/src/kj
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
      "c++/src/kj/mutex.c++",
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
        "c++/src/kj/memory.c++",
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
        "c++/src/kj/threadlocal-test.c++",
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

cc_binary(
    name = "kj_heavy_tests",
    srcs = [
        "c++/src/kj/async-test.c++",
        "c++/src/kj/async-unix-test.c++",
        "c++/src/kj/async-win32-test.c++",
        "c++/src/kj/async-io-test.c++",
        "c++/src/kj/refcount-test.c++",
        "c++/src/kj/string-tree-test.c++",
        "c++/src/kj/encoding-test.c++",
        "c++/src/kj/arena-test.c++",
        "c++/src/kj/units-test.c++",
        "c++/src/kj/tuple-test.c++",
        "c++/src/kj/one-of-test.c++",
        "c++/src/kj/function-test.c++",
        "c++/src/kj/threadlocal-pthread-test.c++",
        "c++/src/kj/filesystem-test.c++",
        "c++/src/kj/filesystem-disk-test.c++",
        "c++/src/kj/parse/common-test.c++",
        "c++/src/kj/parse/char-test.c++",
        "c++/src/kj/compat/url-test.c++",
        "c++/src/kj/compat/http-test.c++",
        "c++/src/kj/compat/gzip-test.c++",
    ],
    deps = [":kj"],
    includes = [".","c++/src/"],
)

#Everything under c++/src/capnp
cc_library(
    name = "capnp_headers",
    hdrs = [
      "c++/src/capnp/c++.capnp.h",
      "c++/src/capnp/common.h",
      "c++/src/capnp/blob.h",
      "c++/src/capnp/endian.h",
      "c++/src/capnp/layout.h",
      "c++/src/capnp/orphan.h",
      "c++/src/capnp/list.h",
      "c++/src/capnp/any.h",
      "c++/src/capnp/message.h",
      "c++/src/capnp/capability.h",
      "c++/src/capnp/membrane.h",
      "c++/src/capnp/dynamic.h",
      "c++/src/capnp/schema.h",
      "c++/src/capnp/schema.capnp.h",
      "c++/src/capnp/schema-lite.h",
      "c++/src/capnp/schema-loader.h",
      "c++/src/capnp/schema-parser.h",
      "c++/src/capnp/pretty-print.h",
      "c++/src/capnp/serialize.h",
      "c++/src/capnp/serialize-async.h",
      "c++/src/capnp/serialize-packed.h",
      "c++/src/capnp/serialize-text.h",
      "c++/src/capnp/pointer-helpers.h",
      "c++/src/capnp/generated-header-support.h",
      "c++/src/capnp/raw-schema.h",
      "c++/src/capnp/arena.h",
    ]
)

cc_library(
    name = "capnp_sources_lite",
    hdrs = [
        "c++/src/capnp/any.h",
    ],
    srcs = [
      "c++/src/capnp/c++.capnp.c++",
      "c++/src/capnp/blob.c++",
      "c++/src/capnp/arena.c++",
      "c++/src/capnp/layout.c++",
      "c++/src/capnp/list.c++",
      "c++/src/capnp/any.c++",
      "c++/src/capnp/message.c++",
      "c++/src/capnp/schema.capnp.c++",
      "c++/src/capnp/serialize.c++",
      "c++/src/capnp/serialize-packed.c++",
    ],
    deps = [":capnp_headers",":kj"],
    includes = [".", "c++/src/"]
)

cc_library(
    name = "capnp_sources_heavy",
    srcs = [
      "c++/src/capnp/schema.c++",
      "c++/src/capnp/schema-loader.c++",
      "c++/src/capnp/dynamic.c++",
      "c++/src/capnp/stringify.c++",
      "c++/src/capnp/schema.capnp.c++",
    ],
    deps = [":kj",":capnp_headers"],
    includes = [".", "c++/src/"]
)

cc_library(
    name = "capnp_rpc_headers",
    hdrs = [
      "c++/src/capnp/rpc-prelude.h",
      "c++/src/capnp/rpc.h",
      "c++/src/capnp/rpc-twoparty.h",
      "c++/src/capnp/rpc.capnp.h",
      "c++/src/capnp/rpc-twoparty.capnp.h",
      "c++/src/capnp/persistent.capnp.h",
      "c++/src/capnp/ez-rpc.h",
    ]
)

cc_library(
    name = "capnp_rpc_sources",
    srcs = [
      "c++/src/capnp/serialize-async.c++",
      "c++/src/capnp/capability.c++",
      "c++/src/capnp/membrane.c++",
      "c++/src/capnp/dynamic-capability.c++",
      "c++/src/capnp/rpc.c++",
      "c++/src/capnp/rpc.capnp.c++",
      "c++/src/capnp/rpc-twoparty.c++",
      "c++/src/capnp/rpc-twoparty.capnp.c++",
      "c++/src/capnp/persistent.capnp.c++",
      "c++/src/capnp/ez-rpc.c++",
    ],
    deps = [":capnp_headers",":kj",":capnp_rpc_headers"],
    includes = [".", "c++/src/"]
)

cc_library(
    name = "capnp_json_headers",
    hdrs = [
        "c++/src/capnp/compat/json.h",
        "c++/src/capnp/compat/json.capnp.h",
    ]
)

cc_library(
    name = "capnp_json_sources",
    srcs = [
        "c++/src/capnp/compat/json.c++",
        "c++/src/capnp/compat/json.capnp.c++",
    ],
    deps = [":capnp_headers",":kj",":capnp_json_headers"],
    includes = [".", "c++/src/"]
)

cc_library(
    name = "capnc_headers",
    hdrs = [
        "c++/src/capnp/compiler/grammar.capnp.h",
        "c++/src/capnp/compiler/compiler.h", 
        "c++/src/capnp/compiler/node-translator.h", 
        "c++/src/capnp/compiler/parser.h", 
        "c++/src/capnp/compiler/lexer.capnp.h", 
        "c++/src/capnp/compiler/lexer.h", 
        "c++/src/capnp/compiler/type-id.h", 
        "c++/src/capnp/compiler/error-reporter.h",
        "c++/src/capnp/compiler/module-loader.h",
        "c++/src/capnp/any.h",
    ],
    deps = [":capnp_headers",":kj"],
    includes = [".", "c++/src/","c++/src/capnp/compiler"]
)

cc_library(
    name = "capnc_sources",
    srcs = [
        "c++/src/capnp/compiler/type-id.c++",
        "c++/src/capnp/compiler/error-reporter.c++",
        "c++/src/capnp/compiler/lexer.capnp.c++",
        "c++/src/capnp/compiler/lexer.c++",
        "c++/src/capnp/compiler/grammar.capnp.c++",
        "c++/src/capnp/compiler/parser.c++",
        "c++/src/capnp/compiler/node-translator.c++",
        "c++/src/capnp/compiler/compiler.c++",
        "c++/src/capnp/schema-parser.c++",
        "c++/src/capnp/serialize-text.c++",
    ],
    deps = [":capnp_headers",":kj",":capnc_headers"],
    includes = [".", "c++/src/","c++/src/capnp/compiler"]
)

cc_library(
    name = "capnp_generated_header_support",
    hdrs = [
      "c++/src/capnp/generated-header-support.h",
    ]
)



cc_library(
    name = "capnp",
    deps = [
        ":capnp_headers",
        ":capnp_generated_header_support",
        ":capnp_sources_lite",
        ":capnp_sources_heavy",
        ":capnp_rpc_headers",
        ":capnp_rpc_sources",
        ":capnp_json_headers",
        ":capnp_json_sources",
        ":capnc_headers",
        ":capnc_sources",
    ]
)

cc_binary(
    name = "capnp_tool",
    srcs = [
	    "c++/src/capnp/compiler/module-loader.c++",
	    "c++/src/capnp/compiler/capnp.c++",
    ],
    deps = [":capnp"]
)

cc_binary(
    name = "capnpc_cpp",
    srcs = [
    "c++/src/capnp/compiler/capnpc-c++.c++"
    ],
    deps = [":capnp"]
)

cc_binary(
    name = "capnpc_capnp",
    srcs = [
    "c++/src/capnp/compiler/capnpc-capnp.c++"
    ],
    deps = [":capnp"]
)

# Tests require generated code
# This is not relevant to build right now
# cc_library(
#    name = "capnp_test_headers",
#    hdrs = [
#     "c++/src/capnp/test-util.h",
#     "c++/src/capnp/layout-test.c++",
#     "c++/src/capnp/endian-test.c++",
#     "c++/src/capnp/test_capnp/capnp/test-import.capnp.h",
#    ],
#     deps = [":capnp_headers",":kj"],
#     includes = [".","c++/src/capnp/test_capnp","c++/src/capnp/compiler"]
# )

# cc_binary(
#     name = "capnp_tests",
#     srcs = [
#     "c++/src/capnp/common-test.c++",
#     "c++/src/capnp/blob-test.c++",
#     "c++/src/capnp/endian-test.c++",
#     "c++/src/capnp/endian-fallback-test.c++",
#     "c++/src/capnp/layout-test.c++",
#     "c++/src/capnp/any-test.c++",
#     "c++/src/capnp/message-test.c++",
#     "c++/src/capnp/encoding-test.c++",
#     "c++/src/capnp/orphan-test.c++",
#     "c++/src/capnp/serialize-test.c++",
#     "c++/src/capnp/serialize-packed-test.c++",
#     "c++/src/capnp/canonicalize-test.c++",
#     "c++/src/capnp/fuzz-test.c++",
#     "c++/src/capnp/test-util.c++",
#     ],
#     deps = [":capnp",":capnp_test_headers"],
#     includes = [".","c++/src/capnp/test_capnp","c++/src/capnp/test_capnp/capnp","c++/src/capnp/compiler"]
# )

