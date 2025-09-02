PHONY_TARGETS       += bootstub
WORLD_TARGETS       += bootstub

bootstub: $(BUILD_DIR)/bootstub/reset.bin \
          $(BUILD_DIR)/bootstub/boot.bin

$(BUILD_DIR)/bootstub/reset.bin: bootstub/reset.asm
	mkdir -p $(dir $@)
	nasm -DFIRMWARE_ROM_START=$(FIRMWARE_ROM_START) -fbin $< -o $@

$(BUILD_DIR)/bootstub/boot.bin: bootstub/boot.asm
	mkdir -p $(dir $@)
	nasm -DFIRMWARE_ROM_START=$(FIRMWARE_ROM_START) -fbin $< -o $@
