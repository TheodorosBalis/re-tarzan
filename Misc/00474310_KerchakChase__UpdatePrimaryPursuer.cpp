#include "tarzan_ghidra_types.hpp"

// Address: 0x00474310
// Label: KerchakChase::UpdatePrimaryPursuer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::UpdatePrimaryPursuer(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value3;
  int value;
  int value2;
  
  AdvanceRuntimePathAttachmentFromEntitySceneObject(entry);
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x40000000);
  if (value2 != 0) {
    *(int *)(entity->sceneObjects + 0x14) =
         *(int *)(entity->sceneObjects + 0x14) + *(int *)(value2 + 0x20);
    *(int *)(entity->sceneObjects + 0x1c) = *(int *)(g_PlayerEntitySceneObject + 0x1c) + 2000;
    *(undefined4 *)(entity->sceneObjects + 0x18) = *(undefined4 *)(value2 + 0x24);
    value = entity->sceneObjects;
    value2 = GetWrappedSignedAngleDelta12Bit
                      ((int)((EntitySceneObject *)value)->yaw,-*(int *)(value2 + 0x1c) - 0x800U & 0xfff);
    value3 = (short *)(&((EntitySceneObject *)value)->yaw);
    *value3 = *value3 + (short)(value2 >> 2);
  }
  return;
}

