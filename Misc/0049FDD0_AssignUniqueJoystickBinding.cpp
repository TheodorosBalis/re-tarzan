#include "tarzan_ghidra_types.hpp"

// Address: 0x0049FDD0
// Label: AssignUniqueJoystickBinding
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void AssignUniqueJoystickBinding(int *arg1,int arg2)

{
  *arg1 = 0;
  if (arg2 != 0) {
    if (g_CfgJoystickBindingAction0 == arg2) {
      g_CfgJoystickBindingAction0 = 0;
    }
    if (g_CfgJoystickBindingAction1 == arg2) {
      g_CfgJoystickBindingAction1 = 0;
    }
    if (g_CfgJoystickBindingAction2 == arg2) {
      g_CfgJoystickBindingAction2 = 0;
    }
    if (g_CfgJoystickBindingAction3 == arg2) {
      g_CfgJoystickBindingAction3 = 0;
    }
    if (g_CfgJoystickBindingAction4 == arg2) {
      g_CfgJoystickBindingAction4 = 0;
    }
    if (g_CfgJoystickBindingAction5 == arg2) {
      g_CfgJoystickBindingAction5 = 0;
    }
    if (g_CfgJoystickBindingAction6 == arg2) {
      g_CfgJoystickBindingAction6 = 0;
    }
    if (g_CfgJoystickBindingAction7 == arg2) {
      g_CfgJoystickBindingAction7 = 0;
    }
    if (g_CfgJoystickBindingAction8 == arg2) {
      g_CfgJoystickBindingAction8 = 0;
    }
    *arg1 = arg2;
  }
  return;
}

