package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook:core.bzl", "hcp","cpp_object")

hcp(name = "trevor_c_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "trevor_contributors_getter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "trevor_cpp_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "trevor_c_sharp_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "trevor_d_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])

hcp(name = "trevor_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
"//code/transcompilers/unilang/user-frontend/command_line_arguments:user_chosen_export_settings",
"//code/transcompilers/unilang/compiler-frontends:language_export_spawner",
"trevor_c_exporter",
"trevor_cpp_exporter",
"//code/transcompilers/unilang/compiler-frontends/plant_uml_exporter:plant_uml_exporter",
"trevor_d_exporter",
"trevor_rust_exporter",
"trevor_c_sharp_exporter",
])

hcp(name = "trevor_rust_exporter", deps = [
"//code/transcompilers/unilang/structure:structure",
"//code/transcompilers/unilang/contributor:contributor",
])
