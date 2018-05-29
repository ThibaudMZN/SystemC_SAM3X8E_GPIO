//  I/O Peripheral Base Address
#define PIOA_BASE_ADDR      0x400E0E00 // 30 I/O Lines
#define PIOB_BASE_ADDR      0x400E1000 // 32 I/O Lines
#define PIOC_BASE_ADDR      0x400E1200 // 31 I/O Lines
#define PIOD_BASE_ADDR      0x400E1400 // 10 I/O Lines
// Number of I/O Lines for each Peripheral
#define PIOA_SIZE           30
#define PIOB_SIZE           32
#define PIOC_SIZE           31
#define PIOD_SIZE           10

/////////////////////////////////////////////////////////////////
////////////////////// GPIO REGISTERS ///////////////////////////
/////////////////////////////////////////////////////////////////
//PIO register
#define PIO_PER_OFFSET      0x0000 // Enable
#define PIO_PDR_OFFSET      0x0004 // Disable
#define PIO_PSR_OFFSET      0x0008 // Status
//Output register
#define PIO_OER_OFFSET      0x0010 // Enable
#define PIO_ODR_OFFSET      0x0014 // Disable
#define PIO_OSR_OFFSET      0x0018 // Status
//glitch input filter register
#define PIO_IFER_OFFSET     0x0020 // Enable
#define PIO_IFDR_OFFSET     0x0024 // Disable
#define PIO_IFSR_OFFSET     0x0028 // Status
// Output data register
#define PIO_SODR_OFFSET     0x0030 // Set
#define PIO_CODR_OFFSET     0x0034 // Clear
#define PIO_ODSR_OFFSET     0x0038 // Status
//Pin data status register
#define PIO_PDSR_OFFSET     0x003C
//Interrupt register
#define PIO_IER_OFFSET      0x0040 // Enable
#define PIO_IDR_OFFSET      0x0044 // Disable
#define PIO_IMR_OFFSET      0x0048 // Mask
#define PIO_ISR_OFFSET      0x004C // Status
// Multi driven register
#define PIO_MDER_OFFSET     0x0050 // Enable
#define PIO_MDDR_OFFSET     0x0054 // Disable
#define PIO_MDSR_OFFSET     0x0058 // Status
// Pull Up register
#define PIO_PUDR_OFFSET     0x0060 // Enable
#define PIO_PUER_OFFSET     0x0064 // Disable
#define PIO_PUSR_OFFSET     0x0068 //Status
// Peripheral AB select register
#define PIO_ABSR_OFFSET     0x0070
//System Clock Glitch Input Filter select register
#define PIO_SCIFSR_OFFSET   0x0080
//Debouncing input Filter select register
#define PIO_DIFSR_OFFSET    0x0084
//Glitch or debouncing input filter clock selection status register
#define PIO_IFDGSR_OFFSET   0x0088
//Slow clock Divider debouncing register
#define PIO_SCDR_OFFSET     0x008C
//Output Write register
#define PIO_OWER_OFFSET     0x00A0 // Enable
#define PIO_OWDR_OFFSET     0x00A4 // Disable
#define PIO_OWSR_OFFSET     0x00A8 // Status
// Additionnal interrupt mode register
#define PIO_AIMER_OFFSET    0x00B0 // Enable
#define PIO_AIMDR_OFFSET    0x00B4 // Disbale
#define PIO_AIMMR_OFFSET    0x00B8 // Mask
//Select register
#define PIO_ESR_OFFSET      0x00C0 // Edge
#define PIO_LSR_OFFSET      0x00C4 // Level
#define PIO_ELSR_OFFSET     0x00C8 // Edge/level Status
// Level Select Register
#define PIO_FELLSR_OFFSET   0x00D0 // Falling edge/Low
#define PIO_REHLSR_OFFSET   0x00D4 // Rising Edge/ High
#define PIO_FRLHSR_OFFSET   0x00D8 // Fall/Rise - Low/High Status
// Lock status
#define PIO_LOCKSR_OFFSET   0x00E0
// Write Protect Mode Register
#define PIO_WPMR_OFFSET     0x00E4
// Write Protect Status Register
#define PIO_WPSR_OFFSET     0x00E8
