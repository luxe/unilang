package(default_visibility = ["//visibility:public"])




cc_library(
  name = "xkbcommon",
  hdrs = glob([
            "xkbcommon/**/*.h",
            "src/**/*.h",
         ],
    exclude = [
        "src/config.h",
    ]
),
  srcs = glob([
            "xkbcommon/**/*.h",
            "src/**/*.c",
         ]),
  includes = ["src","xkbcommon"],
  copts = [
    '-DXLOCALEDIR=\\\"/usr/share/X11/locale\\\"',
    '-DDEFAULT_XKB_RULES=\\\"evdev\\\"',
    '-DDFLT_XKB_CONFIG_ROOT=\\\"/usr/share/X11/xkb\\"',
    '-DDEFAULT_XKB_MODEL=\\\"pc105\\"',
    '-DDEFAULT_XKB_LAYOUT=\\\"us\\"',
  ],
  # copts = [
  #   "-DXLOCALEDIR=\"/usr/share/X11/locale\"",
  #   "-DDEFAULT_XKB_RULES='evdev'",
  #   ],
)
