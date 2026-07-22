#include "tarzan_ghidra_types.hpp"

// Address: 0x0043C840
// Label: WelcomeToTheJungle::UpdateChameleon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WelcomeToTheJungle::UpdateChameleon(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
    if (value2 != 0) {
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value,8,8);
      if ((*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                    ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable) - ((EntitySceneObject *)value)->surfaceIndex
           < 0x14) && (*(char *)(value + 0x75) == '\0')) {
        *(undefined1 *)(value + 0x75) = 0xff;
      }
      else if ((((EntitySceneObject *)value)->surfaceIndex < 0x14) && (*(char *)(value + 0x75) == -1)) {
        *(undefined1 *)(value + 0x75) = 0;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

