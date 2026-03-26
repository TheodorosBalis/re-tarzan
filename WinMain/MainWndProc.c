// Address: 0x004AE400

LRESULT MainWndProc(HWND param_1,uint param_2,uint param_3,LPARAM param_4)

{
  int iVar1;
  HDC hDC;
  HBRUSH hbr;
  HWND pHVar2;
  uint uVar3;
  LRESULT LVar4;
  tagRECT tStack_50;
  tagPAINTSTRUCT tStack_40;
  
  if (param_2 < 0xa2) {
    if (param_2 == 0xa1) {
switchD_004ae630_caseD_a4:
      g_MainWindowMessagePulseCount = g_MainWindowMessagePulseCount + 1;
      SetActiveBitmapSlot(5);
      SetIsWindowActive();
      LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
      return LVar4;
    }
    switch(param_2) {
    case 2:
      if (param_1 == mainWindowHandle) {
        PostQuitMessage(0);
        return 0;
      }
      break;
    case 5:
      iVar1 = VerifyGraphicsMode();
      if (iVar1 != 0) {
        g_IsMainWindowMinimized = 0;
        LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
        return LVar4;
      }
      GetClientRect(mainWindowHandle,&tStack_50);
      if ((1 < tStack_50.right - tStack_50.left) && (1 < tStack_50.bottom - tStack_50.top)) {
        g_IsMainWindowMinimized = 0;
        return 0;
      }
      g_IsMainWindowMinimized = 1;
      SetActiveBitmapSlot(5);
      return 0;
    case 0xf:
      BeginPaint(param_1,&tStack_40);
      if (param_1 == mainWindowHandle) {
        iVar1 = CurrentGraphicsMode();
        if (iVar1 == 0) {
          if (param_1 != (HWND)0x0) {
            hDC = GetDC(param_1);
            GetClientRect(param_1,&tStack_50);
            hbr = GetStockObject(4);
            FillRect(hDC,&tStack_50,hbr);
            ReleaseDC(param_1,hDC);
            EndPaint(param_1,&tStack_40);
            return 0;
          }
        }
        else {
          ShowFrameOnScreen();
        }
      }
      EndPaint(param_1,&tStack_40);
      return 0;
    case 0x14:
      return 1;
    case 0x1c:
      CaptureKInputsInBuffer();
      g_MainWindowActivationState = (param_3 != 0) + 1;
      if (g_MainWindowActivationState != 2) {
        SetActiveBitmapSlot(5);
      }
      pHVar2 = GetActiveWindow();
      if (mainWindowHandle == pHVar2) {
        g_MainWindowActivationState = 2;
        return 0;
      }
      return 0;
    case 0x20:
      iVar1 = VerifyGraphicsMode();
      if (iVar1 != 0) {
        SetCursor((HCURSOR)0x0);
        return 1;
      }
      break;
    case 0x7e:
      g_MainWindowMessagePulseCount = g_MainWindowMessagePulseCount + 1;
      IsDisplayOptionSupported = CheckDisplayCapabilities();
      return 0;
    }
  }
  else if (param_2 < 0x108) {
    if (0x105 < param_2) {
switchD_004ae630_caseD_100:
      return 0;
    }
    switch(param_2) {
    case 0xa4:
    case 0xa7:
      goto switchD_004ae630_caseD_a4;
    case 0x100:
    case 0x101:
    case 0x102:
    case 0x103:
      goto switchD_004ae630_caseD_100;
    case 0x104:
    case 0x105:
      if (param_3 != 0x73) {
        return 0;
      }
    }
  }
  else if (param_2 == 0x112) {
    uVar3 = param_3 & 0xfff0;
    if (uVar3 == 0xf030) {
      g_MainWindowMessagePulseCount = g_MainWindowMessagePulseCount + 1;
      SetActiveBitmapSlot(7);
      return 0;
    }
    if (uVar3 == 0xf140) {
      return 0;
    }
    if (uVar3 == 0xf170) {
      return 0;
    }
  }
  else {
    if (param_2 == 0x116) goto switchD_004ae630_caseD_a4;
    if ((param_2 == 0x219) && (param_3 == 0x8000)) {
      HandleDeviceArrivalForECM();
      LVar4 = DefWindowProcA(param_1,0x219,0x8000,param_4);
      return LVar4;
    }
  }
  LVar4 = DefWindowProcA(param_1,param_2,param_3,param_4);
  return LVar4;
}


