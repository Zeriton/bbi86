BIN_DIR ?= bin
OUT_DIR ?= out

CFLAGS +=
LDFLAGS +=

KCONFIG_C_SOURCES = types.c lexer.c parser.c
KCONFIG_C_OBJECTS = $(patsubst %.c, $(BIN_DIR)/deps/%.o, $(KCONFIG_C_SOURCES))

$(BIN_DIR)/menuconfig: $(BIN_DIR)/deps/menuconfig.o $(KCONFIG_C_OBJECTS) 
	$(CC) $(LDFLAGS) $^ -o $@

$(BIN_DIR)/editconfig: $(BIN_DIR)/deps/editconfig.o $(KCONFIG_C_OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

$(BIN_DIR)/deps/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
