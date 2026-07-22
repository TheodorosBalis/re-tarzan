#include "tarzan_ghidra_types.hpp"

// Address: 0x00405F00
// Label: RockinTheBoat::FindNearestKnifeEnemyAttackAnchor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int RockinTheBoat::FindNearestKnifeEnemyAttackAnchor
              (int *arg1,int arg2,int *arg3,undefined4 *arg4,int *arg5,
              undefined4 *arg6)

{
  int foundIndex;
  uint value;
  int foundIndex2;
  short *localState4;
  int localState3;
  int localState2;
  int localState;
  undefined4 localState7;
  undefined4 localState6;
  undefined4 localState5;
  
  foundIndex2 = 0;
  localState4 = (short *)0x0;
  foundIndex = GetEntitySceneObjectAttachmentList(arg2,&localState4);
  if ((foundIndex != 0) && (0 < foundIndex)) {
    do {
      if ((*(uint *)(localState4 + 6) & 0xc0000000) == 0x80000000) {
        localState3 = *(int *)(arg2 + 0x14) + (int)*localState4;
        localState2 = (int)localState4[1] + *(int *)(arg2 + 0x18);
        localState = (int)localState4[2] + *(int *)(arg2 + 0x1c);
        value = CEntities::ProjectPointToXZSegmentAndDistanceSquared
                          (arg1,g_PlayerEntitySceneObject + 0x14,&localState3,&localState7);
        if (value < 0x2b110) {
          foundIndex2 = *(int *)(arg2 + 0x1c) - arg1[2];
          foundIndex = *(int *)(arg2 + 0x14) - *arg1;
          *arg3 = foundIndex2 * foundIndex2 + foundIndex * foundIndex;
          *arg4 = localState7;
          arg4[1] = localState6;
          arg4[2] = localState5;
          *arg5 = localState3;
          arg5[1] = localState2;
          arg5[2] = localState;
          *arg6 = 0x1a4;
          return arg2;
        }
      }
      localState4 = localState4 + 8;
      foundIndex2 = foundIndex2 + 1;
    } while (foundIndex2 < foundIndex);
  }
  return 0;
}

