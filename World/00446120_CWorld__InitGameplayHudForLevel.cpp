#include "tarzan_ghidra_types.hpp"

// Address: 0x00446120
// Label: CWorld::InitGameplayHudForLevel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CWorld::InitGameplayHudForLevel(void)

{
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  int value;
  undefined4 *dataCursor3;
  undefined4 *dataCursor4;
  
  g_HudCountdownScene = 0;
  g_HudCollectedSketchScene = 0;
  g_HudCollectedTARZANslotScene = 0;
  g_HudPowerFruitSelectorScene = 0;
  g_HudHealthBarEnabled = 0;
  g_OptionalHudMeterScene = 0;
  g_HudLivesCounterScene = 0;
  g_HudLivesAvatarScene = 0;
  _g_HudLifeGainPortraitScene = 0;
  g_HudTokenCounterScene = 0;
  dataCursor = &g_HudEntitySceneObjectSlot0AnchorRef;
  do {
    dataCursor2 = dataCursor + 0x51;
    dataCursor3 = &g_HudEntitySceneObjectTemplate;
    dataCursor4 = dataCursor + -0x40;
    for (value = 0x51; value != 0; value = value + -1) {
      *dataCursor4 = *dataCursor3;
      dataCursor3 = dataCursor3 + 1;
      dataCursor4 = dataCursor4 + 1;
    }
    *(undefined2 *)((int)dataCursor + -0xf2) = 0;
    *dataCursor = &g_TransitionSceneAnchorSecondary;
    dataCursor = dataCursor2;
  } while ((int)dataCursor2 < 0x533bbc);
  g_HudExtraLifeMeterEnabled = 0;
  ResetHudSpriteQuadList();
  switch(*( undefined1 *)((int)&g_LevelTransitionContext + 2)) {
  case 4:
  case 7:
  case 8:
    InitHudTokenCounter();
    InitHudCollectedSketchPanel();
    InitHudCollectedTARZANLettersPanel();
    InitHudHealthBar();
    InitHudLivesCounterAndHeroAvatar();
    return;
  default:
    InitHudTokenCounter();
    InitHudCollectedSketchPanel();
    InitHudCollectedTARZANLettersPanel();
    InitHudHealthBar();
    InitHudPowerFruitSelector();
    InitHudLivesCounterAndHeroAvatar();
    return;
  case 0xc:
    InitHudTokenCounter();
    InitHudExtraLifeMeter();
    InitHudCollectedSketchPanel();
    InitHudCollectedTARZANLettersPanel();
    InitHudHealthBar();
    InitHudPowerFruitSelector();
    InitHudLivesCounterAndHeroAvatar();
    return;
  case 0xd:
    InitHudExtraLifeMeter();
    InitHudCollectedTARZANLettersPanel();
    InitHudHealthBar();
    InitHudPowerFruitSelector();
    InitHudLivesCounterAndHeroAvatar();
    return;
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x12:
  case 0x13:
  case 0x14:
    InitHudTokenCounter();
    return;
  case 0x15:
    return;
  }
}

