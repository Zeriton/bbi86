CFLAGS += 	-ffreestanding					\
		-fno-stack-protector				\
		-fno-pic

LDFLAGS += 	-no-pie						\
		-nostdlib					\
		--defsym FIRMWARE_START=$(BBI86_ROM_START)

FIRM_C_SOURCES := firm_main.c
FIRM_C_OBJECTS = $(patsubst %.c, $(BUILD_DIR)/firm/deps/%.o, $(FIRM_C_SOURCES))

firm: $(BUILD_DIR)/firm/firm.bin

$(BUILD_DIR)/firm/firm.bin: $(FIRM_C_OBJECTS)
	$(LD) $(LDFLAGS) -Tlinker.ld $^ -o $@

$(BUILD_DIR)/firm/deps/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(BUILD_DIR)/firm/deps/%.d
