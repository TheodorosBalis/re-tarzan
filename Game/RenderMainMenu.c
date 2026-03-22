/* Address: 0x00452C90 */

void RenderMainMenu(void)

{
  FUN_004a9e90();
  if (ptrToDecideWhichMenu != 0) {
    FUN_004a9960((int)FadeBrightness,0);
    if (*(code **)(ptrToDecideWhichMenu + 0xc) != (code *)0x0) {
      (**(code **)(ptrToDecideWhichMenu + 0xc))(ptrToDecideWhichMenu);
    }
  }
  return;
}

