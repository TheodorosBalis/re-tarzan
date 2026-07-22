#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C660
// Label: SaborAttacks::InitLevelRuntimeHook
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SaborAttacks::InitLevelRuntimeHook(void)

{
  int value;
  undefined4 localState [3];
  
  g_SaborAnimationState = 0xffffffff;
  g_SaborDefeatedEncounterFlags = 0;
  g_SaborEncounterCleanupFlags = 0;
  _g_CurrentSaborEncounterIndex = 0;
  SaborAttacks::ResetBattle();
  value = ResolveCollisionSurfaceIndexByCoordRef(1);
  _g_SaborFightAnchor0SurfaceB =
       *(short *)(*(int *)(g_CollisionSurfaceTable + 4 + value * 4) + 8 + value * 4 +
                 g_CollisionSurfaceTable) + -0x100;
  InterpolateJungleSurfacePointByCoordRef(value,(int)(short)g_SaborFightAnchor0SurfaceA,localState);
  g_SaborFightAnchor0LeftX = localState[0];
  InterpolateJungleSurfacePointByCoordRef(value,(int)_g_SaborFightAnchor0SurfaceB,localState);
  g_SaborFightAnchor0RightX = localState[0];
  value = ResolveCollisionSurfaceIndexByCoordRef(0x3ea);
  _g_SaborFightAnchor1SurfaceB =
       *(short *)(*(int *)(g_CollisionSurfaceTable + 4 + value * 4) + 8 + value * 4 +
                 g_CollisionSurfaceTable) + -0x100;
  InterpolateJungleSurfacePointByCoordRef(value,(int)*( undefined2 *)((int)&g_SaborFightAnchor0SurfaceA + 2),localState);
  g_SaborFightAnchor1LeftX = localState[0];
  InterpolateJungleSurfacePointByCoordRef(value,(int)_g_SaborFightAnchor1SurfaceB,localState);
  g_SaborFightAnchor1RightX = localState[0];
  value = ResolveCollisionSurfaceIndexByCoordRef(0x3eb);
  _g_SaborFightAnchor2SurfaceB =
       *(short *)(*(int *)(g_CollisionSurfaceTable + 4 + value * 4) + 8 + value * 4 +
                 g_CollisionSurfaceTable) + -0x100;
  InterpolateJungleSurfacePointByCoordRef(value,(int)_g_SaborFightAnchor2SurfaceA,localState);
  _g_SaborFightAnchor2LeftX = localState[0];
  InterpolateJungleSurfacePointByCoordRef(value,(int)_g_SaborFightAnchor2SurfaceB,localState);
  _g_SaborFightAnchor2RightX = localState[0];
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  return;
}

