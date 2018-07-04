def make_symlink_tag(filename, library=False, directory=None,
                     local=False, package=None, verbatim=False,
                     soname=True, target=None, ext=".so", generated=False,
                     configurations=None):
    """
    Create a tag to indicate where link should be created
    in bazel-out/release_links/{directory}/target for the provided target.
    Args:
       filename: name of the file to create link for
       library: is this target a library. If so link the .so
       directory: output directory in the release_links folder.
       local: symlink this file from source, not the build directory
       ext: output file extension
       soname: create a link for the mangled soname library
       configurations: list of applicable compiler configs
    """
    filename = filename

    if library:
        if ext and ext not in filename:
            filename = filename + ext
        if not verbatim:
            filename = "lib" + filename

    if directory == None:
        if library:
            directory = "lib"
        else:
            directory = "bin"

    # default to no sonames for anything that is not a library
    if not library:
        soname = False

    if not target:
        target = filename

    if not configurations:
        configurations = []

    args = [
        filename,
        target,
        soname,
        directory,
        local,
        package,
        generated,
        ",".join(configurations)
    ]

    return "link:" + ":".join(args)

def make_symlink_tags(files, directory="lib"):
    """
    Create a tag to indicate where link should be created for each file
    in bazel-out/release_links/{directory}/target for the provided target.

    Args:
        directory: output directory
    """
    tags = []
    for file in files:
        tags.append(make_symlink_tag(file, directory=directory))
    return tags
