// Address: 0x00452990

void CMenu__Options(undefined **param_1)

{
  if (param_1 == &PTR_Options_Difficulty_004eff98) {
    SetOptionsMenu(6);
    return;
  }
  if (param_1 == &PTR_Options_Controller_004efff8) {
    SetOptionsMenu(4);
    return;
  }
  if (param_1 == &PTR_Options_Sound_004f00d8) {
    SetOptionsMenu(7);
    return;
  }
  if (param_1 == &PTR_Options_SFXunused_004f0130) {
    SetOptionsMenu(7);
    return;
  }
  if (param_1 == &PTR_Options_OptionsSelections_004f0188) {
    SetOptionsMenu(7);
    return;
  }
  if ((code *)param_1[3] != (code *)0x0) {
    (*(code *)param_1[3])(param_1);
  }
  *(undefined ***)(ptrToDecideWhichMenu + 8) = param_1;
  return;
}


