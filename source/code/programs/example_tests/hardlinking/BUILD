# These targets are designed to help experiment with buildfarm's CAS hardlinking implementation.

package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/duplicate:duplicate.bzl", "sh_test_duplicate")

sh_test_duplicate(
    name = "main",
    srcs = ["main.sh"],
    amount = 65537, # Expose the ext4 hardlinking limit: (2^16)+1
)