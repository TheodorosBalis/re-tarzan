#include "tarzan_ghidra_types.hpp"

// Address: 0x00445580
// Label: CEntities::TransformChildSceneObjectLocalPointToWorld
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::TransformChildSceneObjectLocalPointToWorld
               (undefined4 entry,int sceneObject,int *attachment)

{
  Entity *entity2 = (Entity *)sceneObject;
  TransformShortVectorByBasis(sceneObject + 0x2c,entry,&g_SceneTransformScratch_Field0000);
  *attachment = *(int *)(sceneObject + 0x20);
  attachment[1] = *(int *)(sceneObject + 0x24);
  attachment[2] = *(int *)(sceneObject + 0x28);
  *attachment = *attachment + (int)g_SceneTransformScratch_Field0000;
  attachment[1] = attachment[1] + (int)g_SceneTransformScratch_Field0002;
  attachment[2] = attachment[2] + (int)g_SceneTransformScratch_Field0004;
  return;
}

