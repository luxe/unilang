SUBDIRS := shut_down_code
TARGETS := operating_system.o driver
driver_DEPS = driver.o operating_system.o $(TARGETS_$(d)/shut_down_code)
