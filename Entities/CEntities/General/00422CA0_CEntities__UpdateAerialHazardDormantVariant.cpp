#include "tarzan_ghidra_types.hpp"

// Address: 0x00422CA0
// Label: CEntities::UpdateAerialHazardDormantVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateAerialHazardDormantVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value;
  undefined4 value4;
  uint value5;
  int value2;
  uint value6;
  int value3;
  
  value3 = entity->sceneObjects;
  if ((value3 == 0) ||
     (value = CEntities::FindEntityAttachmentByFlags(entry,0x400), value == 0))
  goto LAB_00422e67;
  if (*(short *)(entry + 0x48) == 0) {
    if ((((EntitySceneObject *)value3)->y - *(int *)(g_PlayerEntitySceneObject + 0x18) < 200) &&
       (value2 = CEntities::ComputeSceneObjectDataXZDistanceScaled64
                          (value3 + 0xc,g_PlayerEntitySceneObjectData), value2 < 1000)) {
      value4 = RandomModulo(0xffff);
      *(undefined4 *)(entry + 0x4c) = value4;
      *(undefined4 *)(entry + 0x50) = 0x28;
      *(byte *)(value3 + 0xf) = *(byte *)(value3 + 0xf) | 0x80;
      CEntities::SelectScriptAttachmentSequence(value,1);
      *(undefined2 *)(entry + 0x48) = 6;
    }
    goto LAB_00422e67;
  }
  if (*(short *)(entry + 0x48) != 6) goto LAB_00422e67;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 0x10f) {
    value4 = RandomModulo(4);
    switch(value4) {
    case 0:
      value4 = 0x124;
      break;
    case 1:
      value4 = 0x125;
      break;
    case 2:
      value4 = 0x126;
      break;
    case 3:
      value4 = 0x127;
      break;
    default:
      goto switchD_00422cff_default;
    }
    PlayAudioById(value4,(int *)&((EntitySceneObject *)value3)->soundPosition,(undefined4 *)&((EntitySceneObject *)value3)->x);
  }
switchD_00422cff_default:
  value6 = (*(uint *)(entry + 0x4c) & 0xff) << 2;
  value5 = (int)*(uint *)(entry + 0x4c) >> 4 & 0xff0;
  if ((value6 & 0x200) != 0) {
    value6 = 0x1000 - (value6 & 0x1ff);
  }
  ((EntitySceneObject *)value3)->x =
       ((EntitySceneObject *)value3)->x -
       (((int)(short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] << 6) >> 0xc);
  ((EntitySceneObject *)value3)->z =
       ((EntitySceneObject *)value3)->z - (((int)(short)(&g_SinCosTable12Bit)[value5] << 6) >> 0xc);
  shortValue = (&g_SinCosTable12Bit)[value6 & 0xfff];
  ((EntitySceneObject *)value3)->yaw = (short)value5;
  ((EntitySceneObject *)value3)->y = ((EntitySceneObject *)value3)->y - (((int)shortValue << 6) >> 0xc);
  *(short *)(value3 + 0xa0) = (short)value6;
  value4 = RandomModulo(0x14);
  *(undefined4 *)(value3 + 0x40) = value4;
  value3 = *(int *)(entry + 0x50) + -1;
  *(int *)(entry + 0x50) = value3;
  if (value3 < 1) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
LAB_00422e67:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

