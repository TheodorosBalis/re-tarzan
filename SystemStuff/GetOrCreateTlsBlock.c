// Address: 0x004B3704

DWORD * GetOrCreateTlsBlock(void)

{
  DWORD dwErrCode;
  DWORD *lpTlsValue;
  BOOL BVar1;
  DWORD DVar2;
  
  dwErrCode = GetLastError();
  lpTlsValue = TlsGetValue(TlsIndex);
  if (lpTlsValue == (DWORD *)0x0) {
    lpTlsValue = (DWORD *)SafelyMemAlloc(1,0x74);
    if (lpTlsValue != (DWORD *)0x0) {
      BVar1 = TlsSetValue(TlsIndex,lpTlsValue);
      if (BVar1 != 0) {
        SetValueInHeap(lpTlsValue);
        DVar2 = GetCurrentThreadId();
        lpTlsValue[1] = 0xffffffff;
        *lpTlsValue = DVar2;
        goto LAB_004b375f;
      }
    }
    __amsg_exit(0x10);
  }
LAB_004b375f:
  SetLastError(dwErrCode);
  return lpTlsValue;
}


