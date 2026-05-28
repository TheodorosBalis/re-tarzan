
undefined4 CEntities__UpdateBouncingPickupMotionAndLifetime(int param_1)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 != 0) {
    iVar4 = FindRuntimeEntityAttachmentByFlags(param_1,0x40000063);
    if (iVar4 != 0) {
      if ((*(byte *)(iVar4 + 0x1e) & 0x80) != 0) {
        uVar1 = *(ushort *)(iVar4 + 0x12);
        if ((short)uVar1 < 0) {
          *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + uVar1;
          if (*(short *)(iVar4 + 0x10) < 1) {
            *(undefined2 *)(iVar4 + 0x10) = 0;
            *(ushort *)(iVar4 + 0x12) = ~uVar1 + 1;
          }
          *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) - (int)*(short *)(iVar4 + 0x10);
          if ((*(byte *)(iVar4 + 0x1e) & 1) == 0) {
            MoveSceneEntryWithCollision(0,0,iVar2);
          }
          else {
            *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) - *(short *)(iVar4 + 0xe);
            MoveSceneEntryWithCollision((int)*(short *)(iVar4 + 0xc),0,iVar2);
            *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0x54);
            *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0x5c);
          }
          if ((*(byte *)(iVar4 + 0x1e) & 4) != 0) {
            *(short *)(iVar4 + 0x1a) = *(short *)(iVar4 + 0x1a) + *(short *)(iVar4 + 0x14);
            *(short *)(iVar4 + 0x14) = *(short *)(iVar4 + 0x14) - *(short *)(iVar4 + 0x16);
            uVar5 = *(ushort *)(iVar2 + 0x132) - 0x400 & 0xfff;
            *(int *)(iVar2 + 0x3c) =
                 (int)(short)(&g_SinCosTable12Bit)[uVar5 - 0x400 & 0xfff] *
                 (int)*(short *)(iVar4 + 0x1a) >> 0xc;
            *(int *)(iVar2 + 0x44) =
                 (int)(short)(&g_SinCosTable12Bit)[uVar5] * (int)*(short *)(iVar4 + 0x1a) >> 0xc;
          }
        }
        else {
          *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + uVar1;
          *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + (int)*(short *)(iVar4 + 0x10);
          if ((*(byte *)(iVar4 + 0x1e) & 1) == 0) {
            MoveSceneEntryWithCollision(0,0,iVar2);
          }
          else {
            *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) - *(short *)(iVar4 + 0xe);
            MoveSceneEntryWithCollision((int)*(short *)(iVar4 + 0xc),0,iVar2);
            *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 0x54);
            *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) + *(int *)(iVar2 + 0x5c);
          }
          if ((*(byte *)(iVar4 + 0x1e) & 4) != 0) {
            *(short *)(iVar4 + 0x1a) = *(short *)(iVar4 + 0x1a) + *(short *)(iVar4 + 0x14);
            *(short *)(iVar4 + 0x14) = *(short *)(iVar4 + 0x14) - *(short *)(iVar4 + 0x16);
            uVar5 = *(ushort *)(iVar2 + 0x132) - 0x400 & 0xfff;
            *(int *)(iVar2 + 0x3c) =
                 (int)(short)(&g_SinCosTable12Bit)[uVar5 - 0x400 & 0xfff] *
                 (int)*(short *)(iVar4 + 0x1a) >> 0xc;
            *(int *)(iVar2 + 0x44) =
                 (int)(short)(&g_SinCosTable12Bit)[uVar5] * (int)*(short *)(iVar4 + 0x1a) >> 0xc;
          }
          cVar3 = CEntities__CheckSceneEntryVerticalImpact(iVar2);
          if (cVar3 != '\0') {
            *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) >> 1;
            *(ushort *)(iVar4 + 0x12) = ~*(ushort *)(iVar4 + 0x12) + 1;
            if (*(short *)(iVar4 + 0x10) < 8) {
              *(byte *)(iVar4 + 0x1e) = *(byte *)(iVar4 + 0x1e) & 0x7f;
            }
            cVar3 = *(char *)(iVar4 + 0x1f);
            *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) >> 1;
            *(short *)(iVar4 + 0x14) = *(short *)(iVar4 + 0x14) >> 1;
            *(byte *)(iVar4 + 0x1e) = *(byte *)(iVar4 + 0x1e) | 0x40;
            if (cVar3 != '\0') {
              if (cVar3 == '\x02') {
                uVar6 = 0xb2;
              }
              else if (cVar3 == '\x03') {
                uVar6 = 0xb1;
              }
              else {
                uVar6 = 0xb3;
              }
              PlayAudioById(uVar6,0,iVar2 + 0x14);
              *(char *)(iVar4 + 0x1f) = *(char *)(iVar4 + 0x1f) + -1;
            }
          }
        }
      }
      *(short *)(iVar4 + 0x1c) = *(short *)(iVar4 + 0x1c) + -1;
      if (*(short *)(iVar4 + 0x1c) < 0) {
        CEntities__SpawnRuntimeEntryByTypeAtPosition
                  (*(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18),
                   *(undefined4 *)(iVar2 + 0x1c),0x13,0x11);
        return 1;
      }
    }
  }
  return 0;
}

