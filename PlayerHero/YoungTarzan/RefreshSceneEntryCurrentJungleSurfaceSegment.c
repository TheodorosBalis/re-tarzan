// 0x00449050
int RefreshSceneEntryCurrentJungleSurfaceSegment(int param_1)

{
  int iVar1;
  
  g_JungleSurfaceTraceProbeSpan = 0x20;
  iVar1 = GetJungleSurfaceSegment(*(undefined4 *)(param_1 + 0x110),*(undefined4 *)(param_1 + 0x10c))
  ;
  if (iVar1 != 0) {
    SampleJungleSurfacePointWithFloorOffset(*(undefined4 *)(iVar1 + 0xc),iVar1,param_1 + 0x120);
  }
  return iVar1;
}