SUBDIRS := op_code address
TARGETS := instruction.o driver
driver_DEPS = driver.o instruction.o $(TARGETS_$(d)/op_code) $(TARGETS_$(d)/address)
