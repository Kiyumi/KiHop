#include "../include/main.h"
#include <fstream>
#include <windows.h>

using namespace Main;

bool bhop_enabled;
bool legit_bhop_enabled;
bool jumped;
int sleep_time;
int prev_sleep_time;

void bhop_tick() {
	while (true) {
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && !player.in_air() && bhop_enabled) {
			if(legit_bhop_enabled) {
				sleep_time = rand() % 11 + 0;
				if (sleep_time == prev_sleep_time) {
					sleep_time = rand() % 11 + 0;
				}
				Sleep(sleep_time);
				prev_sleep_time = sleep_time;
			}
			SendMessage(window, WM_KEYDOWN, VK_SPACE, 0x390000);
			jumped = true;
		} else if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && player.in_air() && bhop_enabled) {
			SendMessage(window, WM_KEYUP, VK_SPACE, 0x390000);
			/**
			 * SMAC Bypass
			 */
			if (jumped) {
				Sleep(8);
				SendMessage(window, WM_KEYDOWN, VK_SPACE, 0x390000);
				Sleep(1);
				SendMessage(window, WM_KEYUP, VK_SPACE, 0x390000);
				jumped = false;
			}
		} else {
			Sleep(1);
		}
	}
}

void Bhop::start() {
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) bhop_tick, NULL, 0, NULL);
}

void Bhop::set_enabled(bool b) {
	bhop_enabled = b;
}

void Bhop::enable_legitbhop(bool b) {
	legit_bhop_enabled = b;
}

