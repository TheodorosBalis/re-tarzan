// Address: 0x004A9450

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void QueueRenderPacket(float *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  
  pfVar5 = param_1;
  if (g_RenderPacketCount < 3000) {
    fVar1 = *param_1;
    if (fVar1 <= param_1[1]) {
      fVar2 = param_1[1];
      param_1 = (float *)fVar1;
    }
    else {
      param_1 = (float *)param_1[1];
      fVar2 = fVar1;
    }
    if (pfVar5[2] < (float)param_1) {
      param_1 = (float *)pfVar5[2];
    }
    if (fVar2 < pfVar5[2]) {
      fVar2 = pfVar5[2];
    }
    if ((_DAT_004ba2b4 <= fVar2) && ((float)param_1 <= _DAT_004ba46c)) {
      fVar1 = pfVar5[3];
      if (fVar1 <= pfVar5[4]) {
        fVar2 = pfVar5[4];
        param_1 = (float *)fVar1;
      }
      else {
        param_1 = (float *)pfVar5[4];
        fVar2 = fVar1;
      }
      if (pfVar5[5] < (float)param_1) {
        param_1 = (float *)pfVar5[5];
      }
      if (fVar2 < pfVar5[5]) {
        fVar2 = pfVar5[5];
      }
      if ((_DAT_004ba2b4 <= fVar2) && ((float)param_1 <= _DAT_004ba468)) {
        iVar4 = g_RenderPacketCount + 1;
        pfVar6 = (float *)(&DAT_00a08968 + g_RenderPacketCount * 0x3c);
        for (iVar3 = 0xf; g_RenderPacketCount = iVar4, iVar3 != 0; iVar3 = iVar3 + -1) {
          *pfVar6 = *pfVar5;
          pfVar5 = pfVar5 + 1;
          pfVar6 = pfVar6 + 1;
        }
      }
    }
  }
  return;
}


