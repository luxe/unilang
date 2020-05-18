SUBDIRS := instruction
TARGETS := main_memory.o driver
driver_DEPS = driver.o main_memory.o $(TARGETS_$(d)/instruction) $(TARGETS_$(d)/instruction/op_code) $(TARGETS_$(d)/instruction/address)
