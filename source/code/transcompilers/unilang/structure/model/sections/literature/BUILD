package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "literature_section", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/model/sections/literature:paragraph"
])

hcp(name = "paragraph", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/model/sections/literature:sentence",
"//code/transcompilers/unilang/structure/model/sections/literature:outline_point",
])

hcp(name = "sentence", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/model/sections/literature:sentence_tag",
"//code/transcompilers/unilang/structure/model/sections/literature:sentence_image",
"//code/transcompilers/unilang/structure/model/sections/literature:code_line",
"//code/transcompilers/unilang/structure/model/sections/literature/table:sentence_table",
])

hcp(name = "sentence_image", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/model/sections/literature:sentence_image_size"
])

hcp(name = "sentence_image_size", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "sentence_tag", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "outline_point", deps = [
"//code/transcompilers/unilang/parser:token_value"
])

hcp(name = "code_line", deps = [
"//code/transcompilers/unilang/parser:token_value"
])