#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E9B0
// Label: UpdatePathFollowerAttachmentNearestSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int UpdatePathFollowerAttachmentNearestSegment(int arg1,int *arg2)

{
  Entity *entity = (Entity *)arg1;
  ushort value8;
  int value2;
  int value3;
  int value4;
  int value5;
  uint value9;
  undefined4 value10;
  int value6;
  int value7;
  int value;
  undefined4 localState5;
  undefined4 localState4;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  undefined4 localState8;
  undefined4 localState7;
  undefined4 localState6;
  
  value3 = arg1;
  value = 0;
  value2 = *(int *)(arg1 + 0x14);
  value7 = entity->previous + 0x30;
  value4 = value2 + -3;
  if (value4 < 0) {
    value4 = 0;
  }
  value6 = value7 + value4 * 0x1c;
  value5 = value7 + value2 * 0x1c;
  if ((*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x04') && (value8 = *(ushort *)(value5 + 0x18), value8 != 0))
  {
    *(uint *)(arg1 + 0x28) = (uint)value8;
    *(uint *)(arg1 + 0x2c) = (uint)*(ushort *)(value5 + 0x1a);
    value5 = *(int *)(arg1 + 0x28) * 4 + 4;
    value5 = g_CollisionSurfaceTable + *(int *)(value5 + g_CollisionSurfaceTable) + value5;
    *(int *)(arg1 + 0x30) = value5;
    *(int *)(arg1 + 0x54) = value5 + 0x30 + *(int *)(arg1 + 0x2c) * 0x1c;
    entity->descriptor = **(ushort **)(arg1 + 0x30) - 1;
  }
  arg1 = 0x7fffffff;
  for (; value4 <= value2 + 3; value4 = value4 + 1) {
    value5 = ComputeDistanceSqToPathSegmentXZ(value6,arg2,&localState);
    if (value5 < 0) {
      value5 = 0x7fffffff;
    }
    if (value5 < arg1) {
      localState5 = localState;
      localState4 = localState8;
      localState3 = localState7;
      localState2 = localState6;
      value = value4;
      arg1 = value5;
    }
    value6 = value6 + 0x1c;
  }
  value4 = value7 + value * 0x1c;
  value9 = GetAngleFromXZVector12Bit
                    (*(int *)(value7 + (value + 1) * 0x1c) - *(int *)(value7 + value * 0x1c),
                     *(int *)(value4 + 0x24) - *(int *)(value4 + 8));
  *(int *)(value3 + 0x14) = value;
  *(uint *)(value3 + 0x6c) = value9 & 0xfff;
  *(undefined4 *)(value3 + 0x18) = localState5;
  *(undefined4 *)(value3 + 0x1c) = localState4;
  *(undefined4 *)(value3 + 0x20) = localState3;
  *(undefined4 *)(value3 + 0x24) = localState2;
  *(int *)(value3 + 0x10) = arg1;
  if ((*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x04') && (*(int *)(value3 + 0x28) != 0)) {
    value4 = *(int *)(value3 + 0x54);
    value10 = ComputeDistanceSqToPathSegmentXZ((int *)(value4 + 0x1c),arg2,&localState);
    *(undefined4 *)(value3 + 0x4c) = value10;
    if (*(int *)(value3 + 0x68) == -1) {
      value10 = *(undefined4 *)(value4 + 0x28);
      *(undefined4 *)(value3 + 0x68) = 0;
      *(undefined4 *)(value3 + 100) = value10;
    }
    value4 = GetAngleFromXZVector12Bit
                      (*(int *)(value4 + 0x1c) - *arg2,*(int *)(value4 + 0x24) - arg2[2]);
    value9 = value4 + 0x400U & 0xfff;
    *(undefined4 *)(value3 + 0x50) = 0;
    if (value9 < 0x400) {
      *(undefined4 *)(value3 + 0x50) = 1;
    }
    if (0xc00 < value9) {
      *(undefined4 *)(value3 + 0x50) = 1;
    }
  }
  return arg1;
}

