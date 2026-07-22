#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E910
// Label: CEntities::InitScriptedImpactEffect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitScriptedImpactEffect(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  
  if ((*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\f') || (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x12')) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004ec028);
  }
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x04') {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x30c0;
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004ec040);
  }
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  dataCursor = (ushort *)(entity->sceneObjects + 0xe);
  *dataCursor = *dataCursor | 0x1821;
  *(undefined4 *)(entity->sceneObjects + 0x30) = 0x800;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 3;
  return;
}

