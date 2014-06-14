#include <windows.h>

#ifndef UTIL_H_
#define UTIL_H_

class Util {
	public:
		int move_mouse(int x, int y);
		int send_key(unsigned short key_code, bool key_down);
		DWORD get_module_base_extern(const DWORD dw_process_id, const char *sz_module_name);
};

#endif
