#include "tarzan_ghidra_types.hpp"

// Address: 0x00482300
// Label: CEntities::UpdateLeafSwimmingTreeLogObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateLeafSwimmingTreeLogObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value2;
  int value;
  char resultFlag;
  int localState2 [2];
  int localState;
  
  value = entry;
  value2 = (short *)(entity->sceneObjects + 0xa2);
  *value2 = *value2 + 0x12;
  resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                    (g_PlayerEntitySceneObject,0x200,entity->sceneObjects,0x200,&entry,
                     localState2);
  if (resultFlag != '\0') {
    *(int *)(g_PlayerEntitySceneObject + 0x14) =
         *(int *)(g_PlayerEntitySceneObject + 0x14) + localState2[0];
    *(int *)(g_PlayerEntitySceneObject + 0x1c) =
         *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState;
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

