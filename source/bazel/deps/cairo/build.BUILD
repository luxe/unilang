# Ref: https://github.com/googlecartographer/cartographer/blob/master/bazel/third_party/cairo/cairo.BUILD
# Description:
#   Cairo is a 2D graphics library with support for multiple output devices.

licenses(["reciprocal"])  # MPL 1.1

cc_library(
    name = "cairo",
    srcs = [
        "cairo-version.h",
        #"cairo_internal/config.h",
        "config.h",
        "src/cairo.c",
        "src/cairo.h",
        "src/cairo-analysis-surface.c",
        "src/cairo-analysis-surface-private.h",
        "src/cairo-arc.c",
        "src/cairo-arc-private.h",
        "src/cairo-array.c",
        "src/cairo-array-private.h",
        "src/cairo-atomic.c",
        "src/cairo-atomic-private.h",
        "src/cairo-backend-private.h",
        "src/cairo-base64-stream.c",
        "src/cairo-base85-stream.c",
        "src/cairo-bentley-ottmann.c",
        "src/cairo-bentley-ottmann-rectangular.c",
        "src/cairo-bentley-ottmann-rectilinear.c",
        "src/cairo-botor-scan-converter.c",
        "src/cairo-box-inline.h",
        "src/cairo-boxes.c",
        "src/cairo-boxes-intersect.c",
        "src/cairo-boxes-private.h",
        "src/cairo-cache.c",
        "src/cairo-cache-private.h",
        "src/cairo-cff-subset.c",
        "src/cairo-clip.c",
        "src/cairo-clip-boxes.c",
        "src/cairo-clip-inline.h",
        "src/cairo-clip-polygon.c",
        "src/cairo-clip-private.h",
        "src/cairo-clip-region.c",
        "src/cairo-clip-surface.c",
        "src/cairo-clip-tor-scan-converter.c",
        "src/cairo-color.c",
        "src/cairo-combsort-inline.h",
        "src/cairo-compiler-private.h",
        "src/cairo-composite-rectangles.c",
        "src/cairo-composite-rectangles-private.h",
        "src/cairo-compositor.c",
        "src/cairo-compositor-private.h",
        "src/cairo-contour.c",
        "src/cairo-contour-inline.h",
        "src/cairo-contour-private.h",
        "src/cairo-damage.c",
        "src/cairo-damage-private.h",
        "src/cairo-debug.c",
        "src/cairo-default-context.c",
        "src/cairo-default-context-private.h",
        "src/cairo-deflate-stream.c",
        "src/cairo-deprecated.h",
        "src/cairo-device.c",
        "src/cairo-device-private.h",
        "src/cairo-error.c",
        "src/cairo-error-private.h",
        "src/cairo-fallback-compositor.c",
        "src/cairo-features.h",
        "src/cairo-fixed.c",
        "src/cairo-fixed-private.h",
        "src/cairo-fixed-type-private.h",
        "src/cairo-font-face.c",
        "src/cairo-font-face-twin.c",
        "src/cairo-font-face-twin-data.c",
        "src/cairo-font-options.c",
        "src/cairo-fontconfig-private.h",
        "src/cairo-freed-pool.c",
        "src/cairo-freed-pool-private.h",
        "src/cairo-freelist.c",
        "src/cairo-freelist-private.h",
        "src/cairo-freelist-type-private.h",
        "src/cairo-ft.h",
        "src/cairo-ft-font.c",
        "src/cairo-ft-private.h",
        "src/cairo-gstate.c",
        "src/cairo-gstate-private.h",
        "src/cairo-hash.c",
        "src/cairo-hash-private.h",
        "src/cairo-hull.c",
        "src/cairo-image-compositor.c",
        "src/cairo-image-info.c",
        "src/cairo-image-info-private.h",
        "src/cairo-image-source.c",
        "src/cairo-image-surface.c",
        "src/cairo-image-surface-inline.h",
        "src/cairo-image-surface-private.h",
        "src/cairo-line.c",
        "src/cairo-line-inline.h",
        "src/cairo-line-private.h",
        "src/cairo-list-inline.h",
        "src/cairo-list-private.h",
        "src/cairo-lzw.c",
        "src/cairo-malloc-private.h",
        "src/cairo-mask-compositor.c",
        "src/cairo-matrix.c",
        "src/cairo-mempool.c",
        "src/cairo-mempool-private.h",
        "src/cairo-mesh-pattern-rasterizer.c",
        "src/cairo-misc.c",
        "src/cairo-mono-scan-converter.c",
        "src/cairo-mutex.c",
        "src/cairo-mutex-impl-private.h",
        "src/cairo-mutex-list-private.h",
        "src/cairo-mutex-private.h",
        "src/cairo-mutex-type-private.h",
        "src/cairo-no-compositor.c",
        "src/cairo-observer.c",
        "src/cairo-output-stream.c",
        "src/cairo-output-stream-private.h",
        "src/cairo-paginated-private.h",
        "src/cairo-paginated-surface.c",
        "src/cairo-paginated-surface-private.h",
        "src/cairo-path.c",
        "src/cairo-path-bounds.c",
        "src/cairo-path-fill.c",
        "src/cairo-path-fixed.c",
        "src/cairo-path-fixed-private.h",
        "src/cairo-path-in-fill.c",
        "src/cairo-path-private.h",
        "src/cairo-path-stroke.c",
        "src/cairo-path-stroke-boxes.c",
        "src/cairo-path-stroke-polygon.c",
        "src/cairo-path-stroke-traps.c",
        "src/cairo-path-stroke-tristrip.c",
        "src/cairo-pattern.c",
        "src/cairo-pattern-inline.h",
        "src/cairo-pattern-private.h",
        "src/cairo-pdf.h",
        "src/cairo-pdf-operators.c",
        "src/cairo-pdf-operators-private.h",
        "src/cairo-pdf-shading.c",
        "src/cairo-pdf-shading-private.h",
        "src/cairo-pdf-surface.c",
        "src/cairo-pdf-surface-private.h",
        "src/cairo-pen.c",
        "src/cairo-pixman-private.h",
        "src/cairo-png.c",
        "src/cairo-polygon.c",
        "src/cairo-polygon-intersect.c",
        "src/cairo-polygon-reduce.c",
        "src/cairo-private.h",
        "src/cairo-ps.h",
        "src/cairo-ps-surface.c",
        "src/cairo-ps-surface-private.h",
        "src/cairo-raster-source-pattern.c",
        "src/cairo-recording-surface.c",
        "src/cairo-recording-surface-inline.h",
        "src/cairo-recording-surface-private.h",
        "src/cairo-rectangle.c",
        "src/cairo-rectangular-scan-converter.c",
        "src/cairo-reference-count-private.h",
        "src/cairo-region.c",
        "src/cairo-region-private.h",
        "src/cairo-rtree.c",
        "src/cairo-rtree-private.h",
        "src/cairo-scaled-font.c",
        "src/cairo-scaled-font-private.h",
        "src/cairo-scaled-font-subsets.c",
        "src/cairo-scaled-font-subsets-private.h",
        "src/cairo-script.h",
        "src/cairo-script-private.h",
        "src/cairo-script-surface.c",
        "src/cairo-shape-mask-compositor.c",
        "src/cairo-slope.c",
        "src/cairo-slope-private.h",
        "src/cairo-spans.c",
        "src/cairo-spans-compositor.c",
        "src/cairo-spans-compositor-private.h",
        "src/cairo-spans-private.h",
        "src/cairo-spline.c",
        "src/cairo-stroke-dash.c",
        "src/cairo-stroke-dash-private.h",
        "src/cairo-stroke-style.c",
        "src/cairo-surface.c",
        "src/cairo-surface-backend-private.h",
        "src/cairo-surface-clipper.c",
        "src/cairo-surface-clipper-private.h",
        "src/cairo-surface-fallback.c",
        "src/cairo-surface-fallback-private.h",
        "src/cairo-surface-inline.h",
        "src/cairo-surface-observer.c",
        "src/cairo-surface-observer-inline.h",
        "src/cairo-surface-observer-private.h",
        "src/cairo-surface-offset.c",
        "src/cairo-surface-offset-private.h",
        "src/cairo-xlib.h",
        "src/cairo-xlib-private.h",
        "src/cairo-xlib-xrender-private.h",
        "src/cairo-xlib-xrender.h",
        "src/cairo-surface-private.h",
        "src/cairo-xlib-xcb-surface.c",
        "src/cairo-xlib-surface.c",
        "src/cairo-xlib-surface-shm.c",
        "src/cairo-xlib-render-compositor.c",
        "src/cairo-xlib-core-compositor.c",
        "src/cairo-xlib-visual.c",
        "src/cairo-xlib-source.c",
        "src/cairo-xlib-screen.c",
        "src/cairo-xlib-display.c",
        "src/cairo-xlib-surface-private.h",
        "src/cairo-xlib-fallback-compositor.c",
        "src/cairo-surface-snapshot.c",
        "src/cairo-surface-snapshot-inline.h",
        "src/cairo-surface-snapshot-private.h",
        "src/cairo-surface-subsurface.c",
        "src/cairo-surface-subsurface-inline.h",
        "src/cairo-surface-subsurface-private.h",
        "src/cairo-surface-wrapper.c",
        "src/cairo-surface-wrapper-private.h",
        "src/cairo-svg.h",
        "src/cairo-svg-surface.c",
        "src/cairo-svg-surface-private.h",
        "src/cairo-tee.h",
        "src/cairo-tee-surface.c",
        "src/cairo-tee-surface-private.h",
        "src/cairo-time.c",
        "src/cairo-time-private.h",
        "src/cairo-tor-scan-converter.c",
        "src/cairo-tor22-scan-converter.c",
        "src/cairo-toy-font-face.c",
        "src/cairo-traps.c",
        "src/cairo-traps-compositor.c",
        "src/cairo-traps-private.h",
        "src/cairo-tristrip.c",
        "src/cairo-tristrip-private.h",
        "src/cairo-truetype-subset.c",
        "src/cairo-truetype-subset-private.h",
        "src/cairo-type1-fallback.c",
        "src/cairo-type1-glyph-names.c",
        "src/cairo-type1-private.h",
        "src/cairo-type1-subset.c",
        "src/cairo-type3-glyph-surface.c",
        "src/cairo-type3-glyph-surface-private.h",
        "src/cairo-tag-attributes.c",
        "src/cairo-pdf-interchange.c",
        "src/cairo-tag-stack.c",
        "src/cairo-types-private.h",
        "src/cairo-unicode.c",
        "src/cairo-user-font.c",
        "src/cairo-user-font-private.h",
        "src/cairo-version.c",
        "src/cairo-version.h",
        "src/cairo-wideint.c",
        "src/cairo-wideint-private.h",
        "src/cairo-wideint-type-private.h",
        "src/cairo-tag-attributes-private.h",
        "src/cairo-tag-stack-private.h",
        "src/cairoint.h",
    ],
    hdrs = [
        "src/cairo.h",
        "src/cairo-deprecated.h",
        "src/cairo-features.h",
        "src/cairo-version.h",
    ],
    copts = [
        # Cairo uses shifts in a couple dozen places in ints which are only in the range of unsigned int, then returns
        # them as unsigned int. This is UB, but it works, and there are so many places it happens it would be difficult
        # to blacklist them all individually.
        "-fno-sanitize=thread,shift",
        "-DHAVE_CONFIG_H",
        "-DCAIRO_NO_MUTEX=1",
        "-D_REENTRANT",
        "-Wno-everything",
        "-DCAIRO_HAS_XLIB_SURFACE=1",  # Only effect is to create xlib display mutex
    ],
    includes = [
        "cairo_internal",
        "src",
    ],
    linkopts = [
        #"-lpthread",
        #"-lrt",
        #"-lm",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "@expat",
        "@fontconfig",
        "@freetype2",
        "@libgd//:gd",
        "@libjpeg",
        "@libpng",
        "@pixman",
        "@x11//:x11_hdrs",
        "@xorg_libXext//:Xorg_libXext_headers",
        "@xorg_xorgproto",
        "@zlib",
    ],
)
