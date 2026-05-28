
undefined4 CEntities__IsWorldPointInsideSceneEntryBounds(int param_1,int *param_2)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short local_58;
  short local_56;
  short local_54;
  uint local_50;
  int local_4c;
  int local_48;
  int local_3c;
  int local_38;
  int local_2c;
  int local_28;
  undefined1 local_20 [32];
  
  psVar1 = (short *)CEntities__GetSceneEntryCurrentLocalBounds(param_1);
  if (psVar1 != (short *)0x0) {
    local_2c = (int)psVar1[1];
    local_28 = (int)psVar1[2];
    iVar2 = (int)psVar1[3];
    local_3c = (int)psVar1[4];
    iVar4 = (int)*psVar1;
    local_38 = (int)psVar1[5];
    iVar3 = local_28;
    if (*(int *)(param_1 + 0xb4) == 1) {
      iVar4 = *(int *)(param_1 + 0xa8) * iVar4 >> 0xc;
      local_2c = *(int *)(param_1 + 0xac) * local_2c >> 0xc;
      iVar3 = *(int *)(param_1 + 0xb0) * local_28 >> 0xc;
      iVar2 = *(int *)(param_1 + 0xa8) * iVar2 >> 0xc;
      local_3c = *(int *)(param_1 + 0xac) * local_3c >> 0xc;
      local_38 = *(int *)(param_1 + 0xb0) * local_38 >> 0xc;
    }
    local_50 = (*param_2 - *(int *)(param_1 + 0x14)) - *(int *)(param_1 + 0x3c);
    local_4c = (param_2[1] - *(int *)(param_1 + 0x18)) - *(int *)(param_1 + 0x40);
    local_48 = (param_2[2] - *(int *)(param_1 + 0x1c)) - *(int *)(param_1 + 0x44);
    if (*(short *)(param_1 + 0xa6) != 3) {
      local_58 = -*(short *)(param_1 + 0xa0);
      local_56 = -*(short *)(param_1 + 0xa2);
      local_54 = -*(short *)(param_1 + 0xa4);
      FUN_004a29a0(&local_58,local_20);
      TransformVectorByBasis(local_20,&local_50,&local_50);
    }
    if ((((iVar4 <= (int)local_50) && ((int)local_50 <= iVar2)) && (local_3c <= local_4c)) &&
       (((local_4c <= local_2c && (iVar3 <= local_48)) && (local_48 <= local_38)))) {
      return 1;
    }
  }
  return 0;
}

