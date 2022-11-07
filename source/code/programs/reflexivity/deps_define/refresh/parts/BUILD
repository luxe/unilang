package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")
load("//bazel/rules/cpp:main.bzl", "cpp_main")

hcp_hdrs_derive(
    name = "pragma_warning_supression_settings",
    interface_deps = [
    ],
)

hcp_hdrs_derive(
    name = "pragma_warning_supression_settings_getter",
    interface_deps = [
        "//code/programs/reflexivity/deps_define/refresh/parts:pragma_warning_supression_settings",
    ],
)

hcp_hdrs_derive(
    name = "main_deps_file_creator",
    interface_deps = [
        "//code/programs/reflexivity/comment:generated_comment_getter",
        "//code/programs/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/vectors/converters:lib",
    ],
)

hcp_hdrs_derive(
    name = "get_files_creator",
    interface_deps = [
        "//code/programs/reflexivity/comment:generated_comment_getter",
        "//code/programs/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/types/strings/observers/other:lib",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/web/url:github_url_getter",
    ],
)

hcp_hdrs_derive(
    name = "build_files_creator",
    interface_deps = [
        "//code/programs/reflexivity/comment:generated_comment_getter",
        "//code/programs/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/web/url:github_url_getter",
    ],
)

hcp_hdrs_derive(
    name = "workspace_files_creator",
    interface_deps = [
        "//code/programs/reflexivity/comment:generated_comment_getter",
        "//code/programs/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
    ],
)

hcp_hdrs_derive(
    name = "wrapper_target_creator",
    interface_deps = [
        "//code/programs/reflexivity/comment:generated_comment_getter",
        "//code/programs/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/programs/reflexivity/deps_define/refresh/parts:pragma_warning_supression_settings_getter",
    ],
)

hcp_hdrs_derive(
    name = "deps_table_creator",
    interface_deps = [
        "//code/programs/reflexivity/comment:generated_comment_getter",
        "//code/programs/reflexivity/deps_define/data:dependency_specifications_getter",
        "//code/programs/reflexivity/deps_define/data:dependency_specification_table_entry",
        "//code/utilities/filesystem/files/creating:lib",
        "//code/utilities/filesystem/files/deleting:lib",
        "//code/utilities/filesystem/paths:lib",
        "//code/utilities/linguistics/computer/file_extension:file_extension_getter",
        "//code/utilities/types/strings/transformers/appending:lib",
        "//code/utilities/types/strings/transformers/casing:case_modifier",
        "//code/utilities/types/strings/transformers/casing:lib",
        "//code/utilities/types/strings/transformers/removing:lib",
        "//code/utilities/types/strings/transformers/search_replace:lib",
        "//code/utilities/types/vectors/converters:lib",
        "//code/utilities/types/vectors/observers:lib",
        "//code/utilities/formats/json/converters:type_to_json_string",
        "//code/utilities/formats/json/transformers:transformers",
        "//code/utilities/formats/json/observers:observers",
        "//code/utilities/deps/stl/regex:lib",
        "//code/utilities/formats/html:basic_html_template_getter",
        "//code/utilities/types/strings/observers/regex:lib",
        "//code/utilities/filesystem/files/temp:temp_file",
        "//code/utilities/output/upload:file_upload_settings",
        "//code/utilities/output/upload:file_uploader",
    ],
)