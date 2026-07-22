#include "tarzan_ghidra_types.hpp"

// Address: 0x0047AB80
// Label: JourneyToTheTreeHouse::UpdateCombatBaboon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateCombatBaboon(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  char resultFlag;
  short shortValue2;
  int value2;
  int value3;
  int value4;
  uint value6;
  uint value7;
  undefined4 value5;
  
  value7 = 0;
  value = entity->sceneObjects;
  if (((value != 0) &&
      (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value2 != 0)) &&
     (value3 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000), value3 != 0)) {
    shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    shortValue = *(short *)(value2 + 0x18);
    if ((*(byte *)(value3 + 0x14) & 1) != 0) {
      value4 = CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value,0x26,0x10);
      value7 = value4 << 1;
    }
    if ((*(byte *)(value3 + 0x14) & 2) != 0) {
      value4 = CEntities::HandleAnimalScriptEvent(entry,value,(int)shortValue2);
      value7 = value7 | value4 << 2;
    }
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,5);
      value7 = value7 | 0x11;
      g_PlayerDamageContactEntitySceneObject = value;
    }
    resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag != '\0') {
      value7 = value7 | 8;
      value6 = RandomModulo(8);
      if ((value6 & 1) == 0) {
        value5 = 0xf9;
      }
      else {
        value5 = 0xf8;
      }
      PlayAudioById(value5,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
    }
    if (*(short *)(entry + 0x3e) < 1) {
      CEntities::ProcessEntityDeathAndRelease(entry,1);
      return;
    }
    if ((*(byte *)(value3 + 0x14) & 1) == 0) {
      switch(*(undefined2 *)(entry + 0x48)) {
      case 0:
      case 1:
      case 0xf:
      case 0x11:
      case 0x12:
      case 0x13:
        value4 = GetAngleFromXZVector12Bit
                          (((EntitySceneObject *)value)->x - *(int *)(g_PlayerEntitySceneObjectData + 8),
                           ((EntitySceneObject *)value)->z - *(int *)(g_PlayerEntitySceneObjectData + 0x10));
        value4 = (value4 - ((EntitySceneObject *)value)->yaw) * 0x100000;
        ((EntitySceneObject *)value)->yaw =
             (short)((int)((value4 >> 0x14) + (value4 >> 0x1f & 3U)) >> 2) + ((EntitySceneObject *)value)->yaw;
      }
    }
    if (*(short *)(entry + 0x48) == 0x13) {
      if (shortValue == 0) {
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
    else if (*(short *)(entry + 0x48) == 0x14) {
      if (shortValue == 0x10) {
        *(undefined2 *)(entry + 0x48) = 2;
      }
    }
    else if (*(code **)(value3 + 0x10) != (code *)0x0) {
      (**(code **)(value3 + 0x10))(entry,value,value2,(int)shortValue2,value7);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

