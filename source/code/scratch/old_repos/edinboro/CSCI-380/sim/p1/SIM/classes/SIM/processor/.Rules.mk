SUBDIRS := alu op_code address instruction process_signal
TARGETS := processor.o driver
driver_DEPS = driver.o processor.o $(TARGETS_$(d)/alu) $(TARGETS_$(d)/op_code) $(TARGETS_$(d)/address) $(TARGETS_$(d)/instruction) $(TARGETS_$(d)/process_signal)
