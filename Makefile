CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic

LIB_DIR=lib
LIB_SOURCES=$(wildcard $(LIB_DIR)/*.c)

OBJECTS_DIR=objects
LIB_OBJECTS=$(patsubst $(LIB_DIR)/%.c, $(OBJECTS_DIR)/%.o, $(LIB_SOURCES))

TESTS_DIR=tests
TESTS_SOURCES=$(wildcard $(TESTS_DIR)/*.c)

TESTS_OBJECTS=$(patsubst $(TESTS_DIR)/%.c, $(OBJECTS_DIR)/%.o, $(TESTS_SOURCES))

BIN_DIR=bin
TESTS_BINS=$(patsubst $(TESTS_DIR)/%.c, $(BIN_DIR)/%, $(TESTS_SOURCES))

all: $(LIB_OBJECTS)

clean:
	rm -rf $(BIN_DIR) $(OBJECTS_DIR)

test: $(TESTS_BINS)

runtest: $(TESTS_BINS)
	./$(BIN_DIR)/bitset_test

$(LIB_OBJECTS): $(OBJECTS_DIR) $(LIB_SOURCES)
	$(CC) $(CFLAGS) -c $(LIB_DIR)/bitset.c -o $(OBJECTS_DIR)/bitset.o

$(TESTS_OBJECTS): $(OBJECTS_DIR) $(TESTS_SOURCES)
	$(CC) $(CFLAGS) -c $(TESTS_DIR)/bitset_test.c -o $(OBJECTS_DIR)/bitset_test.o

$(TESTS_BINS): $(BIN_DIR) $(LIB_OBJECTS) $(TESTS_OBJECTS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/bitset_test  $(OBJECTS_DIR)/bitset_test.o $(LIB_OBJECTS)

$(OBJECTS_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@
