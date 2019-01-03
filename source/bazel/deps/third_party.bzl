load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")

def third_party_repositories():

    http_archive(
        name = "com_github_nelhage_rules_boost",
        sha256 = "69456f85900a3fa30e2e921025c3e0c650e77af8f0976dddf339eb33cadafe33",
        strip_prefix = "rules_boost-master",
        urls = [
        	"https://github.com/nelhage/rules_boost/archive/master.zip",
        ],
    )

    http_archive(
        name = "boost",
        build_file = "@com_github_nelhage_rules_boost//:BUILD.boost",
        sha256 = "da3411ea45622579d419bfda66f45cd0f8c32a181d84adfa936f5688388995cf",
        strip_prefix = "boost_1_68_0",
        urls = [
            "https://sourceforge.net/projects/boost/files/boost/1.68.0/boost_1_68_0.tar.gz",
        ],
    )