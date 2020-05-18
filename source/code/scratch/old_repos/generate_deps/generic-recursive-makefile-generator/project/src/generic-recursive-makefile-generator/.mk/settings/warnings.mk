#Warning Flags
#possible reference: https://github.com/Barro/compiler-warnings

#A more modern compiler with warnings cranked up.
#I suspect this will catch more warnings than Windriver's diab compiler.
#Update: It does.
C_AND_CPP_WARNS := -Wall -pedantic -Wextra -Wconversion \
-Wno-format-extra-args -Wno-format-zero-length \
-Wformat-nonliteral -Wformat-security -Wformat=2 \
-Wpacked -Wredundant-decls -Wcast-align -Wcast-qual\
-Wshadow -Wswitch-default -Wswitch-enum -Wuninitialized -Winit-self \
-Wunreachable-code -Wlogical-op -Wmissing-declarations \
-Wshadow -Wundef -Wabi

#I discovered that not all warnings are emitted if optimization is turned off.
#For example, you may be checking for strict-aliasing violations, but if you aren't
#building with -03, you will never see them.  Just something to keep in mind.

#specific C warning flags
C_ONLY_WARNS := -Wnested-externs -Wstrict-prototypes -Wmissing-prototypes

#specific C++ warning flags
CPP_ONLY_WARNS := -Wctor-dtor-privacy -Wnoexcept -Wold-style-cast \
-Woverloaded-virtual -Wsign-promo -Wstrict-null-sentinel

#the flags to use outside of this file
ALL_CPP_WARNINGS := $(C_AND_CPP_WARNS) $(CPP_ONLY_WARNS)
ALL_C_WARNINGS := $(C_AND_CPP_WARNS) $(C_ONLY_WARNS)
