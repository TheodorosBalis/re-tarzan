#include "tarzan_ghidra_types.hpp"

// Address: 0x0049DF80
// Label: PollJoystickButtonEdgeFlags
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint PollJoystickButtonEdgeFlags(UINT arg1)

{
  uint stateFlags2;
  MMRESULT messageResult;
  uint *stateFlags;
  byte flagByte;
  int value;
  uint stateFlags3;
  joyinfoex_tag *value2;
  joyinfoex_tag localState;
  
  stateFlags3 = 0;
  if ((&g_JoystickButtonCountByIndex)[arg1] != '\0') {
    value2 = &localState;
    for (value = 0xd; value != 0; value = value + -1) {
      value2->dwSize = 0;
      value2 = (joyinfoex_tag *)&value2->dwFlags;
    }
    localState.dwSize = 0x34;
    localState.dwFlags = 0x483;
    messageResult = joyGetPosEx(arg1,&localState);
    if (messageResult == 0) {
      flagByte = 0;
      stateFlags = &DAT_00516290;
      do {
        if ((*stateFlags & localState.dwButtons) != 0) {
          stateFlags3 = stateFlags3 | 1 << (flagByte & 0x1f);
        }
        stateFlags = stateFlags + 1;
        flagByte = flagByte + 1;
      } while ((int)stateFlags < 0x516300);
      if (localState.dwXpos < (uint)(&g_JoystickXLowThresholdByIndex)[arg1]) {
        stateFlags3 = stateFlags3 | 0x10000000;
      }
      if ((uint)(&g_JoystickXHighThresholdByIndex)[arg1] < localState.dwXpos) {
        stateFlags3 = stateFlags3 | 0x20000000;
      }
      if (localState.dwYpos < (uint)(&g_JoystickYLowThresholdByIndex)[arg1]) {
        stateFlags3 = stateFlags3 | 0x40000000;
      }
      if ((uint)(&g_JoystickYHighThresholdByIndex)[arg1] < localState.dwYpos) {
        stateFlags3 = stateFlags3 | 0x80000000;
      }
      stateFlags2 = (&g_JoystickPreviousButtonMaskByIndex)[arg1];
      (&g_JoystickPreviousButtonMaskByIndex)[arg1] = stateFlags2 & stateFlags3;
      return ~(stateFlags2 & stateFlags3) & stateFlags3;
    }
  }
  return 0;
}

