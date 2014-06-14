#include "../include/main.h"
#include <fstream>

using namespace Main;

DWORD Main::player_base = 0x53BFC8;
DWORD Main::mflags = 0x34C;
Player Main::player;
Longjump Main::longjump;
Bunnyhop Main::bhop;
Util Main::util;
HWND Main::window;
DWORD Main::pid;
DWORD Main::module_base;
HANDLE Main::process;
bool Main::lj_enabled;
bool Main::sw_lj_enabled;
bool Main::bhop_enabled;
bool Main::legit_bhop_enabled;

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
			lj_enabled = false;
			sw_lj_enabled = false;
			bhop_enabled = false;
			legit_bhop_enabled = false;
		} else if (GetAsyncKeyState(VK_NUMPAD1)) {
			lj_enabled = true;
			sw_lj_enabled = false;
		} else if (GetAsyncKeyState(VK_NUMPAD2)) {
			sw_lj_enabled = true;
			lj_enabled = false;
		} else if (GetAsyncKeyState(VK_NUMPAD3)) {
			bhop_enabled = true;
		} else if (GetAsyncKeyState(VK_NUMPAD4)) {
			legit_bhop_enabled = true;
		} else {
			Sleep(1);
		}
	}
	return 0;
}
