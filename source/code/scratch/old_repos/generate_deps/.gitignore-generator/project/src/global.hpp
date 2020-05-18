#include "ignore_category.hpp"
namespace constant{

	const std::string IGNORE_FILE = ".gitignore";

	const Ignore_Category OBJECT_FILES(
	"object files",
	{"*.slo"
	,"*.lo"
	,"*.o"
	,"*.ko"
	,"*.obj"
	,"*.elf"
	});

	const Ignore_Category DYNAMIC_LIBRARIES(
	"dynamic libraries",
	{"*.so"
	,"*.so.*"
	,"*.dylib"
	,"*.dll"
	});

	const Ignore_Category STATIC_LIBRARIES(
	"static libraries",
	{"*.lai"
	,"*.la"
	,"*.a"
	,"*.lib"
	});

	const Ignore_Category EXECUTABLES(
	"executables",
	{"*.exe"
	,"*.out"
	,"*.app"
	,"*.i*86"
	,"*.x86_64"
	,"*.hex"
	});

	const Ignore_Category BACKUPS(
	"backups",
	{"*~"
	,".*~"
	});

	const Ignore_Category DEPENDENCIES(
	"dependencies",
	{"*.d" //should be "*.deps" since there is a programming language D.  unfortunately .d is the default that gcc uses
	});

	const Ignore_Category WINDOWS_GENERATED(
	"windows generated",
	{ "ehthumbs.db"
	, "Thumbs.db"
	, "Desktop.ini"
	, "$RECYCLE.BIN/"
	});

	const Ignore_Category MAC_GENERATED(
	"mac generated",
	{ ".DS_Store"
	, ".DS_Store?"
	, "._*"
	, ".Spotlight-V100"
	, ".Trashes"
	});

	const Ignore_Category LINUX_GENERATED(
	"linux generated",
	{
	});

	const Ignore_Category ARCHIVED(
	"archived",
	{ "*.zip"
	, "*.gz"
	, "*.7z"
	, "*.dmg"
	, "*.gz"
	, "*.iso"
	, "*.jar"
	, "*.rar"
	, "*.tar"
	, "*.bzip"
	, "*.bz2"
	, "*.xz"
	, "*.lzma"
	, "*.cab"
	, "*.iso"
	, "*.xpi"
	, "*.gem"
	, "*.egg"
	, "*.deb"
	, "*.rpm"
	, "*.msi"
	, "*.msm"
	, "*.msp"
	});

	//yuna - lights and camera
	const Ignore_Category DATABASE(
	"database",
	{ "*.sql"
	, "*.sqlite"
	});

	const Ignore_Category VIM(
	"vim",
	{ "[._]*.s[a-w][a-z]"
	, "[._]s[a-w][a-z]"
	,"*.un~"
	,"Session.vim"
	,".netrwhist"
	});

	const Ignore_Category EMACS(
	"emacs",
	{"\\#*\\#"
	,"/.emacs.desktop"
	,"/.emacs.desktop.lock"
	,"*.elc"
	,"auto-save-list"
	,"tramp"
	,".\\#*"
	});


	const Ignore_Category KATE(
	"kate",
	{".*.kate-swp"
	,".swp.*"
	});

	const Ignore_Category SUBLIME(
	"sublime",
	{"*.sublime-workspace"
	,"*.sublime-project"
	});

	const Ignore_Category NOTEPADPLUSPLUS(
	"notepad++",
	{"*.bak"
	});

	const Ignore_Category AUTO_TOOLS(
	"Auto Tools",
	{"/autom4te.cache"
	,"/aclocal.m4"
	,"/compile"
	,"/configure"
	,"/depcomp"
	,"/install-sh"
	,"/missing"
	,"/stamp-h1"
	});

	const Ignore_Category SCONS(
	"SCons",
	{".sconsign.dblite"
	});

	const Ignore_Category CMAKE(
	"CMake",
	{"CMakeCache.txt"
	,"CMakeFiles"
	,"cmake_install.cmake"
	,"install_manifest.txt"
	});

	const Ignore_Category QT(
	"Qt",
	{"*.pro.user"
	,"*.pro.user.*"
	,"moc_*.cpp"
	,"qrc_*.cpp"
	,"ui_*.h"
	,"*-build-*"
	,"*.autosave"
	});
}
