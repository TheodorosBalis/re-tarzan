#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C7E0
// Label: DoesSaborAttackAttachmentHitPlayer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 DoesSaborAttackAttachmentHitPlayer(undefined4 arg1)

{
  char resultFlag;
  int value;
  int value2;
  int value3;
  int localState3;
  int localState2;
  int localState;
  
  localState = GetEntitySceneObjectAttachmentList(g_PlayerEntitySceneObject,&localState3);
  if ((localState != 0) && (value2 = 0, 0 < localState)) {
    do {
      if (((*(uint *)(localState3 + 0xc) & 0x200) != 0) &&
         ((value = GetEntitySceneObjectAttachmentList(arg1,&localState2), value != 0 &&
          (value3 = 0, 0 < value)))) {
        do {
          if (((*(uint *)(localState2 + 0xc) & 0x400) != 0) &&
             ((((*(uint *)(localState2 + 0xc) & 0xc0000000) == 0x80000000 &&
               ((*(uint *)(localState3 + 0xc) & 0xc0000000) == 0x80000000)) &&
              (resultFlag = CEntities::DoEntitySceneObjectSphereAttachmentsOverlapByFlags
                                 (arg1,0x200,g_PlayerEntitySceneObject,0x200), resultFlag != '\0'))))
          {
            return 1;
          }
          localState2 = localState2 + 0x10;
          value3 = value3 + 1;
        } while (value3 < value);
      }
      localState3 = localState3 + 0x10;
      value2 = value2 + 1;
    } while (value2 < localState);
  }
  return 0;
}

