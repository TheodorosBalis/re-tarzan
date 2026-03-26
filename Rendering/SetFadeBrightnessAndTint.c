// Address: 0x004A9960

void SetFadeBrightnessAndTint(int param_1,int param_2)

{
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (0x1000 < param_1) {
    param_1 = 0x1000;
  }
  g_FadeBrightnessInverse = 0x1000 - param_1;
  SetFadeTintPtrOrDefault(param_2);
  if (param_2 == 0) {
    g_FadeTintRgbPtr = &DAT_00a43a00;
    return;
  }
  g_FadeTintRgbPtr = (undefined *)param_2;
  return;
}


