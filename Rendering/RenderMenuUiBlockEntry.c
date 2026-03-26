// Address: 0x004ADDE0

void RenderMenuUiBlockEntry
               (int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (param_3 < *(int *)(param_1 + 0x10)) {
    if (*(int *)(param_1 + 0x18) == 0) {
      BuildMenuTextBlockRuntime(param_1);
    }
    *(undefined4 *)(param_1 + 0x18) = FrameCount;
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    SetFadeBrightnessAndTint((int)FadeBrightness,&local_10);
    g_RenderBlendMode = 0;
    SetDrawWindow(param_4,param_5);
    RenderBitmapCellGrid(*(int *)(param_1 + 0x14) + param_3 * 0x72,param_2);
  }
  return;
}


