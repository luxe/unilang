all:
	@cd exporter; \
	make --no-print-directory all; \
	mv main ../jstd/exporter; \
	cd ../jstd; \
	./exporter
  
clean:
	@rm -rf jstd-export; \
	cd exporter; \
	make  --no-print-directory clean;