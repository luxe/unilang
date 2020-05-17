SUBDIRS := 
TARGETS := enum_maker.o driver
driver_DEPS = driver.o enum_maker.o
