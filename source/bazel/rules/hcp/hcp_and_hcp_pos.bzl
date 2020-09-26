load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_pos.bzl", "hcp_pos")

#using the boot-strapped hcp compiler built from hcp files
def hcp_and_hcp_pos(name, deps = [], data = []):
    hcp(name, deps, data)
    hcp_pos(name, deps, data)
