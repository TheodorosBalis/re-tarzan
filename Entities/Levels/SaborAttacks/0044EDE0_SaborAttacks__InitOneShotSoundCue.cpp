#include "tarzan_ghidra_types.hpp"

// Address: 0x0044EDE0
// Label: SaborAttacks::InitOneShotSoundCue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitOneShotSoundCue(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined4 soundMask;
  
  if (entity->descriptor == 0) goto LAB_0044ee2e;
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = *(int *)(*(int *)(entity->descriptor + 0x10) + 4);
    if (value2 == 1) {
      soundMask = 0x29b;
    }
    else {
      if (value2 != 2) goto LAB_0044ee27;
      soundMask = 0x29c;
    }
    PlayAudioById(soundMask,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
  }
LAB_0044ee27:
  if (*(short *)(entry + 0x44) == 0) {
    return;
  }
LAB_0044ee2e:
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

