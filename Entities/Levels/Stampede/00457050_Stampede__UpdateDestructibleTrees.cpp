#include "tarzan_ghidra_types.hpp"

// Address: 0x00457050
// Label: Stampede::UpdateDestructibleTrees
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::UpdateDestructibleTrees(int entry)

{
  ushort *dataCursor;
  byte *value5;
  int value;
  char resultFlag;
  int value2;
  int value3;
  undefined4 value4;
  int localState2 [2];
  int localState;
  
  value = entry;
  if (g_StampedeElephantsEntity == 0) goto LAB_00457212;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if ((value2 == 0) || (*(int *)(value2 + 0xc) != 7)) goto LAB_00457212;
  resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                    (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),4,&entry,
                     localState2);
  if (resultFlag != '\0') {
    *(int *)(g_PlayerEntitySceneObject + 0x14) =
         *(int *)(g_PlayerEntitySceneObject + 0x14) + localState2[0];
    *(int *)(g_PlayerEntitySceneObject + 0x1c) =
         *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState;
    if ((g_PlayerActionState != 8) && (g_PlayerDamageInvulnerabilityTicks == 0)) {
      QueuePlayerDamageEvent(value,0x2004);
      value3 = CEntities::IsEntityVectorMostlyPositiveX(g_PlayerEntity,value);
      g_PreviousPlayerActionState = g_PlayerActionState;
      if (value3 == 0) {
        g_PlayerActionState = 6;
        (*(code *)g_StampedeEnterDamageRecoilTowardPositiveXHandlerPtr)();
      }
      else {
        g_PlayerActionState = 5;
        (*(code *)g_StampedeEnterDamageRecoilTowardNegativeXHandlerPtr)();
      }
    }
  }
  if ((g_StampedeElephantsEntity == 0) ||
     (*(int *)(*(int *)(value + 0x38) + 0x1c) <
      *(int *)(*(int *)(g_StampedeElephantsEntity + 0x38) + 0x1c) + -700)) goto LAB_00457212;
  *(undefined4 *)(value2 + 0xc) = 0xc;
  dataCursor = (ushort *)(*(int *)(value + 0x38) + 0xe);
  *dataCursor = *dataCursor & 0x7fff;
  value5 = (byte *)(*(int *)(value + 0x38) + 0xf);
  *value5 = *value5 | 0x10;
  *(undefined2 *)(*(int *)(value + 0x38) + 0xa6) = 3;
  *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
  value2 = *(int *)(value + 0x38);
  CEntities::SpawnEntityByTypeAtPosition
            (*(undefined4 *)(value2 + 0x14),*(int *)(value2 + 0x18) + -0xc0,
             *(undefined4 *)(value2 + 0x1c),0x8a,0x11);
  value2 = RandomModulo(3);
  if (value2 == 0) {
    value2 = *(int *)(value + 0x38) + 0x14;
    value4 = 0x1c4;
LAB_00457201:
    PlayAudioById(value4,(int *)0,(undefined4 *)value2);
  }
  else {
    if (value2 == 1) {
      value2 = *(int *)(value + 0x38) + 0x14;
      value4 = 0x1c9;
      goto LAB_00457201;
    }
    if (value2 == 2) {
      value2 = *(int *)(value + 0x38) + 0x14;
      value4 = 0x1cc;
      goto LAB_00457201;
    }
  }
  CEntities::ReleaseEntityAndMarkDescriptorConsumed(value);
LAB_00457212:
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

