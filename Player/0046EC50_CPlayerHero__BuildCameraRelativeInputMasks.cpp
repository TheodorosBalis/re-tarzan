#include "tarzan_ghidra_types.hpp"

// Address: 0x0046EC50
// Label: CPlayerHero::BuildCameraRelativeInputMasks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::BuildCameraRelativeInputMasks(void)

{
  int value;
  uint mask;
  int value2;
  
  value2 = (int)g_CameraYaw;
  g_CameraFollowFlags = 0;
  g_CameraRelativeTurnInputMask = 0;
  mask = (int)*(short *)(g_PlayerEntitySceneObject + 0xa2) & 0xfff;
  value = (int)(((-0x400 - value2) - mask) * 0x100000) >> 0x14;
  if ((value < 0x259) && (-0x259 < value)) {
    g_CameraFollowFlags = 0x20;
    g_CameraRelativeTurnInputMask = 0xd0;
  }
  value = (int)(((0x400 - value2) - mask) * 0x100000) >> 0x14;
  if ((value < 0x259) && (-0x259 < value)) {
    g_CameraFollowFlags = g_CameraFollowFlags | 0x80;
    g_CameraRelativeTurnInputMask = g_CameraRelativeTurnInputMask | 0x70;
  }
  value = (int)(((-0x800 - value2) - mask) * 0x100000) >> 0x14;
  if ((value < 0x259) && (-0x259 < value)) {
    g_CameraFollowFlags = g_CameraFollowFlags | 0x10;
    g_CameraRelativeTurnInputMask = g_CameraRelativeTurnInputMask | 0xe0;
  }
  value = (int)((value2 + mask) * -0x100000) >> 0x14;
  if ((value < 0x259) && (-0x259 < value)) {
    g_CameraFollowFlags = g_CameraFollowFlags | 0x40;
    g_CameraRelativeTurnInputMask = g_CameraRelativeTurnInputMask | 0xb0;
  }
  return;
}

