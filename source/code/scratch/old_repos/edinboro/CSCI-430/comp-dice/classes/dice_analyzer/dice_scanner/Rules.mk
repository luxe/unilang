SUBDIRS := dice_flex_scanner
TARGETS := dice_scanner.o dice_scanner_driver
dice_scanner_driver_DEPS = dice_scanner_driver.o dice_scanner.o $(SUBDIRS_TGTS)
