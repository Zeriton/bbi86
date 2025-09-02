# People are picky, so we must handle the
# ability to have multiple toolchains
TOOLCHAIN               ?= gnu

# Base flags likely to be use everywhere
# throughout the core project
CFLAGS                  = -Wall -Wextra -Werror -std=c23 -isystem include
LDFLAGS                 = -m elf_i386

# NOTE: Multiple toolchains doesn't mean you can
#       nor do we support de-gnuifying.. but you could try...?
ifeq ($(TOOLCHAIN),gnu)
	CROSS_COMPILER  ?= i686-elf-
	CC              = $(CROSS_COMPILER)gcc
	LD              = $(CROSS_COMPILER)ld
	AS              = $(CROSS_COMPILER)as
	CFLAGS          += -m32 -ffreestanding
	LDFLAGS         +=
else ifeq ($(TOOLCHAIN),llvm)
	TARGET_TRIPLE   ?= i386-unknown-none
	CC              = clang
	LD              = ld.lld
	AS              = $(CC)
	CFLAGS          += --target=$(TARGET_TRIPLE) -m32 -ffreestanding
	LDFLAGS         +=
else
$(error invalid toolchain '$(TOOLCHAIN)')	# Oppsie.. we don't support archaic toolchains or MSVC (ew)
endif

# Python3 is a must for scripts, so probably
# don't change this unless you know what you're doing.
PYTHON                  = python3

export BUILD_DIR        ?= build

# Defines the default target
.DEFAULT_GOAL           := firmware

# To keep make extensible, having a variable of all the
# phony targets to be used in '.PHONY' helps a lot of headaches.
PHONY_TARGETS           = world
.PHONY: $(PHONY_TARGETS)

STANDALONE_GEN_TARGETS  =
WORLD_TARGETS           = standalone_gen
CLEAN_TARGETS           =

# Kconfig shenanigans
include scripts/Makefile.kconfig

# Core makefile includes
include bootstub/Makefile
include firmware/Makefile

# Extra helper scripts
include scripts/Makefile.image

# Creates standalone generated files/folders
standalone_gen: $(STANDALONE_GEN_TARGETS)

# Builds all the useful start
world: $(WORLD_TARGETS)

# Self explanitory?
clean: $(CLEAN_TARGETS)
	rm -rf $(BUILD_DIR)
