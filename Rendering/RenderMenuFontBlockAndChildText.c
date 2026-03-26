// Address: 0x00452D40

void RenderMenuFontBlockAndChildText(int *param_1)

{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = param_1[2];
  if ((iVar1 != 0) && (*(code **)(iVar1 + 0x20) != (code *)0x0)) {
    (**(code **)(iVar1 + 0x20))(iVar1);
  }
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  SetFadeBrightnessAndTint((int)FadeBrightness,&local_10);
  g_RenderBlendMode = 0;
  if (*(int *)(*param_1 + 0xc) != 0) {
    if (param_1[1] != -1) {
      RenderMenuUiBlockEntry
                (*param_1 + 4,&DAT_00533bd8,param_1[1],*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0
                );
    }
    ReleaseMenuTextBlockIfUnused(*param_1 + 4,2);
  }
  return;
}


