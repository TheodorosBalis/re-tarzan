#include "tarzan_ghidra_types.hpp"

// Address: 0x00427750
// Label: ElephantHairDare::InitYoungRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitYoungRhino(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0xc30;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0x100;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_ElephantHairDareYoungRhinoScriptDesc)
    ;
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
  }
  return;
}

