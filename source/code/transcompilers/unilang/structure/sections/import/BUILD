package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "import_item", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/sections/import:import_type",
"//code/transcompilers/unilang/structure/sections/import/relationship:import_relationship",
"//code/utilities/converters:lib"
])
hcp(name = "import_section", deps=[
"import_item"
])
cpp_object(name = "import_type")