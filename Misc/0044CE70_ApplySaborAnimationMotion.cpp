#include "tarzan_ghidra_types.hpp"

// Address: 0x0044CE70
// Label: ApplySaborAnimationMotion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ApplySaborAnimationMotion(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  int value2;
  int value3;
  
  value = entity->sceneObjects;
  value2 = CEntities::FindEntityAttachmentByFlags(arg1,0x10000001);
  value3 = CEntities::FindEntityAttachmentByFlags(arg1,0x800);
  ((EntitySceneObject *)value)->y = g_SaborBattleGroundY;
  switch(*(undefined4 *)(value2 + 0xc)) {
  case 0x13:
  case 0x14:
    value2 = 0x80;
    break;
  case 0x15:
  case 0x1a:
    value2 = 0x14;
    break;
  default:
    goto switchD_0044ceb2_caseD_16;
  case 0x1f:
    value2 = *(int *)(value3 + 0x10);
    goto LAB_0044cf0d;
  case 0x24:
    value2 = -0x30;
    break;
  case 0x2c:
    value2 = (*(ushort *)(value + 0xc) - 0xb5) * 0x80;
    value2 = value2 / 6 + (value2 >> 0x1f);
    goto LAB_0044cf06;
  case 0x2d:
    value2 = (0xd0 - (uint)*(ushort *)(value + 0xc)) * 0x80;
    value2 = value2 / 0xc + (value2 >> 0x1f);
LAB_0044cf06:
    value2 = value2 - (value2 >> 0x1f);
LAB_0044cf0d:
    if (value2 == 0) goto switchD_0044ceb2_caseD_16;
  }
  if (*(char *)(value + 0x75) == -1) {
    value2 = -value2;
  }
  CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(value,value2);
switchD_0044ceb2_caseD_16:
  *(undefined4 *)(value3 + 0x20) = 0;
  return;
}

