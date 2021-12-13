SRC = $(wildcard *.c)
BUILD_DIR = $(abspath ./build/)
EXECUTABLE = $(BUILD_DIR)/out

CFLAGS += -Wall

# NOTA: queste righe sono specifiche a questo makefile
TXTS= $(wildcard *.txt)
test: $(EXECUTABLE)
	@for txt in $(TXTS); do \
		echo === $$txt ===; \
		$(EXECUTABLE) $$txt; \
	done
.PHONY: test

launch: $(EXECUTABLE)
	$(EXECUTABLE)
.PHONY: launch

build: $(EXECUTABLE)
.PHONY: build

$(EXECUTABLE): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CC) $(SRC) -o $(EXECUTABLE) $(CFLAGS)

clean:
	rm -r $(BUILD_DIR) || true
.PHONY: clean
