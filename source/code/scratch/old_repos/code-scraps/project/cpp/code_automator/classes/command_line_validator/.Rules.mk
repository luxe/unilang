SUBDIRS := program_options
TARGETS := command_line_validator.o driver
driver_DEPS = driver.o command_line_validator.o $(TARGETS_$(d)/program_options)
driver_LIBS = -lboost_program_options
