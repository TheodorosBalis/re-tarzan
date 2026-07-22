#include "tarzan_ghidra_types.hpp"

// Address: 0x0044D160
// Label: UpdateSaborActiveBattlePhase
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void UpdateSaborActiveBattlePhase(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  int value2;
  short shortValue;
  int value3;
  int value4;
  
  value = entity->sceneObjects;
  value3 = CEntities::FindEntityAttachmentByFlags(arg1,0x10000001);
  value4 = CEntities::FindEntityAttachmentByFlags(arg1,0x800);
  ((EntitySceneObject *)value)->y = g_SaborBattleGroundY;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(arg1);
  if (shortValue == 0) goto LAB_0044d2cb;
  if (g_SaborBattleCameraState == 1) {
    g_SaborBattleCameraState = 2;
  }
  switch(shortValue) {
  case 0xc:
    value3 = *(int *)(value4 + 0x10) * 2;
    *(int *)(value4 + 0x10) = value3;
    if (0x40 < value3) {
      *(undefined4 *)(value4 + 0x10) = 0x40;
      ApplySaborAnimationMotion(arg1);
      TryApplySaborAttackDamageToPlayer(value);
      return;
    }
    goto LAB_0044d2cb;
  case 0xd:
    *(int *)(value4 + 0x10) = *(int *)(value4 + 0x10) >> 1;
    ApplySaborAnimationMotion(arg1);
    TryApplySaborAttackDamageToPlayer(value);
    return;
  case 0x10:
    g_SaborAttackHitPlayerFlag = 0;
    ApplySaborAnimationMotion(arg1);
    TryApplySaborAttackDamageToPlayer(value);
    return;
  case 0x11:
    if (g_SaborAttackHitPlayerFlag != 0) {
      _g_SaborSuccessfulAttackCount = _g_SaborSuccessfulAttackCount + 1;
      ApplySaborAnimationMotion(arg1);
      TryApplySaborAttackDamageToPlayer(value);
      return;
    }
    g_SaborAttackCycleCount = g_SaborAttackCycleCount + 1;
    ApplySaborAnimationMotion(arg1);
    TryApplySaborAttackDamageToPlayer(value);
    return;
  case 99:
    g_SaborFlipFacingOnNextAnimationFlag = 1;
    ApplySaborAnimationMotion(arg1);
    TryApplySaborAttackDamageToPlayer(value);
    return;
  }
  value2 = *(int *)(value3 + 0xc);
  if (value2 == 0x19) {
LAB_0044d2ad:
    *(undefined4 *)(value3 + 0xc) = 0x15;
LAB_0044d2b4:
    SetSaborAnimationStateAndAdvance(arg1,3);
  }
  else {
    if (value2 == 0x1e) {
      g_SaborFlipFacingOnNextAnimationFlag = 1;
      goto LAB_0044d2b4;
    }
    if (value2 == 0x1f) goto LAB_0044d2ad;
  }
  SelectSaborNextAttack(arg1,value,value3,value4);
LAB_0044d2cb:
  ApplySaborAnimationMotion(arg1);
  TryApplySaborAttackDamageToPlayer(value);
  return;
}

