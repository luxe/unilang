package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "import_item", deps = [
"//code/tools/transcompilers/unilang/parser:token_value",
"//code/tools/transcompilers/unilang/structure/model/sections/import:import_type",
"//code/tools/transcompilers/unilang/structure/model/sections/import/relationship:import_relationship",
"//code/utilities/types/converters:lib"
])
hcp(name = "import_section", deps=[
"import_item"
])
cpp_object(name = "import_type")