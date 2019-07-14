# Reference: https://raw.githubusercontent.com/antonovvk/bazel_rules/master/config.bzl
# Reference License: MIT License

def _fix_config_impl(ctx):
    input = ctx.file.file
    output = ctx.outputs.out

    script = ""
    for k, v in ctx.attr.values.items():
        v = v.replace("\\", "\\\\").replace("/", "\/")
        if ctx.attr.cmake:
            script += "s/\#cmakedefine\\s+%s\\b.*/\#define %s %s/g;" % (k, k, v)
            script += "s/\#cmakedefine01\\s+%s\\b.*/\#define %s 1/g;" % (k, k)
            script += "s/\$\{%s\}/%s/g;" % (k, v)
        script += "s/\@%s\@/%s/g;" % (k, v)

    if ctx.attr.cmake:
        script += "s/\#cmakedefine[\\s]+(\\w+).*/\/* #undef \\1 *\//g;"
        script += "s/\#cmakedefine01[\\s]+(\\w+).*/\#define \\1 0/g;"
        script += "s/\$\{\\w+\}//g;"
    script += "s/\@[^\@]*\@/0/g"

    ctx.actions.run_shell(
        inputs = [input],
        outputs = [output],
        progress_message = "Configuring %s" % input.short_path,
        command = "perl -pe '%s' < %s > %s" % (script, input.path, output.path),
    )

fix_config_rule = rule(
    attrs = {
        "cmake": attr.bool(
            default = False,
            mandatory = False,
        ),
        "file": attr.label(
            mandatory = True,
            allow_single_file = True,
        ),
        "output": attr.string(mandatory = True),
        "values": attr.string_dict(mandatory = True),
    },
    output_to_genfiles = True,
    outputs = {"out": "%{output}"},
    implementation = _fix_config_impl,
)

def cc_fix_config(name, files, values, cmake = False, visibility = None):
    hdrs = []
    for input, output in files.items():
        fix_config_rule(
            name = input + "_impl",
            cmake = cmake,
            file = input,
            output = output,
            values = values,
        )
        hdrs.append(output)

    native.cc_library(
        name = name,
        hdrs = hdrs,
        visibility = visibility,
    )
