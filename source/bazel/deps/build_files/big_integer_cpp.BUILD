
package(default_visibility = ["//visibility:public"])

# doesn't build.  needs patched
cc_library(
    name = "big_integer_cpp",
    hdrs = glob([
        "**/*.h",
        "**/*.hpp",
    ],exclude = [
        "Security/Random.h",
        "Security/SecureRandom.h",
    ]),
    
    srcs = glob([
        "**/*.cpp",
        
    ],exclude = [
        "Security/Random.cpp",
        "Security/SecureRandom.cpp",
        "BigInteger Application.cpp"
        ],
    ),
)
