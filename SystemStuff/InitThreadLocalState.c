// Address: 0x004B369D

undefined4 InitThreadLocalState(void)

{
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  InitCSfor3Globals();
  TlsIndex = TlsAlloc();
  if (TlsIndex != 0xffffffff) {
    lpTlsValue = (DWORD *)SafelyMemAlloc(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(TlsIndex,lpTlsValue);
      if (BVar1 != 0) {
        SetValueInHeap(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        return 1;
      }
    }
  }
  return 0;
}


