#include "tarzan_ghidra_types.hpp"

// Address: 0x004058C0
// Label: RockinTheBoat::UpdateSlidingObstacles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::UpdateSlidingObstacles(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  char resultFlag;
  int value3;
  int value4;
  uint value6;
  int value5;
  undefined4 value7;
  
  value = entity->sceneObjects;
  if (value == 0) goto LAB_00405aff;
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x800);
  if (value3 != 0) {
    value4 = g_RockinTheBoatShipSwayVelocity >> 4;
    *(int *)(value3 + 0x14) = value4;
    if (value4 < 0) {
      value5 = -1;
      *(int *)(value3 + 0x14) = -(*(int *)(value3 + 0x38) + value4);
    }
    else {
      value5 = 0;
      *(int *)(value3 + 0x14) = *(int *)(value3 + 0x34) + value4;
    }
    value4 = *(int *)(value3 + 0x10) + (*(int *)(value3 + 0x14) - *(int *)(value3 + 0x18));
    *(int *)(value3 + 0x10) = value4;
    if (value4 < 0) {
      *(undefined4 *)(value3 + 0x10) = 0;
    }
    else {
      value2 = *(int *)(value3 + 0x1c);
      if (value2 < value4) {
        *(int *)(value3 + 0x10) = value2;
      }
      if (value2 >> 2 < *(int *)(value3 + 0x10)) {
        *(undefined1 *)(value + 0x74) = 0;
      }
      if (*(int *)(entry + 0x50) != value5) {
        *(int *)(entry + 0x50) = value5;
        if ((*(byte *)(entry + 0x4c) & 1) == 0) {
          value4 = RandomModulo(4);
          if (value4 == 1) {
            value7 = 0x354;
          }
          else if (value4 == 2) {
            value7 = 0x355;
          }
          else if (value4 == 3) {
            value7 = 0x356;
          }
          else {
            value7 = 0x353;
          }
        }
        else if ((*(byte *)(value3 + 0x18) & 1) == 0) {
          value7 = 0x358;
        }
        else {
          value7 = 0x357;
        }
        PlayAudioById(value7,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
      }
    }
    value6 = *(uint *)(value3 + 0x10);
    if (value5 != 0) {
      value6 = ~value6 + 1;
    }
    CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,value6);
    if ((*(byte *)(entry + 0x4c) & 1) != 0) {
      value4 = ((EntitySceneObject *)value)->next;
      *(ushort *)(value + 0xa0) = (ushort)((EntitySceneObject *)value)->surfaceIndex & 0xfff;
      if (value4 != 0) {
        *(undefined4 *)(value4 + 0x14) = ((EntitySceneObject *)value)->x;
        *(undefined4 *)(value4 + 0x18) = ((EntitySceneObject *)value)->y;
        *(undefined4 *)(value4 + 0x1c) = ((EntitySceneObject *)value)->z;
      }
    }
    if (((*(byte *)(value + 0x13c) & 2) != 0) || (((EntitySceneObject *)value)->surfaceIndex == 0)) {
      if (*(char *)(value + 0x74) == '\0') {
        value4 = RandomModulo(4);
        if (value4 == 1) {
          value7 = 0x35a;
        }
        else if (value4 == 2) {
          value7 = 0x35b;
        }
        else if (value4 == 3) {
          value7 = 0x35c;
        }
        else {
          value7 = 0x359;
        }
        PlayAudioById(value7,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
        *(undefined1 *)(value + 0x74) = 1;
      }
      *(undefined4 *)(value3 + 0x10) = 0;
    }
    if (*(int *)(value3 + 0x10) != 0) {
      if ((*(byte *)(entry + 0x4c) & 1) == 0) {
        resultFlag = CEntities::CheckPlayerDamageContact(value);
      }
      else {
        if (((EntitySceneObject *)value)->next == 0) goto LAB_00405af5;
        resultFlag = CEntities::CheckPlayerDamageContact(((EntitySceneObject *)value)->next);
      }
      if (resultFlag != '\0') {
        QueuePlayerDamageEvent(entry,0x1004);
      }
    }
  }
LAB_00405af5:
  CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
LAB_00405aff:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

