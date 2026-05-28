
int CEntities__ComputePlayerAttachmentPenetrationDepth
              (int param_1,short *param_2,int param_3,short *param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short local_68;
  short local_66;
  short local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_4c;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined1 local_20 [32];
  
  local_40 = (int)*param_2;
  local_3c = (int)param_2[1];
  local_38 = (int)param_2[2];
  iVar6 = 0x7ffffff;
  if (*(short *)(param_1 + 0xa6) != 3) {
    TransformVectorByBasis(param_1 + 0xb8,&local_40,&local_40);
  }
  local_40 = ((local_40 + *(int *)(param_1 + 0x14)) -
             (*(int *)(param_3 + 0x3c) + *(int *)(param_3 + 0x14))) + *(int *)(param_1 + 0x3c);
  local_3c = ((local_3c + *(int *)(param_1 + 0x18)) -
             (*(int *)(param_3 + 0x40) + *(int *)(param_3 + 0x18))) + *(int *)(param_1 + 0x40);
  local_38 = ((local_38 + *(int *)(param_1 + 0x1c)) -
             (*(int *)(param_3 + 0x44) + *(int *)(param_3 + 0x1c))) + *(int *)(param_1 + 0x44);
  local_4c = (int)param_4[1];
  local_48 = (int)param_4[2];
  local_60 = (int)param_4[3];
  iVar5 = (int)*param_4;
  local_5c = (int)param_4[4];
  iVar4 = (int)param_4[5];
  if (*(int *)(param_3 + 0xb4) == 1) {
    iVar5 = *(int *)(param_3 + 0xa8) * iVar5 >> 0xc;
    local_4c = *(int *)(param_3 + 0xac) * local_4c >> 0xc;
    local_48 = *(int *)(param_3 + 0xb0) * local_48 >> 0xc;
    local_60 = *(int *)(param_3 + 0xa8) * local_60 >> 0xc;
    local_5c = *(int *)(param_3 + 0xac) * local_5c >> 0xc;
    iVar4 = *(int *)(param_3 + 0xb0) * iVar4 >> 0xc;
  }
  local_58 = iVar4;
  if (*(short *)(param_3 + 0xa6) == 3) {
    local_24 = local_34;
    local_30 = local_40;
    local_2c = local_3c;
    local_28 = local_38;
  }
  else {
    local_68 = -*(short *)(param_3 + 0xa0);
    local_66 = -*(short *)(param_3 + 0xa2);
    local_64 = -*(short *)(param_3 + 0xa4);
    FUN_004a29a0(&local_68,local_20);
    TransformVectorByBasis(local_20,&local_40,&local_30);
  }
  bVar2 = local_30 < iVar5;
  if (local_2c < local_5c) {
    bVar2 = bVar2 | 0x10;
  }
  if (local_28 < local_48) {
    bVar2 = bVar2 | 4;
  }
  if (local_60 < local_30) {
    bVar2 = bVar2 | 2;
  }
  if (local_4c < local_2c) {
    bVar2 = bVar2 | 0x20;
  }
  if (iVar4 < local_28) {
    bVar2 = bVar2 | 8;
  }
  iVar4 = local_48;
  iVar1 = local_5c;
  switch(bVar2) {
  case 0:
    iVar6 = 0x7fffffff;
    break;
  case 1:
    uVar3 = local_30 - iVar5 >> 0x1f;
    iVar6 = (local_30 - iVar5 ^ uVar3) - uVar3;
    iVar6 = iVar6 * iVar6;
    break;
  case 2:
    uVar3 = local_30 - local_60 >> 0x1f;
    iVar6 = (local_30 - local_60 ^ uVar3) - uVar3;
    iVar6 = iVar6 * iVar6;
    break;
  case 4:
    uVar3 = local_28 - local_48 >> 0x1f;
    iVar6 = (local_28 - local_48 ^ uVar3) - uVar3;
    iVar6 = iVar6 * iVar6;
    break;
  case 5:
    iVar6 = (local_28 - local_48) * (local_28 - local_48) + (local_30 - iVar5) * (local_30 - iVar5);
    break;
  case 6:
    iVar6 = (local_28 - local_48) * (local_28 - local_48) +
            (local_30 - local_60) * (local_30 - local_60);
    break;
  case 8:
    uVar3 = local_28 - local_58 >> 0x1f;
    iVar6 = (local_28 - local_58 ^ uVar3) - uVar3;
    iVar6 = iVar6 * iVar6;
    break;
  case 9:
    goto LAB_00443180;
  case 10:
    iVar5 = local_60;
LAB_00443180:
    iVar6 = (local_28 - local_58) * (local_28 - local_58) + (local_30 - iVar5) * (local_30 - iVar5);
    break;
  case 0x10:
    uVar3 = local_2c - local_5c >> 0x1f;
    iVar6 = (local_2c - local_5c ^ uVar3) - uVar3;
    iVar6 = iVar6 * iVar6;
    break;
  case 0x11:
    iVar6 = (local_2c - local_5c) * (local_2c - local_5c) + (local_30 - iVar5) * (local_30 - iVar5);
    break;
  case 0x12:
    iVar6 = (local_2c - local_5c) * (local_2c - local_5c) +
            (local_30 - local_60) * (local_30 - local_60);
    break;
  case 0x14:
    iVar6 = (local_28 - local_48) * (local_28 - local_48) +
            (local_2c - local_5c) * (local_2c - local_5c);
    break;
  case 0x15:
    iVar5 = local_30 - iVar5;
    iVar1 = local_2c - local_5c;
    goto LAB_004431a2;
  case 0x16:
    iVar5 = local_30 - local_60;
    iVar1 = local_2c - local_5c;
    goto LAB_004431a2;
  case 0x18:
    iVar6 = (local_28 - local_58) * (local_28 - local_58) +
            (local_2c - local_5c) * (local_2c - local_5c);
    break;
  case 0x19:
    iVar5 = local_30 - iVar5;
    goto LAB_0044319c;
  case 0x1a:
    iVar5 = local_30 - local_60;
    goto LAB_0044319c;
  case 0x20:
    uVar3 = local_2c - local_4c >> 0x1f;
    iVar6 = (local_2c - local_4c ^ uVar3) - uVar3;
    iVar6 = iVar6 * iVar6;
    break;
  case 0x21:
    iVar5 = local_30 - iVar5;
    iVar6 = (local_2c - local_4c) * (local_2c - local_4c);
    goto LAB_004431b0;
  case 0x22:
    iVar5 = local_30 - local_60;
    iVar6 = (local_2c - local_4c) * (local_2c - local_4c);
    goto LAB_004431b0;
  case 0x24:
    iVar6 = (local_28 - local_48) * (local_28 - local_48) +
            (local_2c - local_4c) * (local_2c - local_4c);
    break;
  case 0x25:
    iVar5 = local_30 - iVar5;
    iVar1 = local_2c - local_4c;
    goto LAB_004431a2;
  case 0x26:
    iVar5 = local_30 - local_60;
    iVar1 = local_2c - local_4c;
    goto LAB_004431a2;
  case 0x28:
    iVar6 = (local_28 - local_58) * (local_28 - local_58) +
            (local_2c - local_4c) * (local_2c - local_4c);
    break;
  case 0x29:
    goto LAB_00443198;
  case 0x2a:
    iVar5 = local_60;
LAB_00443198:
    iVar5 = local_30 - iVar5;
    iVar1 = local_4c;
LAB_0044319c:
    iVar1 = local_2c - iVar1;
    iVar4 = local_58;
LAB_004431a2:
    iVar6 = (local_28 - iVar4) * (local_28 - iVar4) + iVar1 * iVar1;
LAB_004431b0:
    iVar6 = iVar6 + iVar5 * iVar5;
  }
  if (iVar6 <= (int)param_2[3] * (int)param_2[3]) {
    iVar6 = SqrtToInt(iVar6);
    return (int)param_2[3] - (iVar6 >> 6);
  }
  return 0;
}

