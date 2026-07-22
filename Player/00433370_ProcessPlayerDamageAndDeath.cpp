#include "tarzan_ghidra_types.hpp"

// Address: 0x00433370
// Label: ProcessPlayerDamageAndDeath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProcessPlayerDamageAndDeath(void)

{
  uint value;
  uint value2;
  
  if (((g_PlayerDamageInvulnerabilityTicks == 0) ||
      (g_PlayerDamageInvulnerabilityTicks = g_PlayerDamageInvulnerabilityTicks + -1,
      g_PlayerDamageFlashTicks == 0)) ||
     (g_PlayerDamageFlashTicks = g_PlayerDamageFlashTicks + -1, FrameCount % 3 != 0)) {
    *(ushort *)(g_PlayerEntitySceneObjectData + 2) =
         *(ushort *)(g_PlayerEntitySceneObjectData + 2) | 0x8000;
  }
  else {
    *(ushort *)(g_PlayerEntitySceneObjectData + 2) =
         *(ushort *)(g_PlayerEntitySceneObjectData + 2) & 0x7fff;
  }
  if ((ram0x0051cdca & 0x400) != 0) {
    if (_g_PlayerHeroMode == 1) {
      PlayAudioById(0x5b,(int *)0,(undefined4 *)0);
    }
    else {
      if (_g_PlayerHeroMode == 2) {
        PlayAudioById(0x1c,(int *)0,(undefined4 *)0);
        _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x8000;
        return;
      }
      if (_g_PlayerHeroMode == 6) {
        PlayAudioById(0x4bf,(int *)0,(undefined4 *)0);
        _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x8000;
        return;
      }
    }
    _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x8000;
    return;
  }
  if ((g_GameplayRuntimeFlags & 0x80000004) == 0x80000004) {
    g_PendingPlayerDamage = 0;
  }
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PendingPlayerDamage != 0)) {
    g_PlayerFacingCurrentCollisionSurface = 1;
    if (g_PendingPlayerDamageSourceEntity != 0) {
      *(byte *)(g_PendingPlayerDamageSourceEntity + 0x43) =
           *(byte *)(g_PendingPlayerDamageSourceEntity + 0x43) | 0x20;
    }
    if ((g_PlayerPendingDamageSourceFlags != g_PendingPlayerDamageSourceEntity) &&
       ((ram0x0051cdca & 0xa00) == 0)) {
      if ((ram0x0051cdca & 0x100) == 0) {
        value = ram0x0051cdca & 0xf;
        value2 = value;
      }
      else {
        value = 1;
        value2 = ram0x0051cdca;
      }
      PlayForceFeedbackEffect_Stub
                (0,CONCAT22((short)(value2 >> 0x10),
                            *(undefined2 *)(&g_PlayerForceFeedbackEffectTable + value * 4)),
                 CONCAT31((int3)(g_GameplayRuntimeFlags >> 8),
                          (&g_PlayerForceFeedbackEffectParamByte)[value * 4]));
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerHealth = g_PlayerHealth - g_PendingPlayerDamage;
      if (g_PlayerHealth < 0) {
        if ((g_GameplayRuntimeFlags & 0x80000008) == 0x80000008) {
          g_PlayerHealth = 0;
          return;
        }
        _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x8000;
        if (_g_PlayerHeroMode == 1) {
          PlayAudioById(0x5a,(int *)0,(undefined4 *)0);
          return;
        }
        if (_g_PlayerHeroMode == 2) {
          PlayAudioById(0x1b,(int *)0,(undefined4 *)0);
          return;
        }
        if (_g_PlayerHeroMode == 6) {
          PlayAudioById(0x4be,(int *)0,(undefined4 *)0);
          return;
        }
      }
      else {
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        g_PlayerDamageFlashTicks = 0x3c;
      }
    }
  }
  return;
}

