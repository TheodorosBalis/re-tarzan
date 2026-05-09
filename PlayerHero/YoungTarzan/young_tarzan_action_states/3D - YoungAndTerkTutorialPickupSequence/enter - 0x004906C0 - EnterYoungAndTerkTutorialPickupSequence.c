/*
State 0x3D Enter: CPlayerHero::EnterYoungTarzanAndTerkTutorialPickupSequence
Address: 0x004906C0
*/


void CPlayerHero__EnterYoungTarzanAndTerkTutorialPickupSequence(void)

{
  CPlayerHero_PlayAnimation(0x9d);
  *(int *)(g_PlayerSceneEntryData + 2) = DAT_0051c6cc + 0xe38;
  *g_PlayerSceneEntryData = 0x2a;
  *(undefined4 *)(g_PlayerSceneEntry + 0x70) = 0;
  *(undefined4 *)(g_PlayerSceneEntry + 0xb4) = 1;
  *(undefined4 *)(g_PlayerSceneEntry + 0xa8) = 0xa00;
  *(undefined4 *)(g_PlayerSceneEntry + 0xac) = 0xa00;
  *(undefined4 *)(g_PlayerSceneEntry + 0xb0) = 0xa00;
  *(undefined2 *)(g_PlayerSceneEntry + 0x140) = 0;
  *(undefined2 *)(g_PlayerGroundShadowProbeSceneEntry + 0x140) = 0;
  g_PlayerCurrentCollisionMode =
       CPlayerHero__ApplyPlacementDescriptorToSceneEntry
                 (g_PlayerSceneEntry,(&PTR_DAT_00515264)[DAT_0053a2dc * 0xc]);
  DAT_0053a2e8 = 3;
  g_PlayerActionState = 0x38;
  return;
}


