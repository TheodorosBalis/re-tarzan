// 0x00448830
void GetJungleSurfaceSegment(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = param_1 * 4 + 4;
  FindJungleSurfaceSegmentAtCoord(*(int *)(iVar1 + g_JungleSurfaceTableBase) + iVar1 + g_JungleSurfaceTableBase,param_2);
  return;
}
