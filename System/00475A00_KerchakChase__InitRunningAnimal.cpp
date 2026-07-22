#include "tarzan_ghidra_types.hpp"

// Address: 0x00475A00
// Label: KerchakChase::InitRunningAnimal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::InitRunningAnimal(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x18,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x958;
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    dataCursor = (ushort *)(entity->sceneObjects + 0xe);
    *dataCursor = *dataCursor & 0x7fff;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined4 *)(value + 0x14) = 0xc;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_KerchakChaseRunningAnimalScriptAttachmentDesc);
    *(int *)(value + 0x10) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0);
    }
  }
  return;
}

