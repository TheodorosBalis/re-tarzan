#include "tarzan_ghidra_types.hpp"

// Address: 0x0043EFC0
// Label: ComputeEntitySceneObjectCollisionMoveDelta
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 ComputeEntitySceneObjectCollisionMoveDelta(int arg1,uint arg2,int arg3)

{
  int *intCursor;
  int *intCursor2;
  undefined4 *dataCursor;
  int *intCursor3;
  undefined1 value;
  short shortValue;
  short shortValue2;
  uint value2;
  int *intCursor4;
  int entry;
  
  value2 = *(uint *)(arg3 + 0x13c);
  entry = *(int *)(arg3 + 0x108);
  intCursor3 = (int *)(arg3 + 0x108);
  *(uint *)(arg3 + 0x13c) = value2 & 0xfffffff9;
  if (entry == 0) {
    *(undefined4 *)(arg3 + 0x54) = 0;
    *(undefined4 *)(arg3 + 0x58) = 0;
    *(undefined4 *)(arg3 + 0x5c) = 0;
  }
  else if (entry == 1) {
    value = *(undefined1 *)(arg3 + 0x75);
    if ((value2 & 1) != 0) {
      arg1 = ClampSurfaceMoveDistanceAgainstEntityColliders(arg3,arg1);
    }
    dataCursor = (undefined4 *)(arg3 + 0x54);
    MoveEntitySceneObjectAlongJungleSurface(intCursor3,arg3 + 0x14,value,arg1,dataCursor);
    if (*intCursor3 == 2) {
      *dataCursor = 0;
      *(undefined4 *)(arg3 + 0x58) = 0;
      *(undefined4 *)(arg3 + 0x5c) = 0;
      ResolveEntitySceneObjectTerrainCollision(intCursor3,arg3 + 0x14,dataCursor,dataCursor);
      return 0;
    }
  }
  else if (entry == 2) {
    intCursor = (int *)(arg3 + 0x14);
    intCursor2 = (int *)(arg3 + 0x54);
    shortValue = (&g_SinCosTable12Bit)[arg2 & 0xfff];
    shortValue2 = (&g_SinCosTable12Bit)[arg2 - 0x400 & 0xfff];
    *(undefined4 *)(arg3 + 0x58) = *(undefined4 *)(arg3 + 0x18);
    *intCursor2 = *intCursor + (-(shortValue2 * arg1) >> 0xc);
    *(int *)(arg3 + 0x5c) = *(int *)(arg3 + 0x1c) + (-(shortValue * arg1) >> 0xc);
    PushEntitySceneObjectAwayFromEntityColliders(arg3,intCursor2);
    *intCursor2 = *intCursor2 - *intCursor;
    *(int *)(arg3 + 0x5c) = *(int *)(arg3 + 0x5c) - *(int *)(arg3 + 0x1c);
    *(undefined4 *)(arg3 + 0x58) = 0;
    ResolveEntitySceneObjectTerrainCollision(intCursor3,intCursor,intCursor2,intCursor2);
    if (*intCursor3 != 1) {
      *(undefined2 *)(arg3 + 0x130) = 0x400;
      *(undefined2 *)(arg3 + 0x132) = 0;
      *(undefined2 *)(arg3 + 0x134) = 0;
      return 0;
    }
    intCursor4 = (int *)GetJungleSurfaceSegment
                              (*(undefined4 *)(arg3 + 0x110),*(undefined4 *)(arg3 + 0x10c));
    if ((intCursor4[5] & 0x2000U) != 0) {
      intCursor4 = intCursor4 + -7;
    }
    entry = GetAngleFromXZVector12Bit(intCursor4[7] - *intCursor4,intCursor4[9] - intCursor4[2]);
    entry = GetWrappedAngleDistance12Bit(arg2 & 0xfff,entry - 0x800U & 0xfff);
    *(char *)(arg3 + 0x75) = (entry < 0x401) + -1;
    MoveEntitySceneObjectAlongJungleSurface(intCursor3,intCursor,0,0,intCursor2);
    return 0;
  }
  return 0;
}

