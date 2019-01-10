load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# TODO(thickey): we can't trust that these git repos will always exist.  
# make copies and store them somewhere else.  Give multiple mirrors
# for the urls.  the first url can be where we host it.

# TODO(thickey): as a rule of thumb, we do not want patch files.  
# when a patch file is created, we need to work the original author to merge it back.
# In the worst case scenarios where an agreement cannot be made with the author, or
# the original author is unresponsive, we can fork the project.

def third_party_libraries():
    
    # C++
    # General Libraries
    
    # Boost 1 (the boost code)
    http_archive(
        name = "boost",
        build_file = "@com_github_nelhage_rules_boost//:BUILD.boost",
        sha256 = "da3411ea45622579d419bfda66f45cd0f8c32a181d84adfa936f5688388995cf",
        strip_prefix = "boost_1_68_0",
        urls = [
            "https://sourceforge.net/projects/boost/files/boost/1.68.0/boost_1_68_0.tar.gz",
        ],
    )
    
    # Boost 2 (the rules to build boost code)
    http_archive(
        name = "com_github_nelhage_rules_boost",
        sha256 = "d44f1e293f58b9c4ed2fe55d3f0fa2888b7f8e406e667b8734f4a4fe3eaa0277",
        patches = [
           "//bazel/deps/build_files:rules_boost.patch",
        ],
        strip_prefix = "rules_boost-c1d618315fa152958baef8ea0d77043eebf7f573",
        urls = [
            "https://github.com/nelhage/rules_boost/archive/c1d618315fa152958baef8ea0d77043eebf7f573.zip",
        ],
    )
    
    # Boost 3 (boost dependency)
    http_archive(
        name = "org_bzip_bzip2",
        build_file = "@com_github_nelhage_rules_boost//:BUILD.bzip2",
        sha256 = "a2848f34fcd5d6cf47def00461fcb528a0484d8edef8208d6d2e2909dc61d9cd",
        strip_prefix = "bzip2-1.0.6",
        urls = [
            "https://mirror.bazel.build/www.bzip.org/1.0.6/bzip2-1.0.6.tar.gz",
            "http://www.bzip.org/1.0.6/bzip2-1.0.6.tar.gz",
        ],
    )
    
    # Boost 4 (boost dependency)
    http_archive(
        name = "org_lzma_lzma",
        build_file = "@com_github_nelhage_rules_boost//:BUILD.lzma",
        sha256 = "71928b357d0a09a12a4b4c5fafca8c31c19b0e7d3b8ebb19622e96f26dbf28cb",
        strip_prefix = "xz-5.2.3",
        urls = [
            "https://sourceforge.net/projects/lzmautils/files/xz-5.2.3.tar.gz",
        ],
    )
    
    # Boost 5 (boost dependency)
    http_archive(
        name = "net_zlib_zlib",
        build_file = "//bazel/deps/build_files:zlib.BUILD",
        sha256 = "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        strip_prefix = "zlib-1.2.11",
        urls = [
            "https://zlib.net/zlib-1.2.11.tar.gz",
        ],
    )
    
    # Other google-like standard library
    http_archive(
        name = "com_google_absl",
        sha256 = "57b7817ad91856399a77300349eda39d2edae2c3c037d453fee0a16b85e92a4d",
        strip_prefix = "abseil-cpp-48cd2c3f351ff188bc85684b84a91b6e6d17d896",
        urls = [
            "https://github.com/abseil/abseil-cpp/archive/48cd2c3f351ff188bc85684b84a91b6e6d17d896.zip",
        ],
    )
    
    # Testing
    http_archive(
        name = "com_google_googletest",
        sha256 = "3efbb860886c6018d707f1b5ee3e84d4ef63517ee85744aa2a8cb12b2feef57b",
        strip_prefix = "googletest-e5e2ef7cd27cc089c1d8302a11970ef870554294",
        urls = [
            "https://github.com/google/googletest/archive/e5e2ef7cd27cc089c1d8302a11970ef870554294.tar.gz",
        ],
    )
    http_archive(
        name = "lcov",
        build_file = "//bazel/deps/build_files:lcov.BUILD",
        sha256 = "97615b9cbb3fae1d1c655c7201b9aa61d59dd8c18eae2a4f94dcea747aa6ecf4",
        strip_prefix = "lcov-a5dd9529f9232b8d901a4d6eb9ae54cae179e5b3",
        urls = [
            "https://github.com/linux-test-project/lcov/archive/a5dd9529f9232b8d901a4d6eb9ae54cae179e5b3.tar.gz",
        ],
    )
    
    # Benchmarking
    http_archive(
        name = "com_github_google_benchmark",
        sha256 = "5bcaca7bcb700c84ea1282d3dfe0d2af1c9c2c8783e592744ae33605c133478a",
        strip_prefix = "benchmark-d939634b8ce7e0741a79c1c1f22205fae54b375d",
        urls = [
            "https://github.com/google/benchmark/archive/d939634b8ce7e0741a79c1c1f22205fae54b375d.tar.gz",
        ],
    )
    http_archive(
        name = "gperftools",
        build_file = "//bazel/deps/build_files:gperftools.BUILD",
        sha256 = "1ee8c8699a0eff6b6a203e59b43330536b22bbcbe6448f54c7091e5efb0763c9",
        strip_prefix = "gperftools-2.7",
        urls = [
            "https://github.com/gperftools/gperftools/releases/download/gperftools-2.7/gperftools-2.7.tar.gz",
        ],
    )
    
    # Logging
    http_archive(
        name = "spdlog",
        build_file = "//bazel/deps/build_files:spdlog.BUILD",
        sha256 = "867a4b7cedf9805e6f76d3ca41889679054f7e5a3b67722fe6d0eae41852a767",
        strip_prefix = "spdlog-1.2.1",
        urls = [
            "https://github.com/gabime/spdlog/releases/tag/v1.2.1",
        ],
    )
    
    # Serialization
    http_archive(
        name = "com_github_tencent_rapidjson",
        build_file = "//bazel/deps/build_files:rapidjson.BUILD",
        sha256 = "bf7ced29704a1e696fbccf2a2b4ea068e7774fa37f6d7dd4039d0787f8bed98e",
        strip_prefix = "rapidjson-1.1.0",
        urls = [
            "https://github.com/Tencent/rapidjson/archive/v1.1.0.tar.gz",
        ],
    )
    http_archive(
        name = "nlohmann_json",
        build_file = "//bazel/deps/build_files:nlohmann_json.BUILD",
        sha256 = "e0b1fc6cc6ca05706cce99118a87aca5248bd9db3113e703023d23f044995c1d",
        strip_prefix = "json-3.5.0",
        urls = [
            "https://github.com/nlohmann/json/archive/v3.5.0.tar.gz",
        ],
    )
    http_archive(
        name = "yaml-cpp",
        build_file = "//bazel/deps/build_files:yaml-cpp.BUILD",
        sha256 = "e4d8560e163c3d875fd5d9e5542b5fd5bec810febdcba61481fe5fc4e6b1fd05",
        strip_prefix = "yaml-cpp-yaml-cpp-0.6.2",
        urls = [
            "https://github.com/jbeder/yaml-cpp/archive/yaml-cpp-0.6.2.tar.gz",
        ],
    )
    http_archive(
        name = "com_google_protobuf",
        sha256 = "fd65488e618032ac924879a3a94fa68550b3b5bcb445b93b7ddf3c925b1a351f",
        strip_prefix = "protobuf-3.6.1",
        urls = [
            "https://github.com/google/protobuf/releases/download/v3.6.1/protobuf-all-3.6.1.tar.gz",
        ],
    )
    http_archive(
        name = "org_apache_thrift",
        build_file = "//bazel/deps/build_files:thrift.BUILD",
        sha256 = "0e324569321a1b626381baabbb98000c8dd3a59697292dbcc71e67135af0fefd",
        strip_prefix = "thrift-0.11.0",
        urls = [
            "https://github.com/apache/thrift/archive/0.11.0.tar.gz",
        ],
    )
    
    # Data Structures
    http_archive(
        name = "andres_graph",
        build_file = "//bazel/deps/build_files:andres_graph.BUILD",
        sha256 = "00432f3007b4cb2a8d6f2e021fd5625a79e307d6532971719ca6ab81dd0ae752",
        strip_prefix = "graph-1.11",
        urls = [
            "https://github.com/bjoern-andres/graph/archive/v1.11.tar.gz",
        ],
    )
    http_archive(
        name = "tbb",
        build_file = "//bazel/deps/build_files:tbb.BUILD",
        sha256 = "4d149895826cea785cd3b9a14f4aa743b6ef0df520eca7ee27d438fdc3d73399",
        strip_prefix = "tbb-2019",
        urls = [
            "https://github.com/01org/tbb/archive/2019.tar.gz",
        ],
    )
    
    # Math
    git_repository(
        name = "gmp",
        remote = "https://github.com/robin-thomas/bazelify-gmp",
        commit = "bb4881b35e6864c90493980d035e1d984cafd093",
    )
    
    # Graphics
    http_archive(
        name = "cairo",
        build_file = "//bazel/deps/build_files:cairo.BUILD",
        sha256 = "8c90f00c500b2299c0a323dd9beead2a00353752b2092ead558139bd67f7bf16",
        strip_prefix = "cairo-1.14.12",
        urls = [
            "https://www.cairographics.org/releases/cairo-1.14.12.tar.xz",
        ],
    )
    http_archive(
        name = "gd",
        build_file = "//bazel/deps/build_files:gd.BUILD",
        sha256 = "a66111c9b4a04e818e9e2a37d7ae8d4aae0939a100a36b0ffb52c706a09074b5",
        strip_prefix = "libgd-2.2.5",
        urls = [
            "https://github.com/libgd/libgd/releases/download/gd-2.2.5/libgd-2.2.5.tar.gz",
        ],
    )
    http_archive(
        name = "opencv",
        build_file = "//bazel/deps/build_files:opencv.BUILD",
        sha256 = "4eef85759d5450b183459ff216b4c0fa43e87a4f6aa92c8af649f89336f002ec",
        strip_prefix = "opencv-3.4.3",
        urls = [
            "https://github.com/opencv/opencv/archive/3.4.3.tar.gz",
        ],
    )
    http_archive(
        name = "opencv_testdata",
        build_file = "//bazel/deps/build_files:opencv_testdata.BUILD",
        sha256 = "dbdab9548b6365ca63f5d4d3a2b27cecd03644a6898cc98c05f3b129a46b416c",
        strip_prefix = "opencv_extra-3.4.3",
        urls = [
            "https://github.com/opencv/opencv_extra/archive/3.4.3.tar.gz",
        ],
    )
    http_archive(
        name = "pixman",
        build_file = "//bazel/deps/build_files:pixman.BUILD",
        sha256 = "21b6b249b51c6800dc9553b65106e1e37d0e25df942c90531d4c3997aa20a88e",
        strip_prefix = "pixman-0.34.0",
        urls = [
            "https://www.cairographics.org/releases/pixman-0.34.0.tar.gz",
        ],
    )
    http_archive(
        name = "plantuml",
        build_file = "//bazel/deps/build_files:plantuml.BUILD",
        sha256 = "53eecf601da9e3f495e1861f064b76e337346f51aa6069e750f1b8ec78b89a55",
        urls = [
            "https://downloads.sourceforge.net/project/plantuml/1.2018.12/plantuml-jar-asl-1.2018.12.zip?r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fplantuml%2Ffiles%2Fplantuml-jar-asl-1.2018.12.zip%2Fdownload&ts=1542658651",
        ],
    )
    
    # Database
    http_archive(
        name = "sqlite3",
        build_file = "//bazel/deps/build_files:sqlite3.BUILD",
        sha256 = "ad68c1216c3a474cf360c7581a4001e952515b3649342100f2d7ca7c8e313da6",
        strip_prefix = "sqlite-amalgamation-3240000",
        urls = [
            "https://www.sqlite.org/2018/sqlite-amalgamation-3240000.zip",
        ],
    )
    
    # Web Query
    http_archive(
        name = "cpr",
        build_file = "//bazel/deps/build_files:cpr.BUILD",
        sha256 = "82597627e8b2aef1f0482631c9b11595c63a7565bb462a5995d126da4419ac99",
        strip_prefix = "cpr-1.3.0",
        urls = [
            "https://github.com/whoshuu/cpr/archive/1.3.0.tar.gz",
        ],
    )
    http_archive(
        name = "net_zlib_zlib",
        build_file = "//bazel/deps/build_files:zlib.BUILD",
        sha256 = "c3e5e9fdd5004dcb542feda5ee4f0ff0744628baf8ed2dd5d66f8ca1197cb1a1",
        strip_prefix = "zlib-1.2.11",
        urls = [
            "https://zlib.net/zlib-1.2.11.tar.gz",
        ],
    )
    http_archive(
        name = "openssl",
        build_file = "//bazel/deps/build_files:openssl.BUILD",
        patches = ["//bazel/deps/build_files:openssl.patch"],
        sha256 = "fb6b5de486f1739dc34f2854a0c8f94d13c130eb9c4876cad73b3d40996f8ba6",
        strip_prefix = "openssl-OpenSSL_1_1_1",
        urls = [
            "https://github.com/openssl/openssl/archive/OpenSSL_1_1_1.tar.gz",
        ],
    )
    http_archive(
        name = "curl",
        build_file = "//bazel/deps/build_files:curl.BUILD",
        patches = ["//bazel/deps/build_files:curl.patch"],
        sha256 = "55ccd5b5209f8cc53d4250e2a9fd87e6f67dd323ae8bd7d06b072cfcbb7836cb",
        strip_prefix = "curl-7.62.0",
        urls = [
            "https://github.com/curl/curl/releases/download/curl-7_62_0/curl-7.62.0.tar.gz",
        ],
    )
    
    # CLI
    http_archive(
        name = "CLI11",
        build_file = "//bazel/deps/build_files:CLI11.BUILD",
        sha256 = "5ce138794b28b48717101cd57aea70382cb14b8d9859c403fbca1dc5ada0101e",
        strip_prefix = "CLI11-1.6.2",
        urls = [
            "https://github.com/CLIUtils/CLI11/archive/v1.6.2.tar.gz",
        ],
    )
    
    # Language Interop
    http_archive(
        name = "pybind11",
        build_file = "//bazel/deps/build_files:pybind11.BUILD",
        sha256 = "b69e83658513215b8d1443544d0549b7d231b9f201f6fc787a2b2218b408181e",
        urls = [
            "https://github.com/pybind/pybind11/archive/v2.2.4.tar.gz",
        ],
    )
    
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
    #gmp
    #json (ttps://github.com/nlohmann/json)
    #pretty_printers
    #curl
    #pstreams
    #add-range-v3 library (Eric Neibler)
    #add klmr-cpp11-range

    #need to make hermetic
    #sudo apt-get install libsdl2-dev
    #sudo apt-get install libsdl1.2-dev
    #sudo apt install libjpeg9-dev libwebp-dev libtiff5-dev libsdl2-image-dev libsdl2-image-2.0-0
    http_archive(
          name = "imgui",
          urls = ['https://github.com/ocornut/imgui/archive/v1.62.tar.gz'],
          build_file = "//bazel/deps/build_files:imgui.BUILD",
          strip_prefix = 'imgui-1.62',
    )

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
