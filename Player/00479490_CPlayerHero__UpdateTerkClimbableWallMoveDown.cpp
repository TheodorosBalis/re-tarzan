#include "tarzan_ghidra_types.hpp"

// Address: 0x00479490
// Label: CPlayerHero::UpdateTerkClimbableWallMoveDown
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTerkClimbableWallMoveDown(void)

{
  undefined2 value2;
  int value;
  
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0xa0;
    value2 = g_PlayerActionState;
    if (g_PlayerInteractionCollisionHeightRange <
        *(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
           g_PlayerInteractionCollisionHeightRange + g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x19;
                    /* WARNING: Could not recover jumptable at 0x0047950d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallIdleHandlerPtr)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x40) == 0) {
      g_PlayerActionState = 0x19;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00479533. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallIdleHandlerPtr)();
      return;
    }
  }
  return;
}

