SUBDIRS := 
TARGETS := program_options.o driver
$(eval driver_DEPS = driver.o program_options.o $(shell print_non_symbolic_targets))
driver_LIBS = -lboost_program_options
