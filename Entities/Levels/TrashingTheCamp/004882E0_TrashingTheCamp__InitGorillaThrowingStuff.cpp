#include "tarzan_ghidra_types.hpp"

// Address: 0x004882E0
// Label: TrashingTheCamp::InitGorillaThrowingStuff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitGorillaThrowingStuff(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3468;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->yaw = *(undefined2 *)(value + 0x132);
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TrashingTheCampThrownPropControllerScriptDesc);
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0xb);
    }
    PlayAudioById(0x2ac,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
    g_TrashingTheCampHeldThrownPropEntity = 0;
    g_TrashingTheCampImpactThrownPropEntity = 0;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

