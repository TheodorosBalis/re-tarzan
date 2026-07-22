#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E360
// Label: ApplyKeyboardBindingsToInputMask
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ApplyKeyboardBindingsToInputMask(void)

{
  int value;
  
  value = IsControlBindingPressed(g_CfgKeyboardBindingUp);
  if (value != 0) {
    *(uint *)g_PolledInputUpMaskPtr = *(uint *)g_PolledInputUpMaskPtr | g_InputUpMask;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingDown);
  if (value != 0) {
    *(uint *)g_PolledInputDownMaskPtr = *(uint *)g_PolledInputDownMaskPtr | g_InputDownMask;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingLeft);
  if (value != 0) {
    *(uint *)g_PolledInputLeftMaskPtr = *(uint *)g_PolledInputLeftMaskPtr | g_InputLeftMask;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingRight);
  if (value != 0) {
    *(uint *)g_PolledInputRightMaskPtr = *(uint *)g_PolledInputRightMaskPtr | g_InputRightMask;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingAction0);
  if (value != 0) {
    *(uint *)g_PolledInputAction0MaskPtr = *(uint *)g_PolledInputAction0MaskPtr | g_InputAction0Mask
    ;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingAction1);
  if (value != 0) {
    *(uint *)g_PolledInputAction1MaskPtr = *(uint *)g_PolledInputAction1MaskPtr | g_InputAction1Mask
    ;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingAction2);
  if (value != 0) {
    *(uint *)g_PolledInputAction2MaskPtr =
         *(uint *)g_PolledInputAction2MaskPtr | (uint)g_InputAction2Mask;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingAction3);
  if (value != 0) {
    *(uint *)g_PolledInputAction3MaskPtr =
         *(uint *)g_PolledInputAction3MaskPtr | (uint)g_InputAction3Mask;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingAction4);
  if (value != 0) {
    *(uint *)g_PolledInputAction4MaskPtr = *(uint *)g_PolledInputAction4MaskPtr | g_InputAction4Mask
    ;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingAction5);
  if (value != 0) {
    *(uint *)g_PolledInputAction5MaskPtr = *(uint *)g_PolledInputAction5MaskPtr | g_InputAction5Mask
    ;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingAction6);
  if (value != 0) {
    *(uint *)g_PolledInputAction6MaskPtr = *(uint *)g_PolledInputAction6MaskPtr | g_InputAction6Mask
    ;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingAction7);
  if (value != 0) {
    *(uint *)g_PolledInputAction7MaskPtr = *(uint *)g_PolledInputAction7MaskPtr | g_InputAction7Mask
    ;
  }
  value = IsControlBindingPressed(g_CfgKeyboardBindingAction8);
  if (value != 0) {
    *(uint *)g_PolledInputAction8MaskPtr = *(uint *)g_PolledInputAction8MaskPtr | g_InputAction8Mask
    ;
  }
  return;
}

