.PHONY: stub build

stub: $(BUILD_DIR)/bbi86-stub.bin

$(BUILD_DIR)/bbi86-stub.bin: stub.asm
	mkdir -p $(dir $@)
	nasm -fbin $< -o $@

EARLY_ASM_SOURCES := 
EARLY_ASM_OBJECTS := $(patsubst %.asm, $(BUILD_DIR)/early/%.o, $(EARLY_ASM_SOURCES))

EARLY_C_SOURCES := entry.c
EARLY_C_OBJECTS := $(patsubst %.c, $(BUILD_DIR)/early/%.o, $(EARLY_C_SOURCES))

EARLY_C_FLAGS = -Wall -Wextra
EARLY_LD_FLAGS = -Tlinker.ld

build: $(BUILD_DIR)/bbi86-early.bin

$(BUILD_DIR)/bbi86-early.bin: $(EARLY_ASM_OBJECTS) $(EARLY_C_OBJECTS)
	nasm -fbin setup.asm -o $(BUILD_DIR)/early/setup.bin
	$(LD) $(EARLY_LD_FLAGS) -m elf_i386 $^ -o $(BUILD_DIR)/early/core.bin
	cat $(BUILD_DIR)/early/setup.bin $(BUILD_DIR)/early/core.bin > $@

$(BUILD_DIR)/early/%.o: %.asm
	mkdir -p $(dir $@)
	nasm -felf32 $< -o $@

$(BUILD_DIR)/early/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(EARLY_C_FLAGS) -m32 -c $< -o $@
