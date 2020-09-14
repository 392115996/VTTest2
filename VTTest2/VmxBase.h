#pragma once

#define IA32_FEATURE_CONTROL			0x03A
#define IA32_VMX_BASIC				0x480

typedef union {
	__int32 Value;
	struct {
		unsigned SSE3 : 1;
		unsigned PCLMULQDQ : 1;
		unsigned DTES64 : 1;
		unsigned MONITOR : 1;
		unsigned DS_CPL : 1;
		unsigned VMX : 1;
		unsigned SMX : 1;
		unsigned EIST : 1;
		unsigned TM2 : 1;
		unsigned SSSE3 : 1;
		unsigned Reserved : 22;
	};
} _CPUID_ECX;

typedef union {
	__int64 Value;
	struct {
		unsigned PE : 1;
		unsigned MP : 1;
		unsigned EM : 1;
		unsigned TS : 1;
		unsigned ET : 1;
		unsigned NE : 1;
		unsigned Reserved_1 : 10;
		unsigned WP : 1;
		unsigned Reserved_2 : 1;
		unsigned AM : 1;
		unsigned Reserved_3 : 10;
		unsigned NW : 1;
		unsigned CD : 1;
		unsigned PG : 1;
		unsigned Reserved_64 : 32;
	};
} _CR0;

typedef union {
	__int64 Value;
	struct {
		unsigned VME : 1;
		unsigned PVI : 1;
		unsigned TSD : 1;
		unsigned DE : 1;
		unsigned PSE : 1;
		unsigned PAE : 1;
		unsigned MCE : 1;
		unsigned PGE : 1;
		unsigned PCE : 1;
		unsigned OSFXSR : 1;
		unsigned PSXMMEXCPT : 1;
		unsigned UNKONOWN_1 : 1;		//These are zero
		unsigned UNKONOWN_2 : 1;		//These are zero
		unsigned VMXE : 1;				//It's zero in normal
		unsigned Reserved : 18;			//These are zero
		unsigned Reserved_64:32;
	};
} _CR4;

typedef union {
	__int64 Value;
	struct {
		unsigned Lock : 1;			// Bit 0 is the lock bit - cannot be modified once lock is set
		unsigned Reserved1 : 1;		// Undefined
		unsigned EnableVmxon : 1;	// Bit 2. If this bit is clear, VMXON causes a general protection exception
		unsigned Reserved2 : 29;	// Undefined
		unsigned Reserved3 : 32;	// Undefined
	};
} _MSR_IA32_FEATURE_CONTROL;