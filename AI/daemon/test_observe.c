#include "observe_manager.h"
#include "observe_hook.c"

#include "observe_kernel.c"
#include "observe_env.c"
#include "observe_log.c"

// forward declaration
bool observe_hook_init(void){}
bool observe_kernel_init(void);
bool observe_env_init(void);
void observe_hook_shutdown(void){}
void observe_kernel_shutdown(void);
void observe_env_shutdown(void);

int main() {
    observe_manager_init();

    // Đăng ký các observer modules
    observe_hook_init();
    observe_kernel_init();
    observe_env_init();

    // Kích hoạt sự kiện mẫu
    observe_manager_notify("hook:syscall:open");
    observe_manager_notify("kernel:ctx_switch");
    observe_manager_notify("env:cpu:75%");
    observe_manager_notify("env:mem:1024MB");
    observe_manager_notify("env:io:disk_read");

    // Tắt observer
    observe_hook_shutdown();
    observe_kernel_shutdown();
    observe_env_shutdown();
    observe_manager_shutdown();

    return 0;
}
