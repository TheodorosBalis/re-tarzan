#include "tarzan_ghidra_types.hpp"

// Address: 0x0041E1B0
// Label: CEntities::InitChargingAnimalVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitChargingAnimalVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x680;
    ((EntitySceneObject *)value)->roll = 0;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    value = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_ChargingAnimalVariantScriptAttachmentDesc);
    if (value != 0) {
      CEntities::SelectScriptAttachmentSequence(value,10);
    }
    *(undefined2 *)(entry + 0x4a) = 0;
    *(undefined2 *)(entry + 0x48) = 2;
  }
  return;
}

