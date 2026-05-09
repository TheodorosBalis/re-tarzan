// 0x004490e0
int RefreshSceneEntryPreviousJungleSurfaceSegment(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00448fe0(param_1 + 0x10c,*(undefined4 *)(param_1 + 0x18),0x20);
  if (iVar1 != 0) {
    SampleJungleSurfacePointWithFloorOffset(*(undefined4 *)(iVar1 + 0xc),iVar1,param_1 + 0x120);
  }
  return iVar1;
}

int FUN_00448fe0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  g_JungleSurfaceTraceProbeSpan = 0x20;
  iVar1 = GetJungleSurfaceSegment(param_1[1],*param_1);
  if (*(int *)(iVar1 + 0xc) == *param_1) {
    _DAT_00533af8 = param_1[1];
    _DAT_00533b00 = 0xffffffff;
    _DAT_00533afc = *param_1 + -1;
    DAT_00533b04 = iVar1;
    if (*param_1 == *(int *)(iVar1 + 0xc)) {
      TraceJungleSurfaceMoveAcrossPreviousSegment(&DAT_00533af8,param_2,param_3);
      iVar1 = DAT_00533b04;
    }
  }
  return iVar1;
}