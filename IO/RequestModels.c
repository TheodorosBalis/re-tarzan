/* Address: 0x00429660 */

int RequestModels(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_0051c6e8 != 0) {
    DAT_0051c6e8 = DAT_0051c6e8 + -1;
    return DAT_0051c6f4 + 1;
  }
  if (DAT_0051c6ec != 0) {
    iVar1 = FUN_004ac1c0();
    if (0 < iVar1) {
      return DAT_0051c6f4 + 1;
    }
    if (iVar1 < 0) {
      FUN_004396e0(DAT_0051c6ec,&DAT_0051d280);
    }
    else {
      iVar1 = DAT_0051c6f0 * 0x18;
      if (*(int *)(&DAT_0051c6fc + DAT_0051c6f0 * 0x18) == 0) {
        FUN_004396e0(DAT_0051c6ec,&DAT_0051d280);
      }
      else if (*(code **)(&DAT_0051c70c + iVar1) == (code *)0x0) {
        **(int **)(&DAT_0051c710 + iVar1) = DAT_0051c6ec;
        if (*(int *)(&DAT_0051c708 + iVar1) == 1) {
          FUN_004397c0(DAT_0051c6ec,*(undefined4 *)(&DAT_0051c710 + iVar1));
        }
        else {
          **(int **)(&DAT_0051c710 + iVar1) = DAT_0051c6ec;
        }
      }
      else {
        (**(code **)(&DAT_0051c70c + iVar1))(DAT_0051c6ec,*(undefined4 *)(&DAT_0051c710 + iVar1));
      }
      DAT_0051c6ec = 0;
      DAT_0051c6e8 = 0xc;
      DAT_0051c6f0 = DAT_0051c6f0 + 1 & 0xf;
      DAT_0051c6f4 = DAT_0051c6f4 + -1;
      if ((DAT_0051c6f4 == 0) && (DAT_0051c6f8 != 0)) {
        FUN_004ac1a0(DAT_0051c6f8,0);
      }
    }
  }
  if (DAT_0051c6f4 != 0) {
    iVar1 = DAT_0051c6f0 * 0x18;
    if (*(int *)(&DAT_0051c6fc + DAT_0051c6f0 * 0x18) == 0) {
      DAT_0051c6f4 = DAT_0051c6f4 + -1;
      DAT_0051c6f0 = DAT_0051c6f0 + 1 & 0xf;
      return DAT_0051c6f4;
    }
    if (DAT_0051c6f4 != 0) {
      if (*(int *)(&DAT_0051c708 + iVar1) == 0) {
        DAT_0051c6ec = FUN_004396c0(((int)(*(int *)(&DAT_0051c704 + iVar1) + 0x7ff +
                                          (*(int *)(&DAT_0051c704 + iVar1) + 0x7ff >> 0x1f & 0x7ffU)
                                          ) >> 0xb) << 0xb,&DAT_0051d280);
      }
      else {
        iVar3 = ((int)(*(int *)(&DAT_0051c704 + iVar1) + 0x7ff +
                      (*(int *)(&DAT_0051c704 + iVar1) + 0x7ff >> 0x1f & 0x7ffU)) >> 0xb) * 0x800 +
                3 >> 2;
        iVar2 = FUN_00439460(iVar3,DAT_0051d284);
        if ((iVar2 == 0) && (iVar2 = FUN_00439460(iVar3,DAT_0051d284), iVar2 == 0)) {
          FUN_00439400(&DAT_0051d280);
          iVar2 = FUN_00439460(iVar3,DAT_0051d284);
          if (iVar2 == 0) {
            return DAT_0051c6f4 + 1;
          }
        }
        DAT_0051c6ec = FUN_00439660(((int)(*(int *)(&DAT_0051c704 + iVar1) + 0x7ff +
                                          (*(int *)(&DAT_0051c704 + iVar1) + 0x7ff >> 0x1f & 0x7ffU)
                                          ) >> 0xb) << 0xb,&DAT_0051d280);
      }
      iVar1 = FUN_004ac160(*(undefined4 *)(&DAT_0051c6fc + iVar1),
                           (int)(*(int *)(&DAT_0051c700 + iVar1) +
                                (*(int *)(&DAT_0051c700 + iVar1) >> 0x1f & 0x7ffU)) >> 0xb,
                           DAT_0051c6ec,
                           (int)(*(int *)(&DAT_0051c704 + iVar1) + 0x7ff +
                                (*(int *)(&DAT_0051c704 + iVar1) + 0x7ff >> 0x1f & 0x7ffU)) >> 0xb);
      if (iVar1 < 0) {
        FUN_004396e0(DAT_0051c6ec,&DAT_0051d280);
        DAT_0051c6ec = 0;
      }
    }
  }
  return (uint)(DAT_0051c6ec != 0) + DAT_0051c6f4 + DAT_0051c6e8;
}

