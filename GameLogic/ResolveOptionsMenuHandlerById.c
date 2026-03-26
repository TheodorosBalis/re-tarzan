// Address: 0x0049E990

code * ResolveOptionsMenuHandlerById(undefined4 param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 0:
    return (code *)0x0;
  case 1:
    return TarzanActionGameMenu;
  case 2:
    return OptionsCategoryMenu;
  case 3:
    return KeyboardControlsMenu;
  case 4:
    return JoystickControlsMenu;
  case 5:
    return GraphicsOptionsMenu;
  case 6:
    return GameplayOptionsMenu;
  case 7:
    return SoundOptionsMenu;
  case 8:
    iVar1 = CanOpenPauseMenu();
    if (iVar1 != 0) {
      return PauseMenu;
    }
    break;
  case 9:
    return RescanCdPromptMenu;
  case 10:
    return UnsupportedDisplaySettingsMenu;
  case 0xb:
    return RecoveryModeMenu;
  case 0xd:
    return ExitGameConfirmationMenu;
  case 0xe:
    return TwoLineMessageMenu;
  }
  return (code *)0xffffffff;
}


