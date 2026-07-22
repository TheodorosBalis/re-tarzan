#include "tarzan_ghidra_types.hpp"

// Address: 0x0045C510
// Label: StorkRide::UpdateBonusTimePickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::UpdateBonusTimePickup(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value8;
  char resultFlag;
  int value;
  uint value5;
  int value2;
  uint value6;
  uint value7;
  int value3;
  int value4;
  undefined4 localState2 [10];
  undefined4 localState [10];
  
  localState[0] = 0x40;
  localState2[0] = 0x100;
  value8 = (short *)(entity->sceneObjects + 0xa2);
  *value8 = *value8 + 0x20;
  value = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
  if (value != 0) {
    CEntities::UpdateParabolicSceneObjectMotionAttachment(entry);
    resultFlag = CEntities::CheckSceneObjectSphereOverlap3D
                      (entity->sceneObjects,localState,g_PlayerEntitySceneObject,
                       localState2);
    if (resultFlag != '\0') {
      value = entity->sceneObjects;
      if (value != 0) {
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + -0xb4,
                   ((EntitySceneObject *)value)->z,0x14,0x11);
      }
      value6 = (uint)(char)((uint)g_HudCountdownBcdTime >> 8);
      value7 = value6 & 0x8000000f;
      if ((int)value7 < 0) {
        value7 = (value7 - 1 | 0xfffffff0) + 1;
      }
      value5 = (uint)(char)((uint)g_HudCountdownBcdTime >> 0x10);
      value = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
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
      value3 = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
      if (g_BcdTimerTicksPerSecond < value3) {
        value = value + 1;
        value3 = value3 - g_BcdTimerTicksPerSecond;
      }
      value4 = value + 5;
      if (0x3b < value4) {
        value2 = value2 + 1;
        value4 = value + -0x37;
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
           (int)(char)((((char)(value3 / 10) + (char)(value3 >> 0x1f)) -
                       (char)((longlong)value3 * 0x66666667 >> 0x3f)) * '\x10' + (char)(value3 % 10));
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

