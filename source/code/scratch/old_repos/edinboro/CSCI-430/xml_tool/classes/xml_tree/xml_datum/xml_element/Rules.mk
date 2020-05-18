SUBDIRS := xml_attribute
TARGETS := xml_element_driver xml_element.o
xml_element_driver_DEPS = xml_element_driver.o xml_element.o $(SUBDIRS_TGTS)
