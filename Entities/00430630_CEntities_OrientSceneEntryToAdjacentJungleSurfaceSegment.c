
void CEntities__OrientSceneEntryToAdjacentJungleSurfaceSegment(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  ushort uVar3;
  short sVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  piVar5 = (int *)GetJungleSurfaceSegment
                            (*(undefined4 *)(param_2 + 0x110),*(undefined4 *)(param_2 + 0x10c));
  if (*(char *)(param_2 + 0x75) == '\0') {
    if ((piVar5[5] & 0x2000U) != 0) {
      return;
    }
    piVar7 = piVar5 + 7;
  }
  else {
    if (piVar5[3] == 0) {
      return;
    }
    piVar7 = piVar5 + -7;
  }
  iVar1 = piVar7[1];
  iVar2 = piVar5[1];
  iVar8 = *piVar7 - *piVar5;
  iVar9 = piVar7[2] - piVar5[2];
  iVar6 = SqrtToInt(iVar9 * iVar9 + iVar8 * iVar8);
  uVar3 = GetAngleFromXZVector12Bit(iVar1 - iVar2,iVar6 >> 6);
  *(ushort *)(param_2 + 0xa0) = uVar3 & 0xfff;
  sVar4 = GetAngleFromXZVector12Bit(iVar8,iVar9);
  *(ushort *)(param_2 + 0xa2) = sVar4 - 0x800U & 0xfff;
  return;
}

