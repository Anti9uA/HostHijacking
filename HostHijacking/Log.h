#pragma once

// #include "stdafx.h"
#include <Windows.h>
#include <Shlobj.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <winerror.h>
#include <Shlobj.h>
#include <atlstr.h>		// to use CString

class CLog
{
public:
	CLog(void)
	{
	}

	static void WriteError(const char* message)
	{
		printf("%s(errorcode=%d, %s:%d)\n", message, GetLastError(), __FILE__, __LINE__);
	}

	static void WriteError(const char* message, const char* parameter)
	{
		printf("%s, %s(errorcode=%d, %s:%d)\n", message, parameter, GetLastError(), __FILE__, __LINE__);
	}
};
