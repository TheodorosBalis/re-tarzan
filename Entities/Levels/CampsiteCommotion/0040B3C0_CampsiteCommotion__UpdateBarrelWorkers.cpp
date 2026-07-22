#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B3C0
// Label: CampsiteCommotion::UpdateBarrelWorkers
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateBarrelWorkers(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  short shortValue;
  int value3;
  undefined4 value4;
  
  value = entity->sceneObjects;
  if (value == 0) goto LAB_0040b5f6;
  value3 = GetSceneAttachmentWorldPositionByMask(value,0x100,&g_BranchBoostChildWorldPositionScratch)
  ;
  if (((value3 != 0) && (*(int *)(entry + 0x18) != 0)) &&
     (value3 = *(int *)(*(int *)(entry + 0x18) + 0x38), value3 != 0)) {
    *(byte *)(value3 + 0xf) = *(byte *)(value3 + 0xf) | 0x80;
    *(undefined4 *)(value3 + 0x14) = g_BranchBoostChildWorldPositionScratch;
    *(undefined4 *)(value3 + 0x18) = g_BranchBoostChildSceneObjectPtrScratch;
    *(undefined4 *)(value3 + 0x1c) = g_BranchBoostChildWorldPositionZScratch;
    *(undefined2 *)(value3 + 0xa2) = ((EntitySceneObject *)value)->yaw;
    *(short *)(value3 + 0xa0) = *(short *)(value3 + 0xa0) + *(short *)(entry + 0x4c) * 2;
  }
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value3 == 0) goto LAB_0040b5f6;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  value2 = ((EntitySceneObject *)value)->surface;
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
  case 1:
switchD_0040b474_caseD_0:
    *(undefined2 *)(entry + 0x48) = 3;
    *(undefined4 *)(entry + 0x4c) = 0x18;
    value4 = 0;
LAB_0040b5cb:
    CEntities::SelectScriptAttachmentSequence(value3,value4);
    break;
  case 3:
    if ((value2 != 0) && ((*(byte *)(value2 + 0x14) & 1) != 0)) {
      *(undefined2 *)(entry + 0x48) = 6;
      *(undefined4 *)(entry + 0x4c) = 0;
      value4 = 2;
      goto LAB_0040b5cb;
    }
    break;
  case 6:
    if ((*(int *)(entry + 0x18) == 0) &&
       (value3 = CEntities::SpawnEntityByTypeAtPosition
                          (g_BranchBoostChildWorldPositionScratch,
                           g_BranchBoostChildSceneObjectPtrScratch,
                           g_BranchBoostChildWorldPositionZScratch,0xff,0x11), value3 != 0)) {
      CEntities::AppendEntityToChildChain(entry,value3);
    }
    *(undefined4 *)(entry + 0x4c) = 0x12;
    *(undefined2 *)(entry + 0x48) = 0xd;
    break;
  case 0xd:
    if ((value2 != 0) && ((*(byte *)(value2 + 0x14) & 8) != 0)) {
      *(undefined2 *)(entry + 0x48) = 0xf;
      *(undefined4 *)(entry + 0x4c) = 0;
      value4 = 4;
      goto LAB_0040b5cb;
    }
    break;
  case 0xf:
    if (shortValue != 0) {
      value2 = *(int *)(entry + 0x18);
      if (value2 != 0) {
        CEntities::UnlinkEntityFromSpawnChain(value2);
        *(undefined2 *)(value2 + 0x46) = 0x109;
        *(undefined4 *)(value2 + 0x2c) = *(undefined4 *)(g_EntityTypeCallbackTable + 0x848);
        value4 = *(undefined4 *)(g_EntityTypeCallbackTable + 0x84c);
        *(undefined4 *)(value2 + 0x4c) = 0x30;
        *(undefined4 *)(value2 + 0x30) = value4;
        value2 = *(int *)(value2 + 0x38);
        if (value2 != 0) {
          *(undefined4 *)(value2 + 0x108) = 1;
          *(undefined4 *)(value2 + 0x110) = 0x6d;
          *(undefined4 *)(value2 + 0x10c) = 0;
          UpdateEntityEntitySceneObjectTransformFromPlacement(value2);
          *(int *)(value2 + 0x14) = *(int *)(value2 + 0x14) + *(int *)(value2 + 0x54);
          *(int *)(value2 + 0x18) = *(int *)(value2 + 0x18) + *(int *)(value2 + 0x58) + -0x60;
          *(int *)(value2 + 0x1c) = *(int *)(value2 + 0x1c) + *(int *)(value2 + 0x5c);
          *(ushort *)(value2 + 0xa2) = *(ushort *)(value2 + 0x132) ^ 0x800;
        }
      }
      goto switchD_0040b474_caseD_0;
    }
  }
  CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,*(undefined4 *)(entry + 0x4c));
  if ((*(byte *)(value + 0x13c) & 2) != 0) {
    ((EntitySceneObject *)value)->surfaceIndex = 0;
  }
LAB_0040b5f6:
  if (g_CampsiteCommotionBarrelWorkerSpawnerListHead == 0) {
    if (*(int *)(entry + 0x18) != 0) {
      CEntities::ReleaseEntityToFreeList(*(int *)(entry + 0x18));
    }
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

