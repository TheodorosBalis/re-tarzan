
void CEntities__ClearDustFromPowerFruit(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  short *psVar6;
  int *piVar7;
  char *pcVar8;
  int iStack_c;
  
  if (*(int *)(param_1 + 0x38) != 0) {
    for (iVar3 = *(int *)(*(int *)(param_1 + 0x38) + 0x34); iVar3 != 0;
        iVar3 = *(int *)(iVar3 + 0x34)) {
      if (*(char *)(iVar3 + 0x74) == '\0') {
        if (((*(byte *)(iVar3 + 0xf) & 0x80) != 0) &&
           (*(short *)(iVar3 + 0xc) = *(short *)(iVar3 + 0xc) + 1, 0x205b < *(ushort *)(iVar3 + 0xc)
           )) {
          *(undefined2 *)(iVar3 + 0xe) = 0;
        }
      }
      else {
        cVar4 = *(char *)(iVar3 + 0x74) + -1;
        *(char *)(iVar3 + 0x74) = cVar4;
        if (cVar4 == '\0') {
          *(byte *)(iVar3 + 0xf) = *(byte *)(iVar3 + 0xf) | 0x80;
        }
      }
    }
    iVar3 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000000);
    if (iVar3 != 0) {
      iStack_c = 0;
      iVar1 = *(int *)(*(int *)(param_1 + 0x38) + 0x38);
      if (iVar1 != 0) {
        if (*(short *)(iVar1 + 0xc) != 0) {
          pcVar8 = (char *)(iVar3 + 0xfc);
          psVar6 = (short *)(iVar3 + 0x110);
          piVar5 = (int *)(iVar3 + 0x10);
          piVar7 = (int *)(iVar1 + 0x1c);
          do {
            sVar2 = *psVar6;
            *psVar6 = sVar2 + -1;
            cVar4 = *pcVar8;
            if (cVar4 == '\0') {
              if ((short)(sVar2 + -1) < 0) {
                *pcVar8 = '\x01';
                sVar2 = RandomModulo(0x14);
                *psVar6 = sVar2 + 0x14;
                *(byte *)((int)piVar7 + -9) = *(byte *)((int)piVar7 + -9) | 0x80;
              }
            }
            else if (cVar4 == '\x01') {
              piVar7[-1] = piVar7[-1] + piVar5[-1];
              *piVar7 = *piVar7 + *piVar5;
              piVar7[1] = piVar7[1] + piVar5[1];
              *piVar5 = *piVar5 + 6;
              if (*psVar6 < 0) {
                *pcVar8 = '\x02';
                *(ushort *)((int)piVar7 + -10) = *(ushort *)((int)piVar7 + -10) & 0x7fff;
              }
            }
            else if (cVar4 == '\x02') {
              iStack_c = iStack_c + 1;
            }
            psVar6 = psVar6 + 1;
            piVar5 = piVar5 + 3;
            pcVar8 = pcVar8 + 1;
            piVar7 = piVar7 + 10;
          } while ((int)(pcVar8 + (-0xfc - iVar3)) < (int)(uint)*(ushort *)(iVar1 + 0xc));
        }
        if ((int)(*(ushort *)(iVar1 + 0xc) - 1) <= iStack_c) {
          CEntities__ReleaseRuntimeEntryToFreeList(param_1);
        }
      }
    }
  }
  cVar4 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar4 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

