#include "tarzan_ghidra_types.hpp"

// Address: 0x0044CC20
// Label: SelectSaborNextAttack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SelectSaborNextAttack(undefined4 arg1,int arg2,int arg3,int arg4)

{
  int value;
  bool flagByte;
  int value2;
  uint value4;
  int value3;
  undefined4 value5;
  
  g_SaborHitProcessedFlag = 0;
  value3 = -1;
  SetSaborBattlePhase(2);
  flagByte = false;
  value2 = *(int *)(*(int *)(g_SaborBattleEntity + 0x38) + 0x14);
  value = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14);
  if (((value < value2) && (*(char *)(g_SaborEntitySceneObject + 0x75) == '\0')) ||
     ((value2 <= value && (*(char *)(g_SaborEntitySceneObject + 0x75) == -1)))) {
    flagByte = true;
  }
  value2 = ComputeEntityHorizontalDistanceSqToPlayer(g_SaborBattleEntity);
  if (g_SaborAttackCycleCount < 3) {
    if (flagByte) {
      value5 = 0x1e;
      value2 = 0xe;
      value4 = NextRandomValue();
      if ((value4 & 1) != 0) {
        value2 = 0x10;
      }
      goto LAB_0044cd9f;
    }
    if (0x12768f < value2) {
      value4 = NextRandomValue();
      if ((value4 & 1) != 0) {
        value4 = NextRandomValue();
        goto joined_r0x0044cd73;
      }
      goto LAB_0044cd7a;
    }
    if (g_PlayerActionState != 0x3c) {
      if (value2 < 160000) {
        value5 = 0x11;
        value2 = 5;
        value4 = NextRandomValue();
        if ((value4 & 1) != 0) {
          value2 = 0xf;
        }
        goto LAB_0044cd9f;
      }
      value5 = 0x1f;
      value2 = 0xd;
      value3 = 0x1f8;
      value4 = NextRandomValue();
      if ((value4 & 1) != 0) {
        value3 = 0x1f9;
      }
      *(undefined4 *)(arg4 + 0x10) = 0x12;
      goto LAB_0044cd84;
    }
    value5 = 0x24;
    value2 = 0x16;
    value4 = NextRandomValue();
    if ((value4 & 1) == 0) goto LAB_0044cd9f;
    value3 = 0x202;
  }
  else {
    g_SaborAttackCycleCount = 0;
    _g_SaborSuccessfulAttackCount = 0;
    value4 = NextRandomValue();
    if ((value4 & 1) != 0) {
      value4 = NextRandomValue();
joined_r0x0044cd73:
      value3 = 0x200;
      if ((value4 & 1) != 0) {
        value3 = 0x201;
      }
    }
LAB_0044cd7a:
    value5 = 0x15;
    value2 = 3;
LAB_0044cd84:
    if (value3 < 0) goto LAB_0044cd9f;
  }
  PlayAudioById(value3,(int *)0,(undefined4 *)arg2 + 0x14);
LAB_0044cd9f:
  *(undefined4 *)(arg3 + 0xc) = value5;
  if (g_SaborAnimationState != value2) {
    SetSaborAnimationState(arg1,value2);
  }
  CEntities::UpdateScriptedEntitySceneObjectAttachment(arg1);
  return;
}

