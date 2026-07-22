#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C020
// Label: DoEntitySceneObjectAttachmentBoxesOverlapByFlags
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
DoEntitySceneObjectAttachmentBoxesOverlapByFlags
          (undefined4 arg1,uint arg2,undefined4 arg3,uint arg4)

{
  char resultFlag;
  int entry;
  int entry2;
  int localState2;
  uint localState;
  
  localState = 0;
  localState2 = 0;
  entry = GetEntitySceneObjectAttachmentList(arg3,&localState2);
  if ((entry != 0) && (entry2 = 0, 0 < entry)) {
    do {
      if (((*(uint *)(localState2 + 0xc) & 0xc0000000) == 0) &&
         ((arg4 & *(uint *)(localState2 + 0xc)) != 0)) {
        entry = GetEntitySceneObjectAttachmentList(arg1,&localState);
        if (entry == 0) {
          return 0;
        }
        entry2 = 0;
        if (entry < 1) {
          return 0;
        }
        while ((((*(uint *)(localState + 0xc) & 0xc0000000) != 0 ||
                ((arg2 & *(uint *)(localState + 0xc)) == 0)) ||
               (resultFlag = DoOrientedEntitySceneObjectAttachmentBoxesOverlap
                                  (arg1,localState,arg3,localState2), resultFlag == '\0'))) {
          localState = localState + 0x10;
          entry2 = entry2 + 1;
          if (entry <= entry2) {
            return 0;
          }
        }
        return 1;
      }
      localState2 = localState2 + 0x10;
      entry2 = entry2 + 1;
    } while (entry2 < entry);
  }
  return 0;
}

