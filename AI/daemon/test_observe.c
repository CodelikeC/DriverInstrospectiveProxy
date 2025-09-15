#include "observe_manager.h"
#include "observe_manager.c"
// forward declaration
bool observe_hook_init(void){}
bool observe_kernel_init(void){} 
void observe_hook_shutdown(void){}
void observe_kernel_shutdown(void){}
void observe_manager_shutdown(void){}
 
int main() {
    observe_manager_init();

    // Đăng ký observer modules
    observe_hook_init();
    observe_kernel_init();

    // Kích hoạt sự kiện mẫu
    observe_manager_notify("hook:drive_attach");
    observe_manager_notify("syscall:open");
    observe_manager_notify("syscall:read");

    // Tắt observer
    observe_hook_shutdown();
    observe_kernel_shutdown();
    observe_manager_shutdown();

    return 0;
}
