#include "tarzan_ghidra_types.hpp"

// Address: 0x00442A50
// Label: PushEntitySceneObjectOutOfEntityCollision
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint PushEntitySceneObjectOutOfEntityCollision
               (undefined4 arg1,undefined4 arg2,undefined4 arg3,uint arg4,int *arg5)

{
  uint value;
  uint value2;
  int entry;
  int entry2;
  int *intCursor;
  uint localState4;
  int localState3;
  short localState2 [2];
  short localState;
  int localState5 [3];
  
  entry = 0;
  localState4 = 0;
  localState3 = 0;
  value = GetEntitySceneObjectAttachmentList(arg3,&localState3);
  if ((value != 0) && (entry2 = 0, 0 < (int)value)) {
    do {
      if (((*(uint *)(localState3 + 0xc) & 0xc0000000) == 0) &&
         ((arg4 & *(uint *)(localState3 + 0xc)) != 0)) {
        value = GetEntitySceneObjectAttachmentList(arg1,&localState4);
        if ((value != 0) && (0 < (int)value)) {
          do {
            value2 = localState4;
            if ((*(uint *)(localState4 + 0xc) & 0xc0000000) == 0x80000000) {
              entry2 = GetSceneAttachmentWorldPositionByMask(arg1,0x4000,localState5);
              intCursor = arg5;
              if (entry2 != 0) {
                intCursor = localState5;
              }
              value2 = CEntities::ComputeLocalAttachmentBoundsPushVector
                                (arg1,localState4,arg3,localState3,localState2,intCursor);
              if (value2 != 0xffffffff) {
                entry = SqrtToInt(value2);
                entry = entry >> 6;
                if ((entry < 0x80) && (0 < entry)) {
                  *arg5 = *arg5 + ((int)localState2[0] * (0x80 - entry) >> 10);
                  entry = arg5[2] + ((int)localState * (0x80 - entry) >> 10);
                  arg5[2] = entry;
                }
                return CONCAT31((int3)((uint)entry >> 8),1);
              }
            }
            localState4 = localState4 + 0x10;
            entry = entry + 1;
            if ((int)value <= entry) {
              return value2 & 0xffffff00;
            }
          } while( true );
        }
        break;
      }
      localState3 = localState3 + 0x10;
      entry2 = entry2 + 1;
    } while (entry2 < (int)value);
  }
  return value & 0xffffff00;
}

