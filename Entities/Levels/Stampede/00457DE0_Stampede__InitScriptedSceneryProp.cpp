#include "tarzan_ghidra_types.hpp"

// Address: 0x00457DE0
// Label: Stampede::InitScriptedSceneryProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::InitScriptedSceneryProp(int entry)

{
  Entity *entity = (Entity *)entry;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0xe38;
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_005034b0);
  return;
}

