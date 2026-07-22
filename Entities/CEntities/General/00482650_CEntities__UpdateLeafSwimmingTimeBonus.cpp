#include "tarzan_ghidra_types.hpp"

// Address: 0x00482650
// Label: CEntities::UpdateLeafSwimmingTimeBonus
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Removing unreachable block (ram,0x004827b8) */
/* WARNING: Removing unreachable block (ram,0x004827f1) */

void CEntities::UpdateLeafSwimmingTimeBonus(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value8;
  ushort value4;
  char resultFlag;
  int value;
  int value2;
  uint value5;
  uint value6;
  uint value7;
  int value3;
  int localState2;
  byte localState;
  
  value8 = (short *)(entity->sceneObjects + 0xa2);
  *value8 = *value8 + 0x20;
  value = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
  if (value != 0) {
    value2 = CEntities::UpdateParabolicSceneObjectMotionAttachment(entry);
    if (value2 != 0) {
      CEntities::SpawnLeafSwimmingWhirlpoolSplashEffects
                (*(undefined4 *)(entity->sceneObjects + 0x14),*(undefined4 *)(value + 0x24),
                 *(undefined4 *)(entity->sceneObjects + 0x1c),0);
    }
    value2 = *(int *)(entity->sceneObjects + 0x1c) - *(int *)(g_PlayerEntitySceneObject + 0x1c);
    value = *(int *)(entity->sceneObjects + 0x14) - *(int *)(g_PlayerEntitySceneObject + 0x14);
    if ((value2 * value2 + value * value < 0x4000) &&
       (resultFlag = CEntities::CanStartPickupCollection(entry), resultFlag != '\0')) {
      value = entity->sceneObjects;
      if (value != 0) {
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + -0xb4,
                   ((EntitySceneObject *)value)->z,0x14,0x11);
      }
      value4 = *(ushort *)(&g_CollectibleTimerBonusByDifficulty + *( undefined1 *)((int)&g_LevelTransitionContext + 1) * 2)
      ;
      value6 = (uint)(char)((uint)g_HudCountdownBcdTime >> 8);
      value7 = value6 & 0x8000000f;
      if ((int)value7 < 0) {
        value7 = (value7 - 1 | 0xfffffff0) + 1;
      }
      value5 = (uint)(char)((uint)g_HudCountdownBcdTime >> 0x10);
      localState2 = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
      value6 = value5 & 0x8000000f;
      if ((int)value6 < 0) {
        value6 = (value6 - 1 | 0xfffffff0) + 1;
      }
      value = value6 + ((int)(value5 + ((int)value5 >> 0x1f & 0xfU)) >> 4) * 10;
      value6 = (uint)(char)g_HudCountdownBcdTime;
      value7 = value6 & 0x8000000f;
      if ((int)value7 < 0) {
        value7 = (value7 - 1 | 0xfffffff0) + 1;
      }
      value2 = value7 + (((value4 & 0xff) >> 4) + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4)) *
                      10 + (value4 & 0xf);
      if (g_BcdTimerTicksPerSecond < value2) {
        localState2 = localState2 + 1;
        value2 = value2 - g_BcdTimerTicksPerSecond;
      }
      localState = (byte)(value4 >> 8);
      value3 = (localState & 0x8000000f) + localState2 + (uint)(localState >> 4) * 10;
      if (0x3b < value3) {
        value = value + 1;
        value3 = value3 + -0x3c;
      }
      if (0x3b < value) {
        value = value + -0x3c;
      }
      g_HudCountdownBcdTime =
           ((char)((((char)(value / 10) + (char)(value >> 0x1f)) -
                   (char)((longlong)value * 0x66666667 >> 0x3f)) * '\x10' + (char)(value % 10)) *
            0x100 + (int)(char)((((char)(value3 / 10) + (char)(value3 >> 0x1f)) -
                                (char)((longlong)value3 * 0x66666667 >> 0x3f)) * '\x10' +
                               (char)(value3 % 10))) * 0x100 +
           (int)(char)((((char)(value2 / 10) + (char)(value2 >> 0x1f)) -
                       (char)((longlong)value2 * 0x66666667 >> 0x3f)) * '\x10' + (char)(value2 % 10));
      PlayAudioById(0x44a,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag != '\0') {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

