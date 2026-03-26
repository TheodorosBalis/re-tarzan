// Address: 0x0049AD70

int DrawGraphicsText(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                    int param_7,int param_8,byte *param_9,undefined4 param_10)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  
  bVar3 = *param_9;
  iVar5 = param_1;
  if (bVar3 == 0) {
    DAT_007223f4._0_1_ = 0;
    return param_1;
  }
  do {
    iVar1 = FUN_004b006e(bVar3);
    if (iVar1 != 0) {
      bVar3 = bVar3 - 0x20;
    }
    if (bVar3 == 10) {
      iVar5 = param_1 - param_3;
      param_2 = param_2 + param_4;
    }
    else if ((0x20 < bVar3) && (bVar3 < 0x61)) {
      uVar2 = (0x100 - param_5) / param_7;
      uVar4 = bVar3 - 0x21 & 0xff;
      DrawTexturedQuad(iVar5,param_2,(short)param_3 + -1,(short)param_4 + -1,
                       (uVar4 % uVar2) * param_7 + param_5,(uVar4 / uVar2) * param_8 + param_6,
                       param_7 + -1,param_8 + -1,0xf,param_10,0,0,1,1);
    }
    param_9 = param_9 + 1;
    iVar5 = iVar5 + param_3;
    bVar3 = *param_9;
  } while (bVar3 != 0);
  DAT_007223f4._0_1_ = bVar3;
  return iVar5;
}


