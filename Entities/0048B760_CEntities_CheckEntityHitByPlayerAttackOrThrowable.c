
uint CEntities__CheckEntityHitByPlayerAttackOrThrowable(int param_1)

{
  short sVar1;
  int iVar2;
  short *in_EAX;
  int iVar3;
  undefined3 uVar5;
  undefined3 extraout_var;
  int iVar4;
  int iVar6;
  int iVar7;
  int local_40;
  int local_3c;
  int local_38;
  short local_34;
  short local_32;
  short local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined1 local_20 [32];
  
  iVar4 = *(int *)(param_1 + 0x38);
  if (iVar4 != 0) {
    local_38 = iVar4;
    iVar3 = GetSceneEntryAttachmentList(iVar4,&local_40);
    in_EAX = (short *)0x0;
    if (iVar3 != 0) {
      local_34 = -*(short *)(iVar4 + 0xa0);
      local_32 = -*(short *)(iVar4 + 0xa2);
      local_30 = -*(short *)(iVar4 + 0xa4);
      local_3c = iVar3;
      BuildRotationBasisFromEulerAngles(&local_34,local_20);
      in_EAX = (short *)0x0;
      if (g_PlayerAttackHitPositionPtr != (int *)0x0) {
        local_2c = *g_PlayerAttackHitPositionPtr - *(int *)(iVar4 + 0x14);
        local_28 = g_PlayerAttackHitPositionPtr[1] - *(int *)(iVar4 + 0x18);
        local_24 = g_PlayerAttackHitPositionPtr[2] - *(int *)(iVar4 + 0x1c);
        in_EAX = (short *)TransformVectorByBasis(local_20,&local_2c,&local_2c);
        iVar6 = 0;
        if (0 < iVar3) {
          in_EAX = (short *)(local_40 + 6);
          do {
            if (((((*(uint *)(in_EAX + 3) & 0x200) != 0) && (in_EAX[-3] + -0x40 <= local_2c)) &&
                (local_2c <= *in_EAX + 0x40)) &&
               (((in_EAX[1] + -0x40 <= local_28 && (local_28 <= in_EAX[-2] + 0x40)) &&
                ((in_EAX[-1] + -0x40 <= local_24 && (local_24 <= in_EAX[2] + 0x40)))))) {
              iVar4 = CONCAT22((short)((uint)in_EAX >> 0x10),*(short *)(param_1 + 0x3e));
              if (-1 < *(short *)(param_1 + 0x3e)) {
                iVar4 = iVar4 + -0xa0;
                *(short *)(param_1 + 0x3e) = (short)iVar4;
              }
              uVar5 = (undefined3)((uint)iVar4 >> 8);
              if (g_PlayerAttackHitSfxPlayed == '\0') {
                PlayAudioById(0xba,0,0);
                uVar5 = extraout_var;
              }
              g_PlayerAttackHitSfxPlayed = 1;
              *(byte *)(param_1 + 0x43) = *(byte *)(param_1 + 0x43) | 0x10;
              return CONCAT31(uVar5,1);
            }
            in_EAX = in_EAX + 8;
            iVar6 = iVar6 + 1;
            iVar3 = local_3c;
            iVar4 = local_38;
          } while (iVar6 < local_3c);
        }
      }
      iVar6 = g_ActiveThrowableRuntimeEntryList;
      if (g_ActiveThrowableRuntimeEntryList != 0) {
        do {
          if (*(short *)(iVar6 + 0x48) != 5) {
            for (iVar2 = *(int *)(iVar6 + 0x38); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
              local_2c = *(int *)(iVar2 + 0x14) - *(int *)(iVar4 + 0x14);
              local_28 = (*(int *)(iVar2 + 0x40) + *(int *)(iVar2 + 0x18)) - *(int *)(iVar4 + 0x18);
              local_24 = *(int *)(iVar2 + 0x1c) - *(int *)(iVar4 + 0x1c);
              in_EAX = (short *)TransformVectorByBasis(local_20,&local_2c,&local_2c);
              iVar7 = 0;
              if (0 < iVar3) {
                in_EAX = (short *)(local_40 + 6);
                do {
                  if (((((*(uint *)(in_EAX + 3) & 0x200) != 0) && (in_EAX[-3] + -0x40 <= local_2c))
                      && ((local_2c <= *in_EAX + 0x40 &&
                          (((in_EAX[1] + -0x40 <= local_28 && (local_28 <= in_EAX[-2] + 0x40)) &&
                           (in_EAX[-1] + -0x40 <= local_24)))))) && (local_24 <= in_EAX[2] + 0x40))
                  {
                    *(undefined2 *)(iVar6 + 0x48) = 6;
                    sVar1 = *(short *)(param_1 + 0x3e);
                    iVar4 = CONCAT22((short)((uint)iVar6 >> 0x10),sVar1);
                    if ((*(byte *)(iVar6 + 0x4a) & 2) == 0) {
                      if (-1 < sVar1) {
                        iVar4 = iVar4 + -0x80;
                        *(short *)(param_1 + 0x3e) = (short)iVar4;
                      }
                    }
                    else if (-1 < sVar1) {
                      *(short *)(param_1 + 0x3e) = (short)(iVar4 + -0x200);
                      return CONCAT31((int3)((uint)(iVar4 + -0x200) >> 8),1);
                    }
                    return CONCAT31((int3)((uint)iVar4 >> 8),1);
                  }
                  in_EAX = in_EAX + 8;
                  iVar7 = iVar7 + 1;
                  iVar3 = local_3c;
                  iVar4 = local_38;
                } while (iVar7 < local_3c);
              }
            }
          }
          iVar6 = *(int *)(iVar6 + 0x20);
          if (iVar6 == 0) {
            return (uint)in_EAX & 0xffffff00;
          }
        } while( true );
      }
    }
  }
  return (uint)in_EAX & 0xffffff00;
}

