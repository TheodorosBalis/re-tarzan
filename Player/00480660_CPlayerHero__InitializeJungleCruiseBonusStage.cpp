#include "tarzan_ghidra_types.hpp"

// Address: 0x00480660
// Label: CPlayerHero::InitializeJungleCruiseBonusStage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::InitializeJungleCruiseBonusStage(void)

{
  int value;
  
  g_LeafSwimmingPlayerRouteSurfaceIndex = 0;
  g_LeafSwimmingWhirlpoolSoundVariant = 0;
  CEntities::ResetRandomAmbientSoundCountdown();
  switch(g_CurrentCheckpointId) {
  case 0:
    *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
    g_LeafSwimmingSurfaceDriftZ = 0;
    g_LeafSwimmingCenterRouteSurfaceIndex = 0;
    g_LeafSwimmingBoundarySurfaceIndexA = 1;
    g_LeafSwimmingBoundarySurfaceIndexB = 2;
    g_LeafSwimmingWhirlpoolPullStrength = 0x2200;
    g_LeafSwimmingWhirlpoolOuterRadius = 0x2e00;
    g_LeafSwimmingWhirlpoolInnerRadius = &DAT_00001a00;
    PlayAudioById(0x44c,(int *)0,(undefined4 *)0);
    g_LeafSwimmingStageSet = 0;
    break;
  case 1:
    *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
    g_LeafSwimmingSurfaceDriftZ = 1;
    g_LeafSwimmingCenterRouteSurfaceIndex = 0;
    g_LeafSwimmingBoundarySurfaceIndexA = 1;
    g_LeafSwimmingBoundarySurfaceIndexB = 2;
    g_LeafSwimmingWhirlpoolPullStrength = 0x2200;
    g_LeafSwimmingWhirlpoolOuterRadius = 0x2e00;
    g_LeafSwimmingWhirlpoolInnerRadius = &DAT_00001a00;
    PlayAudioById(0x44d,(int *)0,(undefined4 *)0);
    g_LeafSwimmingStageSet = 0;
    break;
  case 2:
    g_LeafSwimmingSurfaceDriftZ = 2;
    goto LAB_00480782;
  case 3:
    g_LeafSwimmingSurfaceDriftZ = 3;
LAB_00480782:
    g_LeafSwimmingBoundarySurfaceIndexB = 2;
    g_LeafSwimmingBoundarySurfaceIndexA = 1;
    g_LeafSwimmingCenterRouteSurfaceIndex = 0;
    g_LeafSwimmingWhirlpoolPullStrength = 0x2800;
    g_LeafSwimmingWhirlpoolOuterRadius = 0x3400;
    g_LeafSwimmingWhirlpoolInnerRadius = (undefined1 *)0x2000;
    PlayAudioById(0x44e,(int *)0,(undefined4 *)0);
    g_LeafSwimmingStageSet = 1;
  }
  InitHudCountdownFromLevelConfig();
  if (g_LeafSwimmingStageSet == 0) {
    value = g_WorldEntitySceneObjectArrayBase + 0x23c0;
  }
  else {
    value = g_WorldEntitySceneObjectArrayBase + 0x2428;
  }
  *(int *)(g_PlayerEntitySceneObjectData + 2) = value;
  *g_PlayerEntitySceneObjectData = 0;
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000000);
  if (value == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x4c,0x10000000);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000002);
  if (value == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x1c,0x10000002);
  }
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xb4) = 1;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xa8) = 0x1400;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xac) = 0x1400;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xb0) = 0x1400;
  *(byte *)((int)g_PlayerEntitySceneObjectData + 3) =
       *(byte *)((int)g_PlayerEntitySceneObjectData + 3) | 4;
  return;
}

