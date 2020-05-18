#grabbing all the dependency rules
#these dependency rules are generated automatically by the compiler
-include $(C_SOURCE_PATHS:.c=.d)
-include $(CPP_SOURCE_PATHS:.cpp=.d)
