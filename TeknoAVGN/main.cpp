#include <windows.h>
	char        szAppPath[MAX_PATH] = "";
	char		path[MAX_PATH] = "";
	char cock[512];
	DWORD len = 0;
	DWORD DowStart = 0;
	DWORD Xlive = 0;
	HANDLE threadi;
#define RoundBy1000(a) (a / 0x1000 + ((a % 0x1000) > 0 ? 1 : 0)) * 0x1000
#define DLL __declspec(dllexport)
extern "C" void __declspec() DLL _x();
int main();
void main2();
DWORD WINAPI TehThread(__in  LPVOID lpParameter);
DWORD WINAPI Thredi(__in  LPVOID lpParameter);
void lowercase(char string[]);
bool IsDow2 = false;
DWORD returnmessage = 0;

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
         // Initialize once for each new process.
         // Return FALSE to fail DLL load.
			return main();
            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
         // Perform any necessary cleanup.
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

int main()
{
	memset(cock,512,0xFA);
	main2();
	return returnmessage;
}
void main2()
{
	len = GetModuleFileName(0, szAppPath, MAX_PATH);
	lowercase(szAppPath);
	for(int i = 0; i < 260; i++)
	{
		if(szAppPath[i] == 0)
		{
			if(strcmp(szAppPath+i-8,"avgn.exe") == 0)
			{
				IsDow2 = true;
				break;
			}
			else { returnmessage = 0; return; }
		}
	}
	DWORD MyCheck = (DWORD)GetProcAddress(GetModuleHandle("TeknoAVGN.dll"), "_x");
	if(MyCheck == NULL || MyCheck == -1) ExitProcess(0);
	else CreateThread(0,0,TehThread,0,0,0);
	CreateThread(0,0,Thredi,0,0,0);
	returnmessage = 1;
}
void __declspec(naked) _x()
{


}

DWORD WINAPI Thredi(__in  LPVOID lpParameter)
{
   //DWORD func;
   //func = 0x004A7450;
   //__asm
   //{
	  // call func
   //}
   return 1;
}
int filter(unsigned int code, struct _EXCEPTION_POINTERS *ep) {
	return EXCEPTION_EXECUTE_HANDLER;
}
void setval(DWORD address, DWORD value)
{
	__try
	{
		if(IsBadReadPtr(&address,4) == 0)
		{
			*(DWORD*)address = value;
		}
	}
	__except ( filter(GetExceptionCode(),  GetExceptionInformation()))
	{
		return;
	}
	return;
}

DWORD WINAPI TehThread(__in  LPVOID lpParameter)
{
	DWORD location1 = 0;
	DWORD location2 = 0;
	bool supergun = false;
	bool infinitebeers = false;
	bool foundspot = false;
	bool invul = false;
	DWORD baseptr = 0;
	DWORD baseptr2 = 0;
	DWORD bb2 = 0;
	DWORD beerptr = 0;
	DWORD levelptr = 0;

	Sleep(5000);
	while(1)
	{
			// Get base+size
			DWORD msys = (DWORD)GetModuleHandle(NULL);
			DWORD msysPE = msys + 0x3C;
			msysPE = *(DWORD *)msysPE;
			msysPE += msys + 0x100;
			DWORD TextSize = RoundBy1000(*(DWORD *)msysPE);
			msysPE+= 4;
			DWORD TextStart = msys + *(DWORD *)msysPE;

			for(int i = 0; i < TextSize; i++)
			{
				if(*(WORD *)(TextStart + i) == 0x0D8B)
					if(*(DWORD *)(TextStart + i + 6) == 0xF08B5157)
						if(*(BYTE *)(TextStart + i + 10) == 0xE8)
						{
							location1 = *(DWORD*)(TextStart + i + 2);
							location2 = location1 + 8;
							foundspot = true;
						}
			}
			if(foundspot) break;
		Sleep(1000);
	}

	while(1)
	{
		__try
		{
			baseptr = (*(DWORD*)((*(DWORD*)location1) + 0x268)) + 0xA0;
			levelptr = (*(DWORD*)((*(DWORD*)location1) + 0x268)) + 0x38;
			baseptr2 = *(DWORD*)((*(DWORD*)((*(DWORD*)location2) + 0x1278)) + (0xE6*8));
			if(baseptr2 != 0)
			{
				bb2 = *(DWORD*)(baseptr2 + 0x242) + 0x58;
			}
			beerptr = (*(DWORD*)((*(DWORD*)location1) + 0x258));
		}
		__except ( filter(GetExceptionCode(),  GetExceptionInformation()))
		{
			beerptr = 0;
			baseptr = 0;
			baseptr2 = 0;
			bb2 = 0;
		}
		
		if(supergun)
		{
			if(baseptr != 0)
				setval(baseptr + 0xF8, 0x00000001);
		}
		if(infinitebeers)
		{
			if(beerptr != 0)
				setval(beerptr, 0xFEFFFFFF);
		}
		if(invul)
		{
			//*(DWORD*)bb2 = 0x00000080;
			if(baseptr2 != 0)
			{
				setval(bb2, 0x00000080);
			}
		}
		// Super GUN
		if(GetAsyncKeyState(VK_F3) < 0)
		{
			if(supergun)
				supergun = false;
			else
				supergun = true;
			Sleep(1000);
		}

		// Lives
		if(GetAsyncKeyState(VK_F4) < 0)
		{
			if(baseptr != 0)
				setval(baseptr + 0x08, 0x000003E7);
		}
		// Beers
		if(GetAsyncKeyState(VK_F5) < 0)
		{
			if(infinitebeers)
				infinitebeers = false;
			else
				infinitebeers = true;
			Sleep(1000);
		}
		// Mega Death Christ
		if(GetAsyncKeyState(VK_F6) < 0)
		{
			if(baseptr != 0)
			{
				setval(((baseptr + 0x88) - 0xB0), 0x00000063);
				setval(baseptr + 0x88, 0x00000001);
			}
		}
		// Balls
		if(GetAsyncKeyState(VK_F7) < 0)
		{
			if(baseptr != 0)
			{
				setval(((baseptr + 0x88) - 0xB0), 0x00000063);
				setval(baseptr + 0x88, 0x00000002);
			}
		}
		// Glitch Demon
		if(GetAsyncKeyState(VK_F8) < 0)
		{
			if(baseptr != 0)
			{
				setval(((baseptr + 0x88) - 0xB0), 0x00000063);
				setval(baseptr + 0x88, 0x00000003);
			}
		}
		// Invunerability
		if(GetAsyncKeyState(VK_F9) < 0)
		{
			if(invul)
				invul = false;
			else
				invul = true;
		}
		if(GetAsyncKeyState(VK_F10) < 0)
		{
			if(baseptr != 0)
			{
				setval(levelptr, 0x00000014);
			}
		}
		Sleep(300);
	}
	return 1;
}

void lowercase(char string[])
{
   int  i = 0;

   while ( string[i] )
   {
      string[i] = tolower(string[i]);
      i++;
   }

   return;
}