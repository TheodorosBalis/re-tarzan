
int CEntities__IsSceneEntryWithinCameraYawWindow(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint3 uVar3;
  
  iVar1 = GetAngleFromXZVector12Bit(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(param_1 + 0x14))
  ;
  uVar2 = (iVar1 + 0x400) - (uint)g_CameraYaw & 0xfff;
  uVar3 = (uint3)(uVar2 >> 8);
  if ((int)uVar2 < 0x800 - param_2) {
    return (uint)uVar3 << 8;
  }
  return CONCAT31(uVar3,(int)uVar2 <= param_2 + 0x800);
}

