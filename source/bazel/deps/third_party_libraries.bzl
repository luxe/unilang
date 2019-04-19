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
load("//bazel/deps/get:captnproto.bzl", "captnproto")
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
load("//bazel/deps/get:pybind11.bzl", "pybind11")
load("//bazel/deps/get:grpc.bzl", "grpc")
load("//bazel/deps/get:fmt.bzl", "fmt")
load("//bazel/deps/get:glfw.bzl", "glfw")
load("//bazel/deps/get:cereal.bzl", "cereal")

# TODO(thickey): we can't trust that these git repos will always exist.  
# make copies and store them somewhere else.  Give multiple mirrors
# for the urls.  the first url can be where we host it.

# TODO(thickey): as a rule of thumb, we do not want patch files.  
# when a patch file is created, we need to work with the original author to merge it back.
# In the worst case scenarios where an agreement cannot be made with the author, or
# the original author is unresponsive, we can fork the project.

#other dependencies needed:
#gmp (this was hard)
#pretty_printers
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
    captnproto()
    protobuf()
    apache_thrift()
    cereal()
    
    # Data Structures
    andres_graph()
    
    # Math
    gmp()
    
    # Graphics
    sdl2()
    glfw()
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
    pybind11()
    
    # Threading / Workflow
    cpp_taskflow()
    tbb()
    
    # Other
    grpc()
    fmt()
