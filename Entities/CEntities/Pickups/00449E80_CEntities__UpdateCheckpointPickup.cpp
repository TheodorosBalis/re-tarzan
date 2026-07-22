#include "tarzan_ghidra_types.hpp"

// Address: 0x00449E80
// Label: CEntities::UpdateCheckpointPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateCheckpointPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char conditionMet;
  short shortValue;
  int value2;
  short shortValue2;
  undefined4 value3;
  
  value = entity->sceneObjects;
  if ((value != 0) &&
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x80000058), value2 != 0)) {
    switch(*(undefined2 *)(entry + 0x48)) {
    case 2:
    case 9:
      *(short *)(value2 + 0xc) = *(short *)(value2 + 0xc) + -1;
      if (*(short *)(value2 + 0xc) < 0) {
        *(short *)(value2 + 0xe) = *(short *)(value2 + 0xe) + 1;
        if ((&g_CheckpointPickupActivationFrameSequence)[*(short *)(value2 + 0xe)] == 0) {
          *(undefined2 *)(value2 + 0xc) = 0;
          *(undefined2 *)(value2 + 0xe) = 0;
          *(undefined2 *)(value + 0xc) = g_CheckpointPickupActivationFrameSequence;
        }
        else {
          *(undefined2 *)(value + 0xc) =
               (&g_CheckpointPickupActivationFrameSequence)[*(short *)(value2 + 0xe)];
          *(undefined2 *)(value2 + 0xc) = 0;
        }
      }
      if (g_CurrentCheckpointId == *(int *)(entry + 0x4c)) {
        shortValue2 = *(short *)(value2 + 0x16) + 0x44;
        *(short *)(value2 + 0x16) = shortValue2;
        *(int *)(value + 0x40) =
             -0xc0 - (((int)(short)(&g_SinCosTable12Bit)[(int)shortValue2 - 0x400U & 0xfff] << 6) >> 0xc);
        ((EntitySceneObject *)value)->yaw = shortValue2 >> 1 & 0xfff;
        *(short *)(value + 0xa0) =
             (short)(((int)(short)(&g_SinCosTable12Bit)[(ushort)(shortValue2 >> 1) - 0x400 & 0xfff] +
                     (int)(short)(&g_SinCosTable12Bit)[(int)shortValue2 & 0xfff]) * 0x1c7 >> 0xd);
      }
      else {
        *(undefined2 *)(entry + 0x48) = 3;
        shortValue2 = RandomModulo(0x10);
        *(short *)(value2 + 0xc) = shortValue2 + 0x20;
        *(undefined2 *)(value2 + 0xe) = 0xffff;
        shortValue2 = RandomModulo(0x14);
        *(short *)(value2 + 0x10) = shortValue2 + 1;
        *(undefined2 *)(value + 0xa0) = 0;
      }
      break;
    case 3:
      *(undefined4 *)(value + 0x40) = 0xffffff80;
      ((EntitySceneObject *)value)->yaw = (*(ushort *)(value + 0x132) ^ 0x800) - 0x555;
    case 1:
      *(undefined2 *)(value + 0xc) = 0x1c;
      *(short *)(value2 + 0x10) = *(short *)(value2 + 0x10) + -1;
      shortValue2 = *(short *)(value2 + 0x14);
      if (*(short *)(value2 + 0x10) < 0) {
        shortValue = RandomModulo(0x60);
        *(short *)(value2 + 0xc) = shortValue + 0x20;
        *(ushort *)(value2 + 0xe) = ~*(ushort *)(value2 + 0xe);
        shortValue = RandomModulo(0x1e);
        *(short *)(value2 + 0x10) = shortValue + 1;
      }
      if (*(short *)(value2 + 0xe) == 0) {
        shortValue2 = shortValue2 - *(short *)(value2 + 0xc);
        if (shortValue2 < 0x60) {
          shortValue2 = 0x60;
        }
      }
      else {
        shortValue2 = shortValue2 + *(short *)(value2 + 0xc);
        if (0x3ff < shortValue2) {
          shortValue2 = 0x3ff;
        }
      }
      *(short *)(value2 + 0x14) = shortValue2;
      *(undefined2 *)(value + 0xa0) = 0;
      ((EntitySceneObject *)value)->pitch = shortValue2;
      *(short *)(value + 0x84) = shortValue2 * -2;
      *(undefined2 *)(value + 0x7a) = 1;
      conditionMet = CEntities::IsPlayerWithinPickupTriggerBounds
                        (value,0x120,0,(int)*(short *)(value2 + 0x12));
      if ((conditionMet != '\0') && (conditionMet = CEntities::CanStartPickupCollection(entry), conditionMet != '\0'))
      {
        switch(_g_PlayerHeroMode) {
        default:
          value3 = 0x5e;
          break;
        case 2:
        case 9:
          value3 = 0x1f;
          break;
        case 6:
          value3 = 0x4c2;
        }
        PlayAudioById(value3,(int *)0,(undefined4 *)0);
        *(undefined2 *)(entry + 0x48) = 2;
        *(undefined2 *)(value2 + 0xc) = 0;
        *(undefined2 *)(value2 + 0xe) = 0;
        *(undefined2 *)(value + 0xc) = g_CheckpointPickupActivationFrameSequence;
        ((EntitySceneObject *)value)->pitch = 0;
        *(undefined2 *)(value + 0x84) = 0;
        *(undefined2 *)(value + 0x7a) = 0;
        g_CurrentCheckpointId = *(int *)(entry + 0x4c);
      }
    }
  }
  conditionMet = IsEntityOutsideOuterActivationBounds(entry);
  if (conditionMet != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

