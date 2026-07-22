#include "tarzan_ghidra_types.hpp"

// Address: 0x00426B40
// Label: ElephantHairDare::UpdateSwingingMonkey
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateSwingingMonkey(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  short shortValue2;
  short shortValue3;
  longlong value6;
  char resultFlag;
  short shortValue4;
  int value3;
  int value4;
  int value5;
  uint value7;
  int value;
  int value2;
  int localState3;
  int localState2;
  int localState;
  
  LoadEncodedResourceId(0x1014);
  value5 = entity->sceneObjects;
  if ((value5 == 0) ||
     (value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value3 == 0))
  goto switchD_00426c81_caseD_2;
  shortValue4 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value3 + 0x18);
  CEntities::HandleAnimalScriptEvent(entry,value5,(int)shortValue4);
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag == '\0') {
    resultFlag = CEntities::CheckPlayerDamageContact(value5);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,0x2006);
    }
  }
  else {
    if (*(short *)(entry + 0x3e) < 1) goto LAB_00426be9;
    PlayAudioById(0x112,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
    *(undefined2 *)(entry + 0x48) = 8;
  }
  if (*(short *)(entry + 0x3e) < 1) {
LAB_00426be9:
    PlayAudioById(0x158,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
    ((EntitySceneObject *)value5)->y = ((EntitySceneObject *)value5)->y + 0x200;
    CEntities::ProcessEntityDeathAndRelease(entry,1);
    return;
  }
  if ((*(byte *)(entry + 0x4a) & 0x80) == 0) {
    value4 = GetAngleFromXZVector12Bit
                      (((EntitySceneObject *)value5)->x - *(int *)(g_PlayerEntitySceneObjectData + 8),
                       ((EntitySceneObject *)value5)->z - *(int *)(g_PlayerEntitySceneObjectData + 0x10));
    value6 = (longlong)((value4 - ((EntitySceneObject *)value5)->yaw) * 0x100000 >> 0x14) * 0x55555556;
    ((EntitySceneObject *)value5)->yaw =
         ((short)((ulonglong)value6 >> 0x20) - (short)(value6 >> 0x3f)) + ((EntitySceneObject *)value5)->yaw;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    value5 = RandomModulo(10);
    *(int *)(entry + 0x4c) = value5 + 10;
    *(undefined2 *)(entry + 0x48) = 1;
    break;
  case 1:
    value5 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value5;
    if (value5 < 1) {
      *(undefined2 *)(entry + 0x48) = 4;
    }
    break;
  case 4:
    value4 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity);
    if (((value4 != 0) && (299 < *(int *)(g_PlayerEntitySceneObject + 0x18) - ((EntitySceneObject *)value5)->y)
        ) && (value5 = CEntities::ComputeEntitySceneObjectDataDistance3D
                                (value5 + 0xc,g_PlayerEntitySceneObjectData),
             value5 <= *(int *)(entry + 0x50))) {
      CEntities::SelectScriptAttachmentSequence(value3,1);
      *(undefined2 *)(entry + 0x48) = 5;
      break;
    }
    goto LAB_00426eea;
  case 5:
    if (shortValue4 == 0xb) {
      value5 = GetSceneAttachmentWorldPositionByMask(value5,0x100,&localState3);
      if ((value5 == 0) ||
         (value5 = CEntities::SpawnEntityByTypeAtPosition(localState3,localState2,localState,0x1a,0x11),
         value5 == 0)) break;
      value5 = CEntities::CreateEntityAttachment(value5,0x9c,0x10000000);
      if (value5 != 0) {
        value4 = localState3 - *(int *)(g_PlayerEntitySceneObjectData + 8);
        localState2 = localState2 - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
        value = localState - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
        value3 = SqrtToInt(localState2 * localState2 + value4 * value4 + value * value);
        value2 = value3 >> 6;
        SqrtToInt(value4 * value4 + value * value);
        value7 = GetAngleFromXZVector12Bit(value4,value);
        value4 = RandomModulo(700);
        shortValue4 = ((short)(value2 / 0x50) + (short)(value3 >> 0x1f)) -
                (short)((longlong)value2 * 0x66666667 >> 0x3f);
        ((EntitySceneObject *)value5)->z = 6;
        ((EntitySceneObject *)value5)->y = shortValue4;
        if (shortValue4 == 0) {
          ((EntitySceneObject *)value5)->y = 1;
        }
        shortValue4 = (&g_SinCosTable12Bit)[value7 & 0xfff];
        shortValue2 = (&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff];
        shortValue3 = (&g_SinCosTable12Bit)[value4 + 0x514U & 0xfff];
        *(undefined1 *)(value5 + 0x20) = 0;
        value7 = (uint)((EntitySceneObject *)value5)->y;
        *(int *)(value5 + 0xc) =
             (int)(CONCAT44(shortValue2 * value2 >> 0x1f,shortValue2 * value2 >> 0xc) / (longlong)(int)value7);
        ((EntitySceneObject *)value5)->x =
             (int)(CONCAT44(shortValue4 * value2 >> 0x1f,shortValue4 * value2 >> 0xc) / (longlong)(int)value7);
        ((EntitySceneObject *)value5)->y = ((EntitySceneObject *)value5)->y * 4;
        ((EntitySceneObject *)value5)->worldObject =
             (int)(CONCAT44(shortValue3 * value2 >> 0x1f,shortValue3 * value2 >> 0xc) / (longlong)(int)value7) +
             value7 * 3;
        if ((entity->descriptor != 0) &&
           (value3 = *(int *)(*(int *)(entity->descriptor + 0x10) + 4), value3 != 0)) {
          ((EntitySceneObject *)value5)->y = (short)value3;
        }
      }
    }
    if (shortValue == 0) {
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfeff;
      *(undefined2 *)(entry + 0x48) = 0;
    }
    break;
  case 8:
    *(undefined2 *)(entry + 0x48) = 0xd;
    CEntities::SelectScriptAttachmentSequence(value3,4);
    break;
  case 0xd:
    if (shortValue != 0) break;
LAB_00426eea:
    *(undefined2 *)(entry + 0x48) = 0;
  }
switchD_00426c81_caseD_2:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

