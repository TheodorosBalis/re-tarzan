// Address: 0x00445290

void RenderMenuSceneHierarchy(int param_1)

{
  ushort uVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  ushort local_8;
  ushort local_6;
  ushort local_4;
  
  iVar2 = *(int *)(param_1 + 0x100);
  puVar9 = (ushort *)(param_1 + 0xc);
  if (((*(int *)(param_1 + 0x10) == 0) || ((*(byte *)(param_1 + 0xf) & 0x80) == 0)) ||
     (*(int *)(*(int *)(param_1 + 0x10) + 0xc) == 0)) {
    iVar7 = *(int *)(param_1 + 0x38);
joined_r0x004453b7:
    if (iVar7 != 0) {
      PrepareMenuSceneNodeTransform(param_1,iVar2);
    }
  }
  else {
    PrepareMenuSceneNodeTransform(param_1,iVar2);
    DAT_00a438c4 = *(undefined4 *)(param_1 + 0x10);
    ApplyMenuSceneNodeFadeAndBlend(puVar9,*(undefined4 *)(iVar2 + 0xb0),iVar2 + 0xb4);
    uVar1 = *puVar9;
    uVar6 = uVar1 & 0x7000;
    if (uVar6 < 0x3001) {
      if (uVar6 == 0x3000) {
        iVar7 = (*(int *)(param_1 + 0x14) >> 8) * 0x280;
        iVar8 = (*(int *)(param_1 + 0x18) >> 8) * 0x1e0;
        FUN_004a9a60(*(int *)(*(int *)(param_1 + 0x10) + 0x14) + (uVar1 & 0xfff) * 0x26,
                     CONCAT22(((short)(iVar8 / 0xf0) + (short)(iVar8 >> 0x1f)) -
                              (short)((longlong)iVar8 * 0x88888889 >> 0x3f),
                              (short)((int)(iVar7 + (iVar7 >> 0x1f & 0x1ffU)) >> 9)),0,&DAT_00808080
                    );
        goto LAB_004453c3;
      }
      if ((uVar1 & 0x7000) == 0) {
        RenderMenuSceneModelNode(param_1);
        iVar7 = *(int *)(param_1 + 0x38);
        goto joined_r0x004453b7;
      }
      if (uVar6 != 0x2000) goto LAB_004453c3;
    }
    else if (uVar6 != 0x5000) goto LAB_004453c3;
    RenderMenuSceneAssetNode(puVar9);
  }
LAB_004453c3:
  iVar7 = *(int *)(param_1 + 0x38);
  if (iVar7 != 0) {
    sVar4 = (short)DAT_00a43938;
    sVar5 = (short)DAT_00a4393c;
    sVar3 = (short)DAT_00a43934;
    SetTransformBasisFromRef(&DAT_00a43920);
    puVar9 = (ushort *)(iVar7 + 0x10);
    for (uVar6 = (uint)*(ushort *)(iVar7 + 0xc); uVar6 != 0; uVar6 = uVar6 - 1) {
      if ((puVar9[1] & 0x8000) != 0) {
        if ((*puVar9 & 0x7000) == 0x1000) {
          local_8 = puVar9[4];
          local_6 = puVar9[6];
          local_4 = puVar9[8];
          FUN_004a9920(&local_8,(uint)CONCAT11((char)(*(int *)(puVar9 + 0xe) >> 5),
                                               (char)(*(int *)(puVar9 + 0xc) >> 5)) << 8 |
                                *(int *)(puVar9 + 10) >> 5 & 0xffU);
        }
        else if ((*(int *)(puVar9 + 2) != 0) && (*(int *)(*(int *)(puVar9 + 2) + 0xc) != 0)) {
          if ((puVar9[1] & 0x1000) == 0) {
            TransformVectorByBasis(&DAT_00a43920,puVar9 + 4,&DAT_00a43934);
            DAT_00a43934 = DAT_00a43934 + sVar3;
            DAT_00a43938 = DAT_00a43938 + sVar4;
            DAT_00a4393c = DAT_00a4393c + sVar5;
          }
          else {
            DAT_00a43934 = (*(int *)(iVar2 + 0x58) * *(int *)(puVar9 + 4) >> 0xc) + (int)sVar3;
            DAT_00a43938 = (*(int *)(iVar2 + 0x5c) * *(int *)(puVar9 + 6) >> 0xc) + (int)sVar4;
            DAT_00a4393c = (*(int *)(iVar2 + 0x60) * *(int *)(puVar9 + 8) >> 0xc) + (int)sVar5;
          }
          SetTransformBasisFromRef(&DAT_00a43920);
          DAT_00a438c4 = *(undefined4 *)(puVar9 + 2);
          ApplyMenuSceneNodeFadeAndBlend(puVar9,*(undefined4 *)(iVar2 + 0xb0),iVar2 + 0xb4);
          if ((*puVar9 & 0x7000) == 0x2000) {
            RenderMenuSceneAssetNode(puVar9);
          }
        }
      }
      puVar9 = puVar9 + 0x14;
    }
  }
  return;
}


