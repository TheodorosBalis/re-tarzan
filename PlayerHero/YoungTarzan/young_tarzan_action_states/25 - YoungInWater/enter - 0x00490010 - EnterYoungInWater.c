/*
State 0x25 Enter: CPlayerHero::EnterYoungInWater
Address: 0x00490010
*/


void CPlayerHero__EnterYoungInWater(void)

{
  CPlayerHero_PlayAnimation(0x77);
  g_PlayerAirMoveHeadingAngle = g_PlayerMoveHeadingAngle;
  g_PlayerAirMovePitchAngle = g_PlayerAirMovePitchAngle + 0x400;
  g_PlayerCurrentCollisionMode = 4;
  g_PlayerTiltControlEnabled = 1;
  *(short *)(g_PlayerSceneEntry + 0xa0) = g_PlayerAirMovePitchAngle;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x70;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 1;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  g_CameraFollowMode = 5;
  UnloadEncodedResourceId(0x1009);
  UnloadEncodedResourceId(0x100d);
  UnloadEncodedResourceId(0x100c);
  UnloadEncodedResourceId(0x2037);
  UnloadEncodedResourceId(8);
  UnloadEncodedResourceId(0x18);
  UnloadEncodedResourceId(0x1e);
  InstantiateRuntimeEntryByTypeAtPosition
            (*(undefined4 *)(g_PlayerSceneEntryData + 8),
             *(int *)(g_PlayerSceneEntryData + 0xc) + 100,
             *(undefined4 *)(g_PlayerSceneEntryData + 0x10),0x84,0x11);
  PlayAudioById(0x453,0,0);
  *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) =
       *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) & 0xfffffffd;
  PlayAudioById(0x191,0,g_PlayerSceneEntry + 0x14);
  LoadEncodedResourceId(0x2039);
  return;
}

