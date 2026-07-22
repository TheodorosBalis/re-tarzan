#include "tarzan_ghidra_types.hpp"

// Address: 0x004613A0
// Label: TarzanToTheRescue::InitElephantMountTarget
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitElephantMountTarget(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x10,0x10000000);
  if (value != 0) {
    LoadEncodedResourceId(0x68);
    LoadEncodedResourceId(0x27);
    ReleaseWorldSceneAuxResourceNoOp(g_CurrentWorldSceneContext,3);
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0xfd8;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x14;
    *(undefined2 *)(entity->sceneObjects + 0xa2) = 0x800;
    g_AdultTarzanElephantMountTargetEntity = entry;
    if (g_AdultTarzanElephantEntitySceneObject != 0) {
      *(ushort *)(g_AdultTarzanElephantEntitySceneObject + 0xe) =
           *(ushort *)(g_AdultTarzanElephantEntitySceneObject + 0xe) & 0x7fff;
    }
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TarzanToTheRescueElephantMountTargetScriptDesc);
    *(int *)(value + 0xc) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0);
    }
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  }
  return;
}

