#include "tarzan_ghidra_types.hpp"

// Address: 0x00481310
// Label: CPlayerHero::ClampLeafSwimmingToWaterSurfaceAndSpawnSplash
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::ClampLeafSwimmingToWaterSurfaceAndSpawnSplash(void)

{
  int value;
  
  value = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_LeafSwimmingWhirlpoolPullActive;
  if ((g_LeafSwimmingCameraDistanceBoostActive == 0) && (-1 < value)) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - value) + -0x20;
    if ((g_PlayerActionState == 2) && (g_LeafSwimmingPlayerRouteSurfaceIndex == 0)) {
      CEntities::SpawnEntityByTypeAtPosition
                (*(int *)(g_PlayerEntitySceneObject + 0x14) -
                 (((int)(short)(&g_SinCosTable12Bit)
                               [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) - 0x400U & 0xfff]
                  << 8) >> 0xc),g_LeafSwimmingWhirlpoolPullActive,
                 *(int *)(g_PlayerEntitySceneObject + 0x1c) -
                 (((int)(short)(&g_SinCosTable12Bit)
                               [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff] << 8) >>
                 0xc),0x1a3,0x11);
      PlayAudioById(0x453,(int *)0,(undefined4 *)0);
      g_LeafSwimmingPlayerRouteSurfaceIndex = 1;
    }
    return 1;
  }
  return 0;
}

