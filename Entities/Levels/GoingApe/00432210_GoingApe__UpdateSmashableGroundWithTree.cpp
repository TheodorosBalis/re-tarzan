#include "tarzan_ghidra_types.hpp"

// Address: 0x00432210
// Label: GoingApe::UpdateSmashableGroundWithTree
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::UpdateSmashableGroundWithTree(int entry)

{
  Entity *entity = (Entity *)entry;
  uint *dataCursor;
  int *intCursor;
  int value;
  char resultFlag;
  int value2;
  int value3;
  undefined4 value4;
  uint *dataCursor2;
  uint value5;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if ((value2 == 0) || (value = entity->sceneObjects, value == 0)) goto LAB_0043242a;
  if ((*(byte *)(entry + 0x42) & 0x10) != 0) {
    CEntities::SpawnEntityByTypeAtPosition
              (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
               *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0x13,0x11);
    value3 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value3;
    if (value3 < 0) {
      DecodeEncodedEntitySceneObjectIdToSourceRef(*(undefined4 *)(value2 + 0x18),0x2002);
      *(undefined2 *)(value + 0xc) = 0x2002;
      value5 = *(uint *)(g_PlayerContactSurfaceThisFrame + -8);
      value = g_PlayerContactSurfaceThisFrame;
      while ((value5 & 0x200) != 0) {
        value5 = *(uint *)(value + -0x24);
        value = value + -0x1c;
      }
      dataCursor2 = (uint *)(&((EntitySceneObject *)value)->x);
      value5 = ((EntitySceneObject *)value)->x;
      while ((value5 & 0x200) != 0) {
        *dataCursor2 = value5 & 0xfffffbff;
        dataCursor = dataCursor2 + 7;
        dataCursor2 = dataCursor2 + 7;
        value5 = *dataCursor;
      }
      intCursor = (int *)(value2 + 0xc);
      PlayAudioById(0xce,(int *)0,(undefined4 *)intCursor);
      CEntities::UnlinkEntityFromProcessingList(entry);
      PlayForceFeedbackEffect_Stub(0,3,0x14);
      CEntities::SpawnSmashableFlyingDebris
                (*intCursor + 0x19,*(int *)(value2 + 0x10) + -0x154,*(undefined4 *)(value2 + 0x14),0x2a,
                 0x2001,0x400);
      CEntities::SpawnSmashableDustEmitter
                (*intCursor,*(int *)(value2 + 0x10) + -200,*(undefined4 *)(value2 + 0x14));
      CEntities::SpawnSmashableDustEmitter
                (*intCursor + 0x28,*(int *)(value2 + 0x10) + -0x8c,*(undefined4 *)(value2 + 0x14));
      CEntities::SpawnSmashableDebrisShardBurst
                (*intCursor + 0x1e,*(int *)(value2 + 0x10) + -0x32,*(undefined4 *)(value2 + 0x14),0x2a,
                 0x2012,4,8,0x400);
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    value4 = RandomModulo(4);
    switch(value4) {
    case 0:
      value4 = 0xd8;
      break;
    case 1:
      value4 = 0xd9;
      break;
    case 2:
      value4 = 0xda;
      break;
    case 3:
      value4 = 0xdb;
      break;
    default:
      goto switchD_00432379_default;
    }
    PlayAudioById(value4,(int *)0,(undefined4 *)value2 + 0xc);
  }
switchD_00432379_default:
  CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  resultFlag = CEntities::CheckPlayerDamageContact(value);
  if (resultFlag != '\0') {
    value4 = GetAngleFromXZVector12Bit
                      (*(int *)(g_PlayerEntitySceneObjectData + 8) - ((EntitySceneObject *)value)->x,
                       *(int *)(g_PlayerEntitySceneObjectData + 0x10) - ((EntitySceneObject *)value)->z);
    value5 = g_PlayerDamageContactPushDistance + 2;
    value2 = GetWrappedAngleDistance12Bit(value4,g_PlayerMoveHeadingAngle);
    if (value2 < 0x400) {
      value5 = ~value5 + 1;
    }
    if (*(char *)(g_PlayerEntitySceneObject + 0x75) != '\0') {
      value5 = ~value5 + 1;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(value5,0,g_PlayerEntitySceneObject);
  }
LAB_0043242a:
  *(ushort *)(entry + 0x42) = *(ushort *)(entry + 0x42) & 0xffef;
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

