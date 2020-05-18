SUBDIRS := processor main_memory operating_system instruction process_signal shut_down_code
TARGETS := SIM.o driver
driver_DEPS = driver.o SIM.o $(TARGETS_$(d)/processor) $(TARGETS_$(d)/processor/alu) $(TARGETS_$(d)/proccess_signal) $(TARGETS_$(d)/main_memory) $(TARGETS_$(d)/main_memory/instruction) $(TARGETS_$(d)/main_memory/instruction/op_code) $(TARGETS_$(d)/main_memory/instruction/address) $(TARGETS_$(d)/operating_system) $(TARGETS_$(d)/shut_down_code)
