load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def protobuf():
    # # proto_library, cc_proto_library, and java_proto_library rules implicitly
    # # depend on @com_google_protobuf for protoc and proto runtimes.
    # # This statement defines the @com_google_protobuf repo.
    # http_archive(
    # name = "com_google_protobuf",
    # sha256 = "9cd495ad8b121394a73c068a53faea98783667efe352bc8cddc65875cbbb24fa",
    # strip_prefix = "protobuf-3.7.0-rc-2",
    # urls = [
    #     "https://github.com/protocolbuffers/protobuf/releases/download/v3.7.0rc2/protobuf-all-3.7.0-rc-2.tar.gz",
    # ],
    # )

    # # java_lite_proto_library rules implicitly depend on @com_google_protobuf_javalite//:javalite_toolchain,
    # # which is the JavaLite proto runtime (base classes and common utilities).
    # http_archive(
    #     name = "com_google_protobuf_javalite",
    #     sha256 = "d8a2fed3708781196f92e1e7e7e713cf66804bd2944894401057214aff4f468e",
    #     strip_prefix = "protobuf-5e8916e881c573c5d83980197a6f783c132d4276",
    #     urls = ["https://github.com/google/protobuf/archive/5e8916e881c573c5d83980197a6f783c132d4276.zip"],
    # )
    http_archive(
        name = "build_stack_rules_proto",
        sha256 = "36f11f56f6eb48a81eb6850f4fb6c3b4680e3fc2d3ceb9240430e28d32c47009",
        strip_prefix = "rules_proto-d86ca6bc56b1589677ec59abfa0bed784d6b7767",
        urls = [
            "https://github.com/unilang/rules_proto/archive/d86ca6bc56b1589677ec59abfa0bed784d6b7767.tar.gz",
            "https://github.com/stackb/rules_proto/archive/d86ca6bc56b1589677ec59abfa0bed784d6b7767.tar.gz",
            ],
    )