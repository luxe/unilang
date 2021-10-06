package(default_visibility = ["//visibility:public"])

# cc_library(
#     name = "getch",
#     srcs = glob(["getch/src/**/*.cpp"]),
#     hdrs = glob(["getch/include/*.hpp"]),
#     includes = ["getch/include"],

# )

# cc_binary(
#     name = "get_key",
#     srcs = [
#         "example/getkey_tutorial/main.c",
#     ],
#     deps = [":getch"],
# )

cc_library(
    name = "getch_headers",
    hdrs = glob(["getch/include/*.hpp"]),
)

cc_library(
    name = "getch",
    srcs = [
        "getch/src/ch/ch.cpp",
        "getch/src/ch/get.cpp",
        "getch/src/ch/key.cpp",
        "getch/src/ch/stradd.cpp",
    ],
    includes = ["getch/include"],
    deps = [":getch_headers"],
)

# cc_library(
#     name = "rd",
#     srcs = [
#       "getch/src/rd/add_char.c",
#       "getch/src/rd/back.c",
#       "getch/src/rd/char.c",
#       "getch/src/rd/clear.c",
#       "getch/src/rd/disp.c",
#       "getch/src/rd/down.c",
#       "getch/src/rd/free.c",
#       "getch/src/rd/key.c",
#       "getch/src/rd/left.c",
#       "getch/src/rd/line.c",
#       "getch/src/rd/put.c",
#       #"getch/src/rd/rd.c",
#       "getch/src/rd/right.c",
#       "getch/src/rd/rm_char.c",
#       "getch/src/rd/up.c",
#     ],
#     includes = ["getch/include"],
#     deps = [":getch_headers"],
#
# )

# cc_library(
#     name = "history",
#     srcs = [
#       "getch/src/history/down.c",
#       "getch/src/history/history.c",
#       "getch/src/history/up.c",
#     ],
#     includes = ["getch/include"],
#     deps = [":getch_headers"],
#
# )

# cc_library(
#      name = "getch",
#      srcs = [
#        "getch/src/ch/ch.cpp",
#      ],
#      hdrs = [
#        "getch/include/getch.hpp",
#      ],
#      includes = ["getch/include"],
#      #deps = [":getch_headers"],
# )

# #cc_library(
# #           name = "getch",
# #           deps = [":ch",":rd",":history",":getch_headers"],
# #
# #)
