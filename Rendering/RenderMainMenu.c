// Address: 0x00452C90

void RenderMainMenu(void)

{
  PrepareWorldAndMenuRenderState();
  if (ptrToDecideWhichMenu != 0) {
    SetFadeBrightnessAndTint((int)FadeBrightness,0);
    if (*(code **)(ptrToDecideWhichMenu + 0xc) != (code *)0x0) {
      (**(code **)(ptrToDecideWhichMenu + 0xc))(ptrToDecideWhichMenu);
    }
  }
  return;
}


