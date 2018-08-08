package(default_visibility = ["//visibility:public"])

licenses(["notice"])

cc_library(
  name = "process",
  includes = [
      "include/",
  ],
  hdrs = glob([
      "include/boost/**/*.hpp",
  ]),
  srcs = [
  ],
  deps = [
      "@com_github_boost_algorithm//:algorithm",      
      "@com_github_boost_asio//:asio",      
      "@com_github_boost_config//:config",      
      "@com_github_boost_detail//:detail",      
      "@com_github_boost_filesystem//:filesystem",      
      "@com_github_boost_optional//:optional",      
      "@com_github_boost_system//:system",      
      "@com_github_boost_tokenizer//:tokenizer",      
      "@com_github_boost_winapi//:winapi",      
  ]
)
