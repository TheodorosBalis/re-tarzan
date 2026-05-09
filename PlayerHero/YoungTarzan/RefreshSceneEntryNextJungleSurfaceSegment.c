// 0x004490a0
int RefreshSceneEntryNextJungleSurfaceSegment(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00448f60(param_1 + 0x10c,*(undefined4 *)(param_1 + 0x18),0x20);
  if (iVar1 != 0) {
    SampleJungleSurfacePointWithFloorOffset(*(undefined4 *)(iVar1 + 0xc),iVar1,param_1 + 0x120);
  }
  return iVar1;
}

int FUN_00448f60(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  g_JungleSurfaceTraceProbeSpan = 0x20;
  iVar1 = GetJungleSurfaceSegment(param_1[1],*param_1);
  if ((*(uint *)(iVar1 + 0x14) & 0x2000) != 0) {
    return 0;
  }
  DAT_00533b18 = *(int *)(iVar1 + 0x28) - *param_1;
  _DAT_00533b10 = param_1[1];
  _DAT_00533b14 = *param_1 + DAT_00533b18;
  DAT_00533b1c = iVar1;
  uVar2 = TraceJungleSurfaceMoveAcrossNextSegment(&DAT_00533b10,param_2,param_3);
  if (((uVar2 & 2) != 0) && (0 < DAT_00533b18)) {
    DAT_00533b1c = DAT_00533b1c + 0x1c;
  }
  return DAT_00533b1c;
}