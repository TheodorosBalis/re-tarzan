#include "tarzan_ghidra_types.hpp"

// Address: 0x0045DE70
// Label: JourneyToTheTreeHouse::InitAmbientSoundEmitterC9
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitAmbientSoundEmitterC9(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  PlayAudioById(0xc9,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
  *(undefined2 *)(value + 0xe) = 0;
  return;
}

