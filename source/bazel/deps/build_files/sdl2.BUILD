config_setting(
	name = "windows",
	values = {
		"cpu": "x64_windows",
	},
	visibility = ["//:__subpackages__"],
)

SDL_LINKOPTS = select({
	"//:windows": [
		"-DEFAULTLIB:user32",
		"-DEFAULTLIB:gdi32",
		"-DEFAULTLIB:winmm",
		"-DEFAULTLIB:imm32",
		"-DEFAULTLIB:ole32",
		"-DEFAULTLIB:oleaut32",
		"-DEFAULTLIB:version",
		"-DEFAULTLIB:uuid",
		"-DEFAULTLIB:shell32",
		"-DEFAULTLIB:advapi32",
		"-DEFAULTLIB:hid",
		"-DEFAULTLIB:setupapi",
		"-DEFAULTLIB:opengl32",
	],
	"//conditions:default": [],
})

cc_library(
	name = "SDL2_hdrs",
	hdrs = glob(["include/**/*.h"]),
	strip_include_prefix = "include",
	visibility = ["//visibility:public"],
)

cc_library(
	name = "SDL2base",
	srcs = [
		"src/SDL_assert.c",
		"src/SDL_dataqueue.c",
		"src/SDL_error.c",
		"src/SDL_hints.c",
		"src/SDL_log.c",
		"src/SDL.c",
	],
	deps = ["//src/thread:thread"],
	hdrs = glob(["include/**/*.h", "src/*.h"]),
	includes = ["include", "src"],
	visibility = ["//:__subpackages__"],
)

cc_library(
	name = "SDL2internal",
	hdrs = glob(["include/**/*.h", "src/*.h"]),
	includes = ["include", "src"],
	visibility = ["//:__subpackages__"],
)

cc_library(
	name = "SDL2",
	hdrs = glob(["include/**/*.h"]),
	includes = ["include", "src"],
	srcs = glob(["include/*.h", "src/*.c", "src/*.h"]),
	deps = [
		":SDL2internal",
		"//src/atomic:atomic",
		"//src/audio:audio",
		"//src/core:core",
		"//src/cpuinfo:cpuinfo",
		"//src/dynapi:dynapi",
		"//src/events:events",
		"//src/file:file",
		"//src/filesystem:filesystem",
		"//src/haptic:haptic",
		"//src/hidapi:hidapi",
		"//src/joystick:joystick",
		"//src/libm:libm",
		"//src/loadso:loadso",
		"//src/main:main",
		"//src/power:power",
		"//src/render:render",
		"//src/sensor:sensor",
		"//src/stdlib:stdlib",
		"//src/thread:thread",
		"//src/timer:timer",
		"//src/video:video",
	],
	linkopts = SDL_LINKOPTS,
	visibility = ["//visibility:public"],
)

cc_library(
	name = "SDL2test",
	hdrs = glob(["include/SDL_test*.h"]),
	srcs = glob(["src/test/**/*.c"]),
	deps = ["//:SDL2"],
	visibility = ["//test:__subpackages__"],
)