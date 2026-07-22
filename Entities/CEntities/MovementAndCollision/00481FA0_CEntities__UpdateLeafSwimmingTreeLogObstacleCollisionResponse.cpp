#include "tarzan_ghidra_types.hpp"

// Address: 0x00481FA0
// Label: CEntities::UpdateLeafSwimmingTreeLogObstacleCollisionResponse
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateLeafSwimmingTreeLogObstacleCollisionResponse(int entry)

{
  Entity *entity = (Entity *)entry;
  uint *dataCursor;
  int value;
  int value2;
  uint value3;
  undefined1 localState4 [20];
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000001);
  if (value != 0) {
    BuildBasisMatrixFromEulerAngles(value + 0xc,localState4);
    localState3 = 0;
    localState2 = 0;
    localState = 0;
    dataCursor = (uint *)(value + 0x24);
    *dataCursor = *(int *)(g_PlayerEntitySceneObjectData + 8) -
              *(int *)(entity->sceneObjects + 0x14);
    *(int *)(value + 0x28) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(entity->sceneObjects + 0x18);
    *(int *)(value + 0x2c) =
         *(int *)(g_PlayerEntitySceneObjectData + 0x10) - *(int *)(entity->sceneObjects + 0x1c);
    TransformVectorByBasis(localState4,dataCursor,dataCursor);
    if ((((-*(int *)(value + 0x14) >> 1 < (int)*dataCursor) &&
         ((int)*dataCursor < *(int *)(value + 0x14) >> 1)) && (0 < *(int *)(value + 0x2c))) &&
       (*(int *)(value + 0x2c) < *(int *)(value + 0x1c))) {
      value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000002);
      if (value2 != 0) {
        *(undefined4 *)(value2 + 0x14) = 0;
        *(undefined4 *)(value2 + 0xc) = 0;
        *(undefined4 *)(value2 + 0x10) = 0;
        *(undefined4 *)(value2 + 0x18) = 0x96;
        *(int *)(value2 + 0x14) = (int)*(short *)(value + 0xe);
        *(undefined4 *)(value2 + 0xc) = *(undefined4 *)(value + 0x34);
        value3 = (int)*dataCursor >> 0x1f;
        *(int *)(value2 + 0x10) =
             0xff - (int)(((*dataCursor ^ value3) - value3) * 0x100) / (*(int *)(value + 0x14) >> 1);
      }
    }
    LeafSwimmingObstacleCollisionDebugHookStub
              (entity->sceneObjects + 0x14,value + 0xc,(int *)(value + 0x14));
  }
  return;
}

