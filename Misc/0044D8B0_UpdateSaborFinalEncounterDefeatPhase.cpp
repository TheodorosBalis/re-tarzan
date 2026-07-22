#include "tarzan_ghidra_types.hpp"

// Address: 0x0044D8B0
// Label: UpdateSaborFinalEncounterDefeatPhase
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateSaborFinalEncounterDefeatPhase(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int count;
  short shortValue;
  int count2;
  
  count = entity->sceneObjects;
  count2 = CEntities::FindEntityAttachmentByFlags(arg1,0x10000001);
  CEntities::FindEntityAttachmentByFlags(arg1,0x800);
  if (*(int *)(count2 + 0xc) != 0x1d) {
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(arg1);
    if (shortValue != 0) {
      *(undefined4 *)(count2 + 0xc) = 0x1d;
      *(undefined2 *)(count + 0xc) = 0x1e3;
    }
  }
  return;
}

