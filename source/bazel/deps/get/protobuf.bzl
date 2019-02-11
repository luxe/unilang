load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def protobuf():

    # proto_library, cc_proto_library, and java_proto_library rules implicitly
    # depend on @com_google_protobuf for protoc and proto runtimes.
    # This statement defines the @com_google_protobuf repo.
    http_archive(
    name = "com_google_protobuf",
    sha256 = "fd65488e618032ac924879a3a94fa68550b3b5bcb445b93b7ddf3c925b1a351f",
    strip_prefix = "protobuf-3.6.1",
    urls = [
        "https://github.com/google/protobuf/releases/download/v3.6.1/protobuf-all-3.6.1.tar.gz",
    ],
    )

    # java_lite_proto_library rules implicitly depend on @com_google_protobuf_javalite//:javalite_toolchain,
    # which is the JavaLite proto runtime (base classes and common utilities).
    http_archive(
        name = "com_google_protobuf_javalite",
        sha256 = "d8a2fed3708781196f92e1e7e7e713cf66804bd2944894401057214aff4f468e",
        strip_prefix = "protobuf-5e8916e881c573c5d83980197a6f783c132d4276",
        urls = ["https://github.com/google/protobuf/archive/5e8916e881c573c5d83980197a6f783c132d4276.zip"],
    )
