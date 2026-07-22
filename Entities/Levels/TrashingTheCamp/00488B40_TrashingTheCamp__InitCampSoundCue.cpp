#include "tarzan_ghidra_types.hpp"

// Address: 0x00488B40
// Label: TrashingTheCamp::InitCampSoundCue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitCampSoundCue(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xe) = 0;
    if (entity->descriptor != 0) {
      value2 = *(int *)(*(int *)(entity->descriptor + 0x10) + 4);
      if (value2 == 1) {
        PlayAudioById(0x29b,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
      }
      else if (value2 == 2) {
        PlayAudioById(0x29b,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
        PlayAudioById(0x29c,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
      }
    }
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

