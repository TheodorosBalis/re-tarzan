#include "tarzan_ghidra_types.hpp"

// Address: 0x0045BEF0
// Label: CPlayerHero::ApplyStorkForwardMotionXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ApplyStorkForwardMotionXZ(void)

{
  int value;
  
  value = *(int *)(g_PlayerMotionState + 0x10) >> 8;
  *(int *)(g_PlayerEntitySceneObjectData + 8) =
       *(int *)(g_PlayerEntitySceneObjectData + 8) -
       ((short)(&g_SinCosTable12Bit)[*(ushort *)(g_PlayerEntitySceneObject + 0xa2) - 0x400 & 0xfff]
        * value >> 0xc);
  *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
       *(int *)(g_PlayerEntitySceneObjectData + 0x10) + value;
  return;
}

