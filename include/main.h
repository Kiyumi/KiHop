#include "player.h"
#include "longjump.h"
#include "bhop.h"
#include "util.h"

#ifndef MAIN_H_
#define MAIN_H_

namespace Main {
	extern Player player;
	extern Longjump longjump;
	extern Bunnyhop bhop;
	extern Util util;
	extern HWND window;
	extern DWORD pid;
	extern DWORD module_base;
	extern HANDLE process;
	extern DWORD player_base;
	extern DWORD mflags;
	extern bool lj_enabled;
	extern bool sw_lj_enabled;
	extern bool bhop_enabled;
	extern bool legit_bhop_enabled;
}

#endif
