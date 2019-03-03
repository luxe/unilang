def gtest(name,deps=[]):

    #implicit file names
    explicit_cpp_file = name + ".cpp"
    deps2 = []
    for x in deps:
        deps2.append(x)
    deps2.append("@gtest//:gtest_main")

    #compile object file
    native.cc_test(
        name = name,
        srcs = [explicit_cpp_file],
        deps = deps2,
    )
