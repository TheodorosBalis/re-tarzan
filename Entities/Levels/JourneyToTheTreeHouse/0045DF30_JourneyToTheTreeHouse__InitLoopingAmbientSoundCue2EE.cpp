#include "tarzan_ghidra_types.hpp"

// Address: 0x0045DF30
// Label: JourneyToTheTreeHouse::InitLoopingAmbientSoundCue2EE
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitLoopingAmbientSoundCue2EE(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  PlayAudioById(0x2ee,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
  *(undefined2 *)(value + 0xe) = 0;
  return;
}

