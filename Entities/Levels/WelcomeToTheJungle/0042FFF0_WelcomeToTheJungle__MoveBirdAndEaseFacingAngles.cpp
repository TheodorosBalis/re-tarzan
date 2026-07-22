#include "tarzan_ghidra_types.hpp"

// Address: 0x0042FFF0
// Label: WelcomeToTheJungle::MoveBirdAndEaseFacingAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WelcomeToTheJungle::MoveBirdAndEaseFacingAngles(int arg1,uint arg2)

{
  Entity *entity = (Entity *)arg1;
  int value;
  int value2;
  uint value3;
  ushort value4;
  uint value5;
  
  value = entity->sceneObjects;
  if (value != 0) {
    if (*(char *)(value + 0x75) != '\0') {
      arg2 = ~arg2 + 1;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(arg2,0,value);
    ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x + *(int *)(value + 0x54);
    value3 = *(ushort *)(value + 0x132) & 0xfff;
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
    ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value)->z + *(int *)(value + 0x5c);
    if (*(char *)(value + 0x75) == '\0') {
      value3 = value3 ^ 0x800;
      value4 = 0x400 - *(short *)(value + 0x130);
    }
    else {
      value4 = *(short *)(value + 0x130) - 0x400;
    }
    value5 = value4 & 0xfff;
    if ((int)((EntitySceneObject *)value)->yaw != value3) {
      value2 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value)->yaw,value3);
      if ((value2 >> 3 ^ value2 >> 0x1f) - (value2 >> 0x1f) < 2) {
        ((EntitySceneObject *)value)->yaw = (short)value3;
      }
      else {
        ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + (short)(value2 >> 3);
      }
      ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw & 0xfff;
    }
    if ((int)*(short *)(value + 0xa0) != value5) {
      value2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value + 0xa0),value5);
      if ((value2 >> 3 ^ value2 >> 0x1f) - (value2 >> 0x1f) < 2) {
        *(short *)(value + 0xa0) = (short)value5;
        *(ushort *)(value + 0xa0) = *(ushort *)(value + 0xa0) & 0xfff;
        return;
      }
      *(short *)(value + 0xa0) = *(short *)(value + 0xa0) + (short)(value2 >> 3);
      *(ushort *)(value + 0xa0) = *(ushort *)(value + 0xa0) & 0xfff;
    }
  }
  return;
}

