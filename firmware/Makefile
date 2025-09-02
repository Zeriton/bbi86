PHONY_TARGETS           += firmware
WORLD_TARGETS           += firmware

FIRMWARE_ROM_START      = 0xFFFF0000

FIRMWARE_C_SOURCES      := firmware/firm.c
FIRMWARE_C_OBJECTS      := $(patsubst %.c, $(BUILD_DIR)/firmware/deps/%.o, $(FIRMWARE_C_SOURCES))

firmware: $(BUILD_DIR)/firmware/firmware.bin

$(BUILD_DIR)/firmware/firmware.bin: $(FIRMWARE_C_OBJECTS)
	$(LD) $(LDFLAGS) -Tfirmware/linker.ld $^ -o $(BUILD_DIR)/firmware/firmware.temp.elf
	objcopy -Obinary $(BUILD_DIR)/firmware/firmware.temp.elf $@

$(BUILD_DIR)/firmware/deps/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
