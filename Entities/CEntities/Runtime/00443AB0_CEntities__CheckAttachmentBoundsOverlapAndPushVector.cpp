#include "tarzan_ghidra_types.hpp"

// Address: 0x00443AB0
// Label: CEntities::CheckAttachmentBoundsOverlapAndPushVector
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CEntities::CheckAttachmentBoundsOverlapAndPushVector
               (undefined4 entry,uint sceneObject,undefined4 attachment,uint flags,undefined4 arg5,
               undefined4 arg6)

{
  int value;
  int value2;
  int localState2;
  int localState;
  
  localState = 0;
  localState2 = 0;
  value = GetEntitySceneObjectAttachmentList(attachment,&localState2);
  if ((value != 0) && (value2 = 0, 0 < value)) {
    do {
      if (((*(uint *)(localState2 + 0xc) & 0xc0000000) == 0) &&
         ((flags & *(uint *)(localState2 + 0xc)) != 0)) {
        value = GetEntitySceneObjectAttachmentList(entry,&localState);
        if (value == 0) {
          return false;
        }
        value2 = 0;
        if (value < 1) {
          return false;
        }
        while (((*(uint *)(localState + 0xc) & 0xc0000000) != 0x80000000 ||
               ((sceneObject & *(uint *)(localState + 0xc)) == 0))) {
          localState = localState + 0x10;
          value2 = value2 + 1;
          if (value <= value2) {
            return false;
          }
        }
        value = CEntities::ComputeAttachmentBoundsPushVector
                          (entry,localState,attachment,localState2,arg5,arg6);
        return value != 0;
      }
      localState2 = localState2 + 0x10;
      value2 = value2 + 1;
    } while (value2 < value);
  }
  return false;
}

