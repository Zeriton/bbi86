CROSS_TOOLCHAIN ?= i686-elf-
CC ?= gcc
LD ?= ld
override CC := $(CROSS_TOOLCHAIN)$(CC)
override LD := $(CROSS_TOOLCHAIN)$(LD)

BUILD_DIR ?= build
override BUILD_DIR := $(abspath $(BUILD_DIR))

BBI86_ROM_START = 0xFFFF0000
IMAGE_SIZE = $$((0xFFFFFFF0 - $(BBI86_ROM_START)))

BUILD_TARGETS = boot firm

.PHONY: all clean firm-image $(BUILD_TARGETS)

all: $(BUILD_TARGETS) firm-image

firm-image: $(BUILD_TARGETS)
	dd if=/dev/zero of=$(BUILD_DIR)/bbi86.rom.bin bs=1 count=$(IMAGE_SIZE)
	dd if=$(BUILD_DIR)/boot/stub.bin of=$(BUILD_DIR)/bbi86.rom.bin bs=1 seek=$(IMAGE_SIZE) conv=notrunc
	dd if=$(BUILD_DIR)/boot/boot.bin of=$(BUILD_DIR)/bbi86.rom.bin bs=1 seek=0 conv=notrunc
	dd if=$(BUILD_DIR)/firm/firm.bin of=$(BUILD_DIR)/bbi86.rom.bin bs=1 seek=256 conv=notrunc

$(BUILD_TARGETS):
	$(MAKE) -C $@					\
		CROSS_TOOLCHAIN=$(CROSS_TOOLCHAIN)	\
		CC=$(CC)				\
		LD=$(LD)				\
		BUILD_DIR=$(BUILD_DIR)			\
		BBI86_ROM_START=$(BBI86_ROM_START)

clean:
	rm -r $(BUILD_DIR)
