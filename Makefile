CROSS_TOOLCHAIN ?=
CC ?= gcc
LD ?= ld
override CC := $(CROSS_TOOLCHAIN)$(CC)
override LD := $(CROSS_TOOLCHAIN)$(LD)

BUILD_DIR ?= build
override BUILD_DIR := $(abspath $(BUILD_DIR))

USE_VENDOR_SILICON_INIT ?= 1
override USE_VENDOR_SILICON_INIT := $(if $(filter yes 1 true on,$(USE_VENDOR_SILICON_INIT)),1,0)

export CC LD BUILD_DIR USE_VENDOR_SILICON_INIT

.PHONY: build

build: $(BUILD_DIR)/bbi86-stub.bin \
       $(BUILD_DIR)/bbi86-early.bin

$(BUILD_DIR)/bbi86-stub.bin:
	$(MAKE) stub -C ./early

$(BUILD_DIR)/bbi86-early.bin:
	$(MAKE) build -C ./early
