#include "tarzan_ghidra_types.hpp"

// Address: 0x0045FC90
// Label: CPlayerHero::ApplyAdultTarzanElephantForwardMotionXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ApplyAdultTarzanElephantForwardMotionXZ(void)

{
  short shortValue;
  int value;
  
  if (g_AdultTarzanElephantEntitySceneObject != 0) {
    value = *(int *)(g_PlayerMotionState + 0x10);
    shortValue = (&g_SinCosTable12Bit)[(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff];
    *(int *)(g_AdultTarzanElephantEntitySceneObject + 0x14) =
         *(int *)(g_AdultTarzanElephantEntitySceneObject + 0x14) -
         ((short)(&g_SinCosTable12Bit)
                 [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) - 0x400U & 0xfff] * value >> 0xc
         );
    *(int *)(g_AdultTarzanElephantEntitySceneObject + 0x1c) =
         *(int *)(g_AdultTarzanElephantEntitySceneObject + 0x1c) - (shortValue * value >> 0xc);
  }
  return;
}

