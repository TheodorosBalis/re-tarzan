/* Address: 0x0049D5B0 */

void ReconfigureMainWindowAndMouseIfNeeded2(HWND param_1,int param_2,int param_3)

{
  HWND hWnd;
  int iVar1;
  int iVar2;
  HDC hDC;
  HBRUSH hbr;
  RECT local_20;
  RECT local_10;
  
  hWnd = param_1;
  if (DAT_0072371c != 0) {
    SetWindowLongA(param_1,-0x10,-0x70000000);
    SetWindowLongA(param_1,-0x14,8);
    iVar1 = GetSystemMetrics(1);
    if (iVar1 < param_3) {
      param_1 = (HWND)param_3;
    }
    else {
      param_1 = (HWND)GetSystemMetrics(1);
    }
    iVar2 = GetSystemMetrics(0);
    iVar1 = param_2;
    if (param_2 <= iVar2) {
      iVar1 = GetSystemMetrics(0);
    }
    SetWindowPos(hWnd,(HWND)0xffffffff,0,0,iVar1,(int)param_1,0x548);
    local_20.left = 0;
    local_20.top = 0;
    local_20.right = GetSystemMetrics(0);
    local_20.bottom = GetSystemMetrics(1);
    hDC = GetDC((HWND)0x0);
    hbr = GetStockObject(4);
    FillRect(hDC,&local_20,hbr);
    ReleaseDC((HWND)0x0,hDC);
    local_10.left = param_2 / 2;
    local_10.top = param_3 / 2;
    local_10.right = local_10.left;
    local_10.bottom = local_10.top;
    SetCursorPos(local_10.left,local_10.left);
    ClipCursor(&local_10);
    iVar1 = ShowCursor(0);
    while (-1 < iVar1) {
      iVar1 = ShowCursor(0);
    }
  }
  return;
}

