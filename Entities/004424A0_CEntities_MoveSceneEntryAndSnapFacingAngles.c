
void CEntities__MoveSceneEntryAndSnapFacingAngles(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 0x75) != '\0') {
      param_2 = ~param_2 + 1;
    }
    MoveSceneEntryWithCollision(param_2,0,iVar1);
    *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 0x54);
    *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + *(int *)(iVar1 + 0x5c);
    *(ushort *)(iVar1 + 0xa2) = *(ushort *)(iVar1 + 0x132);
    if (*(char *)(iVar1 + 0x75) != '\0') {
      *(ushort *)(iVar1 + 0xa0) = *(short *)(iVar1 + 0x130) - 0x400U & 0xfff;
      return;
    }
    *(ushort *)(iVar1 + 0xa2) = *(ushort *)(iVar1 + 0x132) ^ 0x800;
    *(ushort *)(iVar1 + 0xa0) = 0x400U - *(short *)(iVar1 + 0x130) & 0xfff;
  }
  return;
}

