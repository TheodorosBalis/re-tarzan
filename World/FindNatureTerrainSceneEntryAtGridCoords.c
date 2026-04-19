// 0x00439c80
int FindNatureTerrainSceneEntryAtGridCoords(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FindNatureTerrainCellIndexAtGridCoords(param_1,g_NatureTerrainDataBlock + 0x3c);
  if (iVar1 != -1) {
    return *(int *)(iVar1 * 4 + g_NatureTerrainSceneEntryOffsetTable) + iVar1 * 4 +
           g_NatureTerrainSceneEntryOffsetTable;
  }
  return 0;
}