package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:main.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")

hcp(name = "import_item", deps = [
"//code/transcompilers/unilang/parser:token_value",
"//code/transcompilers/unilang/structure/model/sections/import:import_type",
"//code/transcompilers/unilang/structure/model/sections/import/relationship:import_relationship",
"//code/utilities/converters:lib"
])
hcp(name = "import_section", deps=[
"import_item"
])
cpp_object(name = "import_type")