package(default_visibility = ["//visibility:public"])

load("//bazel/rules/hcp:hcp.bzl", "hcp")
load("//bazel/rules/hcp:hcp_hdrs_derive.bzl", "hcp_hdrs_derive")
load("//bazel/rules/cpp:object.bzl", "cpp_object")

hcp_hdrs_derive(
    name = "list_of_links",
    interface_deps = [
        "//code/utilities/formats/html:basic_html_template_getter",
        "//code/utilities/formats/html/body:html_list_maker",
        "//code/utilities/formats/html/style:link_list_styling",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp_hdrs_derive(
    name = "centered_image",
    interface_deps = [
        "//code/utilities/formats/html:basic_html_template_getter",
        "//code/utilities/formats/html/body:html_list_maker",
        "//code/utilities/formats/html/style:center_image_styling",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)

hcp_hdrs_derive(
    name = "blog_essay",
    interface_deps = [
        "//code/utilities/formats/html:basic_html_template_getter",
        "//code/utilities/formats/html/body:html_list_maker",
        "//code/utilities/formats/html/style:normalize",
        "//code/utilities/formats/html/style:simple_blog",
        "//code/utilities/types/strings/transformers/appending:lib",
    ],
)
