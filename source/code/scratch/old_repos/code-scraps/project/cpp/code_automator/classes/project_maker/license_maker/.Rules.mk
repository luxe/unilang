SUBDIRS := 
TARGETS := license_maker.o driver
driver_DEPS = driver.o license_maker.o
