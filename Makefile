.PHONY: all clean
all:
	@$(MAKE) $(CRATER)
clean:
	rm -rf $(BIN_DIR) $(CRATER) *.o



BIN_DIR := bin/
SRC_DIR := src/
INC_DIR := inc/
LXR_DIR := lexer/
SHR_DIR := shared/


$(BIN_DIR):
	-mkdir -p $@

CC := clang
CFLAGS := -std=c17 -O2 -Wall -Wextra


SHR_INC_DIR := $(INC_DIR)$(SHR_DIR)

SHR_HEADERS := $(SHR_INC_DIR)*.h


LXR_INC_DIR := $(INC_DIR)$(LXR_DIR)
LXR_SRC_DIR := $(SRC_DIR)$(LXR_DIR)
LXR_BIN_DIR := $(BIN_DIR)$(LXR_DIR)

LXR_HEADERS := $(LXR_INC_DIR)*.h
LXR_SOURCES := $(LXR_SRC_DIR)*.c
LXR_OBJECTS := $(LXR_BIN_DIR)*.o
LXR_INCLUDES := -I$(LXR_INC_DIR) -I$(SHR_INC_DIR)


$(LXR_OBJECTS): $(LXR_BIN_DIR) $(LXR_HEADERS) $(LXR_SOURCES)
	$(CC) $(CFLAGS) $(LXR_INCLUDES) -c $(LXR_SOURCES)
	mv *.o $<

$(LXR_BIN_DIR): $(BIN_DIR)
	-mkdir -p $@


MAIN_C := $(SRC_DIR)main.c
MAIN_O := $(BIN_DIR)main.o
MAIN_INCLUDES := -I$(LXR_INC_DIR) -I$(SHR_INC_DIR)


$(MAIN_O): $(BIN_DIR) $(MAIN_C)
	$(CC) $(CFLAGS) $(MAIN_INCLUDES) -c $(MAIN_C)
	mv *.o $<


CRATER := crater

$(CRATER): $(MAIN_O) $(LXR_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@