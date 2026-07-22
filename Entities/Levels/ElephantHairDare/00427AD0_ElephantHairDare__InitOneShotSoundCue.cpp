#include "tarzan_ghidra_types.hpp"

// Address: 0x00427AD0
// Label: ElephantHairDare::InitOneShotSoundCue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitOneShotSoundCue(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  if (entity->descriptor != 0) {
    value = entity->sceneObjects;
    if (value != 0) {
      PlayAudioById(*(undefined2 *)
                     (&g_ElephantHairDareOneShotSoundCueIdTable +
                     *(int *)(*(int *)(entity->descriptor + 0x10) + 4) * 2),&((EntitySceneObject *)value)->soundPosition,
                    &((EntitySceneObject *)value)->x);
    }
    if (*(short *)(entry + 0x44) == 0) {
      return;
    }
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

