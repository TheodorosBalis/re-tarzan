#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B290
// Label: CampsiteCommotion::SpawnBarrelWorkerVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::SpawnBarrelWorkerVariant(int entry)

{
  int value;
  int value2;
  
  value2 = CEntities::SpawnEntityByTypeAtPosition(0,0,0,0x107,0x11);
  if ((value2 == 0) || (value = *(int *)(value2 + 0x38), value == 0)) goto LAB_0040b3ac;
  *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
  *(undefined2 *)(value + 0xa6) = 0;
  if (g_CampsiteCommotionBarrelWorkerSurfaceIndex != -1) {
    *(int *)(value + 0x110) = g_CampsiteCommotionBarrelWorkerSurfaceIndex;
    *(undefined4 *)(value + 0x10c) =
         *(undefined4 *)
          (*(int *)(g_CollisionSurfaceTable + 4 + g_CampsiteCommotionBarrelWorkerSurfaceIndex * 4) +
           0x40 + (*(int *)(&g_CampsiteCommotionBarrelWorkerSurfaceOffsetTable + entry * 4) * 7 +
                  g_CampsiteCommotionBarrelWorkerSurfaceIndex) * 4 + g_CollisionSurfaceTable);
  }
  *(undefined4 *)(value + 0x108) = 1;
  UpdateEntityEntitySceneObjectTransformFromPlacement(value);
  *(undefined4 *)(value + 0x18) = *(undefined4 *)(value + 0x58);
  *(undefined4 *)(value + 0x14) = *(undefined4 *)(value + 0x54);
  *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value + 0x5c);
  *(ushort *)(value + 0xa2) = *(ushort *)(value + 0x132) ^ 0x800;
  *(int *)(value + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1ad0;
  CEntities::AcquireEntitySceneObjectResourceSet(value);
  if (entry == 1) {
    *(undefined4 *)(value + 0x70) = 2;
LAB_0040b386:
    CEntities::SetEntitySceneObjectScriptAttachment
              (value2,&g_CampsiteCommotionBarrelWorkersScriptDesc);
  }
  else {
    if (entry != 2) {
      *(undefined4 *)(value + 0x70) = 1;
      goto LAB_0040b386;
    }
    *(undefined4 *)(value + 0x70) = 0;
    CEntities::SetEntitySceneObjectScriptAttachment
              (value2,&g_CampsiteCommotionBarrelWorkersScriptDesc);
  }
  *(undefined2 *)(value2 + 0x48) = 0;
  *(undefined4 *)(value2 + 0x4c) = 0;
  *(undefined2 *)(value2 + 0x4a) = 0;
  CEntities::MoveEntitySceneObjectAndSnapFacingAngles(value2,0);
LAB_0040b3ac:
  if (*(short *)(value2 + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)value2);
  }
  return;
}

