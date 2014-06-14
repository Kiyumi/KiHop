#include "../include/util.h"
#include <ctime>
#include <Tlhelp32.h>

int Util::move_mouse(int x, int y) {
	INPUT input = { 0 };
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	input.mi.dx += x;
	input.mi.dy += y;
	return SendInput(1, &input, sizeof(INPUT));
}

int Util::send_key(unsigned short int key_code, bool key_down) {
	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan = key_code;
	input.ki.time = time(NULL);
	input.ki.dwExtraInfo = 0;
	if (key_down) {
		input.ki.dwFlags = KEYEVENTF_SCANCODE;
	} else {
		input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	}
	return SendInput(1, &input, sizeof(input));
}

DWORD Util::get_module_base_extern(const DWORD dw_process_id, const char *sz_module_name) {
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dw_process_id);
	if (!snap) {
		return 0;
	}
	MODULEENTRY32 module_entry;
	module_entry.dwSize = sizeof(MODULEENTRY32);
	DWORD dw_return = 0;
	if (Module32First(snap, &module_entry)) {
		while (Module32Next(snap, &module_entry)) {
			if (lstrcmpi(module_entry.szModule, sz_module_name) == 0) {
				dw_return = (DWORD) module_entry.modBaseAddr;
				break;
			}
		}
	}
	CloseHandle(snap);
	return dw_return;
}

