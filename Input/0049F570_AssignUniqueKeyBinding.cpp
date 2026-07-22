#include "tarzan_ghidra_types.hpp"

// Address: 0x0049F570
// Label: AssignUniqueKeyBinding
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void AssignUniqueKeyBinding(int *arg1,int arg2)

{
  *arg1 = 0;
  if (arg2 != 0) {
    if (g_CfgKeyboardBindingUp == arg2) {
      g_CfgKeyboardBindingUp = 0;
    }
    if (g_CfgKeyboardBindingDown == arg2) {
      g_CfgKeyboardBindingDown = 0;
    }
    if (g_CfgKeyboardBindingLeft == arg2) {
      g_CfgKeyboardBindingLeft = 0;
    }
    if (g_CfgKeyboardBindingRight == arg2) {
      g_CfgKeyboardBindingRight = 0;
    }
    if (g_CfgKeyboardBindingAction0 == arg2) {
      g_CfgKeyboardBindingAction0 = 0;
    }
    if (g_CfgKeyboardBindingAction1 == arg2) {
      g_CfgKeyboardBindingAction1 = 0;
    }
    if (g_CfgKeyboardBindingAction2 == arg2) {
      g_CfgKeyboardBindingAction2 = 0;
    }
    if (g_CfgKeyboardBindingAction3 == arg2) {
      g_CfgKeyboardBindingAction3 = 0;
    }
    if (g_CfgKeyboardBindingAction4 == arg2) {
      g_CfgKeyboardBindingAction4 = 0;
    }
    if (g_CfgKeyboardBindingAction5 == arg2) {
      g_CfgKeyboardBindingAction5 = 0;
    }
    if (g_CfgKeyboardBindingAction6 == arg2) {
      g_CfgKeyboardBindingAction6 = 0;
    }
    if (g_CfgKeyboardBindingAction7 == arg2) {
      g_CfgKeyboardBindingAction7 = 0;
    }
    if (g_CfgKeyboardBindingAction8 == arg2) {
      g_CfgKeyboardBindingAction8 = 0;
    }
    *arg1 = arg2;
  }
  return;
}

