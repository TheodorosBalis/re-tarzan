#include "tarzan_ghidra_types.hpp"

// Address: 0x00453B10
// Label: UpdateIntroScriptedPropB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateIntroScriptedPropB(int arg1)

{
  Entity *entity = (Entity *)arg1;
  if (g_IntroScriptedPropsDisabled == '\0') {
    if (entity->sceneObjects != 0) {
      CEntities::UpdateScriptedEntitySceneObjectAttachment();
      return;
    }
    CEntities::ReleaseEntityToFreeList((byte *)arg1);
  }
  return;
}

