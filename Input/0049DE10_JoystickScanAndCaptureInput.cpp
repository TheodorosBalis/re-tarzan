#include "tarzan_ghidra_types.hpp"

// Address: 0x0049DE10
// Label: JoystickScanAndCaptureInput
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JoystickScanAndCaptureInput(void)

{
  MMRESULT messageResult;
  int value;
  UINT uJoyID;
  tagJOYCAPSA *value2;
  joyinfo_tag localState2;
  tagJOYCAPSA localState;
  
  uJoyID = 0;
  g_JoystickDeviceCount = 0;
  do {
    (&g_JoystickPreviousButtonMaskByIndex)[uJoyID] = 0xffffffff;
    (&g_JoystickButtonCountByIndex)[uJoyID] = 0;
    messageResult = joyGetPos(uJoyID,&localState2);
    if (messageResult == 0) {
      value2 = &localState;
      for (value = 0x65; value != 0; value = value + -1) {
        value2->wMid = 0;
        value2->wPid = 0;
        value2 = (tagJOYCAPSA *)value2->szPname;
      }
      messageResult = joyGetDevCapsA(uJoyID,&localState,0x194);
      if (messageResult == 0) {
        (&g_JoystickYLowThresholdByIndex)[uJoyID] =
             (localState.wYmax * 0x21 + localState.wYmin * -0x21) / 100 + localState.wYmin;
        (&g_JoystickYHighThresholdByIndex)[uJoyID] =
             (localState.wYmax * 0x42 + localState.wYmin * -0x42) / 100 + localState.wYmin;
        (&g_JoystickXLowThresholdByIndex)[uJoyID] =
             (localState.wXmax * 0x21 + localState.wXmin * -0x21) / 100 + localState.wXmin;
        g_JoystickDeviceCount = g_JoystickDeviceCount + 1;
        (&g_JoystickXHighThresholdByIndex)[uJoyID] =
             (localState.wXmax * 0x42 + localState.wXmin * -0x42) / 100 + localState.wXmin;
        (&g_JoystickButtonCountByIndex)[uJoyID] = (undefined1)localState.wNumButtons;
      }
    }
    uJoyID = uJoyID + 1;
  } while ((int)uJoyID < 0x10);
  CaptureKInputsInBuffer();
  return;
}

