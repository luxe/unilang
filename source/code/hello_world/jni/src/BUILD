load("@rules_java//java:defs.bzl", "java_binary")

cc_library(
    name = "main-jni-lib",
    srcs = [
        "Main.cc",
        "Main.h",
    ],
    hdrs = [
        "@bazel_tools//tools/jdk:jni_header",
        "@bazel_tools//tools/jdk:jni_md_header-linux",
    ],
    # deps = [
    #     "@bazel_tools//tools/jdk:jni_header",
    #     "@bazel_tools//tools/jdk:jni_md_header-linux",
    # ],
    includes = [
        "external/bazel_tools/tools/jdk/include",
        "external/bazel_tools/tools/jdk/include/linux",
    ],
    copts = [
    "-isystem","external/bazel_tools/tools/jdk/include",
    "-isystem","external/bazel_tools/tools/jdk/include/linux",
    "-isystem","external/local_jdk/include",
    "-isystem","bazel-out/k8-fastbuild/bin/external/bazel_tools/tools/jdk/include",
    "-isystem","bazel-out/k8-fastbuild/bin/external/bazel_tools/tools/jdk/include/linux"],
    alwayslink = True,
    #strip_include_prefix = "code/hello_world/jni/src/",
)

cc_binary(
    name = "libmain-jni.so",
    deps = [ ":main-jni-lib" ],
    linkshared = True,
)

java_binary(
    name = "Main",
    srcs = [ "Main.java" ],
    main_class = "Main",
    #resources = [ ":libmain-jni.so" ],
    #runtime_deps = [ ":libmain-jni.so" ],
    #use_testrunner = False,
    #deploy_env = [ ":libmain-jni.so" ],
    #create_executable = True,
    #deps = [ ":libmain-jni.so" ],
    data = [ ":libmain-jni.so" ],
    #javacopts = [ "-Djava.library.path=." ],
    
    #works only if I do a full path.  relative fron runfiles doesn't work either.
    jvm_flags = [ "-Djava.library.path=." ],
)
