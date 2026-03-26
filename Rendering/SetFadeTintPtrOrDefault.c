// Address: 0x004A9940

void SetFadeTintPtrOrDefault(undefined *param_1)

{
  if (param_1 == (undefined *)0x0) {
    param_1 = &DAT_00a439f0;
  }
  g_FadeTintRgbPtr = param_1;
  return;
}


