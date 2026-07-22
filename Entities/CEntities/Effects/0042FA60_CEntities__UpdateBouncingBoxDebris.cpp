#include "tarzan_ghidra_types.hpp"

// Address: 0x0042FA60
// Label: CEntities::UpdateBouncingBoxDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateBouncingBoxDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value3;
  char resultFlag;
  int value;
  int value2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
  if (value != 0) {
    value2 = CEntities::AdvanceEntityBounceMotionAndReturnImpact(entry);
    if (value2 != 0) {
      if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) != '\x04') {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      value = entity->sceneObjects;
      value = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + 0x100,
                         ((EntitySceneObject *)value)->z,0x178,0x11);
      if (value != 0) {
        *(int *)(*(int *)(value + 0x38) + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x30c0;
        *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x2054;
        value = CEntities::FindEntityAttachmentByFlags(value,0x10000000);
        if (value != 0) {
          value2 = *(int *)(entity->sceneObjects + 0x18);
          *(undefined4 *)(value + 0x524) = 0x100;
          ((EntitySceneObject *)value)->next = value2 + 0x200;
        }
      }
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    value3 = (short *)(entity->sceneObjects + 0xa0);
    *value3 = *value3 + *(short *)(value + 0x54);
    value3 = (short *)(entity->sceneObjects + 0xa4);
    *value3 = *value3 + *(short *)(value + 0x56);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

