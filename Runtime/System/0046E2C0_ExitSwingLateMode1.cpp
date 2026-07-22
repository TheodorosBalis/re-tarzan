#include "tarzan_ghidra_types.hpp"

// Address: 0x0046E2C0
// Label: ExitSwingLateMode1
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ExitSwingLateMode1(void)

{
  undefined2 value2;
  int value;
  
  if (g_CurrentSwingEntity != 0) {
    value = CEntities::FindEntityAttachmentByFlags(g_CurrentSwingEntity,0x8000000);
    value2 = g_PlayerActionState;
    if (value == 0) {
      g_PlayerActionState = 0x17;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046e322. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterSwingingHandlerPtr)();
      return;
    }
    *(undefined2 *)(value + 0xe) = 4;
    value2 = g_PlayerActionState;
    if (g_MaxSwingSegmentIndex <= g_CurrentSwingSegmentIndex) {
      g_PlayerActionState = 0x17;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046e305. Too many branches */
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
    CPlayerHero::PlayAdultTarzanAnimation(0x49);
    return;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x48);
  return;
}

