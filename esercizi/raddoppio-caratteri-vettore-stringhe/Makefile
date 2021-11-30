SRC = $(wildcard *.c)
BUILD_DIR = $(abspath ./build/)
EXECUTABLE = $(BUILD_DIR)/out

CFLAGS += -Wall

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
