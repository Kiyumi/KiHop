#include "../include/main.h"
#include <fstream>

using namespace Main;

DWORD Main::player_base = 0x53BFC8;
DWORD Main::mflags = 0x34C;
Player Main::player;
Longjump Main::longjump;
Bhop Main::bhop;
Util Main::util;
HWND Main::window;
DWORD Main::pid;
DWORD Main::module_base;
HANDLE Main::process;

int main() {
	printf("Waiting for Counter-Strike Source.\n");
	window = FindWindow(NULL, "Counter-Strike Source");
	while (window == NULL) {
		Sleep(1000);
		window = FindWindow(NULL, "Counter-Strike Source");
	}
	printf("Counter-Strike Source was found.\n");
	GetWindowThreadProcessId(window, &pid);
	process = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	module_base = util.get_module_base_extern(pid, "client.dll");
	player.start();
	longjump.start();
	bhop.start();
	while (true) {
		if (GetAsyncKeyState(VK_NUMPAD0)) {
			longjump.set_enabled(false);
			longjump.set_sw_enabled(false);
			bhop.set_enabled(false);
			bhop.enable_legitbhop(false);
		} else if (GetAsyncKeyState(VK_NUMPAD1)) {
			longjump.set_enabled(true);
			longjump.set_sw_enabled(false);
		} else if (GetAsyncKeyState(VK_NUMPAD2)) {
			longjump.set_sw_enabled(true);
			longjump.set_enabled(false);
		} else if (GetAsyncKeyState(VK_NUMPAD3)) {
			bhop.set_enabled(true);
		} else if (GetAsyncKeyState(VK_NUMPAD4)) {
			bhop.enable_legitbhop(true);
		}
		Sleep(1);
	}
	return 0;
}
