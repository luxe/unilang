package(default_visibility = ["//visibility:public"])

load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(
    name = "literature_section",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:paragraph",
    ],
)

hcp(
    name = "paragraph",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:outline_point",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:sentence",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:thought_connection",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature/citation",
    ],
)

hcp(
    name = "sentence",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:code_line",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:reference_citation",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:sentence_image",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:sentence_tag",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature/table:sentence_table",
    ],
)

hcp(
    name = "sentence_image",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
        "//code/tools/transcompilers/unilang/structure/model/sections/literature:sentence_image_size",
    ],
)

hcp(
    name = "sentence_image_size",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "sentence_tag",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "outline_point",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "thought_connection",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "code_line",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)

hcp(
    name = "reference_citation",
    deps = [
        "//code/tools/transcompilers/unilang/parser:token_value",
    ],
)
