/*
State 0x24 Enter: CPlayerHero::EnterYoungDiveAnimation
Address: 0x0048FE40
*/


void CPlayerHero__EnterYoungDiveAnimation(void)

{
  CPlayerHero_PlayAnimation(0x75);
  g_PlayerTiltControlEnabled = 0;
  *(undefined1 *)(g_PlayerSceneEntry + 0x75) = 0;
  g_PlayerAirMoveHeadingAngle = g_PlayerMoveHeadingAngle;
  g_PlayerAirMovePitchAngle = 0xee3;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xd0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 2;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x50;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 1;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x10;
  CPlayerHero_UpdateMovementAndCollision(1);
  *(ushort *)(g_PlayerGroundShadowProbeSceneEntry + 0xe) =
       *(ushort *)(g_PlayerGroundShadowProbeSceneEntry + 0xe) & 0x7fff;
  UnloadEncodedResourceId(0x1009);
  UnloadEncodedResourceId(0x100d);
  UnloadEncodedResourceId(0x100c);
  UnloadEncodedResourceId(0x2037);
  UnloadEncodedResourceId(8);
  UnloadEncodedResourceId(0x18);
  UnloadEncodedResourceId(0x1e);
  return;
}

