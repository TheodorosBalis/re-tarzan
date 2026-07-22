#include "tarzan_ghidra_types.hpp"

// Address: 0x00405E00
// Label: RockinTheBoat::UpdateKnifeEnemyController
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RockinTheBoat::UpdateKnifeEnemyController(int entry)

{
  int value;
  undefined4 value3;
  int value2;
  undefined4 value4;
  
  if (*(int *)(g_PlayerEntitySceneObject + 0x108) == 1) {
    value2 = *(int *)(entry + 0x18);
    if (*(int *)(entry + 0x18) != 0) {
      do {
        value = *(int *)(value2 + 0x18);
        if (*(short *)(value2 + 0x46) == 0x150) {
          CEntities::ReleaseEntityToFreeList((byte *)value2);
        }
        value2 = value;
      } while (value != 0);
      return;
    }
  }
  else if (-0x501 < *(int *)(g_PlayerEntitySceneObjectData + 0xc)) {
    _g_RockinTheBoatActiveKnifeEnemyCount = RockinTheBoat::CountActiveKnifeEnemies(entry);
    if (_g_RockinTheBoatActiveKnifeEnemyCount == 0) {
      if (*(short *)(&g_RockinKnifeEnemySpawnVariantTable +
                    g_RockinTheBoatNextFreeRoamKnifeVariant * 0x10) < 0) {
        g_RockinTheBoatNextFreeRoamKnifeVariant = 6;
        return;
      }
      if (g_RockinTheBoatKnifeEnemySpawnCooldown != 0) {
        g_RockinTheBoatKnifeEnemySpawnCooldown = g_RockinTheBoatKnifeEnemySpawnCooldown + -1;
        return;
      }
      if (*(int *)(g_PlayerEntitySceneObjectData + 0x10) < 0x1001) {
        value3 = 0xfffffc49;
        value4 = 0x1f50;
      }
      else {
        value3 = 0xfffffc17;
        value4 = 0x5e0;
      }
      value2 = CEntities::SpawnEntityByTypeAtPosition(value3,0,value4,0x150,0x11);
      if (value2 != 0) {
        CEntities::AppendEntityToChildChain(entry,value2);
        g_RockinTheBoatNextFreeRoamKnifeVariant = g_RockinTheBoatNextFreeRoamKnifeVariant + 1;
        value2 = RandomModulo(0x3c);
        g_RockinTheBoatKnifeEnemySpawnCooldown = value2 + 0x3c;
      }
    }
  }
  return;
}

