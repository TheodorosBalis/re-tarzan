// Address: 0x00438B80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FinalizeLevelTransitionAndInvokeHook(void)

{
  _DAT_00515510 = 1;
  FUN_00432ac0();
  FUN_00444470();
  if (*(code **)(DAT_00534004 + 0xc) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00438ba0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_00534004 + 0xc))();
    return;
  }
  return;
}


