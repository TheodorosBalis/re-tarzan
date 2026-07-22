#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E500
// Label: PollControlKeysOnlyInput
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void PollControlKeysOnlyInput(void)

{
  int value;
  uint value2;
  
  value = IsControlBindingPressed(0x26);
  if (value != 0) {
    *(uint *)g_PolledInputUpMaskPtr = *(uint *)g_PolledInputUpMaskPtr | g_InputUpMask;
  }
  value = IsControlBindingPressed(0x28);
  if (value != 0) {
    *(uint *)g_PolledInputDownMaskPtr = *(uint *)g_PolledInputDownMaskPtr | g_InputDownMask;
  }
  value = IsControlBindingPressed(0x25);
  if (value != 0) {
    *(uint *)g_PolledInputLeftMaskPtr = *(uint *)g_PolledInputLeftMaskPtr | g_InputLeftMask;
  }
  value = IsControlBindingPressed(0x27);
  if (value != 0) {
    *(uint *)g_PolledInputRightMaskPtr = *(uint *)g_PolledInputRightMaskPtr | g_InputRightMask;
  }
  value = IsControlBindingPressed(0x20);
  if (value != 0) {
    *(uint *)g_ControlKeysOnlyInputMask = *(uint *)g_ControlKeysOnlyInputMask | g_InputConfirmMask;
  }
  value = IsControlBindingPressed(0xd);
  if (value != 0) {
    *(uint *)g_ControlKeysOnlyInputMask = *(uint *)g_ControlKeysOnlyInputMask | g_InputConfirmMask;
  }
  value = IsControlBindingPressed(0x1b);
  if (value != 0) {
    *(uint *)g_PolledInputMaskPtr = *(uint *)g_PolledInputMaskPtr | g_InputCancelMask;
  }
  value2 = CheckForJoystickInputs(0);
  if ((value2 & 0x40000000) != 0) {
    *(uint *)g_PolledInputUpMaskPtr = *(uint *)g_PolledInputUpMaskPtr | g_InputUpMask;
  }
  if ((value2 & 0x80000000) != 0) {
    *(uint *)g_PolledInputDownMaskPtr = *(uint *)g_PolledInputDownMaskPtr | g_InputDownMask;
  }
  if ((value2 & 0x10000000) != 0) {
    *(uint *)g_PolledInputLeftMaskPtr = *(uint *)g_PolledInputLeftMaskPtr | g_InputLeftMask;
  }
  if ((value2 & 0x20000000) != 0) {
    *(uint *)g_PolledInputRightMaskPtr = *(uint *)g_PolledInputRightMaskPtr | g_InputRightMask;
  }
  if ((value2 & 0xfffffff) != 0) {
    *(uint *)g_ControlKeysOnlyInputMask = *(uint *)g_ControlKeysOnlyInputMask | g_InputConfirmMask;
  }
  return;
}

