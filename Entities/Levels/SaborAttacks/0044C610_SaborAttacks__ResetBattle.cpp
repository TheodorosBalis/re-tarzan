#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C610
// Label: SaborAttacks::ResetBattle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::ResetBattle(void)

{
  CEntities::SpawnEntityByTypeAtPosition
            (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
             *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
             *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0x20,0x11);
  SelectBackgroundMusicTrackForLevel(0);
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  CEntities::ResetRandomAmbientSoundCountdown();
  g_SaborBattleHudMeterValue = 1;
  return;
}

