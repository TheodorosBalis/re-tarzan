#include "tarzan_ghidra_types.hpp"

// Address: 0x004741B0
// Label: CEntities::StartKerchakChasePursuerFromPlayer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::StartKerchakChasePursuerFromPlayer(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value3;
  int value;
  int value2;
  
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0xea0;
  *(undefined4 *)(entity->sceneObjects + 0x14) =
       *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
  *(undefined4 *)(entity->sceneObjects + 0x18) =
       *(undefined4 *)(g_PlayerEntitySceneObject + 0x18);
  *(int *)(entity->sceneObjects + 0x1c) = *(int *)(g_PlayerEntitySceneObject + 0x1c) + 2000;
  CEntities::SetEntitySceneObjectScriptAttachment
            (entry,&g_KerchakChasePursuerScriptAttachmentConfig);
  value3 = (byte *)(entity->sceneObjects + 0xf);
  *value3 = *value3 | 8;
  if (g_KerchakChasePrimaryPursuerEntity == 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffff80;
    g_KerchakChasePrimaryPursuerEntity = entry;
  }
  *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x1400;
  *(undefined4 *)(entity->sceneObjects + 0xac) = 0x1400;
  *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x1400;
  PlayAudioById(0x327,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
  value = CEntities::FindEntityAttachmentByFlags(entry,0x40000000);
  if (value == 0) {
    CEntities::CreateEntityAttachment(entry,0x38,0x40000000);
  }
  value = CEntities::FindEntityAttachmentByFlags(entry,0x40000000);
  if (value != 0) {
    value2 = *(int *)(g_CollisionSurfaceTable + 0x10) + 0x10 + g_CollisionSurfaceTable;
    *(int *)(value + 0xc) = value2;
    value2 = FindRuntimePathSegmentForEntitySceneObject(value2,g_PlayerEntitySceneObject);
    *(int *)(value + 0x10) = value2;
    *(int *)(value + 0x18) = value2;
    *(undefined4 *)(value + 0x30) = 0;
    *(int *)(value + 0x14) = *(int *)(value + 0xc) + 0x30 + value2 * 0x1c;
    *(undefined4 *)(value + 0x34) = 0;
    AdvanceRuntimePathAttachmentFromEntitySceneObject(entry);
    *(int *)(entity->sceneObjects + 0x14) =
         *(int *)(entity->sceneObjects + 0x14) + *(int *)(value + 0x20);
    *(undefined4 *)(entity->sceneObjects + 0x18) = *(undefined4 *)(value + 0x24);
  }
  return;
}

