
CC := clang++
CFLAGS := -Wall

SRC_DIR := ./src
BUILD_DIR := ./build

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

#########################################

TARGET := MainProgram

# DEPS := Bruh.o Madam.o

#########################################

.PHONY: clean

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<

# $(TARGET): $(OUTDIR)/$(TARGET).o $(OUTDIR)/$(DEPS)
# 	$(CC) $(CFLAGS) -o $(OUTDIR)/$@ $^

# # Compile
# $(OUTDIR)/%.o: $(SRCDIR)/%.cpp
# 	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -r $(BUILD_DIR)/*
