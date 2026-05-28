
uint CEntities__ComputeSignedPlayerFacingDistanceXZ(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(g_PlayerSceneEntryData + 8) - *param_1;
  iVar5 = *(int *)(g_PlayerSceneEntryData + 0x10) - param_1[2];
  iVar1 = SqrtToInt(iVar5 * iVar5 + iVar4 * iVar4);
  uVar3 = iVar1 >> 6;
  uVar2 = GetAngleFromXZVector12Bit(iVar4,iVar5);
  iVar1 = GetWrappedAngleDistance12Bit(uVar2,(int)*(short *)(g_PlayerSceneEntry + 0x132));
  if (0x400 < iVar1) {
    uVar3 = ~uVar3 + 1;
  }
  return uVar3;
}

