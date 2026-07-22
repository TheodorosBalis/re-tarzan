#include "tarzan_ghidra_types.hpp"

// Address: 0x004623E0
// Label: TarzanToTheRescue::HandleRhinoCollisionWithActiveEntry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 TarzanToTheRescue::HandleRhinoCollisionWithActiveEntry(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  char resultFlag;
  int value2;
  int value3;
  
  value = g_ActiveEntityListHead;
  while( true ) {
    if (value == 0) {
      return 0;
    }
    value3 = *(int *)(value + 0x38);
    if ((((value3 != entity->sceneObjects) &&
         (value2 = CEntities::FindEntityAttachmentByFlags(arg1,0x10000000), value2 != 0)) &&
        (resultFlag = CEntities::DoEntitySceneObjectSphereAttachmentsOverlapByFlags
                           (entity->sceneObjects,8,value3,1), resultFlag != '\0')) &&
       (value3 = CEntities::FindEntityAttachmentByFlags(value,0x10000000), value3 != 0)) break;
    value = *(int *)(value + 0x20);
  }
  if (*(int *)(value3 + 0xc) != 0xb) {
    *(undefined4 *)(value3 + 0xc) = 0xb;
  }
  if (*(int *)(*(int *)(value + 0x38) + 0x60) != 0) {
    QueuePlayerDamageEvent(arg1,0xd);
  }
  return 1;
}

