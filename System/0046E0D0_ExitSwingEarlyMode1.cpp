#include "tarzan_ghidra_types.hpp"

// Address: 0x0046E0D0
// Label: ExitSwingEarlyMode1
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ExitSwingEarlyMode1(void)

{
  undefined2 value2;
  int value;
  
  if (g_CurrentSwingEntity != 0) {
    value = CEntities::FindEntityAttachmentByFlags(g_CurrentSwingEntity,0x8000000);
    if (value != 0) {
      *(undefined2 *)(value + 0xe) = 4;
    }
    value2 = g_PlayerActionState;
    if (g_CurrentSwingSegmentIndex < 3) {
      g_PlayerActionState = 0x17;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046e10f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterSwingingHandlerPtr)();
      return;
    }
  }
  if (g_PreviousPlayerActionState == 0x17) {
    if (*(byte *)(g_PlayerEntitySceneObject + 0x75) != g_PlayerFacingBeforeSwing) {
      *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
      *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
           *(ushort *)(g_PlayerEntitySceneObject + 0xa2) ^ 0x800;
    }
  }
  if (g_PlayerAnimationSurfaceSide == '\0') {
    CPlayerHero::PlayAdultTarzanAnimation(0x43);
    return;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x42);
  return;
}

