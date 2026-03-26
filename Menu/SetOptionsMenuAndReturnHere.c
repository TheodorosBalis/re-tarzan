// Address: 0x004A1440

void SetOptionsMenuAndReturnHere(int param_1)

{
  int iVar1;
  
  iVar1 = ResolveOptionsMenuHandlerById(param_1);
  if ((iVar1 != -1) && (param_1 != g_ActiveOptionsMenuId)) {
    bIsPaused = 1;
    g_PendingOptionsMenuId = param_1;
    g_ReturnOptionsMenuId = g_ActiveOptionsMenuId;
  }
  return;
}


