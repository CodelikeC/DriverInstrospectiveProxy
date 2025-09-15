#include "hook_manager.h"
#include "driver_hook.c"
#include "hook_manager.c"
#include "syscall_hook.c"

// cac ham init tu driver_hook.c va syscall_hook.c ....//
void init_drive_hooks(){}
void init_syscall_hooks(){}

int main()
{
    printf(
        "=== TEST HOOK MODULE START ===\n"
    ); 

    // 1. init manager .. // 
     hook_manager_init();

    // 2. Đăng ký các hook
    init_drive_hooks();
    init_syscall_hooks();

    // 3. Thử invoke các hook
    printf("\n[TEST] Invoke drive_read\n");
    hook_manager_invoke("drive_read", NULL);

    printf("\n[TEST] Invoke drive_write\n");
    hook_manager_invoke("drive_write", NULL);

    printf("\n[TEST] Invoke sys_open\n");
    hook_manager_invoke("sys_open", NULL);

    printf("\n[TEST] Invoke sys_exec\n");
    hook_manager_invoke("sys_exec", NULL);

    // 4. Thử invoke một target không có
    printf("\n[TEST] Invoke unknown_target\n");
    int res = hook_manager_invoke("unknown_target", NULL);
    if (res == HOOK_NOT_FOUND) {
        printf("[INFO] Unknown target not found, as expected.\n");
    }

    // 5. Shutdown
    hook_manager_shutdown();

    printf("\n=== TEST HOOK MODULE END ===\n");
    return 0;
}