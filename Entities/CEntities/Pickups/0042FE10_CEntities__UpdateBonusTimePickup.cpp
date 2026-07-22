#include "tarzan_ghidra_types.hpp"

// Address: 0x0042FE10
// Label: CEntities::UpdateBonusTimePickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateBonusTimePickup(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  int value;
  uint value5;
  int value2;
  int value3;
  int value4;
  uint value6;
  uint value7;
  
  value3 = *(int *)(g_PlayerEntitySceneObject + 0x1c);
  value2 = entity->sceneObjects;
  value = ((EntitySceneObject *)value2)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
  ((EntitySceneObject *)value2)->yaw = ((EntitySceneObject *)value2)->yaw + 0x20;
  value3 = ((EntitySceneObject *)value2)->z - value3;
  if (value3 * value3 + value * value < 0x4000) {
    PlayAudioById(0x44a,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
    value3 = entity->sceneObjects;
    CEntities::SpawnEntityByTypeAtPosition
              (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
               ((EntitySceneObject *)value3)->z,0x14,0x11);
    value6 = (uint)(char)((uint)g_HudCountdownBcdTime >> 8);
    value7 = value6 & 0x8000000f;
    if ((int)value7 < 0) {
      value7 = (value7 - 1 | 0xfffffff0) + 1;
    }
    value5 = (uint)(char)((uint)g_HudCountdownBcdTime >> 0x10);
    value3 = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
    value6 = value5 & 0x8000000f;
    if ((int)value6 < 0) {
      value6 = (value6 - 1 | 0xfffffff0) + 1;
    }
    value2 = value6 + ((int)(value5 + ((int)value5 >> 0x1f & 0xfU)) >> 4) * 10;
    value6 = (uint)(char)g_HudCountdownBcdTime;
    value7 = value6 & 0x8000000f;
    if ((int)value7 < 0) {
      value7 = (value7 - 1 | 0xfffffff0) + 1;
    }
    value = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
    if (g_BcdTimerTicksPerSecond < value) {
      value3 = value3 + 1;
      value = value - g_BcdTimerTicksPerSecond;
    }
    value4 = value3 + 5;
    if (0x3b < value4) {
      value2 = value2 + 1;
      value4 = value3 + -0x37;
    }
    if (0x3b < value2) {
      value2 = value2 + -0x3c;
    }
    g_HudCountdownBcdTime =
         ((char)((((char)(value2 / 10) + (char)(value2 >> 0x1f)) -
                 (char)((longlong)value2 * 0x66666667 >> 0x3f)) * '\x10' + (char)(value2 % 10)) *
          0x100 + (int)(char)((((char)(value4 / 10) + (char)(value4 >> 0x1f)) -
                              (char)((longlong)value4 * 0x66666667 >> 0x3f)) * '\x10' +
                             (char)(value4 % 10))) * 0x100 +
         (int)(char)((((char)(value / 10) + (char)(value >> 0x1f)) -
                     (char)((longlong)value * 0x66666667 >> 0x3f)) * '\x10' + (char)(value % 10));
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

