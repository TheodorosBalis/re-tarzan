#include "tarzan_ghidra_types.hpp"

// Address: 0x00436980
// Label: CPlayerHero::ClampPositionWithinGroundContactRadius
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ClampPositionWithinGroundContactRadius(void)

{
  int value;
  int value2;
  uint value6;
  undefined4 value7;
  int value3;
  int value4;
  int value5;
  int localState2;
  int localState;
  
  for (value = *(int *)(g_PlayerEntitySceneObject + 0x60); value != 0;
      value = *(int *)(value + 0x34)) {
    localState2 = GetEntitySceneObjectAttachmentList(value,&localState);
    if ((localState2 != 0) && (0 < localState2)) {
      do {
        if (((*(uint *)(localState + 0xc) & 0x10) != 0) &&
           ((*(uint *)(localState + 0xc) & 0xc0000000) == 0x80000000)) {
          value3 = (int)*(short *)(localState + 6) - (int)*(short *)(g_PlayerEntitySceneObject + 0x140);
          value4 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *(int *)(value + 0x14);
          value5 = *(int *)(g_PlayerEntitySceneObjectData + 0x10) - *(int *)(value + 0x1c);
          value2 = SqrtToInt(value5 * value5 + value4 * value4);
          if (value3 < value2 >> 6) {
            value6 = (value2 >> 6) - value3;
            value7 = GetAngleFromXZVector12Bit(value4,value5);
            value2 = GetWrappedAngleDistance12Bit
                              (value7,(int)*(short *)(g_PlayerEntitySceneObject + 0x132));
            if (value2 < 0x400) {
              value6 = ~value6 + 1;
            }
            ComputeEntitySceneObjectCollisionMoveDelta(value6,0,g_PlayerEntitySceneObject);
          }
        }
        localState2 = localState2 + -1;
      } while (localState2 != 0);
    }
  }
  return;
}

