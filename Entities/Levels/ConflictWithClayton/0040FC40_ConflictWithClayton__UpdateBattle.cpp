#include "tarzan_ghidra_types.hpp"

// Address: 0x0040FC40
// Label: ConflictWithClayton::UpdateBattle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ConflictWithClayton::UpdateBattle(void)

{
  int value;
  
  CEntities::UpdateRandomAmbientSoundCue();
  if (*(short *)(g_ClaytonEntity + 0x48) == 0x16) goto LAB_0040fdc6;
  if (0 < _g_ClaytonVoiceLineCooldown) {
    _g_ClaytonVoiceLineCooldown = _g_ClaytonVoiceLineCooldown + -1;
    goto LAB_0040fdc6;
  }
  switch(_g_ClaytonPendingVoiceLineState) {
  case 3:
    value = RandomModulo(2);
    g_ClaytonCloseAttackVoiceLineIndex = (value + 1 + g_ClaytonCloseAttackVoiceLineIndex) % 3;
    PlayAudioById(*(undefined4 *)
                   (&g_ClaytonCloseAttackVoiceLineTable + g_ClaytonCloseAttackVoiceLineIndex * 4),0,
                  0);
    _g_ClaytonPendingVoiceLineState = 0;
    break;
  case 4:
    value = RandomModulo(5);
    g_ClaytonAttackVoiceLineIndex = (value + 1 + g_ClaytonAttackVoiceLineIndex) % 6;
    PlayAudioById(*(undefined4 *)
                   (&g_ClaytonAttackVoiceLineTable + g_ClaytonAttackVoiceLineIndex * 4),0,0);
    _g_ClaytonPendingVoiceLineState = 0;
    break;
  case 5:
    value = RandomModulo(2);
    g_ClaytonHitReactionVoiceLineIndex = (value + 1 + g_ClaytonHitReactionVoiceLineIndex) % 3;
    PlayAudioById(*(undefined4 *)
                   (&g_ClaytonHitReactionVoiceLineTable + g_ClaytonHitReactionVoiceLineIndex * 4),0,
                  0);
    _g_ClaytonPendingVoiceLineState = 0;
    g_ClaytonIdleTauntCountdown = 0x7512;
    goto LAB_0040fdc6;
  default:
    if ((g_ClaytonBattleBehaviorState != 0) ||
       (g_ClaytonIdleTauntCountdown = g_ClaytonIdleTauntCountdown + -1,
       g_ClaytonIdleTauntCountdown != 0)) goto LAB_0040fdc6;
    value = RandomModulo(5);
    g_ClaytonIdleTauntVoiceLineIndex = (value + 1 + g_ClaytonIdleTauntVoiceLineIndex) % 6;
    PlayAudioById(*(undefined4 *)
                   (&g_ClaytonIdleTauntVoiceLineTable + g_ClaytonIdleTauntVoiceLineIndex * 4),0,0);
    break;
  case 7:
    PlayAudioById(*(undefined4 *)
                   (&g_ClaytonDefeatVoiceLineTable + g_ClaytonDefeatVoiceLineIndex * 4),0,0);
    if (g_ClaytonDefeatVoiceLineIndex < 4) {
      g_ClaytonDefeatVoiceLineIndex = g_ClaytonDefeatVoiceLineIndex + 1;
    }
    _g_ClaytonPendingVoiceLineState = 0;
    goto LAB_0040fdc6;
  }
  value = RandomModulo(600);
  g_ClaytonIdleTauntCountdown = value + 0xf0;
LAB_0040fdc6:
  if ((g_ClaytonBattleCameraState != 1) && ((_g_PlayerSequenceFlags & 0x8000) != 0)) {
    if (g_PlayerActionState != 7) {
      _g_ClaytonPendingVoiceLineState = 5;
    }
    g_ClaytonBattleCameraState = 1;
    g_ClaytonBattleBehaviorState = 2;
  }
  UpdateModelHeapStats();
  return;
}

