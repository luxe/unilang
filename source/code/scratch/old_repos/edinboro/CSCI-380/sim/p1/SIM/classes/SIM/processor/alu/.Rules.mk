SUBDIRS := 
TARGETS := alu.o driver
driver_DEPS = driver.o alu.o
