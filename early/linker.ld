OUTPUT_FORMAT("binary")
ENTRY(_start)

SECTIONS {
	. = 0xF0000;
	
	.text : {
		PROVIDE(__pentry_addr = _pentry);
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
