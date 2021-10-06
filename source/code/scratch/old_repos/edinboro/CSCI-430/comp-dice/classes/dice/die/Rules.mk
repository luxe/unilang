TARGETS := die.o die_driver


die_driver_DEPS = die_driver.o die.o
die_driver_LIBS = -lboost_random


