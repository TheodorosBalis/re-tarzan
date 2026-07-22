#include "tarzan_ghidra_types.hpp"

// Address: 0x0045D160
// Label: StorkRide::UpdateScriptedObstacleB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::UpdateScriptedObstacleB(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value;
  char resultFlag;
  undefined4 localState2 [10];
  undefined4 localState [10];
  
  localState[0] = 0xe6;
  localState2[0] = 0x20;
  GetAngleFromXZVector12Bit
            (*(int *)(entity->sceneObjects + 0x14) - *(int *)(g_PlayerEntitySceneObjectData + 8)
             ,*(int *)(entity->sceneObjects + 0x1c) -
              *(int *)(g_PlayerEntitySceneObjectData + 0x10));
  value = (short *)(entity->sceneObjects + 0xa2);
  *value = *value + 0x40;
  value = (short *)(entity->sceneObjects + 0xa4);
  *value = *value + 4;
  value = (short *)(entity->sceneObjects + 0xa0);
  *value = *value + 0x80;
  resultFlag = CEntities::CheckSceneObjectSphereOverlap3D
                    (g_PlayerEntitySceneObject,localState,entity->sceneObjects,localState2
                    );
  if (resultFlag != '\0') {
    CPlayerHero::EnterStorkTerrainImpactReaction();
  }
  return;
}

