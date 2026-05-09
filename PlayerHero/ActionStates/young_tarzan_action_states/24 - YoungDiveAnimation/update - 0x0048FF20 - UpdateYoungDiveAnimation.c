/*
State 0x24 Update: CPlayerHero::UpdateYoungDiveAnimation
Address: 0x0048FF20
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048FF20_CPlayerHero__UpdateYoungDiveAnimation.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungDiveAnimation(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  CPlayerHero__UpdateJumpArcVerticalMotion(0);
  CPlayerHero__UpdateMovementAndCollision(1);
  iVar3 = ((*(int *)(g_PlayerMotionState + 0x10) * 0x4b) / 0x30) * -0x1000 + 0x14f;
  g_PlayerAirMovePitchAngle =
       (short)((ulonglong)((longlong)iVar3 * 0xb60b60b7) >> 0x28) -
       ((short)(char)((char)(iVar3 / 0x1680000) + (char)(iVar3 >> 0x1f)) >> 0xf);
  UnloadEncodedResourceId(0x1009);
  UnloadEncodedResourceId(0x100d);
  UnloadEncodedResourceId(0x100c);
  UnloadEncodedResourceId(0x2037);
  UnloadEncodedResourceId(8);
  UnloadEncodedResourceId(0x18);
  UnloadEncodedResourceId(0x1e);
  cVar2 = CPlayerHero__IsOnTreeSurfingSurface();
  uVar1 = g_PlayerActionState;
  if ((cVar2 != '\0') && (0 < *(int *)(g_PlayerSceneEntryData + 0xc))) {
    g_PlayerActionState = 0x25;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x25 -> CPlayerHero::EnterYoungInWater */
  CPlayerHero__EnterYoungInWater();
    return;
  }
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  if (iVar3 == 8) {
    PlayAudioById(400,g_PlayerSceneEntry + 0x104,g_PlayerSceneEntry + 0x14);
  }
  return;
}


