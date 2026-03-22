/* Address: 0x004A1690 */

MMRESULT QueryMixerControlDetails(void)

{
  uint uVar1;
  DWORD DVar2;
  MMRESULT MVar3;
  UINT UVar4;
  int iVar5;
  int *piVar6;
  DWORD *pDVar7;
  undefined4 *puVar8;
  DWORD in_stack_00000018;
  DWORD in_stack_00000024;
  DWORD in_stack_00000030;
  DWORD in_stack_00000034;
  DWORD in_stack_0000003c;
  DWORD *in_stack_000094c4;
  DWORD in_stack_000094c8;
  
  MVar3 = SafeCheckStackPtr();
  if (in_stack_000094c4 != (DWORD *)0x0) {
    pDVar7 = in_stack_000094c4;
    for (iVar5 = 0x10a; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pDVar7 = 0;
      pDVar7 = pDVar7 + 1;
    }
    in_stack_000094c4[2] = 0x32;
    *in_stack_000094c4 = in_stack_000094c8;
    UVar4 = mixerGetNumDevs();
    MVar3 = 0;
    if (UVar4 != 0) {
      in_stack_00000030 = *in_stack_000094c4;
      in_stack_00000018 = 0xa8;
      MVar3 = mixerGetLineInfoA((HMIXEROBJ)0x0,(LPMIXERLINEA)&stack0x00000018,3);
      if (MVar3 == 0) {
        puVar8 = (undefined4 *)register0x00000010;
        for (iVar5 = 6; DVar2 = in_stack_0000003c, iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        MVar3 = mixerGetLineControlsA((HMIXEROBJ)0x0,(LPMIXERLINECONTROLSA)&stack0x00000000,0);
        if (MVar3 == 0) {
          iVar5 = 0;
          if (0 < (int)DVar2) {
            piVar6 = (int *)&stack0x000000c8;
            do {
              if (*piVar6 == 0x50030001) break;
              iVar5 = iVar5 + 1;
              piVar6 = piVar6 + 0x25;
            } while (iVar5 < (int)DVar2);
          }
          ((LPMIXERCONTROLDETAILS)(in_stack_000094c4 + 4))->cbStruct = 0x18;
          in_stack_000094c4[5] = *(DWORD *)(&stack0x000000c4 + iVar5 * 0x94);
          in_stack_000094c4[6] = in_stack_00000034;
          in_stack_000094c4[7] = 0;
          in_stack_000094c4[8] = 4;
          in_stack_000094c4[9] = (DWORD)(in_stack_000094c4 + 10);
          MVar3 = mixerGetControlDetailsA
                            ((HMIXEROBJ)0x0,(LPMIXERCONTROLDETAILS)(in_stack_000094c4 + 4),0);
          if (MVar3 == 0) {
            uVar1 = in_stack_000094c4[10];
            MVar3 = uVar1 * -0x6fc7b815;
            in_stack_000094c4[1] = 1;
            in_stack_000094c4[2] = uVar1 / 0x28f;
          }
        }
      }
    }
  }
  return MVar3;
}

