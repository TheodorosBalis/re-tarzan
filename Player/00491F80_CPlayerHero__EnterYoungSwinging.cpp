#include "tarzan_ghidra_types.hpp"

// Address: 0x00491F80
// Label: CPlayerHero::EnterYoungSwinging
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungSwinging(void)

{
  int value;
  
  if (g_CurrentSwingEntity == 0) {
    if (g_PlayerAnimationSurfaceSide == '\0') {
      CPlayerHero::PlayAnimation(0x52);
      g_PlayerSwingTransitionStep = 0;
      return;
    }
    CPlayerHero::PlayAnimation(0x51);
    g_PlayerSwingTransitionStep = 0;
    return;
  }
  value = CEntities::FindEntityAttachmentByFlags(g_CurrentSwingEntity,0x8000000);
  if (value != 0) {
    *(undefined2 *)(value + 0xe) = 4;
  }
  if (g_PreviousPlayerActionState == 0x1f) {
    if (g_PlayerAnimationSurfaceSide == '\0') {
      CPlayerHero::PlayAnimation(99);
      g_PlayerSwingTransitionStep = 0;
      return;
    }
    CPlayerHero::PlayAnimation(0x62);
    g_PlayerSwingTransitionStep = 0;
    return;
  }
  if (g_PlayerAnimationSurfaceSide == '\0') {
    CPlayerHero::PlayAnimation(0x3e);
    g_PlayerSwingTransitionStep = 0;
    return;
  }
  CPlayerHero::PlayAnimation(0x3d);
  g_PlayerSwingTransitionStep = 0;
  return;
}

