#include "tarzan_ghidra_types.hpp"

// Address: 0x0044AA20
// Label: CEntities::UpdateWeaponPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Removing unreachable block (ram,0x0044ac72) */
/* WARNING: Removing unreachable block (ram,0x0044acab) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateWeaponPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort value5;
  int value;
  char resultFlag;
  uint value6;
  int value2;
  uint value7;
  uint value8;
  int value3;
  int value4;
  int localState2;
  byte localState;
  
  value = entity->sceneObjects;
  if (value == 0) {
LAB_0044ad72:
    resultFlag = CEntities::UpdateBouncingPickupMotionAndLifetime(entry);
    if ((resultFlag != '\0') || (resultFlag = IsEntityOutsideOuterActivationBounds(entry), resultFlag != '\0')) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
    return;
  }
  ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x38U & 0xfff;
  resultFlag = CEntities::IsPlayerWithinPickupTriggerBounds
                    (value,g_PlayerPickupTriggerRadius,
                     (int)*(short *)(g_PlayerEntitySceneObject + 0x142),0);
  if ((resultFlag == '\0') || (resultFlag = CEntities::CanStartPickupCollection(entry), resultFlag == '\0'))
  goto LAB_0044ad72;
  switch(*(undefined4 *)(entry + 0x4c)) {
  case 0:
    _g_PlayerPowerFruitInventoryFlags = _g_PlayerPowerFruitInventoryFlags | 4;
    *( undefined2 *)((int)&g_PowerFruitAmmoType2 + 2) = *( undefined2 *)((int)&g_PowerFruitAmmoType2 + 2) + 5;
    g_PowerFruitPickupFlashType = 3;
    g_PowerFruitPickupFlashTicks = 0x3c;
    if (_g_PlayerHeroMode != 2) {
      PlayAudioById(0x68,(int *)0,(undefined4 *)0);
      goto switchD_0044aa9e_caseD_3;
    }
    break;
  case 1:
    *( undefined2 *)((int)&g_PowerFruitAmmoType2 + 0) = (short)g_PowerFruitAmmoType2 + 5;
    _g_PlayerPowerFruitInventoryFlags = _g_PlayerPowerFruitInventoryFlags | 2;
    g_PowerFruitPickupFlashType = 2;
    g_PowerFruitPickupFlashTicks = 0x3c;
    if ((_g_PlayerHeroMode != 2) && (_g_PlayerHeroMode != 9)) {
      PlayAudioById(0x68,(int *)0,(undefined4 *)0);
      goto switchD_0044aa9e_caseD_3;
    }
    break;
  case 2:
    _g_PlayerPowerFruitInventoryFlags = _g_PlayerPowerFruitInventoryFlags | 1;
    g_PowerFruitAmmoType1 = g_PowerFruitAmmoType1 + 1;
    g_PowerFruitPickupFlashType = 1;
    g_PowerFruitPickupFlashTicks = 0x3c;
    if (_g_PlayerHeroMode != 2) {
      PlayAudioById(0x68,(int *)0,(undefined4 *)0);
      goto switchD_0044aa9e_caseD_3;
    }
    break;
  default:
    goto switchD_0044aa9e_caseD_3;
  case 10:
    _g_PlayerPowerFruitInventoryFlags = _g_PlayerPowerFruitInventoryFlags | 0x10;
    if (_g_PlayerHeroMode == 2) {
      PlayAudioById(0x25,(int *)0,(undefined4 *)0);
    }
    else {
      PlayAudioById(0x67,(int *)0,(undefined4 *)0);
    }
    goto switchD_0044aa9e_caseD_3;
  case 0x14:
    PlayAudioById(0x44a,(int *)0,(undefined4 *)0);
    value5 = *(ushort *)(&g_CollectibleTimerBonusByDifficulty + *( undefined1 *)((int)&g_LevelTransitionContext + 1) * 2);
    value7 = (uint)(char)((uint)g_HudCountdownBcdTime >> 8);
    value8 = value7 & 0x8000000f;
    if ((int)value8 < 0) {
      value8 = (value8 - 1 | 0xfffffff0) + 1;
    }
    value6 = (uint)(char)((uint)g_HudCountdownBcdTime >> 0x10);
    localState2 = value8 + ((int)(value7 + ((int)value7 >> 0x1f & 0xfU)) >> 4) * 10;
    value7 = value6 & 0x8000000f;
    if ((int)value7 < 0) {
      value7 = (value7 - 1 | 0xfffffff0) + 1;
    }
    value2 = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
    value7 = (uint)(char)g_HudCountdownBcdTime;
    value8 = value7 & 0x8000000f;
    if ((int)value8 < 0) {
      value8 = (value8 - 1 | 0xfffffff0) + 1;
    }
    value3 = value8 + (((value5 & 0xff) >> 4) + ((int)(value7 + ((int)value7 >> 0x1f & 0xfU)) >> 4)) * 10
            + (value5 & 0xf);
    if (g_BcdTimerTicksPerSecond < value3) {
      localState2 = localState2 + 1;
      value3 = value3 - g_BcdTimerTicksPerSecond;
    }
    localState = (byte)(value5 >> 8);
    value4 = (localState & 0x8000000f) + localState2 + (uint)(localState >> 4) * 10;
    if (0x3b < value4) {
      value2 = value2 + 1;
      value4 = value4 + -0x3c;
    }
    if (0x3b < value2) {
      value2 = value2 + -0x3c;
    }
    g_HudCountdownBcdTime =
         ((char)((((char)(value2 / 10) + (char)(value2 >> 0x1f)) -
                 (char)((longlong)value2 * 0x66666667 >> 0x3f)) * '\x10' + (char)(value2 % 10)) *
          0x100 + (int)(char)((((char)(value4 / 10) + (char)(value4 >> 0x1f)) -
                              (char)((longlong)value4 * 0x66666667 >> 0x3f)) * '\x10' +
                             (char)(value4 % 10))) * 0x100 +
         (int)(char)((((char)(value3 / 10) + (char)(value3 >> 0x1f)) -
                     (char)((longlong)value3 * 0x66666667 >> 0x3f)) * '\x10' + (char)(value3 % 10));
    goto switchD_0044aa9e_caseD_3;
  }
  g_PowerFruitPickupFlashTicks = 0x3c;
  PlayAudioById(0x26,(int *)0,(undefined4 *)0);
switchD_0044aa9e_caseD_3:
  CEntities::SpawnEntityByTypeAtPosition
            (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
             ((EntitySceneObject *)value)->z,0x14,0x11);
  CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  return;
}

