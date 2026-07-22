#include "tarzan_ghidra_types.hpp"

// Address: 0x00433C70
// Label: CPlayerHero::PlayHeroModeAnimation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CPlayerHero::PlayHeroModeAnimation(int arg1)

{
  undefined2 value;
  
  CPlayerHero::RefreshPowerFruitDrawWindow();
  value = (undefined2)arg1;
  switch(_g_PlayerHeroMode) {
  default:
    CPlayerHero::PlayAdultTarzanAnimation(arg1);
    return 0;
  case 2:
    CPlayerHero::PlayAnimation(arg1);
    return 0;
  case 4:
    g_PlayerCurrentAnimationId = value;
    *(undefined **)(g_PlayerAnimationState + 0xc) = (&g_JaneAnimationScriptPtrTable)[arg1];
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return 0;
  case 5:
    g_PlayerCurrentAnimationId = value;
    *(undefined **)(g_PlayerAnimationState + 0xc) = (&PTR_DAT_0050aab8)[arg1];
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return 0;
  case 6:
    g_PlayerCurrentAnimationId = value;
    *(undefined **)(g_PlayerAnimationState + 0xc) = (&PTR_DAT_0050c240)[arg1];
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return 0;
  }
}

