#
# Uber, Inc. (c) 2019.
#

load("//bazel/cookbook:av.bzl", "av_cc_library")
load("//bazel/cookbook/hub:idl.bzl", "av_cc_hidl_library")

package(    default_visibility = ["//visibility:public"],)


av_cc_hidl_library(
    name = "code_company_1_source_local_map_regeneration_event_annotations",
    gen_python = True,
    hidl_deps = [
        "//local_map/libs/route/serializable:serializable_route_overlay",
        "//mlp/messages:map_ref_id",
        "//route_planner/messages:route_planner_messages",
    ],
    hidls = ["event_annotations.hidl"],
)
av_cc_library(
    name = "code_company_1_source_local_map_regeneration_event_annotations",
    srcs = [
        "event_annotations.cc"
    ],
hdrs = [
        "event_annotations.hh"
    ],

    deps = [
        "//local_map/libs/route/serializable:serializable_route_overlay",
        "//mlp/messages:map_ref_id",
        "//route_planner/messages:route_planner_messages",
    ],
)

