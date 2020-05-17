SUBDIRS := code_paster
TARGETS := make_putter.o driver
driver_DEPS = driver.o make_putter.o $(TARGETS_$(d)/code_paster)
