load("//bazel/cookbook/image:png_to_xpm.bzl", "png_to_xpm")
load("//bazel/cookbook/image:xpm_to_ppm.bzl", "xpm_to_ppm")
load("//bazel/cookbook/image:ppm_to_mask.bzl", "ppm_to_mask")
load("//bazel/cookbook/image:ppm_to_xpm.bzl", "ppm_to_xpm")
load("//bazel/cookbook/image:xpm_to_xbm.bzl", "xpm_to_xbm")
load("//bazel/cookbook/image:png_mirror.bzl", "png_mirror")

def png_to_x11_artifacts(name):
    
    png_to_xpm(name)
    xpm_to_ppm(name)
    ppm_to_mask(name)
    ppm_to_xpm(name + "_mask")
    xpm_to_xbm(name + "_mask")
    
    png_mirror(name)
    
    png_to_xpm(name + "_mirror")
    xpm_to_ppm(name + "_mirror")
    ppm_to_mask(name + "_mirror")
    ppm_to_xpm(name + "_mirror_mask")
    xpm_to_xbm(name + "_mirror_mask")
    
    native.filegroup(
        name = name + "_image_data",
        srcs = [
            name + ".xpm",
            name + "_mask.xbm",
            name + "_mirror.xpm",
            name + "_mirror_mask.xbm",
        ],
    )