#include "tarzan_ghidra_types.hpp"

// Address: 0x004811E0
// Label: CPlayerHero::IntegrateLeafSwimmingMotionAndClearObstacleResponse
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::IntegrateLeafSwimmingMotionAndClearObstacleResponse(void)

{
  short shortValue;
  short shortValue2;
  int value;
  int value2;
  int value3;
  
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000002);
  if ((value != 0) && (g_LeafSwimmingCameraDistanceBoostActive == 0)) {
    value2 = (0xff - (*(int *)(value + 0x18) * *(int *)(value + 0x10) >> 8)) *
            (*(int *)(g_PlayerMotionState + 0x10) >> 8) >> 8;
    value3 = (*(int *)(value + 0xc) >> 8) * *(int *)(value + 0x10) >> 8;
    shortValue = (&g_SinCosTable12Bit)[(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff];
    shortValue2 = (&g_SinCosTable12Bit)[*(int *)(value + 0x14) - 0x800U & 0xfff];
    *(int *)(g_PlayerEntitySceneObjectData + 8) =
         *(int *)(g_PlayerEntitySceneObjectData + 8) -
         (((short)(&g_SinCosTable12Bit)[*(int *)(value + 0x14) + 0x400U & 0xfff] * value3 >> 0xc) +
         ((short)(&g_SinCosTable12Bit)
                 [(int)*(short *)(g_PlayerEntitySceneObject + 0xa2) - 0x400U & 0xfff] * value2 >> 0xc
         ));
    *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
         *(int *)(g_PlayerEntitySceneObjectData + 0x10) -
         ((shortValue2 * value3 >> 0xc) + (shortValue * value2 >> 0xc));
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000002);
  if (value != 0) {
    *(undefined4 *)(value + 0x14) = 0;
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined4 *)(value + 0x10) = 0;
    *(undefined4 *)(value + 0x18) = 0;
    _g_LeafSwimmingObstacleResponseFlags = 0;
    g_LeafSwimmingCameraDistanceBoostActive = 0;
  }
  return;
}

