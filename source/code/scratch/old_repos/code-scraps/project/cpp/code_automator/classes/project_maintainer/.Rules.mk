SUBDIRS := namespace_generator
TARGETS := project_maintainer.o driver
driver_DEPS = driver.o project_maintainer.o $(TARGETS_$(d)/namespace_generator)
