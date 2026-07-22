#include "tarzan_ghidra_types.hpp"

// Address: 0x004290A0
// Label: ElephantHairDare::InitWaterSurfaceEffect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitWaterSurfaceEffect(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x14,0x10000000);
  if (value != 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 1;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_ElephantHairDareWaterSurfaceEffectScriptDesc);
    *(int *)(value + 0x10) = value2;
    if (value2 != 0) {
      *(undefined4 *)(value + 0xc) = 0;
      *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1450;
      CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),0);
    }
  }
  return;
}

