#include "tarzan_ghidra_types.hpp"

// Address: 0x004055F0
// Label: RockinTheBoat::UpdateLevelEntityState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::UpdateLevelEntityState(void)

{
  g_RockinTheBoatShipSwayVelocity =
       ((int)(short)(&g_SinCosTable12Bit)[(TotalGameLoopTicks - 0x40 & 0xff) * 0x10] +
       (int)(short)(&g_SinCosTable12Bit)[(TotalGameLoopTicks & 0x1ff) * 8]) * 0x71 >> 0xc;
  if (0x200 < *(int *)(g_PlayerEntitySceneObjectData + 0xc)) {
    QueuePlayerDamageEvent(0,0x200);
    g_PlayerSequenceDelayTicks = 0;
  }
  if (*(int *)(g_PlayerEntitySceneObjectData + 0xc) < -0xa00) {
    if (*(int *)(g_PlayerEntitySceneObjectData + 0x10) < 0xa01) {
      UpdateCurrentWorldSceneAuxResourceIfLoaded(9);
    }
    else {
      RequestCurrentWorldSceneAuxResourceIfMissing();
    }
    if (*(int *)(g_PlayerEntitySceneObjectData + 0x10) < 0x2000) {
      RequestCurrentWorldSceneAuxResourceIfMissing();
      RequestCurrentWorldSceneAuxResourceIfMissing(6);
      RequestCurrentWorldSceneAuxResourceIfMissing(2);
    }
    else {
      UpdateCurrentWorldSceneAuxResourceIfLoaded(3);
      UpdateCurrentWorldSceneAuxResourceIfLoaded(6);
      UpdateCurrentWorldSceneAuxResourceIfLoaded(2);
    }
    UpdateCurrentWorldSceneAuxResourceIfLoaded(1);
    UpdateCurrentWorldSceneAuxResourceIfLoaded(5);
    UpdateCurrentWorldSceneAuxResourceIfLoaded(6);
    return;
  }
  UpdateCurrentWorldSceneAuxResourceIfLoaded(3);
  UpdateCurrentWorldSceneAuxResourceIfLoaded(9);
  if (*(int *)(g_PlayerEntitySceneObjectData + 8) < 0) {
    RequestCurrentWorldSceneAuxResourceIfMissing();
    RequestCurrentWorldSceneAuxResourceIfMissing(6);
  }
  else {
    UpdateCurrentWorldSceneAuxResourceIfLoaded(5);
    UpdateCurrentWorldSceneAuxResourceIfLoaded(6);
  }
  if (*(int *)(g_PlayerEntitySceneObjectData + 0x10) < 0x3801) {
    UpdateCurrentWorldSceneAuxResourceIfLoaded(7);
  }
  else {
    RequestCurrentWorldSceneAuxResourceIfMissing();
  }
  if (*(int *)(g_PlayerEntitySceneObjectData + 0x10) < 0x3c01) {
    UpdateCurrentWorldSceneAuxResourceIfLoaded(2);
    UpdateCurrentWorldSceneAuxResourceIfLoaded(8);
  }
  else {
    RequestCurrentWorldSceneAuxResourceIfMissing();
    RequestCurrentWorldSceneAuxResourceIfMissing(8);
  }
  if (0x4a00 < *(int *)(g_PlayerEntitySceneObjectData + 0x10)) {
    UpdateCurrentWorldSceneAuxResourceIfLoaded(5);
    UpdateCurrentWorldSceneAuxResourceIfLoaded(6);
  }
  if (*(int *)(g_PlayerEntitySceneObjectData + 0x10) < -0x800) {
    RequestCurrentWorldSceneAuxResourceIfMissing();
    return;
  }
  UpdateCurrentWorldSceneAuxResourceIfLoaded(1);
  return;
}

