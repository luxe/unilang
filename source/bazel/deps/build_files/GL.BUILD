package(
    default_visibility = ["//visibility:public"],
)

# Decide how we are going to source the openGL library.
# I had problems sourcing this from the system, so we can also try
# getting it from different sysroots. This dependency is what we use on targets
# and the implementation of where we source the shard object from is abstracted so its
# easier to change if needed.
cc_library(
    name = "GL",
    deps = ["@debian_stretch_amd64_sysroot//:GL"],
)
