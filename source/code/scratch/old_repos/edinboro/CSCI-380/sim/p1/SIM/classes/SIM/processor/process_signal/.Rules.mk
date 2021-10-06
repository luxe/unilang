SUBDIRS := 
TARGETS := process_signal.o driver
$(eval driver_DEPS = driver.o process_signal.o $(shell print_non_symbolic_targets))
