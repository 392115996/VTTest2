#include<ntddk.h>
#include<intrin.h>
#include"VmxBase.h"

static BOOLEAN IsVTEnabled()
{
    _CPUID_ECX cpuidecx = { 0 };
    _CR0 cr0 = { 0 };
    _CR4 cr4 = { 0 };
    _MSR_IA32_FEATURE_CONTROL msr = { 0 };
    int cpuinfo[4] = { -1 };
    __cpuid(cpuinfo, 1);
    cpuidecx.Value = cpuinfo[2];
    if (cpuidecx.VMX != 1)
    {
        DbgPrint("ERROR: ���CPU��֧��VT!");
        return FALSE;
    }

    cr0.Value = __readcr0();
    cr4.Value = __readcr4();

    if (cr0.PE != 1 || cr0.PG != 1 || cr0.NE != 1)
    {
        DbgPrint("ERROR:���CPUû�п���VT!");
        return FALSE;
    }

    if (cr4.VMXE == 1)
    {
        DbgPrint("ERROR:���CPU�Ѿ�������VT!");
        DbgPrint("�����Ǳ�������Ѿ�ռ����VT�������ر�������ܿ�����");
        return FALSE;
    }

    // 3. MSR
    msr.Value = __readmsr(IA32_FEATURE_CONTROL);
    if (msr.Lock != 1)
    {
        DbgPrint("ERROR:VTָ��δ������!");
        return FALSE;
    }
    DbgPrint("SUCCESS:���CPU֧��VT!");
    return TRUE;
}


void _DriverUnload(PDRIVER_OBJECT pdrvobj)
{
	DbgPrint("Unload\n");
}

NTSTATUS DriverEntry(PDRIVER_OBJECT  pdrvobj, PUNICODE_STRING regpath)
{
	pdrvobj->DriverUnload = _DriverUnload;
	DbgPrint("Entry\n");
    IsVTEnabled();
	return STATUS_SUCCESS;
}
