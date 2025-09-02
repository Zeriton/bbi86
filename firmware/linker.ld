SECTIONS {
	.text : {
		*(.text.head)
		*(.text)
	}

	.rodata : {
		*(.rodata)
	}
}
