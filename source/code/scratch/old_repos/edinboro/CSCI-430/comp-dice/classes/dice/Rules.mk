SUBDIRS := die
TARGETS := dice.o dice_driver

dice_driver_DEPS = dice_driver.o dice.o $(call subtree_tgts,$(d)/die)
dice_driver_LIBS = -lboost_random



