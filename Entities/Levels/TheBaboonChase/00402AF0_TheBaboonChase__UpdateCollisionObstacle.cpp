#include "tarzan_ghidra_types.hpp"

// Address: 0x00402AF0
// Label: TheBaboonChase::UpdateCollisionObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdateCollisionObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  int localState2 [2];
  int localState;
  
  value = entry;
  resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                    (g_PlayerEntitySceneObject,0x200,entity->sceneObjects,0x200,&entry,
                     localState2);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(value,7);
    value2 = CEntities::IsEntityVectorMostlyPositiveX(value,g_PlayerEntity);
    g_JaneDamageReactionType = (uint)(value2 == 0);
    g_PlayerFacingCurrentCollisionSurface = 1;
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

