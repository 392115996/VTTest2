#include<ntddk.h>

void _DriverUnload(PDRIVER_OBJECT pdrvobj)
{
	DbgPrint("Unload\n");
}


NTSTATUS DriverEntry(PDRIVER_OBJECT  pdrvobj, PUNICODE_STRING regpath)
{
	pdrvobj->DriverUnload = _DriverUnload;
	DbgPrint("Entry\n");
	return STATUS_SUCCESS;
}
