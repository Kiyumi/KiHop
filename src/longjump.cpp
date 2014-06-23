#include "../include/main.h"

using namespace Main;

void longjump_tick() {
	while (true) {
		if (auto_lj_enabled || auto_sw_lj_enabled) {
			if (player.in_air()) {
				for (int x = 0; x < 50; x++) {
					util.send_key(!auto_sw_lj_enabled ? 0x20 : 0x1F, true);
					util.move_mouse(x, 0);
					Sleep(1);
					util.send_key(!auto_sw_lj_enabled ? 0x20 : 0x1F, false);
				}
				for (int y = 0; y < 50; y++) {
					util.send_key(!auto_sw_lj_enabled ? 0x1e : 0x11, true);
					util.move_mouse(-y, 0);
					Sleep(1);
					util.send_key(!auto_sw_lj_enabled ? 0x1e : 0x11, false);
				}
			} else {
				Sleep(1);
			}
		} else if (strafe_hack_enabled) {
			if (player.in_air()) {
				GetCursorPos(&cursor_pos);
				if (cursor_pos.x > center.x
						&& (!(GetKeyState(0x44) & 0x8000)
								|| !(GetKeyState(0x41) & 0x8000))) {
					util.send_key(0x20, true); //D
					Sleep(1);
					util.send_key(0x20, false); //D
				} else if (cursor_pos.x < center.x
						&& (!(GetKeyState(0x44) & 0x8000)
								|| !(GetKeyState(0x41) & 0x8000))) {
					util.send_key(0x1e, true); //D
					Sleep(1);
					util.send_key(0x1e, false); //D
				}
			} else {
				Sleep(1);
			}
		} else {
			Sleep(1);
		}
	}
}

void Longjump::start() {
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) longjump_tick, NULL, 0,
			NULL);
}
