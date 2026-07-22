#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B030
// Label: CampsiteCommotion::UpdateBarrelEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateBarrelEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  undefined4 value3;
  
  value2 = entity->sceneObjects;
  if (value2 == 0) goto LAB_0040b199;
  value = GetSceneAttachmentWorldPositionByMask(value2,0x100,&g_BranchBoostChildWorldPositionScratch)
  ;
  if (((value != 0) && (*(int *)(entry + 0x18) != 0)) &&
     (value = *(int *)(*(int *)(entry + 0x18) + 0x38), value != 0)) {
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 0x80;
    *(undefined4 *)(value + 0x14) = g_BranchBoostChildWorldPositionScratch;
    *(undefined4 *)(value + 0x18) = g_BranchBoostChildSceneObjectPtrScratch;
    *(undefined4 *)(value + 0x1c) = g_BranchBoostChildWorldPositionZScratch;
    *(undefined2 *)(value + 0xa2) = ((EntitySceneObject *)value2)->yaw;
    *(short *)(value + 0xa0) = *(short *)(value + 0xa0) + *(short *)(entry + 0x4c) * 2;
  }
  value = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value == 0) goto LAB_0040b199;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  value2 = ((EntitySceneObject *)value2)->surface;
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
switchD_0040b0e4_caseD_0:
    *(undefined2 *)(entry + 0x48) = 3;
    *(undefined4 *)(entry + 0x4c) = 0x18;
    value3 = 4;
LAB_0040b182:
    CEntities::SelectScriptAttachmentSequence(value,value3);
    break;
  case 3:
    if ((value2 != 0) && ((((EntitySceneObject *)value2)->x & 1) != 0)) {
      *(undefined2 *)(entry + 0x48) = 6;
      *(undefined4 *)(entry + 0x4c) = 0;
      value3 = 0xc;
      goto LAB_0040b182;
    }
    break;
  case 6:
    if ((*(int *)(entry + 0x18) == 0) &&
       (value2 = CEntities::SpawnEntityByTypeAtPosition
                          (g_BranchBoostChildWorldPositionScratch,
                           g_BranchBoostChildSceneObjectPtrScratch,
                           g_BranchBoostChildWorldPositionZScratch,0xff,0x11), value2 != 0)) {
      CEntities::AppendEntityToChildChain(entry,value2);
    }
    if (shortValue != 0) {
      *(undefined4 *)(entry + 0x4c) = 0x12;
      *(undefined2 *)(entry + 0x48) = 0xd;
    }
    break;
  case 0xd:
    if ((value2 != 0) && ((((EntitySceneObject *)value2)->x & 8) != 0)) {
      if (*(int *)(entry + 0x18) != 0) {
        CEntities::ReleaseEntityToFreeList(*(int *)(entry + 0x18));
      }
      goto switchD_0040b0e4_caseD_0;
    }
  }
  CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,*(undefined4 *)(entry + 0x4c));
LAB_0040b199:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    if (*(int *)(entry + 0x18) != 0) {
      CEntities::ReleaseEntityToFreeList(*(int *)(entry + 0x18));
    }
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

