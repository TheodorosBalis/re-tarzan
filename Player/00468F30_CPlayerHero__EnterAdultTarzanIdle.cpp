#include "tarzan_ghidra_types.hpp"

// Address: 0x00468F30
// Label: CPlayerHero::EnterAdultTarzanIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanIdle(void)

{
  undefined2 value;
  short shortValue;
  
  value = g_PlayerActionState;
  if (g_PlayerCurrentCollisionMode != 1) {
    CPlayerHero::PlayAdultTarzanAnimation(8);
    shortValue = RandomModulo(10);
    g_PlayerIdleFidgetDelayTicks = shortValue + 5;
    g_PlayerTiltControlEnabled = 0;
    return;
  }
  g_PlayerActionState = 0x40;
  g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x00468f72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*g_AdultTarzanActionCallback_Field01E8)();
  return;
}

