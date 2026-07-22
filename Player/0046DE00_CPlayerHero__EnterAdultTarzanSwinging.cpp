#include "tarzan_ghidra_types.hpp"

// Address: 0x0046DE00
// Label: CPlayerHero::EnterAdultTarzanSwinging
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanSwinging(void)

{
  int value;
  
  if (g_CurrentSwingEntity == 0) {
    if (g_PlayerAnimationSurfaceSide == '\0') {
      CPlayerHero::PlayAdultTarzanAnimation(0x51);
      g_PlayerSwingTransitionStep = 0;
      return;
    }
    CPlayerHero::PlayAdultTarzanAnimation(0x50);
    g_PlayerSwingTransitionStep = 0;
    return;
  }
  value = CEntities::FindEntityAttachmentByFlags(g_CurrentSwingEntity,0x8000000);
  if (value != 0) {
    *(undefined2 *)(value + 0xe) = 4;
  }
  if (g_PreviousPlayerActionState == 0x1e) {
    if (g_PlayerAnimationSurfaceSide == '\0') {
      CPlayerHero::PlayAdultTarzanAnimation(0x5f);
      g_PlayerSwingTransitionStep = 0;
      return;
    }
    CPlayerHero::PlayAdultTarzanAnimation(0x5e);
    g_PlayerSwingTransitionStep = 0;
    return;
  }
  if (g_PlayerAnimationSurfaceSide == '\0') {
    CPlayerHero::PlayAdultTarzanAnimation(0x40);
    g_PlayerSwingTransitionStep = 0;
    return;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x3f);
  g_PlayerSwingTransitionStep = 0;
  return;
}

