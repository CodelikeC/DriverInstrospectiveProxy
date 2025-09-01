#include <ntddk.h> 

// logging tiện dụng ,,.. 
#define LOG(msg, ...) DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "[DIP] " msg "\n", __VA_ARGS__ )

void DriverUnload(PDRIVER_OBJECT DriverObject)
{
    UNREFERENCED_PARAMETER(DriverObject); 
    LOG("Driver unloading....", 0); 
}

NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
    UNREFERENCED_PARAMETER(RegistryPath);

    LOG("DriverEntry called", 0);

    DriverObject->DriverUnload = DriverUnload;

    // Tại đây có thể: 
    // - Khởi tạo hook 
    // - Register với comm module
    // - Gọi monitor logic từ kernel folder

    LOG("DIP Kernel Init completed", 0);
    return STATUS_SUCCESS;
}