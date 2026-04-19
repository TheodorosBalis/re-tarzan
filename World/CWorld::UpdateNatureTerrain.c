// 0x00439f10

void CWorld::UpdateNatureTerrain(int *param_1,undefined4 param_2)

{
  if ((*(byte *)(param_1 + 5) & 2) != 0) {
    CollectNatureTerrainSceneEntries(param_1,param_2);
  }
  UpdateSceneEntryAnimations(*param_1 + 0x10);
  return;
}