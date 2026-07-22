#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE400
// Label: MainWndProc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

LRESULT MainWndProc(HWND windowHandle,uint messageId,uint wParam,LPARAM lParam)

{
  int value2;
  HDC hDC;
  HBRUSH hbr;
  HWND value4;
  uint value3;
  LRESULT value;
  tagRECT localState2;
  tagPAINTSTRUCT localState;
  
  if (messageId < 0xa2) {
    if (messageId == 0xa1) {
switchD_004ae630_caseD_a4:
      g_MainWindowMessagePulseCount = g_MainWindowMessagePulseCount + 1;
      RequestGraphicsModeChange(5);
      UpdateMainWindowActiveState();
      value = DefWindowProcA(windowHandle,messageId,wParam,lParam);
      return value;
    }
    switch(messageId) {
    case 2:
      if (windowHandle == mainWindowHandle) {
        PostQuitMessage(0);
        return 0;
      }
      break;
    case 5:
      value2 = VerifyGraphicsMode();
      if (value2 != 0) {
        g_IsMainWindowMinimized = 0;
        value = DefWindowProcA(windowHandle,messageId,wParam,lParam);
        return value;
      }
      GetClientRect(mainWindowHandle,&localState2);
      if ((1 < localState2.right - localState2.left) && (1 < localState2.bottom - localState2.top)) {
        g_IsMainWindowMinimized = 0;
        return 0;
      }
      g_IsMainWindowMinimized = 1;
      RequestGraphicsModeChange(5);
      return 0;
    case 0xf:
      BeginPaint(windowHandle,&localState);
      if (windowHandle == mainWindowHandle) {
        value2 = CurrentGraphicsMode();
        if (value2 == 0) {
          if (windowHandle != (HWND)0x0) {
            hDC = GetDC(windowHandle);
            GetClientRect(windowHandle,&localState2);
            hbr = GetStockObject(4);
            FillRect(hDC,&localState2,hbr);
            ReleaseDC(windowHandle,hDC);
            EndPaint(windowHandle,&localState);
            return 0;
          }
        }
        else {
          ShowFrameOnScreen();
        }
      }
      EndPaint(windowHandle,&localState);
      return 0;
    case 0x14:
      return 1;
    case 0x1c:
      CaptureKInputsInBuffer();
      g_MainWindowActivationState = (wParam != 0) + 1;
      if (g_MainWindowActivationState != 2) {
        RequestGraphicsModeChange(5);
      }
      value4 = GetActiveWindow();
      if (mainWindowHandle == value4) {
        g_MainWindowActivationState = 2;
        return 0;
      }
      return 0;
    case 0x20:
      value2 = VerifyGraphicsMode();
      if (value2 != 0) {
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
  else if (messageId < 0x108) {
    if (0x105 < messageId) {
switchD_004ae630_caseD_100:
      return 0;
    }
    switch(messageId) {
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
      if (wParam != 0x73) {
        return 0;
      }
    }
  }
  else if (messageId == 0x112) {
    value3 = wParam & 0xfff0;
    if (value3 == 0xf030) {
      g_MainWindowMessagePulseCount = g_MainWindowMessagePulseCount + 1;
      RequestGraphicsModeChange(7);
      return 0;
    }
    if (value3 == 0xf140) {
      return 0;
    }
    if (value3 == 0xf170) {
      return 0;
    }
  }
  else {
    if (messageId == 0x116) goto switchD_004ae630_caseD_a4;
    if ((messageId == 0x219) && (wParam == 0x8000)) {
      ResumeBackgroundMusicAfterDeviceArrival();
      value = DefWindowProcA(windowHandle,0x219,0x8000,lParam);
      return value;
    }
  }
  value = DefWindowProcA(windowHandle,messageId,wParam,lParam);
  return value;
}

