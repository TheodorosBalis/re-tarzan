#include "tarzan_ghidra_types.hpp"

// Address: 0x004AECB0
// Label: WinMessageLoop
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WinMessageLoop(void)

{
  char resultFlag;
  BOOL value;
  int value2;
  DWORD apiResult;
  int value3;
  uint value4;
  uint value5;
  undefined4 *dataCursor;
  char *stringCursor2;
  char *stringCursor;
  tagPOINT localState4;
  int localState3;
  tagMSG localState2;
  char localState;
  undefined4 localState5;
  
  do {
    g_MainWindowMessagePulseCount = 0;
    localState3 = 0;
    do {
      value = PeekMessageA(&localState2,(HWND)0x0,0,0,0);
      if (value == 0) break;
      value = GetMessageA(&localState2,(HWND)0x0,0,0);
      if (value == 0) {
        ExitIfFailed2();
      }
      TranslateMessage(&localState2);
      DispatchMessageA(&localState2);
      localState3 = localState3 + 1;
    } while (localState3 < 0x14);
    if (g_MainWindowActivationState == 1) {
      g_MainWindowActivationState = 0;
    }
    IsPauseOptionsMenuRequested();
    value2 = HasPendingGraphicsModeChange();
    if (value2 != 0) {
      PauseAudioLinePlayback();
      StopActiveStreamedWork();
    }
    ApplyRequestedGraphicsModeWithFallback();
    value2 = ConsumeGraphicsModeFailure(&localState3);
    if (value2 != 0) {
      localState = g_MessageLoopWaitCursorState;
      dataCursor = &localState5;
      for (value3 = 0x3f; value3 != 0; value3 = value3 + -1) {
        *dataCursor = 0;
        dataCursor = dataCursor + 1;
      }
      *(undefined2 *)dataCursor = 0;
      *(undefined1 *)((int)dataCursor + 2) = 0;
      switch(localState3) {
      case 1:
        value4 = 0xffffffff;
        stringCursor = s_COMPATIBLE_CARD_NOT_FOUND_00518f6c;
        do {
          stringCursor2 = stringCursor;
          if (value4 == 0) break;
          value4 = value4 - 1;
          stringCursor2 = stringCursor + 1;
          resultFlag = *stringCursor;
          stringCursor = stringCursor2;
        } while (resultFlag != '\0');
        value4 = ~value4;
        stringCursor2 = stringCursor2 + -value4;
        break;
      case 2:
        value4 = 0xffffffff;
        stringCursor = s_CARD_NOT_SUITABLE_00518f58;
        do {
          stringCursor2 = stringCursor;
          if (value4 == 0) break;
          value4 = value4 - 1;
          stringCursor2 = stringCursor + 1;
          resultFlag = *stringCursor;
          stringCursor = stringCursor2;
        } while (resultFlag != '\0');
        value4 = ~value4;
        stringCursor2 = stringCursor2 + -value4;
        break;
      case 3:
        value4 = 0xffffffff;
        stringCursor = s_FAILED_TO_SETUP_CARD_00518f40;
        do {
          stringCursor2 = stringCursor;
          if (value4 == 0) break;
          value4 = value4 - 1;
          stringCursor2 = stringCursor + 1;
          resultFlag = *stringCursor;
          stringCursor = stringCursor2;
        } while (resultFlag != '\0');
        value4 = ~value4;
        stringCursor2 = stringCursor2 + -value4;
        break;
      case 4:
        value4 = 0xffffffff;
        stringCursor = s_IT_CONFLICTS_WITH_A_PREVIOUS_MOD_00518f1c;
        do {
          stringCursor2 = stringCursor;
          if (value4 == 0) break;
          value4 = value4 - 1;
          stringCursor2 = stringCursor + 1;
          resultFlag = *stringCursor;
          stringCursor = stringCursor2;
        } while (resultFlag != '\0');
        value4 = ~value4;
        stringCursor2 = stringCursor2 + -value4;
        break;
      default:
        goto switchD_004aed82_default;
      }
      localState4.x = (LONG)&localState;
      stringCursor = (char *)localState4.x;
      for (value5 = value4 >> 2; value5 != 0; value5 = value5 - 1) {
        *(undefined4 *)stringCursor = *(undefined4 *)stringCursor2;
        stringCursor2 = stringCursor2 + 4;
        stringCursor = stringCursor + 4;
      }
      for (value4 = value4 & 3; value4 != 0; value4 = value4 - 1) {
        *stringCursor = *stringCursor2;
        stringCursor2 = stringCursor2 + 1;
        stringCursor = stringCursor + 1;
      }
switchD_004aed82_default:
      switch(value2) {
      case 1:
        if (g_ActiveStreamedWorkHandle == 0) {
          stringCursor = s_GLIDE_3D_NOT_AVAILABLE_00518f04;
LAB_004aee78:
          ShowTwoLineOptionsMessage(stringCursor,&localState);
        }
        break;
      case 2:
        if (g_ActiveStreamedWorkHandle == 0) {
          stringCursor = s_DIRECT3D_NOT_AVAILABLE_00518eec;
          goto LAB_004aee78;
        }
        break;
      case 3:
        if (g_ActiveStreamedWorkHandle == 0) {
          stringCursor = s_DDRAW_LOW_RES_NOT_AVAILABLE_00518ed0;
          goto LAB_004aee78;
        }
        break;
      case 4:
        if (g_ActiveStreamedWorkHandle == 0) {
          stringCursor = s_DDRAW_HIGH_RES_NOT_AVAILABLE_00518eb0;
          goto LAB_004aee78;
        }
      }
    }
    UpdateMainWindowActiveState();
    if ((g_MainWindowActivationState == 0) || (g_IsMainWindowMinimized != 0)) {
      WaitMessage();
    }
    if (((g_MainWindowActivationState != 0) && (g_IsMainWindowMinimized == 0)) &&
       (g_MainWindowMessagePulseCount == 0)) {
      value2 = VerifyGraphicsMode();
      if ((value2 != 0) && (apiResult = timeGetTime(), g_NextCursorKeepaliveTickMs < apiResult)) {
        GetCursorPos(&localState4);
        SetCursorPos(localState4.x,localState4.y);
        g_NextCursorKeepaliveTickMs = apiResult + 5000;
      }
      return;
    }
  } while( true );
}

