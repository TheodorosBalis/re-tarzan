#include "tarzan_ghidra_types.hpp"

// Address: 0x004040B0
// Label: TheBaboonChase::UpdateChargingBaboon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdateChargingBaboon(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  short shortValue2;
  char resultFlag;
  int value;
  int value2;
  int value3;
  uint value5;
  int value4;
  undefined4 value6;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value == 0) {
LAB_004040fa:
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag != '\0') {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
    return;
  }
  if (*(int *)(value + 0xc) != 3) {
    if (*(int *)(value + 0xc) == 4) {
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      value = CEntities::AdvanceBounceMotionAndReturnImpact
                        (entity->sceneObjects,value + 0x1c);
      if (value != 0) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      }
    }
    goto LAB_004040fa;
  }
  CEntities::MoveEntityWithCollisionAndEaseSurfaceAngles(entry,0x30);
  value3 = entity->sceneObjects;
  value2 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value3);
  ((EntitySceneObject *)value3)->y = ((EntitySceneObject *)value3)->y + value2;
  CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  value3 = entity->sceneObjects;
  value2 = ((EntitySceneObject *)value3)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
  value4 = ((EntitySceneObject *)value3)->y - *(int *)(g_PlayerEntitySceneObject + 0x18);
  value3 = ((EntitySceneObject *)value3)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c);
  value5 = value3 * value3 + value4 * value4 + value2 * value2;
  if ((g_TarzanSurfingWithJaneActionEffectLevel == 0) || (489999 < value5)) {
    if (value5 < 250000) {
      QueuePlayerDamageEvent(entry,4);
      value3 = RandomModulo(0x200);
      shortValue = *(short *)(entity->sceneObjects + 0xa2);
      value2 = RandomModulo(0x200);
      shortValue2 = *(short *)(entity->sceneObjects + 0xa2);
      value4 = RandomModulo(2);
      value5 = value3 + 0x3c8 + (int)shortValue;
      if (value4 == 0) {
        value5 = (shortValue2 - value2) - 0x3c8;
      }
      *(undefined4 *)(value + 0x34) = 0x28;
      *(int *)(value + 0x5c) = (short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] * 0x26 >> 0xc;
      shortValue = (&g_SinCosTable12Bit)[value5 & 0xfff];
      *(undefined4 *)(value + 0xc) = 4;
      *(int *)(value + 0x60) = shortValue * 0x26 >> 0xc;
      CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),10);
      value = RandomModulo(8);
      if (value == 0) {
        PlayAudioById(0x25a,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
      if (value == 1) {
        PlayAudioById(0x25b,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
      if (value == 2) {
        PlayAudioById(0x25c,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
      if (value == 3) {
        PlayAudioById(0x25d,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
      if (value == 4) {
        PlayAudioById(0x25e,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
      if (value == 5) {
        PlayAudioById(0x25f,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
      if (value != 6) {
        if (value != 7) {
          return;
        }
        PlayAudioById(0x261,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        return;
      }
      PlayAudioById(0x260,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      return;
    }
    goto LAB_004040fa;
  }
  *(undefined4 *)(value + 0xc) = 4;
  value3 = RandomModulo(8);
  if (value3 == 0) {
    value3 = entity->sceneObjects + 0x14;
    value2 = entity->sceneObjects + 0x104;
    value6 = 0x25a;
  }
  else if (value3 == 1) {
    value3 = entity->sceneObjects + 0x14;
    value2 = entity->sceneObjects + 0x104;
    value6 = 0x25b;
  }
  else if (value3 == 2) {
    value3 = entity->sceneObjects + 0x14;
    value2 = entity->sceneObjects + 0x104;
    value6 = 0x25c;
  }
  else if (value3 == 3) {
    value3 = entity->sceneObjects + 0x14;
    value2 = entity->sceneObjects + 0x104;
    value6 = 0x25d;
  }
  else if (value3 == 4) {
    value3 = entity->sceneObjects + 0x14;
    value2 = entity->sceneObjects + 0x104;
    value6 = 0x25e;
  }
  else if (value3 == 5) {
    value3 = entity->sceneObjects + 0x14;
    value2 = entity->sceneObjects + 0x104;
    value6 = 0x25f;
  }
  else if (value3 == 6) {
    value3 = entity->sceneObjects + 0x14;
    value2 = entity->sceneObjects + 0x104;
    value6 = 0x260;
  }
  else {
    if (value3 != 7) goto LAB_00404268;
    value3 = entity->sceneObjects + 0x14;
    value2 = entity->sceneObjects + 0x104;
    value6 = 0x261;
  }
  PlayAudioById(value6,(int *)value2,(undefined4 *)value3);
LAB_00404268:
  *(undefined4 *)(value + 0x34) = 0x50;
  value3 = RandomModulo(0x200);
  shortValue = *(short *)(entity->sceneObjects + 0xa2);
  value2 = RandomModulo(0x200);
  shortValue2 = *(short *)(entity->sceneObjects + 0xa2);
  value4 = RandomModulo(2);
  value5 = (shortValue2 - value2) - 0x364;
  if (value4 != 0) {
    value5 = value3 + 0x364 + (int)shortValue;
  }
  *(int *)(value + 0x5c) = (short)(&g_SinCosTable12Bit)[value5 - 0x400 & 0xfff] * 0x26 >> 0xc;
  *(int *)(value + 0x60) = (short)(&g_SinCosTable12Bit)[value5 & 0xfff] * 0x26 >> 0xc;
  CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),10);
  return;
}

