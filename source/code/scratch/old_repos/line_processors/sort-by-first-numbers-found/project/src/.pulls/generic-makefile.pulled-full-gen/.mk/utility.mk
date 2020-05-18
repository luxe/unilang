#For debugging purposes.
#This rule will allow querying 'make' for variable contents:
#http://stackoverflow.com/a/25817631/908939
print-%  : ; @echo $* = $($*)

# Make does not offer a recursive wildcard function, so here's one:
#http://stackoverflow.com/a/12959764/908939
rwildcard=$(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))
