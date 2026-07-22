#include "tarzan_ghidra_types.hpp"

// Address: 0x00433B80
// Label: SetPlayerActionState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetPlayerActionState(int arg1)

{
  undefined2 stateFlags;
  
  stateFlags = (undefined2)arg1;
  switch(_g_PlayerHeroMode) {
  case 1:
  case 3:
    g_PreviousPlayerActionState = g_PlayerActionState;
                    /* WARNING: Could not recover jumptable at 0x00433baf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    g_PlayerActionState = stateFlags;
    (*(code *)(&g_AdultTarzanActionStateEnterColumn)[arg1 * 2])();
    return;
  case 2:
    g_PreviousPlayerActionState = g_PlayerActionState;
                    /* WARNING: Could not recover jumptable at 0x00433bce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    g_PlayerActionState = stateFlags;
    (*(code *)(&g_YoungTarzanActionStateTable)[arg1 * 2])();
    return;
  case 4:
    g_PreviousPlayerActionState = g_PlayerActionState;
                    /* WARNING: Could not recover jumptable at 0x00433c0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    g_PlayerActionState = stateFlags;
    (**(code **)(&g_JaneActionStateEnterColumn + arg1 * 8))();
    return;
  case 5:
    g_PreviousPlayerActionState = g_PlayerActionState;
                    /* WARNING: Could not recover jumptable at 0x00433c29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    g_PlayerActionState = stateFlags;
    (*(code *)(&g_TarzanSurfingWithJaneActionStateEnterColumn)[arg1 * 2])();
    return;
  case 6:
    g_PreviousPlayerActionState = g_PlayerActionState;
                    /* WARNING: Could not recover jumptable at 0x00433bed. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    g_PlayerActionState = stateFlags;
    (*(code *)(&g_TerkActionStateHandlerTable)[arg1 * 2])();
    return;
  default:
    g_PreviousPlayerActionState = g_PlayerActionState;
                    /* WARNING: Could not recover jumptable at 0x00433c48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    g_PlayerActionState = stateFlags;
    (*(code *)(&g_AdultTarzanActionStateEnterColumn)[arg1 * 2])();
    return;
  }
}

