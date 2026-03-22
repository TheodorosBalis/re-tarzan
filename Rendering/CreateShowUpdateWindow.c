/* Address: 0x004AE830 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CreateShowUpdateWindow(int param_1)

{
  ATOM AVar1;
  DWORD DVar2;
  int iVar3;
  HMODULE hInstance;
  int iVar4;
  int Y;
  undefined4 *puVar5;
  LPVOID lpParam;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  DVar2 = timeGetTime();
  GetOrCreateTlsBlock_stub(DVar2);
  DAT_00c46c38 = SetWindowsHookExA(2,(HOOKPROC)&LAB_004ae9e0,(HINSTANCE)0x0,0);
  puVar5 = &DAT_00c46c00;
  for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  DAT_00c46c00 = 0x102b;
  DAT_00c46c04 = &MainWndProc;
  _DAT_00c46c10 = GetModuleHandleA((LPCSTR)0x0);
  _DAT_00c46c14 = LoadIconA(_DAT_00c46c10,(LPCSTR)0x80);
  _DAT_00c46c18 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  _DAT_00c46c1c = GetStockObject(4);
  _DAT_00c46c24 = s_DITARZANAG_00518e60;
  AVar1 = RegisterClassA((WNDCLASSA *)&DAT_00c46c00);
  if (AVar1 == 0) {
    InternalError(s_Win_Init_1__00518e54);
  }
  iVar4 = SetWindowWidth();
  iVar4 = iVar4 + DAT_00c46c28;
  iVar3 = SetWindowHeight();
  iVar3 = iVar3 + DAT_00c46c2c;
  SystemParametersInfoA(0x30,0,&local_10,0);
  if (iVar4 < local_8 - local_10) {
    local_10 = ((local_8 - local_10) - iVar4) / 2 + local_10;
  }
  Y = local_c;
  if (iVar3 < local_4 - local_c) {
    Y = ((local_4 - local_c) - iVar3) / 2 + local_c;
  }
  lpParam = (LPVOID)0x0;
  hInstance = GetModuleHandleA((LPCSTR)0x0);
  mainWindowHandle =
       CreateWindowExA(0x300,s_DITARZANAG_00518e60,s_Tarzan_Action_Game_00518e10,0xcb0000,local_10,Y
                       ,iVar4,iVar3,(HWND)0x0,(HMENU)0x0,hInstance,lpParam);
  if (mainWindowHandle == (HWND)0x0) {
    InternalError(s_Win_Init_2__00518e48);
  }
  ShowWindow(mainWindowHandle,param_1);
  ShowWindow(mainWindowHandle,10);
  UpdateWindow(mainWindowHandle);
  IsDisplayOptionSupported = CheckDisplayCapabilities();
  return;
}

