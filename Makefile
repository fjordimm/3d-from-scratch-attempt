
CC := clang++
CFLAGS := -Wall

SRC_DIR := ./src
BUILD_DIR := ./build

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
_OBJS := $(SRCS:.cpp=.o)
OBJS := $(_OBJS:%=$(BUILD_DIR)/%)

#########################################

TARGET := MainProgram

#########################################

.PHONY: all clean run

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(BUILD_DIR)/*

run:
	@$(BUILD_DIR)/$(TARGET)
