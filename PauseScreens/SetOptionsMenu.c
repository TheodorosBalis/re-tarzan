// Address: 0x0049E950

void SetOptionsMenu(int param_1)

{
  int iVar1;
  
  iVar1 = ResolveOptionsMenuHandlerById(param_1);
  if ((iVar1 != -1) && (param_1 != g_ActiveOptionsMenuId)) {
    bIsPaused = 1;
    g_PendingOptionsMenuId = param_1;
    g_ReturnOptionsMenuId = 0;
  }
  return;
}


