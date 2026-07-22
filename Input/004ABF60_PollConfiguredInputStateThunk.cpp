#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABF60
// Label: PollConfiguredInputStateThunk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 PollConfiguredInputStateThunk(void)

{
  int value;
  
  g_PolledInputMask = 0;
  if (bGameInitSuccess != 0) {
    value = IsGamePaused();
    if (value == 0) {
      if (g_ControlKeysOnlyMode == 0) {
        ApplyKeyboardBindingsToInputMask(0);
        ApplyJoystickBindingsToInputMask(0);
      }
      else {
        PollControlKeysOnlyInput();
      }
    }
  }
  if ((*(uint *)g_PolledInputUpMaskPtr & g_InputUpMask) != 0) {
    *(uint *)g_PolledInputDownMaskPtr = *(uint *)g_PolledInputDownMaskPtr & ~g_InputDownMask;
  }
  if ((*(uint *)g_PolledInputLeftMaskPtr & g_InputLeftMask) != 0) {
    *(uint *)g_PolledInputRightMaskPtr = *(uint *)g_PolledInputRightMaskPtr & ~g_InputRightMask;
  }
  return g_PolledInputMask;
}

