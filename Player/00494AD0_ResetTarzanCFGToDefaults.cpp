#include "tarzan_ghidra_types.hpp"

// Address: 0x00494AD0
// Label: ResetTarzanCFGToDefaults
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetTarzanCFGToDefaults(void)

{
  int value;
  int value2;
  int value3;
  undefined4 *dataCursor;
  bool flagByte;
  
  g_CfgKeyboardBindingDown = g_DefaultKeyboardBindingDown;
  dataCursor = &tarzanCFGbuffer;
  for (value3 = 0x2f; value3 != 0; value3 = value3 + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  g_CfgKeyboardBindingUp = g_DefaultKeyboardBindingUp;
  g_CfgKeyboardBindingRight = g_DefaultKeyboardBindingRight;
  g_CfgKeyboardBindingLeft = g_DefaultKeyboardBindingLeft;
  g_CfgKeyboardBindingAction1 = g_DefaultKeyboardBindingAction1;
  g_CfgKeyboardBindingAction0 = g_DefaultKeyboardBindingAction0;
  g_CfgKeyboardBindingAction3 = g_DefaultKeyboardBindingAction3;
  g_CfgKeyboardBindingAction2 = g_DefaultKeyboardBindingAction2;
  g_CfgKeyboardBindingAction5 = g_DefaultKeyboardBindingAction5;
  g_CfgKeyboardBindingAction4 = g_DefaultKeyboardBindingAction4;
  g_CfgKeyboardBindingAction6 = g_DefaultKeyboardBindingAction6;
  g_CfgKeyboardBindingAction7 = g_DefaultKeyboardBindingAction7;
  g_CfgKeyboardBindingAction8 = g_DefaultKeyboardBindingAction8;
  value3 = -1;
  g_TarzanCfgLoaded = 1;
  g_MusicEnabled = 1;
  g_SoundEffectsEnabled = 1;
  g_LegacyAudioModeEnabled = 1;
  g_CurrentDisplayModeIndex = 1;
  _g_GameDifficulty = 1;
  g_CfgJoystickBindingAction0 = 1;
  g_AuxVolumePercent = 0x5a;
  g_MasterVolumePercent = 0x3c;
  _g_CfgUnknownOptionValue5 = 5;
  g_BrightnessPercent = 0x32;
  g_SelectedJoystickIndex = -1;
  g_CfgJoystickBindingAction3 = 2;
  g_CfgJoystickBindingAction4 = 3;
  g_CfgJoystickBindingAction7 = 4;
  g_CfgJoystickBindingAction2 = 5;
  g_CfgJoystickBindingAction1 = 6;
  g_CfgJoystickBindingAction6 = 7;
  g_CfgJoystickBindingAction5 = 8;
  g_CfgJoystickBindingAction8 = 9;
  value2 = 0;
  while ((value = g_SelectedJoystickIndex, (&g_JoystickButtonCountByIndex)[value2] == '\0' ||
         (flagByte = value3 == -1, value3 = value2, value = value2, flagByte))) {
    g_SelectedJoystickIndex = value;
    value2 = value2 + 1;
    if (0xf < value2) {
      return;
    }
  }
  g_MusicEnabled = 1;
  g_MasterVolumePercent = 0x3c;
  g_SoundEffectsEnabled = 1;
  g_AuxVolumePercent = 0x5a;
  g_LegacyAudioModeEnabled = 1;
  g_CurrentDisplayModeIndex = 1;
  g_BrightnessPercent = 0x32;
  _g_GameDifficulty = 1;
  _g_CfgUnknownOptionValue5 = 5;
  g_CfgKeyboardBindingUp = g_DefaultKeyboardBindingUp;
  g_CfgKeyboardBindingLeft = g_DefaultKeyboardBindingLeft;
  g_CfgKeyboardBindingRight = g_DefaultKeyboardBindingRight;
  g_CfgKeyboardBindingAction0 = g_DefaultKeyboardBindingAction0;
  g_CfgKeyboardBindingAction1 = g_DefaultKeyboardBindingAction1;
  g_CfgKeyboardBindingAction2 = g_DefaultKeyboardBindingAction2;
  g_CfgKeyboardBindingAction3 = g_DefaultKeyboardBindingAction3;
  g_CfgKeyboardBindingAction4 = g_DefaultKeyboardBindingAction4;
  g_CfgKeyboardBindingAction5 = g_DefaultKeyboardBindingAction5;
  g_CfgKeyboardBindingAction6 = g_DefaultKeyboardBindingAction6;
  g_CfgKeyboardBindingAction7 = g_DefaultKeyboardBindingAction7;
  g_CfgKeyboardBindingAction8 = g_DefaultKeyboardBindingAction8;
  g_CfgJoystickBindingAction0 = 1;
  g_CfgJoystickBindingAction1 = 6;
  g_CfgJoystickBindingAction2 = 5;
  g_CfgJoystickBindingAction3 = 2;
  g_CfgJoystickBindingAction4 = 3;
  g_CfgJoystickBindingAction5 = 8;
  g_CfgJoystickBindingAction6 = 7;
  g_CfgJoystickBindingAction7 = 4;
  g_CfgJoystickBindingAction8 = 9;
  g_TarzanCfgLoaded = 1;
  return;
}

