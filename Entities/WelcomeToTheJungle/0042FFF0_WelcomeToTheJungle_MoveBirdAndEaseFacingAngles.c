
void WelcomeToTheJungle__MoveBirdAndEaseFacingAngles(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x75) != '\0') {
      param_2 = ~param_2 + 1;
    }
    MoveSceneEntryWithCollision(param_2,0,iVar1);
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 0x54);
    uVar3 = *(ushort *)(iVar1 + 0x132) & 0xfff;
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x58);
    *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + *(int *)(iVar1 + 0x5c);
    if (*(char *)(iVar1 + 0x75) == '\0') {
      uVar3 = uVar3 ^ 0x800;
      uVar4 = 0x400 - *(short *)(iVar1 + 0x130);
    }
    else {
      uVar4 = *(short *)(iVar1 + 0x130) - 0x400;
    }
    uVar5 = uVar4 & 0xfff;
    if ((int)*(short *)(iVar1 + 0xa2) != uVar3) {
      iVar2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(iVar1 + 0xa2),uVar3);
      if ((iVar2 >> 3 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f) < 2) {
        *(short *)(iVar1 + 0xa2) = (short)uVar3;
      }
      else {
        *(short *)(iVar1 + 0xa2) = *(short *)(iVar1 + 0xa2) + (short)(iVar2 >> 3);
      }
      *(ushort *)(iVar1 + 0xa2) = *(ushort *)(iVar1 + 0xa2) & 0xfff;
    }
    if ((int)*(short *)(iVar1 + 0xa0) != uVar5) {
      iVar2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(iVar1 + 0xa0),uVar5);
      if ((iVar2 >> 3 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f) < 2) {
        *(short *)(iVar1 + 0xa0) = (short)uVar5;
        *(ushort *)(iVar1 + 0xa0) = *(ushort *)(iVar1 + 0xa0) & 0xfff;
        return;
      }
      *(short *)(iVar1 + 0xa0) = *(short *)(iVar1 + 0xa0) + (short)(iVar2 >> 3);
      *(ushort *)(iVar1 + 0xa0) = *(ushort *)(iVar1 + 0xa0) & 0xfff;
    }
  }
  return;
}

