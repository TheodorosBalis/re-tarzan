#include "tarzan_ghidra_types.hpp"

// Address: 0x0045AE80
// Label: CPlayerHero::UpdateYoungTarzanOnStork
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTarzanOnStork(void)

{
  AdvanceRuntimePathAttachmentFromEntitySceneObject(g_PlayerEntity);
  (**(code **)(&g_StorkActionStateUpdateColumn + (uint)g_PlayerActionState * 8))();
  CPlayerHero::ConstrainStorkFlightBetweenBoundaryRails();
  _g_StorkTerrainCollisionFlags = 0;
  _g_StorkTerrainCollisionFlags = CPlayerHero::ResolveStorkNatureTerrainCollision();
  CEntities::UpdateRandomAmbientSoundCue();
  CPlayerHero::UpdateStorkModeHookNoOp();
  CPlayerHero::UpdateStorkImpactReactionCooldown();
  CPlayerHero::UpdateStorkGroundShadow();
  return;
}

