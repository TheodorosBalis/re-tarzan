#include "tarzan_ghidra_types.hpp"

// Address: 0x0049F0D0
// Label: GetUserInputInMenuAndProcessSound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint GetUserInputInMenuAndProcessSound(int menu)

{
  int menuIndex;
  uint soundMask;
  uint soundMask2;
  
  menuIndex = IsControlBindingPressed(0x26);
  soundMask2 = (uint)(menuIndex != 0);
  menuIndex = IsControlBindingPressed(0x28);
  if (menuIndex != 0) {
    soundMask2 = soundMask2 | 2;
  }
  menuIndex = IsControlBindingPressed(0xd);
  if (menuIndex != 0) {
    soundMask2 = soundMask2 | 0x10;
  }
  menuIndex = IsControlBindingPressed(0x20);
  if (menuIndex != 0) {
    soundMask2 = soundMask2 | 0x10;
  }
  menuIndex = IsControlBindingPressed(0x25);
  if (menuIndex != 0) {
    soundMask2 = soundMask2 | 4;
  }
  menuIndex = IsControlBindingPressed(0x27);
  if (menuIndex != 0) {
    soundMask2 = soundMask2 | 8;
  }
  menuIndex = IsControlBindingPressed(0x1b);
  if (menuIndex != 0) {
    soundMask2 = soundMask2 | 0x60;
  }
  menuIndex = IsControlBindingPressed(8);
  if (menuIndex != 0) {
    soundMask2 = soundMask2 | 0x20;
  }
  soundMask = CheckForJoystickInputs(0);
  if ((soundMask & 0x40000000) != 0) {
    soundMask2 = soundMask2 | 1;
  }
  if ((soundMask & 0x80000000) != 0) {
    soundMask2 = soundMask2 | 2;
  }
  if ((soundMask & 0x10000000) != 0) {
    soundMask2 = soundMask2 | 4;
  }
  if ((soundMask & 0x20000000) != 0) {
    soundMask2 = soundMask2 | 8;
  }
  if ((menu != 0) && ((soundMask & 0xfffffff) != 0)) {
    soundMask2 = soundMask2 | 0x10;
  }
  soundMask = soundMask2;
  if ((g_LastOptionsMenuInputMask != 0) && (soundMask2 != 0)) {
    soundMask2 = soundMask2 | 0x8000;
    soundMask = g_LastOptionsMenuInputMask;
  }
  g_LastOptionsMenuInputMask = soundMask;
  if (((soundMask2 & 0x8000) == 0) && (soundMask2 != 0)) {
    InitSoundAndNewGameStateFile(0xaa);
    PlaySoundID(0xaa,100,0,0,0x3fb33333);
  }
  return soundMask2;
}

