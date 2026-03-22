/* Address: 0x004A4BC0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ShowFrameAndUpdateAppTime(void)

{
  DWORD DVar1;
  
  ShowFrameOnScreen();
  DVar1 = timeGetTime();
  _appUpTime = _appUpTime + DVar1;
  return;
}

