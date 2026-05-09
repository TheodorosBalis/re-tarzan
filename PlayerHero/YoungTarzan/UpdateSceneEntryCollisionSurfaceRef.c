// 0x0043f1f0
int UpdateSceneEntryCollisionSurfaceRef(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (*(int *)(param_3 + 0x108) != 1) {
    return 0;
  }
  if (*(int *)(param_3 + 0x110) == -1) {
    return 2;
  }
  if (param_1 == 0) {
    iVar1 = RefreshSceneEntryCurrentJungleSurfaceSegment();
    *(int *)(param_3 + 0x114) = iVar1;
    return (-(uint)(iVar1 != 0) & 0xfffffffc) + 4;
  }
  if (0 < param_1) {
    iVar1 = RefreshSceneEntryNextJungleSurfaceSegment();
    *(int *)(param_3 + 0x114) = iVar1;
    return (-(uint)(iVar1 != 0) & 0xfffffffc) + 4;
  }
  iVar1 = RefreshSceneEntryPreviousJungleSurfaceSegment(param_3);
  *(int *)(param_3 + 0x114) = iVar1;
  return (-(uint)(iVar1 != 0) & 0xfffffffc) + 4;
}