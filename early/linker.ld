OUTPUT_FORMAT("binary")

SECTIONS {
	. = 0xF0100;
	
	.text : {
		*(.entry)
		*(.text)
	}

	.bss : {
		*(.bss)
	}

	.rodata : {
		*(.rodata)
	}

	.data : {
		*(.data)
	}
}
