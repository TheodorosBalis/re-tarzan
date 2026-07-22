#include "tarzan_ghidra_types.hpp"

// Address: 0x0044D360
// Label: UpdateSaborLeapAttackPhase
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateSaborLeapAttackPhase(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  short shortValue;
  int value2;
  undefined4 value3;
  
  value = entity->sceneObjects;
  value2 = CEntities::FindEntityAttachmentByFlags(arg1,0x10000001);
  value3 = CEntities::FindEntityAttachmentByFlags(arg1,0x800);
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(arg1);
  if (shortValue != 0) {
    *(undefined4 *)(value2 + 0xc) = 0x17;
    SetSaborAnimationStateAndAdvance(arg1,4);
  }
  if (*(int *)(value2 + 0xc) == 0xd) {
    ComputeEntitySceneObjectCollisionMoveDelta(0xfffffff8,0,value);
    IntegrateSaborLeapMotion(value,value3);
    if (*(int *)(g_PlayerEntitySceneObject + 0x18) <= ((EntitySceneObject *)value)->y) {
      ((EntitySceneObject *)value)->y = *(int *)(g_PlayerEntitySceneObject + 0x18);
      *(undefined4 *)(value2 + 0xc) = 0x17;
      SetSaborAnimationStateAndAdvance(arg1,4);
    }
  }
  return;
}

