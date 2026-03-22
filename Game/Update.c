/* Address: 0x00432E60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CGameLogic::Update(void)

{
  short sVar1;
  int iVar2;
  
  if ((DAT_0051ce54 != 0 && DAT_0051cda8 != 0) && DAT_0051cd10 != 0) {
    if ((_DAT_0051cdc4 & 0x8000) != 0) {
      if (DAT_0051cdc0 == 0) {
        DAT_00533ff4._0_2_ = 0x8040;
      }
      else {
        DAT_0051cdc0 = DAT_0051cdc0 + -1;
      }
    }
    if ((_DAT_0051cdc4 & 0xf000) == 0) {
      FUN_00433370();
      DAT_0051cdc8 = DAT_0051cdc8 & 0xf000ffff;
      DAT_0051ce34 = 0;
      if ((DAT_00534010 & 0x80000000) != 0) {
        if (((byte)DAT_0051cf68 & 1) != 0) {
          FUN_004332d0();
        }
        if (((DAT_00534010 & 0x10) != 0) && ((DAT_0051cf38 & 0x400) != 0)) {
          _DAT_0051cdc4 = _DAT_0051cdc4 | 0x8000;
          DAT_0051cdc0 = 0;
        }
        if (((DAT_00534010 & 0x20) != 0) && ((DAT_0051cf38 & 0x800) != 0)) {
          _DAT_0051cdc4 = _DAT_0051cdc4 | 0x4000;
          DAT_00533ff4._0_2_ = 0x8001;
        }
      }
    }
    else {
      DAT_0051cf60 = DAT_0051cf60 & 0xffff0000;
    }
    FUN_0048a820();
    DAT_0051cd94 = 0;
    if (DAT_0051cdfc != 0) {
      *(undefined2 *)(DAT_0051cdfc + 0xe) = 0;
    }
    switch(_DAT_0051cdb6) {
    case 1:
    case 3:
      FUN_00468de0();
      break;
    case 2:
      FUN_0048cb00();
      break;
    case 4:
      FUN_00437560();
      break;
    case 5:
      FUN_00470fa0();
      break;
    case 6:
      FUN_00476a70();
      break;
    case 7:
      FUN_0045fb50();
      break;
    case 8:
      FUN_0045ae80();
      break;
    case 9:
      FUN_00455800();
      break;
    case 10:
      FUN_00473d90();
      break;
    case 0xb:
    case 0xc:
      FUN_004813e0();
    }
    DAT_0051ccfc = 0;
    DAT_0051cd90 = FUN_00436930();
    FUN_00449410();
    sVar1 = DAT_0051cd14;
    if ((short)DAT_0051cdc8 != DAT_0051cd14) {
      if ((DAT_0051cdc8 & 0xc000) != 0) {
        FUN_004449d0(DAT_0051cdc8);
      }
      sVar1 = (short)DAT_0051cdc8;
      if ((DAT_0051cdc8 & 0x2000) != 0) {
        SelectECMfileAndInitAudio(DAT_0051cdc8 & 0xff);
        sVar1 = (short)DAT_0051cdc8;
      }
    }
    DAT_0051cd14 = sVar1;
    if ((_DAT_0051cdc4 & 0x2000) == 0) {
      iVar2 = FUN_00445990(DAT_0051cd10,0x80,&DAT_0051ce08);
      DAT_0051cd1c = 0;
      DAT_00533b40 = -(uint)(iVar2 != 0) & 0x51ce08;
    }
    if (DAT_0051ce62 == '\0') {
      iVar2 = FUN_00445990(DAT_0051cd10,0x20,&DAT_0051ce18);
      DAT_0051ce58 = -(uint)(iVar2 != 0) & 0x51ce18;
    }
    else {
      DAT_0051ce58 = 0;
    }
    DAT_0051cdc8 = DAT_0051cdc8 & 0xf00ffff;
    DAT_0051ce5c = DAT_00531d3c;
    DAT_00531d3c = 0;
  }
  return;
}

