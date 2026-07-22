#include "tarzan_ghidra_types.hpp"

// Address: 0x0041E210
// Label: CEntities::UpdateChargingAnimalVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateChargingAnimalVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  char resultFlag;
  short shortValue2;
  int value2;
  
  value = entity->sceneObjects;
  if ((value == 0) ||
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value2 == 0))
  goto switchD_0041e292_caseD_1;
  shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value2 + 0x18);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value,0,0x10);
  CEntities::HandleAnimalScriptEvent(entry,value,(int)shortValue2);
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    CEntities::SelectScriptAttachmentSequence(value2,0);
    *(undefined2 *)(entry + 0x48) = 1;
    break;
  case 2:
    CEntities::SelectScriptAttachmentSequence(value2,10);
    *(undefined2 *)(entry + 0x48) = 4;
    break;
  case 3:
    if ((((EntitySceneObject *)value)->surfaceIndex < 0x12d) && (*(char *)(value + 0x75) == -1)) {
      *(undefined2 *)(entry + 0x48) = 6;
      CEntities::SelectScriptAttachmentSequence(value2,0xc);
    }
    else if ((*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                       ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable) -
              ((EntitySceneObject *)value)->surfaceIndex < 0x12d) && (*(char *)(value + 0x75) == '\0')) {
      *(undefined2 *)(entry + 0x48) = 6;
      CEntities::SelectScriptAttachmentSequence(value2,0xc);
    }
    break;
  case 4:
    goto joined_r0x0041e31e;
  case 5:
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
    break;
  case 6:
joined_r0x0041e31e:
    if (shortValue == 0xb) {
      *(undefined2 *)(entry + 0x48) = 3;
    }
  }
switchD_0041e292_caseD_1:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

