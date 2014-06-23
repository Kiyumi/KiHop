#include "../include/main.h"

using namespace Main;

bool jumped;

void bhop_tick() {
	while (true) {
		if (bhop_enabled) {
			if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && !player.in_air()) {
				if (legit_bhop_enabled) {
					Sleep(rand() % 10 + 0);
				}
				SendMessage(window, WM_KEYDOWN, VK_SPACE, 0x390000);
				jumped = true;
			} else if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && player.in_air()) {
				SendMessage(window, WM_KEYUP, VK_SPACE, 0x390000);
				/**
				 * SMAC Bypass
				 */
				if (jumped) {
					Sleep(16);
					SendMessage(window, WM_KEYDOWN, VK_SPACE, 0x390000);
					SendMessage(window, WM_KEYUP, VK_SPACE, 0x390000);
					jumped = false;
				}
			} else {
				Sleep(1);
			}
		} else {
			Sleep(1);
		}
	}
}

void Bunnyhop::start() {
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) bhop_tick, NULL, 0, NULL);
}

