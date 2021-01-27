package(default_visibility = ["//visibility:public"])

#Notes: had to get rid of a japanese file (non-ascii error)

# Nested Folders
cc_library(
    name = "json_pull",
    srcs = ["jsonpull/jsonpull.c"],
    hdrs = ["jsonpull/jsonpull.h"],
)

cc_library(
    name = "milo",
    hdrs = ["milo/dtoa_milo.h"],
)

cc_library(
    name = "protozero",
    hdrs = glob(["protozero/**/*.hpp"]),
)

cc_library(
    name = "mapbox",
    hdrs = glob(["mapbox/**/*.hpp"]),
)

cc_library(
    name = "catch",
    hdrs = ["catch/catch.hpp"],
)

cc_library(
    name = "nested_deps",
    deps = [
        ":catch",
        ":json_pull",
        ":mapbox",
        ":milo",
        ":protozero",
    ],
)

cc_library(
    name = "main_headers",
    hdrs = [
        "csv.hpp",
        "dirtiles.hpp",
        "evaluator.hpp",
        "geobuf.hpp",
        "geocsv.hpp",
        "geojson.hpp",
        "geojson-loop.hpp",
        "geometry.hpp",
        "main.hpp",
        "mbtiles.hpp",
        "memfile.hpp",
        "mvt.hpp",
        "options.hpp",
        "plugin.hpp",
        "pool.hpp",
        "projection.hpp",
        "read_json.hpp",
        "serial.hpp",
        "text.hpp",
        "tile.hpp",
        "version.hpp",
        "write_json.hpp",
    ],
    includes = ["."],
    deps = [
        ":nested_deps",
        "@sqlite3",
    ],
)

cc_library(
    name = "main_src",
    srcs = [
        "csv.cpp",
        #"decode.cpp",
        "dirtiles.cpp",
        #"enumerate.cpp",
        "evaluator.cpp",
        "geobuf.cpp",
        "geocsv.cpp",
        "geojson.cpp",
        "geojson-loop.cpp",
        "geometry.cpp",
        #"jsontool.cpp",
        #"main.cpp",
        "mbtiles.cpp",
        "memfile.cpp",
        "mvt.cpp",
        "plugin.cpp",
        "pool.cpp",
        "projection.cpp",
        "read_json.cpp",
        "serial.cpp",
        "text.cpp",
        "tile.cpp",
        "tile-join.cpp",
        #"unit.cpp",
        "write_json.cpp",
    ],
    includes = ["."],
    deps = [
        ":main_headers",
        ":nested_deps",
        "@sqlite3",
    ],
)

# programs from makefile
# tippecanoe
# enumerate
# decode
# join
# json-tool
# unit
cc_binary(
    name = "tippecanoe",
    srcs = [
        "main.cpp",
    ],
    includes = ["."],
    linkopts = [
        "-lm",
        "-lz",
    ],
    deps = [
        ":main_headers",
        ":main_src",
        ":nested_deps",
        "@sqlite3",
    ],
)
