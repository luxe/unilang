SUBDIRS := 
TARGETS := program_options.o driver
driver_DEPS = driver.o program_options.o
driver_LIBS = -lboost_program_options
