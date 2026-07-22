#include "tarzan_ghidra_types.hpp"

// Address: 0x0045B890
// Label: CPlayerHero::EnterStorkTerrainImpactReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStorkTerrainImpactReaction(void)

{
  int value;
  undefined *dataCursor;
  undefined4 value2;
  
  value = RandomModulo(3);
  if (value == 0) {
    value2 = 0x424;
LAB_0045b8f5:
    PlayAudioById(value2,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  }
  else {
    if (value == 1) {
      value2 = 0x425;
      goto LAB_0045b8f5;
    }
    if (value == 2) {
      value2 = 0x426;
      goto LAB_0045b8f5;
    }
  }
  if (g_StorkImpactReactionCooldownActive != 0) {
    return;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xffffffe8;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x100;
  if ((g_StorkTerrainCollisionFlags & 0x10) == 0) {
    if ((g_StorkTerrainCollisionFlags & 0x20) != 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x2b00;
      g_StorkImpactReactionCooldownActive = 1;
      g_StorkImpactAnimationVariant = 4;
      *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) = *g_PlayerEntitySceneObjectData;
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
      *(undefined2 *)(g_PlayerAnimationState + 0x1c) = 0x33;
      g_PlayerCurrentAnimationId = 6;
      dataCursor = g_StorkImpactAnimationScriptB;
      goto LAB_0045baef;
    }
    if ((g_StorkTerrainCollisionFlags & 1) != 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
      g_StorkImpactAnimationVariant = 1;
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x2b00;
      g_StorkImpactReactionCooldownActive = 1;
LAB_0045ba22:
      *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) = *g_PlayerEntitySceneObjectData;
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
      *(undefined2 *)(g_PlayerAnimationState + 0x1c) = 0x33;
      g_PlayerCurrentAnimationId = 4;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_StorkImpactAnimationScriptA;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero::AdvanceAnimationScript();
      return;
    }
    if ((g_StorkTerrainCollisionFlags & 8) != 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
      g_StorkImpactAnimationVariant = 2;
      g_StorkImpactReactionCooldownActive = 1;
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
      goto LAB_0045ba22;
    }
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x2b00;
  g_StorkImpactReactionCooldownActive = 1;
  g_StorkImpactAnimationVariant = 3;
  *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) = *g_PlayerEntitySceneObjectData;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
  *(undefined2 *)(g_PlayerAnimationState + 0x1c) = 0x33;
  g_PlayerCurrentAnimationId = 7;
  dataCursor = g_StorkImpactAnimationScriptC;
LAB_0045baef:
  *(undefined **)(g_PlayerAnimationState + 0xc) = dataCursor;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

