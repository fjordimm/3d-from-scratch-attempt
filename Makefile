
CC := clang++
CFLAGS := -Wall

SRC_DIR := ./src
BUILD_DIR := ./build

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

#########################################

TARGET := MainProgram

#########################################

.PHONY: clean run

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(BUILD_DIR)/*

run:
	@$(BUILD_DIR)/$(TARGET)
