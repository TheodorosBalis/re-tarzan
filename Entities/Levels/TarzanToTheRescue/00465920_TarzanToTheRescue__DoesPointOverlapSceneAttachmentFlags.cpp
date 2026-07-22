#include "tarzan_ghidra_types.hpp"

// Address: 0x00465920
// Label: TarzanToTheRescue::DoesPointOverlapSceneAttachmentFlags
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
TarzanToTheRescue::DoesPointOverlapSceneAttachmentFlags(int *arg1,int arg2,uint arg3)

{
  uint stateFlags;
  char resultFlag;
  int entry;
  int entry2;
  int entry3;
  int localState3;
  int localState2;
  int localState;
  
  entry2 = arg2;
  entry = GetEntitySceneObjectAttachmentList(arg2,&arg2);
  stateFlags = arg3;
  if (entry != 0) {
    localState3 = *arg1 - *(int *)(entry2 + 0x14);
    localState2 = arg1[1] - *(int *)(entry2 + 0x18);
    localState = arg1[2] - *(int *)(entry2 + 0x1c);
    entry3 = 0;
    entry2 = arg2;
    if (0 < entry) {
      do {
        if ((((*(uint *)(entry2 + 0xc) & 0xc0000000) == 0) && ((stateFlags & *(uint *)(entry2 + 0xc)) != 0)
            ) && (resultFlag = CEntities::IsPointInsideLocalAttachmentBounds(&localState3,entry2),
                 entry2 = arg2, resultFlag != '\0')) {
          return 1;
        }
        entry3 = entry3 + 1;
      } while (entry3 < entry);
    }
  }
  return 0;
}

