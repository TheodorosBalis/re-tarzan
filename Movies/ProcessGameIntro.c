// Address: 0x004ABD90

void ProcessGameIntro(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &g_LevelTransitionContext;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = &DAT_00a438b8;
  for (iVar1 = 0x47; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  CIntro__Process();
  return;
}


