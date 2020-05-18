#The clang compiler to use:
CLANG_C_COMPILER := clang-3.9
CLANG_CPP_COMPILER := clang++-3.9

#The gcc compiler to use:
GCC_C_COMPILER := gcc-6
GCC_CPP_COMPILER := g++-6

#The final decision on what compiler to use:
C_COMPILER := $(GCC_C_COMPILER)
CPP_COMPILER := $(GCC_CPP_COMPILER)
