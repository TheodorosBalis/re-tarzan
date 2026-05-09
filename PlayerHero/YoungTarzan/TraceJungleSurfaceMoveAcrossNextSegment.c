// 0x00448200
undefined4 TraceJungleSurfaceMoveAcrossNextSegment(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = param_1[3];
  param_1[3] = uVar1 + 0x1c;
  uVar2 = *(uint *)(uVar1 + 0x30);
  if ((uVar2 & 0xc000) == 0) {
LAB_00448300:
    if (((((uVar2 & 0x2000) == 0) && (*(short *)(uVar1 + 0x2e) != 0)) &&
        (*(short *)(uVar1 + 0x4a) != 0)) &&
       (((uVar2 & 0x30) == 0 &&
        (param_2 - param_3 < *(int *)(uVar1 + 0x20) - (int)*(short *)(uVar1 + 0x2e))))) {
LAB_0044832c:
      iVar3 = *(int *)(uVar1 + 0x28);
      param_1[3] = uVar1;
      param_1[1] = iVar3 - 1;
      return 6;
    }
  }
  else {
    if ((uVar2 & 0xe000) == 0x6000) {
      param_1[4] = 0;
      return 8;
    }
    if ((uVar2 & 0xc000) == 0x4000) {
      return 0;
    }
    iVar3 = *(int *)(g_JungleSurfaceTableBase + 4 + (uint)*(ushort *)(uVar1 + 0x34) * 4) + 0x34 +
            ((uint)*(ushort *)(uVar1 + 0x36) * 7 + (uint)*(ushort *)(uVar1 + 0x34)) * 4;
    uVar4 = iVar3 + g_JungleSurfaceTableBase;
    if ((*(uint *)(iVar3 + 0x14 + g_JungleSurfaceTableBase) & 0x2000) != 0) {
      return 0;
    }
    uVar2 = *(uint *)(uVar1 + 0x30);
    iVar3 = *(int *)(uVar4 + 4);
    if ((uVar2 & 0x2000) == 0) {
      if (*(int *)(uVar1 + 0x20) <= iVar3) {
        return 0;
      }
      if (iVar3 <= param_2 - g_JungleSurfaceTraceProbeSpan) {
        if ((*(short *)(uVar1 + 0x2e) != 0) && ((uVar2 & 0x30) == 0)) {
          iVar3 = *(int *)(uVar1 + 0x20) - (int)*(short *)(uVar1 + 0x2e);
        }
        if (param_2 - param_3 < iVar3) goto LAB_0044832c;
        goto LAB_00448300;
      }
    }
    else if ((iVar3 < param_2) && (g_JungleSurfaceTraceProbeSpan < param_2 - iVar3))
    goto LAB_0044832c;
    *param_1 = (uint)*(ushort *)(uVar1 + 0x34);
    iVar3 = *(int *)(uVar1 + 0x28);
    param_1[3] = uVar4;
    param_1[1] = param_1[1] - iVar3;
    param_1[1] = param_1[1] + *(int *)(uVar4 + 0xc);
  }
  return 0;
}