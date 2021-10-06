.PHONY: clean all

all:
	@(cd p1/SIM; make --no-print-directory all)
	@cp p1/SIM/obj/main sim
	@tput setaf 2
	@echo DONE
	@tput sgr0
clean:
	@(cd p1/SIM; make --no-print-directory clean_all)
	@rm -rf sim
	@tput setaf 2
	@echo DONE
	@tput sgr0
