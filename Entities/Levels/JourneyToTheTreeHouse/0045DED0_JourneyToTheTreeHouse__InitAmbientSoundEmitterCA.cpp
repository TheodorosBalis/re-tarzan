#include "tarzan_ghidra_types.hpp"

// Address: 0x0045DED0
// Label: JourneyToTheTreeHouse::InitAmbientSoundEmitterCA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitAmbientSoundEmitterCA(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  PlayAudioById(0xca,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
  *(undefined2 *)(value + 0xe) = 0;
  return;
}

