#include <windows.h>
#include <iostream>
#include <Lmcons.h>

std::string get_username()
{
	TCHAR username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);
	std::wstring username_w(username);
	std::string username_s(username_w.begin(), username_w.end());
	return username_s;
}

int main(int argc, char** argv)
{
	// Printing Curent User
	printf("[+] Current user is: %s\n", (get_username()).c_str());

	// Grab PID from command line argument
	char *pid_c = argv[1];
	DWORD PID = atoi(pid_c);
	// Call OpenProcess(), print return code and error code
	HANDLE processHandle = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, true, PID);
	if (GetLastError() == NULL)
		printf("[+] OpenProcess() success!\n");
	else
	{
		printf("[-] OpenProcess() Return Code: %i\n", processHandle);
		printf("[-] OpenProcess() Error: %i\n", GetLastError());
	}

	return 0;
}