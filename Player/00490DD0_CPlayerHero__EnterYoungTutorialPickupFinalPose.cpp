#include "tarzan_ghidra_types.hpp"

// Address: 0x00490DD0
// Label: CPlayerHero::EnterYoungTutorialPickupFinalPose
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungTutorialPickupFinalPose(void)

{
  g_TutorialPickupSequenceTick = 0;
  g_TutorialPickupFinalPoseDurationTicks =
       *(undefined4 *)(&g_TutorialPickupSequenceTable + g_ActiveTutorialPickupId * 0x30);
  g_TutorialPickupVoiceCueTick =
       *(undefined4 *)(&g_TutorialPickupVoiceCueTickTable + g_ActiveTutorialPickupId * 0x30);
  CPlayerHero::PlayAnimation(0x9f);
  return;
}

