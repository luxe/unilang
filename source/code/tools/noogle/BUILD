package(default_visibility = ["//visibility:public"])
load("//bazel/cookbook/hcp:hcp.bzl", "hcp")
load("//bazel/cookbook/cpp:object.bzl", "cpp_object")
load("//bazel/cookbook/cpp:distributable_main.bzl", "distributable_cpp_main")
load("//bazel/cookbook/data:package_binaries.bzl", "package_binaries")
load("//bazel/cookbook/data:distributable_data.bzl", "distributable_data")

hcp(name = "meta_settings", deps = [
])


hcp(name = "noogle_result", deps = [
])

hcp(name = "queue_state", deps = [
])

hcp(name = "noogle_documentation_getter", deps = [
    "//code/tools/transcompilers/unilang/structure/model:inlined_structures",
    "//code/tools/transcompilers/unilang/structure/model:structure",
    "//code/utilities/types/converters:lib",
    "//code/utilities/formats/json/functions:lib",
    "//code/tools/noogle/program_options:lib",
    "//code/utilities/documentation:common_documentation_getter",
])

hcp(name = "query_extender", deps = [
    "//code/tools/noogle/settings:noogle_settings",
])

hcp(name = "results_shower", deps = [
    "//code/tools/noogle/settings:noogle_settings",
    "//code/utilities/data_structures/queue:finishable_safe_queue",
    "//code/tools/noogle/state:noogle_running_stats",
    "//code/tools/noogle:noogle_result",
    "//code/utilities/time/sleeping:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/observers/char:lib",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/chart/ascii:chart_getter",
    "//code/utilities/output/printers:lib",
    "//code/utilities/colors:lib",
    "//code/utilities/types/strings/observers/splitting:lib",
    "//code/utilities/types/strings/observers/characteristic:is_month_word_checker",
])


hcp(name = "results_url_to_html_converter", deps = [
    "@boost//:asio",
    "//code/tools/noogle/settings:noogle_settings",
    "//code/utilities/data_structures/queue:finishable_safe_queue",
    "//code/tools/noogle/state:noogle_running_stats",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/web:lib",
    "//code/utilities/web/url:url_parser",
    "//code/utilities/types/sets:lib",
    "//code/utilities/filesystem/files/creating:lib",
])

hcp(name = "noogle_results_extractor", deps = [
    "//code/tools/noogle/settings:noogle_settings",
    "//code/utilities/data_structures/queue:finishable_safe_queue",
    "//code/tools/noogle/state:noogle_running_stats",
    "//code/tools/noogle:token_adder",
    "//code/utilities/types/strings/observers/splitting:lib",
    "//code/tools/noogle:noogle_result",
])


hcp(name = "html_sanitizer", deps = [
    "//code/tools/noogle/settings:noogle_settings",
    "//code/utilities/data_structures/queue:finishable_safe_queue",
    "//code/tools/noogle/state:noogle_running_stats",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/web:lib",
    "//code/utilities/web/url:url_parser",
    "//code/utilities/types/sets:lib",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/types/strings/transformers/html:html_raw_text_getter",
])

hcp(name = "noogle_runner", deps = [
    "//code/tools/noogle:meta_settings",
    "//code/utilities/web/chrome/driver:chrome_driver_selector",
    "//code/utilities/web/automate/browser:browser_creator",
    "//code/utilities/web/automate/browser:browser_settings",
    "//code/utilities/web/automate/navigation:browser_navigator",
    "//code/tools/noogle/settings:default_settings_getter",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/types/strings/transformers/squeeze:lib",
    "@pybind11//:pybind11",
    "@boost//:asio",
    #"@boost//:stacktrace",
    "//code/utilities/web/url:url_parser",
    "//code/tools/noogle/settings:noogle_settings",
    "//code/utilities/data_structures/queue:safe_queue",
    "//code/utilities/data_structures/queue:finishable_safe_queue",
    "//code/utilities/time/sleeping:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/web/google:google_search_url_deviser",
    "//code/utilities/web/google:google_json_url_deviser",
    "//code/utilities/web:lib",
    "//code/tools/noogle/state:noogle_running_stats",
    "//code/utilities/output/printers:lib",
    "//code/tools/noogle:noogle_result",
    "//code/utilities/types/strings/observers/splitting:lib",
    "//code/utilities/types/strings/observers/characteristic:spirit_numeric_checker",
    "//code/tools/noogle/program_options:lib",
    "//code/utilities/program/common_actions/exits:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/observers/char:lib",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/utilities/chart/ascii:chart_getter",
    "//code/utilities/types/sets:lib",
    "//code/utilities/types/strings/observers/characteristic:english_number_to_integral_converter",
    "//code/utilities/types/strings/observers/characteristic:is_english_number_checker",
    "//code/tools/noogle:results_shower",
    "//code/utilities/web/bing:bing_json_url_deviser",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/types/strings/transformers/html:html_raw_text_getter",
    "//code/tools/noogle:token_adder",
    "//code/tools/noogle:query_extender",
    "//code/utilities/program/common_actions/signals:lib",
    "//code/tools/noogle/state:noogle_state_getter",
    "//code/utilities/web/search_engines:search_engine_url_deviser",
    "//code/utilities/formats/json/functions:lib",
    "//code/tools/noogle:results_url_getter",
    "//code/tools/noogle:results_url_to_html_converter",
    "//code/tools/noogle:html_sanitizer",
    "//code/tools/noogle:input_poller",
    "//code/utilities/ncurses:scoped_getch",
    "//code/tools/noogle:noogle_results_extractor",
])

hcp(name = "input_poller", deps = [
    "//code/tools/noogle/state:noogle_running_stats",
    "@getch//:getch",
])



hcp(name = "results_url_getter", deps = [
    "//code/utilities/web/automate/browser:browser_settings",
    "//code/tools/noogle/settings:noogle_settings",
    "//code/utilities/data_structures/queue:finishable_safe_queue",
    "//code/tools/noogle/state:noogle_running_stats",
    "@pybind11//:pybind11",
    "@fmt//:fmt",
    "//code/utilities/web/automate/browser:browser_creator",
    "//code/utilities/web/automate/navigation:browser_navigator",
    "//code/tools/noogle/settings:default_settings_getter",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/types/strings/transformers/squeeze:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/web/google:google_search_url_deviser",
    "//code/utilities/web/google:google_json_url_deviser",
    "//code/utilities/web/bing:bing_json_url_deviser",
    "//code/utilities/web:lib",
    "//code/utilities/program/common_actions/exits:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/observers/char:lib",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/utilities/chart/ascii:chart_getter",
    "//code/utilities/web/url:url_parser",
    "//code/utilities/types/sets:lib",
    "//code/utilities/types/strings/observers/characteristic:english_number_to_integral_converter",
    "//code/utilities/types/strings/observers/characteristic:is_english_number_checker",
    "//code/tools/noogle:results_shower",
    "//code/utilities/filesystem/files/creating:lib",
    "//code/utilities/types/strings/transformers/html:html_raw_text_getter",
    "//code/utilities/web/search_engines:search_engine_url_deviser",
    "//code/utilities/formats/json/functions:lib",
    "//code/utilities/web/search_engines:search_engine_fetch_settings",
])

hcp(name = "token_adder", deps = [
    "//code/tools/noogle/settings:noogle_settings",
    "//code/tools/noogle/state:noogle_running_stats",
    "//code/utilities/types/strings/transformers/search_replace:lib",
    "//code/utilities/types/strings/transformers/squeeze:lib",
    "//code/utilities/types/strings/observers/other:lib",
    "//code/utilities/types/strings/observers/splitting:lib",
    "//code/utilities/types/vectors/observers:lib",
    "//code/utilities/types/strings/observers/char:lib",
    "//code/utilities/types/vectors/transformers:lib",
    "//code/utilities/types/vectors/operators:lib",
    "//code/utilities/types/strings/transformers/casing:lib",
    "//code/utilities/types/strings/observers/characteristic:english_number_to_integral_converter",
    "//code/utilities/types/strings/observers/characteristic:is_english_number_checker",
    "//code/utilities/types/strings/observers/characteristic:spirit_numeric_checker",
])

distributable_data(name="chrome_drivers",
                   description="chrome drivers for automating google chrome with selenium",
                   file_groups=["@chrome_drivers//:chrome_drivers"]
                   )

distributable_cpp_main(
    name = "noogle",
    deps = [
        "//code/tools/noogle:noogle_runner",
        "//code/tools/noogle:meta_settings",
        "//code/tools/noogle/program_options:lib",
    ],
    description = "google but numbers",
    depends = [
        "zlib1g-dev",
        "unzip",
        "python3",
        "python3-bs4",
    ],
)