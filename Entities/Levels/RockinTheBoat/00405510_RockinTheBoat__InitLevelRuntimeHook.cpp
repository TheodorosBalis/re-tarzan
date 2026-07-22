#include "tarzan_ghidra_types.hpp"

// Address: 0x00405510
// Label: RockinTheBoat::InitLevelRuntimeHook
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RockinTheBoat::InitLevelRuntimeHook(void)

{
  int value;
  undefined2 value2;
  uint value3;
  
  *( undefined1 *)((int)&g_RockinTheBoatDeckSurfaceA + 0) = (uint3)(ushort)g_RockinTheBoatDeckSurfaceA;
  *(undefined4 *)(g_CurrentWorldSceneContextPtr + 0x54) = 0;
  g_RockinTheBoatShipSwayVelocity = 0;
  PlayAudioById(0x352,(int *)0,(undefined4 *)0);
  if (g_CurrentCheckpointId != 0) {
    *( undefined1 *)((int)&g_RockinTheBoatDeckSurfaceA + 0) = CONCAT12(1,(ushort)g_RockinTheBoatDeckSurfaceA);
  }
  _g_RockinTheBoatLevelStateTable = 1;
  g_RockinTheBoatClampKnifeEnemyTargetZ = 0;
  _g_RockinTheBoatActiveKnifeEnemyCount = 0;
  g_RockinTheBoatNextFreeRoamKnifeVariant = 0;
  g_RockinTheBoatKnifeEnemySpawnCooldown = 0;
  g_RockinTheBoatNextKnifeEnemyVariant = 1;
  value2 = FindCollisionSurfaceIndexByCoordRef(0x46);
  g_RockinTheBoatDeckSurfaceA = CONCAT22(*( undefined2 *)((int)&g_RockinTheBoatDeckSurfaceA + 2),value2);
  *( undefined2 *)((int)&g_RockinTheBoatDeckSurfaceB + 0) = FindCollisionSurfaceIndexByCoordRef(0x47);
  *( undefined2 *)((int)&g_RockinTheBoatDeckSurfaceB + 2) = FindCollisionSurfaceIndexByCoordRef(0x48);
  value3 = g_RockinTheBoatDeckSurfaceA & 0xffff;
  value = value3 * 4 + 8;
  *( undefined2 *)((int)&g_RockinTheBoatDeckPathOffsetA + 0) =
       *(undefined2 *)
        (*(int *)(g_CollisionSurfaceTable + 4 + value3 * 4) + value + g_CollisionSurfaceTable);
  g_RockinTheBoatDeckPathOffsetB =
       *(undefined2 *)
        (*(int *)(g_CollisionSurfaceTable + 4 + value3 * 4) + value + g_CollisionSurfaceTable);
  _g_RockinTheBoatDeckPathOffsetC =
       *(undefined2 *)
        (*(int *)(g_CollisionSurfaceTable + 4 + value3 * 4) + value + g_CollisionSurfaceTable);
  return;
}

