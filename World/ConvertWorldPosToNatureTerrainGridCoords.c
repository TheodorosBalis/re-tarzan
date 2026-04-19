// 0x00439cc0
void ConvertWorldPosToNatureTerrainGridCoords(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 < 0) {
    iVar1 = (iVar1 - g_NatureTerrainCellSizeX) + 1;
  }
  *param_2 = iVar1;
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    iVar1 = (iVar1 - g_NatureTerrainCellSizeY) + 1;
  }
  param_2[1] = iVar1;
  iVar1 = param_1[2];
  if (iVar1 < 0) {
    iVar1 = (iVar1 - g_NatureTerrainCellSizeZ) + 1;
  }
  param_2[2] = iVar1;
  *param_2 = *param_2 / g_NatureTerrainCellSizeX;
  param_2[1] = param_2[1] / g_NatureTerrainCellSizeY;
  param_2[2] = param_2[2] / g_NatureTerrainCellSizeZ;
  return;
}