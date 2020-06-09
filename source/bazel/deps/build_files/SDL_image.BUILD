package(default_visibility = ["//visibility:public"])

#glob the files we care about
hdrs = glob(
    include = [
        "*.h",
    ],
    exclude = [
    ],
)

srcs = glob(
    include = [
        "*.c",
    ],
    exclude = [

        #main programs
        "showanim.c",
        "showimage.c",
    ],
)

cc_library(
    name = "SDL_image",
    srcs = srcs,
    hdrs = hdrs,
    copts = [
    ],
    includes = [
        ".",
    ],
    deps = [
        "@libjpeg",
        "@libpng",
        "@sdl2",
        "@zlib",
    ],
)

#libtool: compile:  gcc -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\"
#-DPACKAGE_URL=\"\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1
#-DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_DLFCN_H=1 -DLT_OBJDIR=\".libs/\" -DPACKAGE=\"SDL2_image\" -DVERSION=\"2.0.6\" -DLOAD_JPG=1
#-DLOAD_PNG=1 -DLOAD_TIF=1 -DLOAD_WEBP=1 -DLOAD_BMP=1 -DLOAD_GIF=1 -DLOAD_LBM=1 -DLOAD_PCX=1 -DLOAD_PNM=1 -DLOAD_SVG=1 -DLOAD_TGA=1 -DLOAD_XCF=1 -DLOAD_XPM=1
#-DLOAD_XV=1 -DLOAD_WEBP_DYNAMIC=\"libwebp.so.6\" -DLOAD_TIF_DYNAMIC=\"libtiff.so.5\" -DLOAD_JPG_DYNAMIC=\"libjpeg.so.8\"
#-DLOAD_PNG_DYNAMIC=\"libpng16.so.16\" -I. -I/usr/include/libpng16 -g -O2 -D_REENTRANT -I/usr/include/SDL2 -MT IMG_svg.lo -MD -MP -MF .deps/IMG_svg.Tpo -c IMG_svg.c -o IMG_svg.o >/dev/null 2>&1
