#include "tarzan_ghidra_types.hpp"

// Address: 0x0040FBD0
// Label: ConflictWithClayton::InitializeBattle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ConflictWithClayton::InitializeBattle(void)

{
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  g_ClaytonBattleBehaviorState = 0;
  _g_ClaytonPendingVoiceLineState = 0;
  g_ClaytonDefeatVoiceLineIndex = 0;
  CCamera::EnterClaytonBattleCameraMode();
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  CEntities::ResetRandomAmbientSoundCountdown();
  _g_ClaytonVoiceLineCooldown = 0;
  g_ClaytonIdleTauntCountdown = 0x5a;
  g_PlayerSequenceDelayTicks = 100;
  CEntities::SpawnEntityByTypeAtPosition
            (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
             *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
             *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0x2a,0x11);
  return;
}

