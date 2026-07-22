#include "tarzan_ghidra_types.hpp"

// Address: 0x004116C0
// Label: CEntities::InitChargingAnimal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitChargingAnimal(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3190;
  *(undefined2 *)(value + 0xc) = 0x68;
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_ChargingAnimalScriptAttachmentDesc);
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value2 == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  CEntities::SelectEntityAnimationAttachmentState(entry,0);
  ((EntitySceneObject *)value)->roll = 1;
  *(undefined1 *)(value + 0x75) = 0xff;
  *(undefined2 *)(entry + 0x48) = 0;
  CEntities::MoveClaytonForwardAndUpdateFacing(entry,value,10);
  return;
}

