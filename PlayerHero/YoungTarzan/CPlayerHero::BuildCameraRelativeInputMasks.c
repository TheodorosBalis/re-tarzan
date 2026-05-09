// 0x0046ec50
void CPlayerHero_BuildCameraRelativeInputMasks(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (int)g_CameraYaw;
  g_CameraFollowFlags = 0;
  g_CameraRelativeTurnInputMask = 0;
  uVar2 = (int)*(short *)(g_PlayerSceneEntry + 0xa2) & 0xfff;
  iVar1 = (int)(((-0x400 - iVar3) - uVar2) * 0x100000) >> 0x14;
  if ((iVar1 < 0x259) && (-0x259 < iVar1)) {
    g_CameraFollowFlags = 0x20;
    g_CameraRelativeTurnInputMask = 0xd0;
  }
  iVar1 = (int)(((0x400 - iVar3) - uVar2) * 0x100000) >> 0x14;
  if ((iVar1 < 0x259) && (-0x259 < iVar1)) {
    g_CameraFollowFlags = g_CameraFollowFlags | 0x80;
    g_CameraRelativeTurnInputMask = g_CameraRelativeTurnInputMask | 0x70;
  }
  iVar1 = (int)(((-0x800 - iVar3) - uVar2) * 0x100000) >> 0x14;
  if ((iVar1 < 0x259) && (-0x259 < iVar1)) {
    g_CameraFollowFlags = g_CameraFollowFlags | 0x10;
    g_CameraRelativeTurnInputMask = g_CameraRelativeTurnInputMask | 0xe0;
  }
  iVar1 = (int)((iVar3 + uVar2) * -0x100000) >> 0x14;
  if ((iVar1 < 0x259) && (-0x259 < iVar1)) {
    g_CameraFollowFlags = g_CameraFollowFlags | 0x40;
    g_CameraRelativeTurnInputMask = g_CameraRelativeTurnInputMask | 0xb0;
  }
  return;
}