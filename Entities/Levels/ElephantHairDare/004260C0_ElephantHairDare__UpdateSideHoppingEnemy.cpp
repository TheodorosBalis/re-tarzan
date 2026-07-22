#include "tarzan_ghidra_types.hpp"

// Address: 0x004260C0
// Label: ElephantHairDare::UpdateSideHoppingEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateSideHoppingEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  char resultFlag;
  short shortValue2;
  int value;
  undefined4 value4;
  int value2;
  int value3;
  
  value3 = entity->sceneObjects;
  if ((value3 != 0) &&
     (value = CEntities::FindEntityAttachmentByFlags(entry,0x400), value != 0)) {
    shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value2 = *(int *)(entry + 0x50);
    shortValue = *(short *)(value + 0x18);
    if ((*(byte *)(entry + 0x4a) & 1) != 0) {
      value4 = CEntities::AdvanceEntityAlongJungleSurface(entry,value3,8,8);
      *(undefined4 *)(entry + 0x50) = value4;
    }
    if (shortValue2 == 4) {
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
    }
    else if (shortValue2 == 0x105) {
      *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 1;
    }
    else if (shortValue2 == 0x107) {
      *(byte *)(value3 + 0x75) = ~*(byte *)(value3 + 0x75);
      CEntities::AdvanceEntityAlongJungleSurface(entry,value3,0,0x40);
    }
    switch(*(undefined2 *)(entry + 0x48)) {
    case 0:
      CEntities::SelectScriptAttachmentSequence(value,0);
      *(undefined2 *)(entry + 0x48) = 1;
      value3 = RandomModulo(0x14);
      *(int *)(entry + 0x4c) = value3 + 10;
      break;
    case 1:
      value2 = *(int *)(entry + 0x4c) + -1;
      *(int *)(entry + 0x4c) = value2;
      if ((value2 < 1) && ((shortValue2 == 3 || (shortValue2 == 2)))) {
        value4 = RandomModulo(7);
        switch(value4) {
        case 0:
          *(undefined2 *)(entry + 0x48) = 7;
          CEntities::SelectScriptAttachmentSequence(value,1);
          break;
        case 1:
          *(undefined2 *)(entry + 0x48) = 7;
          CEntities::SelectScriptAttachmentSequence(value,4);
          break;
        case 2:
          value = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value3)->surfacePathIndex * 4) + 8 +
                           ((EntitySceneObject *)value3)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
          if (*(char *)(value3 + 0x75) == '\0') {
            if (value / 2 < *(int *)(entry + 0x50)) {
              *(undefined2 *)(entry + 0x48) = 4;
            }
          }
          else if (*(int *)(entry + 0x50) < value / 2) {
            *(undefined2 *)(entry + 0x48) = 4;
          }
          break;
        case 3:
        case 4:
        case 5:
        case 6:
          *(undefined2 *)(entry + 0x48) = 2;
          CEntities::SelectScriptAttachmentSequence(value,0);
        }
      }
      break;
    case 2:
      *(undefined2 *)(entry + 0x48) = 3;
      value3 = RandomModulo(7);
      *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 1;
      *(int *)(entry + 0x4c) = value3 + 1;
      CEntities::SelectScriptAttachmentSequence(value,7);
      break;
    case 3:
      if (((shortValue2 == 3) || (shortValue2 == 2)) &&
         (value3 = *(int *)(entry + 0x4c) + -1, *(int *)(entry + 0x4c) = value3, value3 < 1)) {
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
        *(undefined2 *)(entry + 0x48) = 0;
        CEntities::SelectScriptAttachmentSequence(value,0);
      }
      if (*(int *)(entry + 0x50) == value2) {
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
        *(undefined2 *)(entry + 0x48) = 5;
      }
      break;
    case 4:
      CEntities::SelectScriptAttachmentSequence(value,8);
      *(undefined2 *)(entry + 0x48) = 7;
      break;
    case 5:
      CEntities::SelectScriptAttachmentSequence(value,0xb);
      *(undefined2 *)(entry + 0x48) = 6;
      break;
    case 6:
      if (shortValue == 7) {
        *(undefined2 *)(entry + 0x48) = 2;
      }
      break;
    case 7:
      if (shortValue == 0) {
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

