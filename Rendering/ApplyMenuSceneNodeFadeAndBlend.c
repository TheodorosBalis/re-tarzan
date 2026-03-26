// Address: 0x00444AE0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ApplyMenuSceneNodeFadeAndBlend(int param_1,int param_2,undefined4 param_3)

{
  if ((*(ushort *)(param_1 + 2) & 1) == 0) {
    g_RenderBlendMode = 0;
  }
  else {
    g_RenderBlendMode = (byte)*(ushort *)(param_1 + 2) >> 5 & 3;
  }
  if (param_2 != 0x1000) {
    if ((*(byte *)(param_1 + 3) & 4) != 0) {
      _DAT_00531e58 = *(int *)(param_1 + 0x14) * param_2 >> 0xc;
      _DAT_00531e5c = *(int *)(param_1 + 0x18) * param_2 >> 0xc;
      _DAT_00531e60 = *(int *)(param_1 + 0x1c) * param_2 >> 0xc;
      SetFadeBrightnessAndTint(*(int *)(param_1 + 0x24) * param_2 >> 0xc,&DAT_00531e58);
      return;
    }
    SetFadeBrightnessAndTint(param_2,param_3);
    return;
  }
  if ((*(byte *)(param_1 + 3) & 4) != 0) {
    SetFadeBrightnessAndTint(*(undefined4 *)(param_1 + 0x24),param_1 + 0x14);
    return;
  }
  SetFadeBrightnessAndTint(0x1000,0);
  return;
}


