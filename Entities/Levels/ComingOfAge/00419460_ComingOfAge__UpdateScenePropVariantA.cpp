#include "tarzan_ghidra_types.hpp"

// Address: 0x00419460
// Label: ComingOfAge::UpdateScenePropVariantA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateScenePropVariantA(int entry3)

{
  Entity *entity = (Entity *)entry3;
  int entry;
  char resultFlag;
  int entry2;
  
  entry = entity->sceneObjects;
  if (entry != 0) {
    entry2 = CEntities::FindEntityAttachmentByFlags(entry3,0x400);
    if (entry2 != 0) {
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry3);
      CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry3,entry,8,8);
      if ((*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)entry)->surfacePathIndex * 4) + 8 +
                    ((EntitySceneObject *)entry)->surfacePathIndex * 4 + g_CollisionSurfaceTable) - ((EntitySceneObject *)entry)->surfaceIndex
           < 0x14) && (*(char *)(entry + 0x75) == '\0')) {
        *(undefined1 *)(entry + 0x75) = 0xff;
      }
      else if ((((EntitySceneObject *)entry)->surfaceIndex < 0x14) && (*(char *)(entry + 0x75) == -1)) {
        *(undefined1 *)(entry + 0x75) = 0;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry3);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry3);
  }
  return;
}

