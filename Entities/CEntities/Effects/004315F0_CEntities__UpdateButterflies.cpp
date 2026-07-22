#include "tarzan_ghidra_types.hpp"

// Address: 0x004315F0
// Label: CEntities::UpdateButterflies
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateButterflies(int entry)

{
  Entity *entity = (Entity *)entry;
  byte flagByte;
  int value;
  char resultFlag;
  undefined2 value3;
  int value2;
  uint value4;
  
  value = entity->sceneObjects;
  if (*(short *)(entry + 0x48) != 8) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    value3 = RandomModulo(0x20);
    ((EntitySceneObject *)value)->yaw = value3;
    value2 = RandomModulo(0x40);
    ((EntitySceneObject *)value)->x = ((EntitySceneObject *)value)->x + value2 + -0x20;
    value2 = RandomModulo(0x20);
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + value2 + -0x10;
    value2 = RandomModulo(0x20);
    ((EntitySceneObject *)value)->z = ((EntitySceneObject *)value)->z + value2 + -0x10;
    CEntities::ClampEffectSceneObjectNearSourcePosition(entry,400);
    break;
  case 8:
    *(short *)(entry + 0x4a) = *(short *)(entry + 0x4a) + -1;
    if (*(short *)(entry + 0x4a) == 0) {
      *(undefined2 *)(entry + 0x48) = 0x1c;
    }
    break;
  case 0x1c:
    value2 = ((EntitySceneObject *)value)->surface;
    CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
              (value,*(undefined4 *)(entry + 0x4c));
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
    if ((*(byte *)(value + 0x13c) & 2) == 0) {
      if ((value2 != ((EntitySceneObject *)value)->surface) &&
         (flagByte = *(byte *)(((EntitySceneObject *)value)->surface + 0x14), (flagByte & 7) != 0)) {
        *(undefined2 *)(entry + 0x48) = 0x26;
        *(ushort *)(entry + 0x4a) = (flagByte & 7) << 5;
      }
    }
    else {
      *(int *)(entry + 0x4c) = -*(int *)(entry + 0x4c);
      flagByte = *(byte *)(((EntitySceneObject *)value)->surface + 0x14);
      if ((flagByte & 7) != 0) {
        *(undefined2 *)(entry + 0x48) = 8;
        *(ushort *)(entry + 0x4a) = (flagByte & 7) << 5;
      }
    }
    value4 = *(int *)(entry + 0x50) + 1;
    *(uint *)(entry + 0x50) = value4;
    value2 = *(int *)(&g_ButterfliesVerticalBobOffsetTable + (value4 & 0xf) * 4);
    goto LAB_00431755;
  case 0x26:
    *(short *)(entry + 0x4a) = *(short *)(entry + 0x4a) + -1;
    if (*(short *)(entry + 0x4a) == 0) {
      *(undefined2 *)(entry + 0x48) = 0x1c;
    }
    value2 = ((int)(short)(&g_SinCosTable12Bit)[(TotalGameLoopTicks - 8U & 0x1f) * 0x80] << 1) >> 0xc
    ;
LAB_00431755:
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + value2;
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

