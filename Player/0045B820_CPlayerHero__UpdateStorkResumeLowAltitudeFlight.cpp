#include "tarzan_ghidra_types.hpp"

// Address: 0x0045B820
// Label: CPlayerHero::UpdateStorkResumeLowAltitudeFlight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkResumeLowAltitudeFlight(void)

{
  short *value2;
  int value;
  
  value2 = (short *)(g_PlayerEntitySceneObject + 0xa0);
  value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa0),0);
  *value2 = *value2 + (short)(value >> 3);
  value2 = (short *)(g_PlayerEntitySceneObject + 0xa4);
  value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa4),0);
  *value2 = *value2 + (short)(value >> 3);
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 2;
  (*(code *)g_StorkEnterLowAltitudeFlightHandlerPtr)();
  CPlayerHero::AdvanceAnimationScript();
  return;
}

