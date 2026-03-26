// Address: 0x00444BA0

undefined4 * PrepareMenuSceneNodeTransform(int param_1,int *param_2)

{
  uint *puVar1;
  ushort uVar2;
  short sVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  int local_8;
  
  local_20 = (*(int *)(param_1 + 0x3c) + *(int *)(param_1 + 0x14)) - *param_2;
  local_1c = (*(int *)(param_1 + 0x40) - param_2[1]) + *(int *)(param_1 + 0x18);
  puVar1 = (uint *)(param_2 + 0x1a);
  uVar2 = *(ushort *)(param_1 + 0xe);
  local_18 = (*(int *)(param_1 + 0x44) - param_2[2]) + *(int *)(param_1 + 0x1c);
  TransformVectorByBasis(puVar1,&local_20,&DAT_00a43934);
  DAT_00a43934 = DAT_00a43934 + param_2[0x1f];
  DAT_00a43938 = DAT_00a43938 + param_2[0x20];
  DAT_00a4393c = DAT_00a4393c + param_2[0x21];
  DAT_00a438eb = (&DAT_004ef5b0)[((int)(uint)uVar2 >> 1 & 7U) * 4];
  sVar3 = *(short *)(param_1 + 0xa6);
  if (sVar3 == 3) {
    if ((uVar2 & 0x1000) == 0) {
      DAT_00a43920 = *puVar1;
      DAT_00a43924 = param_2[0x1b];
      DAT_00a43928 = param_2[0x1c];
      DAT_00a4392c = param_2[0x1d];
      DAT_00a43930 = (short)param_2[0x1e];
      if ((uVar2 & 0xe) == 0) {
        if (*(int *)(param_1 + 0xb4) != 0) {
          ScaleBasisAxesClamped(&DAT_00a43920,param_1 + 0xa8);
        }
      }
      else if (*(int *)(param_1 + 0xb4) == 0) {
        local_10 = (-(uint)((uVar2 & 2) != 0) & 0xffffe000) + 0x1000;
        local_c = (-(uint)((uVar2 & 4) != 0) & 0xffffe000) + 0x1000;
        local_8 = (-(uint)((uVar2 & 8) != 0) & 0xffffe000) + 0x1000;
        ScaleBasisAxesClamped(&DAT_00a43920,&local_10);
      }
      else {
        ScaleBasisAxesClamped(&DAT_00a43920,param_1 + 0xa8);
      }
    }
    else {
      uVar5 = *(ushort *)(param_2 + 0x16);
      DAT_00a43920 = (uint)uVar5;
      DAT_00a43924 = 0;
      uVar4 = *(ushort *)(param_2 + 0x17);
      DAT_00a43928 = (uint)uVar4;
      DAT_00a4392c = 0;
      DAT_00a43930 = (short)param_2[0x18];
      if ((uVar2 & 0xe) == 0) {
        if (*(int *)(param_1 + 0xb4) != 0) {
          DAT_00a43920 = *(int *)(param_1 + 0xa8) * (int)(short)uVar5 >> 0xc & 0xffff;
          DAT_00a43928 = *(int *)(param_1 + 0xac) * (int)(short)uVar4 >> 0xc & 0xffff;
          DAT_00a43930 = (short)(*(int *)(param_1 + 0xb0) * (int)DAT_00a43930 >> 0xc);
        }
      }
      else if (*(int *)(param_1 + 0xb4) == 0) {
        DAT_00a43920 = (uint)(ushort)((-(ushort)((uVar2 & 2) != 0) & 0xe000) + 0x1000);
        DAT_00a43928 = (uint)(ushort)((-(ushort)((uVar2 & 4) != 0) & 0xe000) + 0x1000);
        DAT_00a43930 = (-(ushort)((uVar2 & 8) != 0) & 0xe000) + 0x1000;
      }
      else {
        if ((uVar2 & 2) == 0) {
          uVar5 = (ushort)(*(int *)(param_1 + 0xa8) * (int)(short)uVar5 >> 0xc);
        }
        else {
          uVar5 = -(short)(*(int *)(param_1 + 0xa8) * (int)(short)uVar5 >> 0xc);
        }
        DAT_00a43920 = (uint)uVar5;
        if ((uVar2 & 4) == 0) {
          uVar5 = (ushort)(*(int *)(param_1 + 0xac) * (int)(short)uVar4 >> 0xc);
        }
        else {
          uVar5 = -(short)(*(int *)(param_1 + 0xac) * (int)(short)uVar4 >> 0xc);
        }
        DAT_00a43928 = (uint)uVar5;
        if ((uVar2 & 8) == 0) {
          DAT_00a43930 = (short)(*(int *)(param_1 + 0xb0) * (int)DAT_00a43930 >> 0xc);
        }
        else {
          DAT_00a43930 = -(short)(*(int *)(param_1 + 0xb0) * (int)DAT_00a43930 >> 0xc);
        }
      }
    }
  }
  else {
    if (FrameCount != *(int *)(param_1 + 0xf8)) {
      *(int *)(param_1 + 0xf8) = FrameCount;
      if (sVar3 == 0) {
        BuildBasisMatrixFromEulerAngles(param_1 + 0xa0,param_1 + 0xb8);
      }
      else if (sVar3 == 1) {
        FUN_004a26b0(param_1 + 0xa0,param_1 + 0xb8);
      }
      else if (sVar3 == 2) {
        FUN_004a2830(param_1 + 0xa0,param_1 + 0xb8);
      }
      if (*(int *)(param_1 + 0xb4) != 0) {
        ScaleBasisAxesClamped(param_1 + 0xb8,param_1 + 0xa8);
      }
    }
    if ((uVar2 & 0xe) != 0) {
      if ((uVar2 & 2) != 0) {
        *(short *)(param_1 + 0xb8) = -*(short *)(param_1 + 0xb8);
        *(short *)(param_1 + 0xbe) = -*(short *)(param_1 + 0xbe);
        *(short *)(param_1 + 0xc4) = -*(short *)(param_1 + 0xc4);
      }
      if ((uVar2 & 4) != 0) {
        *(short *)(param_1 + 0xba) = -*(short *)(param_1 + 0xba);
        *(short *)(param_1 + 0xc0) = -*(short *)(param_1 + 0xc0);
        *(short *)(param_1 + 0xc6) = -*(short *)(param_1 + 0xc6);
      }
      if ((uVar2 & 8) != 0) {
        *(short *)(param_1 + 0xbc) = -*(short *)(param_1 + 0xbc);
        *(short *)(param_1 + 0xc2) = -*(short *)(param_1 + 0xc2);
        *(short *)(param_1 + 200) = -*(short *)(param_1 + 200);
      }
    }
    MultiplyBasisMatrices(puVar1,param_1 + 0xb8,&DAT_00a43920);
  }
  SetDrawWindow(param_2[0x31],*(undefined4 *)(param_1 + 0x6c));
  if ((*(byte *)(param_1 + 0xf) & 1) == 0) {
    iVar7 = param_2[7];
    iVar6 = param_2[6];
  }
  else {
    iVar7 = ((*(int *)(param_1 + 0x58) >> 8) * 0x1e0) / 0xf0;
    iVar6 = (*(int *)(param_1 + 0x54) >> 8) * 0x280;
    iVar6 = (int)(iVar6 + (iVar6 >> 0x1f & 0x1ffU)) >> 9;
  }
  FUN_004aa030(iVar6,iVar7);
  FUN_004aa050(param_2[8]);
  SetTransformBasisFromRef(&DAT_00a43920);
  return &DAT_00a43920;
}


