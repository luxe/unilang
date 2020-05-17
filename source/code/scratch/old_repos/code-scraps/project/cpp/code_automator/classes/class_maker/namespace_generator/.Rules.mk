SUBDIRS := 
TARGETS := namespace_generator.o driver
driver_DEPS = driver.o namespace_generator.o 
