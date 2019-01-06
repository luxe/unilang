load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")

# TODO(thickey): we can't trust that these git repos will always exist.  
# make copies and store them somewhere else.  Give multiple mirrors
# for the urls.  the first url can be where we host it.

def third_party_repositories():
    
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
        sha256 = "725d8979e752acb3228ddf87477a42c59af80473318b5f52f5116dae0142b12a",
        patches = [
            "//bazel/deps:rules_boost.patch",
        ],
        strip_prefix = "rules_boost-0be13900fbf54aaf66dac06634e500747879e554",
        urls = [
            "https://github.com/nelhage/rules_boost/archive/0be13900fbf54aaf66dac06634e500747879e554.zip",
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
        build_file = "//third_party:zlib.BUILD",
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
        build_file = "//third_party:gperftools.BUILD",
        sha256 = "1ee8c8699a0eff6b6a203e59b43330536b22bbcbe6448f54c7091e5efb0763c9",
        strip_prefix = "gperftools-2.7",
        urls = [
            "https://github.com/gperftools/gperftools/releases/download/gperftools-2.7/gperftools-2.7.tar.gz",
        ],
    )
    
    # Serialization
    http_archive(
        name = "com_github_tencent_rapidjson",
        build_file = "//third_party:rapidjson.BUILD",
        sha256 = "bf7ced29704a1e696fbccf2a2b4ea068e7774fa37f6d7dd4039d0787f8bed98e",
        strip_prefix = "rapidjson-1.1.0",
        urls = [
            "https://github.com/Tencent/rapidjson/archive/v1.1.0.tar.gz",
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
    
    # Other Data Structures
    http_archive(
        name = "andres_graph",
        build_file = "//third_party:andres_graph.BUILD",
        sha256 = "00432f3007b4cb2a8d6f2e021fd5625a79e307d6532971719ca6ab81dd0ae752",
        strip_prefix = "graph-1.11",
        urls = [
            "https://github.com/bjoern-andres/graph/archive/v1.11.tar.gz",
        ],
    )
    
    # Graphics
    http_archive(
        name = "cairo",
        build_file = "//third_party:cairo.BUILD",
        sha256 = "8c90f00c500b2299c0a323dd9beead2a00353752b2092ead558139bd67f7bf16",
        strip_prefix = "cairo-1.14.12",
        urls = [
            "https://www.cairographics.org/releases/cairo-1.14.12.tar.xz",
        ],
    )
    
    # CLI
    http_archive(
        name = "CLI11",
        build_file = "//third_party:CLI11.BUILD",
        sha256 = "5ce138794b28b48717101cd57aea70382cb14b8d9859c403fbca1dc5ada0101e",
        strip_prefix = "CLI11-1.6.2",
        urls = [
            "https://github.com/CLIUtils/CLI11/archive/v1.6.2.tar.gz",
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
          build_file = "//bazel/deps:imgui.BUILD",
          strip_prefix = 'imgui-1.62',
    )

    #need to make hermetic
    #sudo apt-get install xdotool
    #sudo apt-get install libxdo-dev
    #sudo apt-get install libxtst-dev
    # http_archive(
    #     name = "xdo",
    #     build_file = "//bazel/deps/xdo:xdo.BUILD",
    #     commit = "08c8e2d6cad60a69ce415499e34865157a1b66fd",
    #     remote = "https://github.com/jordansissel/xdotool.git",
    # )
