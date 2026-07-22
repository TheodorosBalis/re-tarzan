#include "tarzan_ghidra_types.hpp"

// Address: 0x00468CD0
// Label: TarzanToTheRescue::UpdateScriptedRescueEffectB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateScriptedRescueEffectB(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value2;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value2 = (short *)(entity->sceneObjects + 0xa2);
    *value2 = *value2 + *(short *)(value + 0x34);
    *(int *)(entity->sceneObjects + 0x18) =
         *(int *)(entity->sceneObjects + 0x18) +
         (*(int *)(g_PlayerEntitySceneObject + 0x18) - *(int *)(g_PlayerEntitySceneObject + 0x4c));
  }
  return;
}

