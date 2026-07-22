#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E1B0
// Label: ApplyJoystickBindingsToInputMask
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ApplyJoystickBindingsToInputMask(undefined4 arg1)

{
  uint mask;
  
  mask = CheckForJoystickInputs(arg1);
  if (mask != 0) {
    if ((mask & 0x40000000) != 0) {
      *(uint *)g_PolledInputUpMaskPtr = *(uint *)g_PolledInputUpMaskPtr | g_InputUpMask;
    }
    if ((mask & 0x80000000) != 0) {
      *(uint *)g_PolledInputDownMaskPtr = *(uint *)g_PolledInputDownMaskPtr | g_InputDownMask;
    }
    if ((mask & 0x10000000) != 0) {
      *(uint *)g_PolledInputLeftMaskPtr = *(uint *)g_PolledInputLeftMaskPtr | g_InputLeftMask;
    }
    if ((mask & 0x20000000) != 0) {
      *(uint *)g_PolledInputRightMaskPtr = *(uint *)g_PolledInputRightMaskPtr | g_InputRightMask;
    }
    if ((g_CfgJoystickBindingAction0 != 0) &&
       ((mask & 1 << ((char)g_CfgJoystickBindingAction0 - 1U & 0x1f)) != 0)) {
      *(uint *)g_PolledInputAction0MaskPtr =
           *(uint *)g_PolledInputAction0MaskPtr | g_InputAction0Mask;
    }
    if ((g_CfgJoystickBindingAction1 != 0) &&
       ((mask & 1 << ((char)g_CfgJoystickBindingAction1 - 1U & 0x1f)) != 0)) {
      *(uint *)g_PolledInputAction1MaskPtr =
           *(uint *)g_PolledInputAction1MaskPtr | g_InputAction1Mask;
    }
    if ((g_CfgJoystickBindingAction2 != 0) &&
       ((mask & 1 << ((char)g_CfgJoystickBindingAction2 - 1U & 0x1f)) != 0)) {
      *(uint *)g_PolledInputAction2MaskPtr =
           *(uint *)g_PolledInputAction2MaskPtr | (uint)g_InputAction2Mask;
    }
    if ((g_CfgJoystickBindingAction3 != 0) &&
       ((mask & 1 << ((char)g_CfgJoystickBindingAction3 - 1U & 0x1f)) != 0)) {
      *(uint *)g_PolledInputAction3MaskPtr =
           *(uint *)g_PolledInputAction3MaskPtr | (uint)g_InputAction3Mask;
    }
    if ((g_CfgJoystickBindingAction4 != 0) &&
       ((mask & 1 << ((char)g_CfgJoystickBindingAction4 - 1U & 0x1f)) != 0)) {
      *(uint *)g_PolledInputAction4MaskPtr =
           *(uint *)g_PolledInputAction4MaskPtr | g_InputAction4Mask;
    }
    if ((g_CfgJoystickBindingAction5 != 0) &&
       ((mask & 1 << ((char)g_CfgJoystickBindingAction5 - 1U & 0x1f)) != 0)) {
      *(uint *)g_PolledInputAction5MaskPtr =
           *(uint *)g_PolledInputAction5MaskPtr | g_InputAction5Mask;
    }
    if ((g_CfgJoystickBindingAction6 != 0) &&
       ((mask & 1 << ((char)g_CfgJoystickBindingAction6 - 1U & 0x1f)) != 0)) {
      *(uint *)g_PolledInputAction6MaskPtr =
           *(uint *)g_PolledInputAction6MaskPtr | g_InputAction6Mask;
    }
    if ((g_CfgJoystickBindingAction7 != 0) &&
       ((mask & 1 << ((char)g_CfgJoystickBindingAction7 - 1U & 0x1f)) != 0)) {
      *(uint *)g_PolledInputAction7MaskPtr =
           *(uint *)g_PolledInputAction7MaskPtr | g_InputAction7Mask;
    }
    if ((g_CfgJoystickBindingAction8 != 0) &&
       ((mask & 1 << ((char)g_CfgJoystickBindingAction8 - 1U & 0x1f)) != 0)) {
      *(uint *)g_PolledInputAction8MaskPtr =
           *(uint *)g_PolledInputAction8MaskPtr | g_InputAction8Mask;
    }
  }
  return;
}

