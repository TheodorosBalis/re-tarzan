/* Address: 0x0049F260 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 DrawOptionsMenu(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined2 extraout_var;
  char cVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  int local_c;
  int local_8;
  
  if (DAT_007241ec != param_1) {
    if (DAT_007241e8 == (undefined4 *)0x0) {
      DAT_007241e8 = DAT_007241ec;
    }
    DAT_007241ec = param_1;
    if (DAT_007241e8 == (undefined4 *)0x0) goto LAB_0049f2a0;
    DAT_007241f0 = 100;
  }
  if (DAT_007241e8 != (undefined4 *)0x0) {
    param_1 = DAT_007241e8;
  }
LAB_0049f2a0:
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  local_c = 0;
  iVar10 = 0;
  pcVar12 = (char *)*param_1;
  puVar9 = param_1;
  while (pcVar12 != (char *)0x0) {
    uVar7 = 0xffffffff;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar6 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar6 != '\0');
    if (iVar10 < (int)(~uVar7 - 1)) {
      iVar10 = ~uVar7 - 1;
    }
    puVar1 = puVar9 + 2;
    puVar9 = puVar9 + 2;
    local_c = local_c + 1;
    pcVar12 = (char *)*puVar1;
  }
  iVar2 = GetWindowWidth_stub2();
  iVar2 = iVar2 * (iVar10 + 4);
  iVar10 = GetWindowWidth_Stub();
  iVar10 = iVar10 * (local_c + 4);
  iVar3 = GetWindowWidth();
  iVar11 = (iVar3 - iVar2) / 2;
  iVar4 = GetWindowHeight();
  iVar4 = (iVar4 - iVar10) / 2;
  if (DAT_007241e8 == (undefined4 *)0x0) {
    DAT_007241f0 = DAT_007241f0 + 0x1c;
    if (99 < DAT_007241f0) {
      DAT_007241f0 = 100;
    }
  }
  else {
    DAT_007241f0 = DAT_007241f0 + -0x1c;
    if (DAT_007241f0 < 1) {
      DAT_007241e8 = (undefined4 *)0x0;
      DAT_007241f0 = 0;
    }
  }
  local_8 = DAT_007241f0;
  iVar5 = GetBitMapStructValue_2();
  if ((iVar5 == 0) && (local_8 < 0x32)) {
    local_8 = 0;
  }
  uVar7 = (local_8 * 0xff) / 100;
  uVar7 = uVar7 | ((uVar7 * 0x100 | uVar7) << 8 | uVar7) << 8;
  if (local_8 != 0) {
    iVar5 = GetWindowWidth_Stub();
    local_8 = iVar4 + iVar5 * 2;
    if (0 < local_c) {
      do {
        pcVar12 = (char *)*param_1;
        iVar5 = GetWindowWidth_stub2();
        uVar8 = 0xffffffff;
        pcVar13 = pcVar12;
        do {
          if (uVar8 == 0) break;
          uVar8 = uVar8 - 1;
          cVar6 = *pcVar13;
          pcVar13 = pcVar13 + 1;
        } while (cVar6 != '\0');
        FUN_0049ad10(iVar3 - iVar5 * (~uVar8 - 1) >> 1,local_8,pcVar12,uVar7,0);
        iVar5 = GetWindowWidth_Stub();
        local_8 = local_8 + iVar5;
        param_1 = param_1 + 2;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
  }
  if (DAT_007241f0 == 100) {
    iVar3 = GetWindowWidth_Stub();
    if (-1 < param_2) {
      cVar6 = DAT_00516b74;
      if (DAT_007241f4 < '\x10') {
        cVar6 = DAT_00516b74 << 1;
      }
      DAT_007241f4 = DAT_007241f4 + cVar6;
      if (DAT_007241f4 < ' ') {
        if (DAT_007241f4 < '\0') {
          DAT_007241f4 = '\0';
          DAT_00516b74 = '\x01';
        }
      }
      else {
        DAT_007241f4 = '\x1f';
        DAT_00516b74 = -1;
      }
      iVar5 = GetWindowWidth_Stub();
      iVar3 = iVar5 * param_2 + -1 + iVar4 + iVar3 * 2;
      iVar5 = iVar2 / 2;
      iVar4 = GetWindowWidth_Stub(1,0xda,CONCAT22((short)(iVar2 >> 0x1f),(short)DAT_007241f4),0xf,
                                  0xf,uVar7,1,0,1,0);
      iVar4 = GetWindowWidth_stub2(iVar4 + 1);
      iVar4 = GetWindowWidth_stub2(iVar3,iVar5 - iVar4);
      SetFontBrightness(iVar4 + iVar11);
      iVar4 = GetWindowWidth_Stub(CONCAT22(extraout_var,(short)DAT_007241f4) + 1,0xda,
                                  -CONCAT22(extraout_var,(short)DAT_007241f4),0xf,0xf,uVar7,1,0,1,0)
      ;
      iVar4 = GetWindowWidth_stub2(iVar4 + 1);
      SetFontBrightness(iVar5 + iVar11,iVar3,iVar5 - iVar4);
    }
  }
  FUN_0049f560((float)(DAT_007241f0 * iVar2) * _DAT_004ba2b8,
               (float)(DAT_007241f0 * iVar10) * _DAT_004ba2b8);
  return 1;
}

