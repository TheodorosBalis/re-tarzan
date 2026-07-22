#include "tarzan_ghidra_types.hpp"

// Address: 0x0045C790
// Label: StorkRide::UpdateBonusFruitPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::UpdateBonusFruitPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  uint value5;
  int value;
  uint value6;
  uint value7;
  int value2;
  int value3;
  int value4;
  undefined4 localState2 [10];
  undefined4 localState [10];
  
  localState[0] = 0x40;
  localState2[0] = 0x100;
  value3 = entity->sceneObjects;
  if (value3 != 0) {
    shortValue = RandomModulo(0x20);
    ((EntitySceneObject *)value3)->yaw = ((EntitySceneObject *)value3)->yaw + shortValue + 0x20;
    CEntities::UpdateParabolicSceneObjectMotionAttachment(entry);
    resultFlag = CEntities::CheckSceneObjectSphereOverlap3D
                      (value3,localState,g_PlayerEntitySceneObject,localState2);
    if (resultFlag != '\0') {
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
      value = value6 + ((int)(value5 + ((int)value5 >> 0x1f & 0xfU)) >> 4) * 10;
      value6 = (uint)(char)g_HudCountdownBcdTime;
      value7 = value6 & 0x8000000f;
      if ((int)value7 < 0) {
        value7 = (value7 - 1 | 0xfffffff0) + 1;
      }
      value2 = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
      if (g_BcdTimerTicksPerSecond < value2) {
        value3 = value3 + 1;
        value2 = value2 - g_BcdTimerTicksPerSecond;
      }
      value4 = value3 + 5;
      if (0x3b < value4) {
        value = value + 1;
        value4 = value3 + -0x37;
      }
      if (0x3b < value) {
        value = value + -0x3c;
      }
      g_HudCountdownBcdTime =
           ((char)((((char)(value / 10) + (char)(value >> 0x1f)) -
                   (char)((longlong)value * 0x66666667 >> 0x3f)) * '\x10' + (char)(value % 10)) *
            0x100 + (int)(char)((((char)(value4 / 10) + (char)(value4 >> 0x1f)) -
                                (char)((longlong)value4 * 0x66666667 >> 0x3f)) * '\x10' +
                               (char)(value4 % 10))) * 0x100 +
           (int)(char)((((char)(value2 / 10) + (char)(value2 >> 0x1f)) -
                       (char)((longlong)value2 * 0x66666667 >> 0x3f)) * '\x10' + (char)(value2 % 10));
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
  }
  return;
}

