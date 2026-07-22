#include "tarzan_ghidra_types.hpp"

// Address: 0x0045EB50
// Label: CMenu::LevelComplete_UpdateTARZANSlots
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_UpdateTARZANSlots(int menu)

{
  int slotIndex;
  uint value;
  uint value2;
  byte flagByte;
  undefined4 value3;
  
  slotIndex = *(int *)(&g_LevelCompleteRewardSlotPtrTable + menu * 0xc);
  value = *(uint *)(slotIndex + 0x58);
  value2 = value + 0x800;
  *(uint *)(slotIndex + 0x58) = value2;
  flagByte = (byte)menu;
  if ((0x63ff < (int)(value2 & 0xffffff00)) || (g_LevelCompleteFastForwardRequested != 0)) {
    g_LevelCompleteRewardSlotDoneMask = g_LevelCompleteRewardSlotDoneMask | 1 << (flagByte & 0x1f);
    if ((int)(value & 0xffffff00) < 0x6400) {
      if ((g_CollectedTARZANLetterMask6 >> (flagByte & 0x1f) & 1) == 0) {
        value3 = 0x3db;
      }
      else {
        value3 = 0x3dc;
      }
      PlayAudioById(value3,(int *)0,(undefined4 *)0);
    }
    *(uint *)(slotIndex + 0x58) = (uint)CONCAT11(100,(char)*(undefined4 *)(slotIndex + 0x58));
  }
  CMenu::LevelComplete_AddSlotSpin(slotIndex,0x3c);
  if ((g_CollectedTARZANLetterMask6 >> (flagByte & 0x1f) & 1) != 0) {
    *(ushort *)(slotIndex + 0xe) = *(ushort *)(slotIndex + 0xe) & 0xfbde;
    return;
  }
  *(ushort *)(slotIndex + 0xe) = *(ushort *)(slotIndex + 0xe) | 0x421;
  *(int *)(slotIndex + 0x30) =
       ((int)(short)(&g_SinCosTable12Bit)[(TotalGameLoopTicks + -4) * 0x100 + menu * 400 & 0xfff]
       >> 2) + 0x600;
  return;
}

