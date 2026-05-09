/*
State 0x0E Enter: CPlayerHero::EnterYoungTouchSurfaceOnSurfing
Address: 0x00491510
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00491510_CPlayerHero__EnterYoungTouchSurfaceOnSurfing.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterYoungTouchSurfaceOnSurfing(void)

{
  undefined4 uVar1;
  
  if (DAT_0051ce84 == 1) {
    switch(DAT_0051cdf0) {
    case 0x2e:
      goto switchD_00491533_caseD_2e;
    default:
      goto switchD_00491533_caseD_2f;
    case 0x31:
      goto switchD_00491533_caseD_31;
    case 0x34:
      goto switchD_00491533_caseD_34;
    case 0x37:
      goto switchD_00491533_caseD_37;
    case 0x3a:
switchD_00491533_caseD_3a:
      uVar1 = 0x3b;
      goto LAB_00491592;
    }
  }
  if (DAT_0051ce84 != 2) {
    switch(DAT_0051cdf0) {
    case 0x2e:
switchD_00491533_caseD_2e:
      uVar1 = 0x2f;
      break;
    default:
switchD_00491533_caseD_2f:
      uVar1 = 0x23;
      break;
    case 0x31:
switchD_00491533_caseD_31:
      uVar1 = 0x32;
      break;
    case 0x34:
switchD_00491533_caseD_34:
      uVar1 = 0x35;
      break;
    case 0x37:
switchD_00491533_caseD_37:
      uVar1 = 0x38;
      break;
    case 0x3a:
      goto switchD_00491533_caseD_3a;
    }
LAB_00491592:
    CPlayerHero__PlayAnimation(uVar1);
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = DAT_0051ce00;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x80;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
    if (DAT_0051ce90 == 0) {
      PlayAudioById(0x29,&DAT_0051ce90,g_PlayerSceneEntry + 0x14);
    }
    _DAT_0053a2c0 = 0xffffffff;
    return;
  }
  switch(DAT_0051cdf0) {
  case 0x2e:
    goto switchD_00491533_caseD_2e;
  default:
    goto switchD_00491533_caseD_2f;
  case 0x31:
    goto switchD_00491533_caseD_31;
  case 0x34:
    goto switchD_00491533_caseD_34;
  case 0x37:
    goto switchD_00491533_caseD_37;
  case 0x3a:
    uVar1 = 0x34;
    goto LAB_00491592;
  }
}


