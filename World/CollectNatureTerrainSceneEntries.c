// 0x00439db0

void CollectNatureTerrainSceneEntries(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar1 = param_1;
  ConvertWorldPosToNatureTerrainGridCoords(param_2,&local_18);
  local_18 = local_18 - g_NatureTerrainVisibleGridCellsX / 2;
  local_14 = local_14 - g_NatureTerrainVisibleGridCellsY / 2;
  local_10 = local_10 - g_NatureTerrainVisibleGridCellsZ / 2;
  *(undefined4 *)(param_1 + 0x40) = 0;
  ResolveSceneEntryPointers(param_1);
  param_1 = 0;
  iVar2 = g_NatureTerrainVisibleGridCellsX;
  iVar3 = g_NatureTerrainVisibleGridCellsZ;
  iVar4 = g_NatureTerrainVisibleGridCellsY;
  if (0 < g_NatureTerrainVisibleGridCellsZ) {
    do {
      local_4 = local_10 + param_1;
      iVar5 = 0;
      if (0 < iVar4) {
        do {
          local_8 = local_14 + iVar5;
          iVar6 = 0;
          if (0 < iVar2) {
            do {
              local_c = iVar6 + local_18;
              iVar2 = FindNatureTerrainSceneEntryAtGridCoords(&local_c);
              if (iVar2 != 0) {
                *(int *)(iVar1 + 0x44 + *(int *)(iVar1 + 0x40) * 0x14) = iVar2;
                iVar2 = iVar1 + 0x48 + *(int *)(iVar1 + 0x40) * 0x14;
                *(int *)(iVar1 + 0x48 + *(int *)(iVar1 + 0x40) * 0x14) = local_c;
                *(int *)(iVar2 + 4) = local_8;
                *(int *)(iVar2 + 8) = local_4;
                *(int *)(iVar1 + 0x40) = *(int *)(iVar1 + 0x40) + 1;
              }
              iVar6 = iVar6 + 1;
              iVar2 = g_NatureTerrainVisibleGridCellsX;
              iVar3 = g_NatureTerrainVisibleGridCellsZ;
              iVar4 = g_NatureTerrainVisibleGridCellsY;
            } while (iVar6 < g_NatureTerrainVisibleGridCellsX);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      param_1 = param_1 + 1;
    } while (param_1 < iVar3);
  }
  return;
}