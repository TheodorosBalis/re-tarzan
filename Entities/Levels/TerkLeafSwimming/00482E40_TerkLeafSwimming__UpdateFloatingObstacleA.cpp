#include "tarzan_ghidra_types.hpp"

// Address: 0x00482E40
// Label: TerkLeafSwimming::UpdateFloatingObstacleA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TerkLeafSwimming::UpdateFloatingObstacleA(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (*(int *)(value2 + 0xc) == 1) {
      intCursor = (int *)(entity->sceneObjects + 0x14);
      *intCursor = *intCursor + -8;
    }
    else if (*(int *)(value2 + 0xc) == 7) {
      value5 = entity->sceneObjects;
      value = *(int *)(g_PlayerEntity + 0x38);
      value3 = ((EntitySceneObject *)value5)->x - *(int *)(value + 0x14);
      value4 = ((EntitySceneObject *)value5)->y - *(int *)(value + 0x18);
      value5 = ((EntitySceneObject *)value5)->z - *(int *)(value + 0x1c);
      if (value5 * value5 + value4 * value4 + value3 * value3 <
          *(int *)(value2 + 0x18) * *(int *)(value2 + 0x18)) {
        *(undefined4 *)(value2 + 0xc) = 1;
        return;
      }
    }
  }
  return;
}

