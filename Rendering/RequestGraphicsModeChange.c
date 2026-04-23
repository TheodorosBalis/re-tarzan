// Address: 0x0049C7E0

undefined4 RequestGraphicsModeChange(int param_1)

{
  if (param_1 != 7) {
    if ((param_1 < 1) || (5 < param_1)) {
      param_1 = 5;
    }
    g_RequestedGraphicsMode = -param_1;
    if ((&DAT_0072297c)[param_1] != 0) {
      return 0;
    }
  }
  g_RequestedGraphicsMode = param_1;
  return 1;
}


