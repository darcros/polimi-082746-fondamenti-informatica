EXERCISE_MAKEFILES = $(shell find esercizi/ -type f -name Makefile)
SUBDIRS = $(dir $(EXERCISE_MAKEFILES))

all:
	@for dir in $(SUBDIRS); do \
		printf "\n==[ $$dir ]==\n\n"; \
		$(MAKE) -C $$dir; \
	done
.PHONY: all
