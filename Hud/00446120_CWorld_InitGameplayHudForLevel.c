
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CWorld_InitGameplayHudForLevel(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
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
  puVar1 = &g_HudSceneEntrySlot0AnchorRef;
  do {
    puVar2 = puVar1 + 0x51;
    puVar4 = &g_HudSceneEntryTemplate;
    puVar5 = puVar1 + -0x40;
    for (iVar3 = 0x51; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    *(undefined2 *)((int)puVar1 + -0xf2) = 0;
    *puVar1 = &g_TransitionSceneAnchorSecondary;
    puVar1 = puVar2;
  } while ((int)puVar2 < 0x533bbc);
  g_HudExtraLifeMeterEnabled = 0;
  ResetHudSpriteQuadList();
  switch(g_LevelTransitionContext._2_1_) {
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

