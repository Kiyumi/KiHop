#include "../include/main.h"
#include <windows.h>

using namespace Main;

bool lj_enabled;
bool sw_lj_enabled;

void longjump_tick() {
	while (true) {
		if ((lj_enabled || sw_lj_enabled) && player.in_air()) {
			for (int x = 0; x < 50; x++) {
				util.send_key(!sw_lj_enabled ? 0x20 : 0x1F, true);
				util.move_mouse(x, 0);
				Sleep(1);
				util.send_key(!sw_lj_enabled ? 0x20 : 0x1F, false);
			}
			for (int y = 0; y < 50; y++) {
				util.send_key(!sw_lj_enabled ? 0x1e : 0x11, true);
				util.move_mouse(-y, 0);
				Sleep(1);
				util.send_key(!sw_lj_enabled ? 0x1e : 0x11, false);
			}
		} else {
			Sleep(1);
		}
	}
}

void Longjump::start() {
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) longjump_tick, NULL, 0, NULL);
}

void Longjump::set_enabled(bool b) {
	lj_enabled = b;
}

void Longjump::set_sw_enabled(bool b) {
	sw_lj_enabled = b;
}

