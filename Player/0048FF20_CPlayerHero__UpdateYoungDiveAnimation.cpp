#include "tarzan_ghidra_types.hpp"

// Address: 0x0048FF20
// Label: CPlayerHero::UpdateYoungDiveAnimation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungDiveAnimation(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  CPlayerHero::UpdateMovementAndCollision(1);
  value = ((*(int *)(g_PlayerMotionState + 0x10) * 0x4b) / 0x30) * -0x1000 + 0x14f;
  g_PlayerAirMovePitchAngle =
       (short)((ulonglong)((longlong)value * 0xb60b60b7) >> 0x28) -
       ((short)(char)((char)(value / 0x1680000) + (char)(value >> 0x1f)) >> 0xf);
  UnloadEncodedResourceId(0x1009);
  UnloadEncodedResourceId(0x100d);
  UnloadEncodedResourceId(0x100c);
  UnloadEncodedResourceId(0x2037);
  UnloadEncodedResourceId(8);
  UnloadEncodedResourceId(0x18);
  UnloadEncodedResourceId(0x1e);
  resultFlag = CPlayerHero::IsOnTreeSurfingSurface();
  value2 = g_PlayerActionState;
  if ((resultFlag != '\0') && (0 < *(int *)(g_PlayerEntitySceneObjectData + 0xc))) {
    g_PlayerActionState = 0x25;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048ffe1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_g_YoungTarzanFallDiveCallback_Field0000)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    PlayAudioById(400,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  }
  return;
}

