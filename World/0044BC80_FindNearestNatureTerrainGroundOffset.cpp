#include "tarzan_ghidra_types.hpp"

// Address: 0x0044BC80
// Label: FindNearestNatureTerrainGroundOffset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FindNearestNatureTerrainGroundOffset(undefined4 *arg1,int *arg2,int arg3)

{
  byte flagByte;
  int foundIndex2;
  int foundIndex3;
  undefined4 value4;
  int foundIndex4;
  int foundIndex5;
  int foundIndex6;
  undefined4 *dataCursor;
  short *value3;
  int foundIndex;
  short *value2;
  byte *value;
  int localState5;
  uint localState4;
  int localState3;
  int localState2;
  int localState;
  int localState8;
  int localState7;
  int localState6;
  
  foundIndex4 = *arg2;
  foundIndex = -1;
  localState5 = 0x7fffffff;
  localState6 = arg2[2];
  g_NatureTerrainHazardContactFlag = 0;
  localState7 = arg2[1] - arg3;
  dataCursor = (undefined4 *)((int)arg1 + 0x44);
  foundIndex5 = *(int *)((int)arg1 + 0x40);
  localState8 = foundIndex4;
  do {
    if (foundIndex5 == 0) {
      return localState5 - arg3;
    }
    value2 = (short *)*dataCursor;
    dataCursor = dataCursor + 5;
    value3 = value2 + 8;
    for (foundIndex2 = (int)*value2; foundIndex2 != 0; foundIndex2 = foundIndex2 + -1) {
      foundIndex3 = ResolveSceneAssetPointerEntry(value3);
      if (((((foundIndex3 != 0) && (*(int *)(foundIndex3 + 0x24) != 0)) &&
           (*(int *)(value3 + 4) + -0x20 <= foundIndex4)) &&
          ((*(int *)(value3 + 8) + -0x20 <= localState6 && (foundIndex4 <= *(int *)(value3 + 10) + 0x20)))) &&
         (localState6 <= *(int *)(value3 + 0xe) + arg3)) {
        localState3 = foundIndex4 - *(int *)(value3 + 0x10);
        localState2 = localState7 - *(int *)(value3 + 0x12);
        localState = localState6 - *(int *)(value3 + 0x14);
        value3[0x30] = 0;
        value3[0x31] = 0;
        value3[0x32] = 0;
        value3[0x33] = 0;
        value3[0x34] = 0;
        value3[0x35] = 0;
        TransformVectorByBasis(value3 + 0x26,&localState3,&localState3);
        value2 = (short *)(*(int *)(foundIndex3 + 0xc) + 0x4c + foundIndex3);
        arg2 = (int *)(*(int *)(foundIndex3 + 0x24) + 0x24 + foundIndex3);
        value = (byte *)(*(int *)(foundIndex3 + 0x10) + foundIndex3 + 0x11);
        flagByte = *value;
        foundIndex3 = localState3;
        foundIndex6 = localState;
        foundIndex4 = localState8;
        while (localState4 = (uint)flagByte, localState8 = foundIndex4, localState4 != 0xff) {
          if (localState4 != 0) {
            arg1 = (undefined4 *)((int)arg2 + 0x10);
            arg2 = (int *)((int)arg2 + localState4 * 8);
            foundIndex4 = foundIndex;
            do {
              foundIndex = foundIndex4;
              if ((*(byte *)((int)value2 + 0x17) & 1) != 0) {
                if ((((*value2 + -0x40 < foundIndex3) || (value2[4] + -0x40 < foundIndex3)) ||
                    (value2[8] + -0x40 < foundIndex3)) &&
                   (((((foundIndex3 < *value2 + 0x40 || (foundIndex3 < value2[4] + 0x40)) ||
                      (foundIndex3 < value2[8] + 0x40)) &&
                     (((value2[2] + -0x40 < foundIndex6 || (value2[6] + -0x40 < foundIndex6)) ||
                      (value2[10] + -0x40 < foundIndex6)))) &&
                    (((foundIndex6 < value2[2] + 0x40 || (foundIndex6 < value2[6] + 0x40)) ||
                     (foundIndex6 < value2[10] + 0x40)))))) {
                  value4 = ComputePointToTriangleDistanceSquared(&localState3,value2);
                  foundIndex4 = SqrtToInt(value4);
                  foundIndex4 = foundIndex4 >> 6;
                  foundIndex6 = localState;
                  foundIndex3 = localState3;
                }
                foundIndex = foundIndex4;
                if ((0 < foundIndex4) && (foundIndex4 < localState5)) {
                  _g_NatureTerrainGroundProbeBestDistance = *arg1;
                  _g_NatureTerrainGroundProbeBestY = arg1[1];
                  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\f') {
                    if (foundIndex4 <= arg3) {
                      flagByte = *(byte *)(value2 + 0xb) & 8;
                      goto joined_r0x0044bede;
                    }
                  }
                  else if (foundIndex4 <= arg3) {
                    flagByte = *(byte *)((int)value2 + 0x17) & 2;
joined_r0x0044bede:
                    if (flagByte != 0) {
                      g_NatureTerrainHazardContactFlag = 1;
                    }
                  }
                  foundIndex = -1;
                  localState5 = foundIndex4;
                }
              }
              value2 = value2 + 4;
              arg1 = arg1 + 2;
              localState4 = localState4 - 1;
              foundIndex4 = foundIndex;
            } while (localState4 != 0);
          }
          arg2 = (int *)((int)arg2 + 0x10);
          value2 = value2 + 8;
          value = value + 2;
          foundIndex4 = localState8;
          flagByte = *value;
        }
      }
      value3 = value3 + 0x3a;
    }
    foundIndex5 = foundIndex5 + -1;
  } while( true );
}

