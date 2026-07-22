#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE830
// Label: CreateShowUpdateWindow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CreateShowUpdateWindow(int windowHandle)

{
  ATOM value;
  DWORD apiResult;
  int value2;
  HMODULE hInstance;
  int value3;
  int Y;
  undefined4 *dataCursor;
  LPVOID lpParam;
  int scratchRect;
  int scratchRect4;
  int scratchRect3;
  int scratchRect2;
  
  apiResult = timeGetTime();
  srand(apiResult);
  g_InstalledWindowsHook = (int)SetWindowsHookExA(2,WindowsCallWndHook_ReturnZero,(HINSTANCE)0x0,0);
  dataCursor = &g_MainWindowClass_Field0000;
  for (value3 = 10; value3 != 0; value3 = value3 + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  g_MainWindowClass_Field0000 = 0x102b;
  g_MainWindowClass_Field0004 = (int)MainWndProc;
  _g_MainWindowClass_Field0010 = (int)GetModuleHandleA((LPCSTR)0x0);
  _g_MainWindowClass_Field0014 = (int)LoadIconA((HINSTANCE)_g_MainWindowClass_Field0010,(LPCSTR)0x80);
  _g_MainWindowClass_Field0018 = (int)LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  _g_MainWindowClass_Field001C = (int)GetStockObject(4);
  _g_MainWindowClass_Field0024 = (int)s_DITARZANAG_00518e60;
  value = RegisterClassA((WNDCLASSA *)&g_MainWindowClass_Field0000);
  if (value == 0) {
    InternalError(s_Win_Init_1__00518e54);
  }
  value3 = GetSoftwareFrameBufferWidth();
  value3 = value3 + g_WindowFrameExtraWidth;
  value2 = GetSoftwareFrameBufferHeight();
  value2 = value2 + g_WindowFrameExtraHeight;
  SystemParametersInfoA(0x30,0,&scratchRect,0);
  if (value3 < scratchRect3 - scratchRect) {
    scratchRect = ((scratchRect3 - scratchRect) - value3) / 2 + scratchRect;
  }
  Y = scratchRect4;
  if (value2 < scratchRect2 - scratchRect4) {
    Y = ((scratchRect2 - scratchRect4) - value2) / 2 + scratchRect4;
  }
  lpParam = (LPVOID)0x0;
  hInstance = GetModuleHandleA((LPCSTR)0x0);
  mainWindowHandle =
       (int)CreateWindowExA(0x300,s_DITARZANAG_00518e60,s_Tarzan_Action_Game_00518e10,0xcb0000,scratchRect,Y
                            ,value3,value2,(HWND)0x0,(HMENU)0x0,hInstance,lpParam);
  if ((HWND)mainWindowHandle == (HWND)0x0) {
    InternalError(s_Win_Init_2__00518e48);
  }
  ShowWindow(mainWindowHandle,windowHandle);
  ShowWindow(mainWindowHandle,10);
  UpdateWindow(mainWindowHandle);
  IsDisplayOptionSupported = CheckDisplayCapabilities();
  return;
}

