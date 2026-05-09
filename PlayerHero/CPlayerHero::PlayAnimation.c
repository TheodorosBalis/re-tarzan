// 0x0048cc20
void CPlayerHero_PlayAnimation(int param_1)

{
  if ((DAT_0051cd16 & 0x10) == 0) {
    *(undefined4 *)(g_PlayerSceneEntry + 0x70) = 0;
  }
  else {
    *(undefined4 *)(g_PlayerSceneEntry + 0x70) = 1;
  }
  DAT_0051cdf0 = (undefined2)param_1;
  *(undefined **)(g_PlayerAnimationState + 0xc) = (&PTR_DAT_00514ad0)[param_1];
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero_AdvanceAnimationScript();
  return;
}