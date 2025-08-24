BOOT_ASM_SOURCES = stub.asm boot.asm
BOOT_ASM_BINARIES = $(patsubst %.asm, $(BUILD_DIR)/boot/%.bin, $(BOOT_ASM_SOURCES))

boot: $(BOOT_ASM_BINARIES)

$(BUILD_DIR)/boot/%.bin: %.asm
	mkdir -p $(dir $@)
	nasm -fbin $< -o $@ -DBBI86_ROM_START=$(BBI86_ROM_START)
