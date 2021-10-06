package(
    default_visibility = ["//visibility:public"],
)

load("//bazel/rules/enum_cpp:enum_cpp.bzl", "enum_cpp")

enum_cpp(
    name = "bibtex_standard_entry",
    values = [
        "article",
        "book",
        "booklet",
        "conference",
        "inbook",
        "incollection",
        "inproceedings",
        "manual",
        "masterthesis",
        "misc",
        "phdthesis",
        "proceedings",
        "techreport",
        "unpublished",
    ],
)

enum_cpp(
    name = "bibtex_standard_field",
    values = [
        "address",
        "annote",
        "author",
        "booktitle",
        "chapter",
        "crossref",
        "edition",
        "editor",
        "howpublished",
        "institution",
        "journal",
        "key",
        "month",
        "note",
        "number",
        "organization",
        "pages",
        "publisher",
        "school",
        "series",
        "title",
        "type",
        "volume",
        "year",
    ],
)

enum_cpp(
    name = "bibtex_other_field",
    values = [
        "url",
        "isbn",
        "issn",
        "lccn",
        "abstract",
        "keywords",
        "price",
        "copyright",
        "language",
        "contents",
    ],
)
