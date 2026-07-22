#include "tarzan_ghidra_types.hpp"

// Address: 0x004659B0
// Label: TarzanToTheRescue::DoesEntryOverlapActiveAttachment200
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 TarzanToTheRescue::DoesEntryOverlapActiveAttachment200(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  char resultFlag;
  
  value = g_ActiveEntityListHead;
  while( true ) {
    if (value == 0) {
      return 0;
    }
    resultFlag = TarzanToTheRescue::DoesPointOverlapSceneAttachmentFlags
                      (entity->sceneObjects + 0x14,*(undefined4 *)(value + 0x38),0x200);
    if (resultFlag != '\0') break;
    value = *(int *)(value + 0x20);
  }
  return 1;
}

