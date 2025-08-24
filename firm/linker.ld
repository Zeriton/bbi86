OUTPUT_FORMAT("binary")

SECTIONS {
	. = FIRMWARE_START; /* To be defined by the build system */

	.text : {
		*(.text.head)
		*(.text)
	}

	.rodata : {
		*(.rodata)
	}
}
