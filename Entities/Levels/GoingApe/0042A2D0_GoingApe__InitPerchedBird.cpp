#include "tarzan_ghidra_types.hpp"

// Address: 0x0042A2D0
// Label: GoingApe::InitPerchedBird
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitPerchedBird(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  
  GoingApe::InitBirdCommon(entry);
  CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,0);
  value3 = entity->sceneObjects;
  if (value3 != 0) {
    value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
    if (value != 0) {
      *(code **)(value + 0xc) = GoingApe::TriggerBirdTakeoffWhenPlayerNear;
      *(undefined2 *)(value + 0x10) = 0;
      *(undefined2 *)(value + 0x14) = 0x28;
      *(undefined2 *)(value + 0x16) = 0;
      *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 0xf;
      *(undefined2 *)(entry + 0x48) = 0;
      value2 = RandomModulo(0x28);
      *(int *)(entry + 0x4c) = value2 + 0x1e;
      switch(*(undefined2 *)(value + 0x20)) {
      case 0:
      case 2:
      case 5:
        *(undefined4 *)(value3 + 0x70) = 1;
        break;
      case 1:
      case 3:
        *(undefined4 *)(value3 + 0x70) = 3;
        break;
      case 4:
        *(undefined4 *)(value3 + 0x70) = 0;
        break;
      case 6:
        *(undefined4 *)(value3 + 0x70) = 4;
        break;
      case 7:
        *(undefined4 *)(value3 + 0x70) = 5;
      }
    }
    value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
    if (value3 != 0) {
      CEntities::SelectScriptAttachmentSequence(value3,1);
    }
  }
  return;
}

