#include "tarzan_ghidra_types.hpp"

// Address: 0x00442910
// Label: CEntities::DoEntitySceneObjectSphereAttachmentsOverlapByFlags
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::DoEntitySceneObjectSphereAttachmentsOverlapByFlags
          (int entry4,undefined4 sceneObject,int attachment,uint flags)

{
  char resultFlag;
  int entry;
  int entry2;
  int entry3;
  short *localState6;
  int localState5;
  int localState4;
  int localState3;
  int localState2;
  int localState;
  int localState8;
  int localState7;
  
  entry3 = 0;
  localState6 = (short *)0x0;
  localState5 = 0;
  entry = GetEntitySceneObjectAttachmentList(attachment,&localState5);
  if ((entry != 0) && (entry2 = 0, 0 < entry)) {
    do {
      if (((*(uint *)(localState5 + 0xc) & 0xc0000000) == 0x80000000) &&
         ((flags & *(uint *)(localState5 + 0xc)) != 0)) {
        entry = GetEntitySceneObjectAttachmentList(entry4,&localState6);
        if (entry == 0) {
          return 0;
        }
        localState = (int)*localState6;
        localState8 = (int)localState6[1];
        localState7 = (int)localState6[2];
        TransformVectorByBasis(entry4 + 0xb8,&localState,&localState);
        if (entry < 1) {
          return 0;
        }
        do {
          if ((*(uint *)(localState6 + 6) & 0xc0000000) == 0x80000000) {
            localState4 = *(int *)(entry4 + 0x14) + localState;
            localState3 = *(int *)(entry4 + 0x18) - localState8;
            localState2 = *(int *)(entry4 + 0x1c) + localState7;
            resultFlag = CEntities::DoWorldSpheresOverlap
                              (&localState4,(int)localState6[3],attachment + 0x14,
                               (int)*(short *)(localState5 + 6));
            if (resultFlag != '\0') {
              return 1;
            }
          }
          localState6 = localState6 + 8;
          entry3 = entry3 + 1;
        } while (entry3 < entry);
        return 0;
      }
      localState5 = localState5 + 0x10;
      entry2 = entry2 + 1;
    } while (entry2 < entry);
  }
  return 0;
}

