load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("//bazel/deps/get:boost.bzl", "boost")
load("//bazel/deps/get:abseil.bzl", "abseil")
load("//bazel/deps/get:gtest.bzl", "gtest")
load("//bazel/deps/get:lcov.bzl", "lcov")
load("//bazel/deps/get:google_benchmark.bzl", "google_benchmark")
load("//bazel/deps/get:gperf.bzl", "gperf")
load("//bazel/deps/get:spdlog.bzl", "spdlog")
load("//bazel/deps/get:rapidjson.bzl", "rapid_json")
load("//bazel/deps/get:nlohmann_json.bzl", "nlohmann_json")
load("//bazel/deps/get:yaml_cpp.bzl", "yaml_cpp")
load("//bazel/deps/get:protobuf.bzl", "protobuf")
load("//bazel/deps/get:apache_thrift.bzl", "apache_thrift")
load("//bazel/deps/get:andres_graph.bzl", "andres_graph")
load("//bazel/deps/get:gmp.bzl", "gmp")
load("//bazel/deps/get:tbb.bzl", "tbb")
load("//bazel/deps/get:cpp_taskflow.bzl", "cpp_taskflow")
load("//bazel/deps/get:sdl2.bzl", "sdl2")
load("//bazel/deps/get:imgui.bzl", "imgui")
load("//bazel/deps/get:cairo.bzl", "cairo")
load("//bazel/deps/get:gd.bzl", "gd")
load("//bazel/deps/get:open_cv.bzl", "open_cv")
load("//bazel/deps/get:open_cv_testdata.bzl", "open_cv_testdata")
load("//bazel/deps/get:pixman.bzl", "pixman")
load("//bazel/deps/get:plant_uml.bzl", "plant_uml")
load("//bazel/deps/get:sqlite3.bzl", "sqlite3")
load("//bazel/deps/get:cpr.bzl", "cpr")
load("//bazel/deps/get:zlib.bzl", "zlib")
load("//bazel/deps/get:openssl.bzl", "openssl")
load("//bazel/deps/get:curl.bzl", "curl")
load("//bazel/deps/get:cli11.bzl", "cli11")

# TODO(thickey): we can't trust that these git repos will always exist.  
# make copies and store them somewhere else.  Give multiple mirrors
# for the urls.  the first url can be where we host it.

# TODO(thickey): as a rule of thumb, we do not want patch files.  
# when a patch file is created, we need to work with the original author to merge it back.
# In the worst case scenarios where an agreement cannot be made with the author, or
# the original author is unresponsive, we can fork the project.

def third_party_libraries():
    
    # C++
    # General Libraries
    boost()
    abseil()
    
    # Testing
    gtest()
    lcov()
    
    # Benchmarking
    google_benchmark()
    gperf()
    
    # Logging
    spdlog()
    
    # Serialization
    rapid_json()
    nlohmann_json()
    yaml_cpp()
    protobuf()
    apache_thrift()
    
    # Data Structures
    andres_graph()
    
    # Math
    gmp()
    
    # Graphics
    sdl2()
    imgui()
    cairo()
    gd()
    open_cv()
    open_cv_testdata()
    pixman()
    plant_uml()
    
    # Database
    sqlite3()
    
    # Web Query
    cpr()
    zlib()
    openssl()
    curl()
    
    # CLI
    cli11()
    
    # Language Interop
    http_archive(
        name = "pybind11",
        build_file = "//bazel/deps/build_files:pybind11.BUILD",
        sha256 = "b69e83658513215b8d1443544d0549b7d231b9f201f6fc787a2b2218b408181e",
        urls = [
            "https://github.com/pybind/pybind11/archive/v2.2.4.tar.gz",
        ],
    )
    
    # Threading / Workflow
    cpp_taskflow()
    tbb()
    
    # Other
    http_archive(
        name = "com_github_grpc_grpc",
        sha256 = "d99db0b39b490d2469a8ef74197d5f211fa740fc9581dccecbb76c56d080fce1",
        strip_prefix = "grpc-1.16.0",
        urls = [
            "https://github.com/grpc/grpc/archive/v1.16.0.tar.gz",
        ],
    )
    http_archive(
        name = "fmt",
        build_file = "//bazel/deps/build_files:fmt.BUILD",
        sha256 = "3c812a18e9f72a88631ab4732a97ce9ef5bcbefb3235e9fd465f059ba204359b",
        strip_prefix = "fmt-5.2.1",
        urls = [
            "https://github.com/fmtlib/fmt/archive/5.2.1.tar.gz",
        ],
    )



    #other dependencies needed:

    #other things to add
    #gmp (this was hard)
    #pretty_printers
    #curl
    #pstreams
    #add-range-v3 library
    #add klmr-cpp11-range

    #need to make hermetic
    #sudo apt-get install xdotool
    #sudo apt-get install libxdo-dev
    #sudo apt-get install libxtst-dev
    # http_archive(
    #     name = "xdo",
    #     build_file = "//bazel/deps/build_files/xdo:xdo.BUILD",
    #     commit = "08c8e2d6cad60a69ce415499e34865157a1b66fd",
    #     remote = "https://github.com/jordansissel/xdotool.git",
    # )
