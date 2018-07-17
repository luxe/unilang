package(default_visibility = ["//visibility:public"])
	
	cc_library(
	    name = "imgui",
		linkopts = [
			"-lm",
	        # FIXME(cfrantz): Detect whether we're building for linux or windows,
	        # and select the appropriate GL library
			# "-lGL",
			# "-lopengl32",
	    ],
	    hdrs = [
	        "imgui.h",
	        "imconfig.h",
	        "imgui_internal.h",
	    ],
	    srcs = [
	        "imgui.cpp",
	        "imgui_draw.cpp",
	        "stb_rect_pack.h",
	        "stb_textedit.h",
	        "stb_truetype.h",
	    ],
	)
	
	cc_library(
	    name = "imgui_sdl_opengl",
	    copts = ["-I/usr/include/SDL2"],
	    includes = ["."],
	    hdrs = [
	        "examples/sdl_opengl_example/imgui_impl_sdl.h",
	    ],
	    srcs = [
	        "examples/sdl_opengl_example/imgui_impl_sdl.cpp",
	    ],
	    deps = [
	        ":imgui",
	    ],
	)