SUBDIRS := xml_element
TARGETS := xml_datum_driver xml_datum.o
xml_datum_driver_DEPS = xml_datum_driver.o xml_datum.o $(SUBDIRS_TGTS)
