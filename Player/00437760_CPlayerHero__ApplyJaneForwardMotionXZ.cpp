#include "tarzan_ghidra_types.hpp"

// Address: 0x00437760
// Label: CPlayerHero::ApplyJaneForwardMotionXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ApplyJaneForwardMotionXZ(void)

{
  short shortValue;
  int value;
  
  value = *(int *)(g_PlayerMotionState + 0x10);
  shortValue = (&g_SinCosTable12Bit)[(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff];
  *(int *)(g_PlayerEntitySceneObjectData + 8) =
       *(int *)(g_PlayerEntitySceneObjectData + 8) -
       ((short)(&g_SinCosTable12Bit)
               [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) - 0x400U & 0xfff] * value >> 0xc);
  *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
       *(int *)(g_PlayerEntitySceneObjectData + 0x10) - (shortValue * value >> 0xc);
  return;
}

