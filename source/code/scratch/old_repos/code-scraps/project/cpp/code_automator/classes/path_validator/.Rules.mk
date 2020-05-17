SUBDIRS := program_options
TARGETS := path_validator.o driver
driver_LIBS = -lboost_program_options
driver_DEPS = driver.o path_validator.o $(TARGETS_$(d)/program_options)
