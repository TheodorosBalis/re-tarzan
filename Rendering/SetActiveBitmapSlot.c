// Address: 0x0049C7E0

undefined4 SetActiveBitmapSlot(int param_1)

{
  if (param_1 != 7) {
    if ((param_1 < 1) || (5 < param_1)) {
      param_1 = 5;
    }
    DAT_00515de0 = -param_1;
    if ((&DAT_0072297c)[param_1] != 0) {
      return 0;
    }
  }
  DAT_00515de0 = param_1;
  return 1;
}


