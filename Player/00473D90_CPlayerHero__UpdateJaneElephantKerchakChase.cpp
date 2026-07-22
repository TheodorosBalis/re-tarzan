#include "tarzan_ghidra_types.hpp"

// Address: 0x00473D90
// Label: CPlayerHero::UpdateJaneElephantKerchakChase
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateJaneElephantKerchakChase(void)

{
  int value;
  
  if (g_KerchakChasePursuerStartChecked == 0) {
    if (g_KerchakChasePrimaryPursuerEntity != 0) {
      CEntities::StartKerchakChasePursuerFromPlayer(g_KerchakChasePrimaryPursuerEntity);
    }
    g_KerchakChasePursuerStartChecked = 1;
  }
  CEntities::UpdateRandomAmbientSoundCue();
  AdvanceRuntimePathAttachmentFromCachedDirection(g_PlayerEntity);
  (**(code **)(&g_JaneElephantKerchakChaseActionStateUpdateColumn + (uint)g_PlayerActionState * 8))
            ();
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000018);
  if (value != 0) {
    UpdatePathFollowerAttachmentNearestSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
    PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
              (g_PlayerEntitySceneObject,*(undefined4 *)(value + 0x10),1,value + 0x18,0x80);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000019);
  if (value != 0) {
    UpdatePathFollowerAttachmentNearestSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
    PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
              (g_PlayerEntitySceneObject,*(undefined4 *)(value + 0x10),0,value + 0x18,0x80);
  }
  return;
}

