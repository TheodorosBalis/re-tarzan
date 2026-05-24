
void ResetHudSpriteQuadList(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = g_WorldSceneEntryArrayBase + 0x68;
  piVar2 = &g_HudSpriteQuadListFirstSceneRef;
  do {
    piVar2[-1] = 0;
    *piVar2 = iVar1;
    piVar2[1] = 0x3016;
    piVar2[2] = 0;
    piVar2[3] = 0;
    piVar2[4] = 0;
    piVar2[5] = 0;
    piVar2[8] = 0;
    piVar2[9] = 0;
    piVar2[10] = 0;
    piVar2[0xb] = 0;
    *(undefined2 *)(piVar2 + 6) = 0;
    *(undefined2 *)((int)piVar2 + 0x1a) = 0;
    *(undefined2 *)(piVar2 + 7) = 0;
    *(undefined2 *)((int)piVar2 + 0x1e) = 0;
    piVar2[0xc] = 0;
    piVar2 = piVar2 + 0xe;
  } while ((int)piVar2 < 0x53270c);
  return;
}

