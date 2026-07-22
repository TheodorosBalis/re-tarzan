#include "tarzan_ghidra_types.hpp"

// Address: 0x00402570
// Label: TheBaboonChase::UpdateAnimatedHazard
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdateAnimatedHazard(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  char resultFlag;
  short shortValue2;
  int value;
  int value2;
  int value3;
  undefined4 value5;
  int value4;
  uint value6;
  int localState2 [2];
  int localState;
  
  value4 = entity->sceneObjects;
  if (((value4 == 0) ||
      (value = CEntities::FindEntityAttachmentByFlags(entry,0x400), value == 0)) ||
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x800), value2 == 0))
  goto switchD_004025c9_caseD_3;
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value3 = ((EntitySceneObject *)value4)->x - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value4 = ((EntitySceneObject *)value4)->y - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
    if ((uint)(value4 * value4 + value3 * value3) < *(uint *)(entry + 0x50)) {
      *(undefined2 *)(entry + 0x48) = 1;
      *(undefined4 *)(entry + 0x50) = 0;
      CEntities::SelectScriptAttachmentSequence(value,3);
      *(undefined4 *)(value2 + 0x20) = 0x30;
      *(undefined4 *)(value2 + 0x24) = 0;
      *(undefined4 *)(value2 + 0x28) = 8;
      *(undefined4 *)(value2 + 0x2c) = 0x50;
      *(undefined1 *)(value2 + 0xd) = 0xff;
    }
    break;
  case 1:
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value3 = *(int *)(value2 + 0x20) + (*(int *)(value2 + 0x24) - *(int *)(value2 + 0x28));
    *(int *)(value2 + 0x20) = value3;
    if (value3 < 0) {
      *(undefined4 *)(value2 + 0x20) = 0;
    }
    if (*(int *)(value2 + 0x2c) < *(int *)(value2 + 0x20)) {
      *(int *)(value2 + 0x20) = *(int *)(value2 + 0x2c);
    }
    if (*(char *)(value2 + 0xd) == '\0') {
      value3 = ((EntitySceneObject *)value4)->y + *(int *)(value2 + 0x20);
    }
    else {
      value3 = ((EntitySceneObject *)value4)->y - *(int *)(value2 + 0x20);
    }
    ((EntitySceneObject *)value4)->y = value3;
    if (*(int *)(value2 + 0x20) == 0) {
      value5 = *(undefined4 *)(value2 + 0x28);
      *(undefined4 *)(value2 + 0x28) = 0;
      *(undefined4 *)(value2 + 0x24) = value5;
      *(undefined1 *)(value2 + 0xd) = 0;
    }
    if ((*(char *)(value2 + 0xd) == '\0') &&
       (resultFlag = CEntities::CheckEntitySceneObjectVerticalImpact(value4), resultFlag != '\0')) {
      *(undefined2 *)(entry + 0x48) = 2;
    }
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x30);
    value4 = GetSceneAttachmentWorldPositionByMask(value4,0x20,localState2);
    if (value4 == 0) break;
    if (g_TarzanSurfingWithJaneActionEffectLevel != 0) {
LAB_00402871:
      if ((g_TarzanSurfingWithJaneAttachmentProbeBRadiusSquared != 0) &&
         ((uint)((localState - g_TarzanSurfingWithJaneAttachmentProbeBZ) *
                 (localState - g_TarzanSurfingWithJaneAttachmentProbeBZ) +
                (localState2[0] - g_TarzanSurfingWithJaneAttachmentProbeBX) *
                (localState2[0] - g_TarzanSurfingWithJaneAttachmentProbeBX)) <
          g_TarzanSurfingWithJaneAttachmentProbeBRadiusSquared)) {
        value4 = RandomModulo(0x20);
        *(int *)(value2 + 0x20) = value4 + 0x40;
        value4 = RandomModulo(6);
        *(int *)(value2 + 0x28) = value4 + 6;
        value4 = RandomModulo(6);
        *(int *)(value2 + 0x24) = value4 + 6;
        *(undefined4 *)(value2 + 0x2c) = 0x80;
        *(undefined1 *)(value2 + 0xd) = 0xff;
        value4 = RandomModulo(0x20);
        *(int *)(value2 + 0x10) = value4 + 0x30;
        value4 = RandomModulo(4);
        *(int *)(value2 + 0x18) = value4 + 4;
        *(undefined4 *)(value2 + 0x14) = 0;
        *(undefined4 *)(value2 + 0x2c) = 0x50;
        value4 = RandomModulo(2);
        *(char *)(value2 + 0xc) = -(value4 != 0);
        CEntities::SelectScriptAttachmentSequence(value,10);
        *(undefined2 *)(entry + 0x48) = 6;
        return;
      }
    }
    goto LAB_00402935;
  case 2:
    shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue2 == 8) {
      value3 = RandomModulo(10);
      if (value3 == 7) {
        CEntities::SelectScriptAttachmentSequence(value,3);
      }
      else if (value3 == 8) {
        CEntities::SelectScriptAttachmentSequence(value,5);
      }
      else {
        value5 = RandomModulo(3);
        CEntities::SelectScriptAttachmentSequence(value,value5);
      }
    }
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x30);
    ((EntitySceneObject *)value4)->y = ((EntitySceneObject *)value4)->y + *(int *)(value4 + 0x58);
    value3 = *(int *)(entry + 0x4c) + (-(uint)(*(int *)(entry + 0x50) != 0) & 0xfffffffe) + 1;
    *(int *)(entry + 0x4c) = value3;
    if (0x11 < value3) {
      *(undefined4 *)(entry + 0x50) = 1;
    }
    if (*(int *)(entry + 0x4c) < -0x11) {
      *(undefined4 *)(entry + 0x50) = 0;
    }
    value3 = *(int *)(entry + 0x4c);
    if (value3 < 0x10) {
      if (value3 < -0xf) {
        value3 = -0xf;
      }
    }
    else {
      value3 = 0xf;
    }
    value3 = (value3 * 0x8c) / 0xf;
    value6 = ((EntitySceneObject *)value4)->yaw + 0x400 & 0xfff;
    *(int *)(value4 + 0x3c) = -((short)(&g_SinCosTable12Bit)[value6 - 0x400 & 0xfff] * value3) >> 0xc;
    *(int *)(value4 + 0x44) = -((short)(&g_SinCosTable12Bit)[value6] * value3) >> 0xc;
    value3 = value3 + value3 / 2;
    value6 = -value3 & 0xfff;
    shortValue2 = (&g_SinCosTable12Bit)[value6 - 0x400 & 0xfff];
    ((EntitySceneObject *)value4)->pitch = (short)value6;
    *(int *)(value4 + 0x40) = -(shortValue2 * value3) >> 0xc;
    value4 = GetSceneAttachmentWorldPositionByMask(value4,0x20,localState2);
    if (value4 == 0) break;
    if (3 < g_TarzanSurfingWithJaneActionEffectLevel) goto LAB_00402871;
LAB_00402935:
    if ((g_TarzanSurfingWithJaneAttachmentProbeARadiusSquared != 0) &&
       ((uint)((localState - g_TarzanSurfingWithJaneAttachmentProbeAZ) *
               (localState - g_TarzanSurfingWithJaneAttachmentProbeAZ) +
              (localState2[0] - g_TarzanSurfingWithJaneAttachmentProbeAX) *
              (localState2[0] - g_TarzanSurfingWithJaneAttachmentProbeAX)) <
        g_TarzanSurfingWithJaneAttachmentProbeARadiusSquared)) {
      QueuePlayerDamageEvent(entry,8);
    }
    break;
  case 6:
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (*(char *)(value2 + 0xd) == '\0') {
      value = *(int *)(value2 + 0x20) + *(int *)(value2 + 0x24);
      *(int *)(value2 + 0x20) = value;
      if (*(int *)(value2 + 0x2c) < value) {
        *(int *)(value2 + 0x20) = *(int *)(value2 + 0x2c);
      }
      ((EntitySceneObject *)value4)->y = ((EntitySceneObject *)value4)->y + *(int *)(value2 + 0x20);
    }
    else {
      value = *(int *)(value2 + 0x20) - *(int *)(value2 + 0x28);
      *(int *)(value2 + 0x20) = value;
      if (value < 1) {
        *(undefined4 *)(value2 + 0x20) = 0;
        *(undefined1 *)(value2 + 0xd) = 0;
      }
      ((EntitySceneObject *)value4)->y = ((EntitySceneObject *)value4)->y - *(int *)(value2 + 0x20);
    }
    value = *(int *)(value2 + 0x10) - *(int *)(value2 + 0x18);
    *(int *)(value2 + 0x10) = value;
    if (value < 1) {
      *(undefined4 *)(value2 + 0x10) = 0;
    }
    value = *(int *)(value2 + 0x10);
    value6 = (uint)((EntitySceneObject *)value4)->yaw;
    if (*(char *)(value2 + 0xc) == '\0') {
      shortValue2 = (&g_SinCosTable12Bit)[value6 - 0x800 & 0xfff];
      value6 = value6 - 0x400;
    }
    else {
      shortValue2 = (&g_SinCosTable12Bit)[value6 & 0xfff];
      value6 = value6 + 0x400;
    }
    shortValue = (&g_SinCosTable12Bit)[value6 & 0xfff];
    ((EntitySceneObject *)value4)->x = ((EntitySceneObject *)value4)->x + (-(shortValue2 * value) >> 0xc);
    ((EntitySceneObject *)value4)->z = ((EntitySceneObject *)value4)->z + (-(shortValue * value) >> 0xc);
  }
switchD_004025c9_caseD_3:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

