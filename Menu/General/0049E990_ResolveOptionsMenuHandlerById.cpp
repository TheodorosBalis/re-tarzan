#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E990
// Label: ResolveOptionsMenuHandlerById
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

code * ResolveOptionsMenuHandlerById(undefined4 menu)

{
  int menuIndex;
  
  switch(menu) {
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
    menuIndex = CanOpenPauseMenu();
    if (menuIndex != 0) {
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

