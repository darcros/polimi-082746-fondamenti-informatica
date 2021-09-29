SRC = $(wildcard *.c)
BUILD_DIR = $(abspath ./build/)
EXERCISE_NAME = $(notdir $(CURDIR))
EXECUTABLE = $(BUILD_DIR)/$(EXERCISE_NAME)

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
	rm -r $(BUILD_DIR)
.PHONY: clean
