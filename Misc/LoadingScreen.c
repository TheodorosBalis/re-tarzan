// Address: 0x004AB1B0

void LoadingScreen(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  char local_100 [256];
  
  uVar3 = 0xffffffff;
  do {
    pcVar5 = param_1;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar5 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar5;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar5 = pcVar5 + -uVar3;
  pcVar7 = local_100;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar5 = local_100;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_100[~uVar3 - 4] = 'e';
  uVar3 = 0xffffffff;
  pcVar5 = local_100;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_100[~uVar3 - 3] = 'g';
  uVar3 = 0xffffffff;
  pcVar5 = local_100;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  local_100[~uVar3 - 2] = 'f';
  iVar2 = OpenMenuEgfAndIndexChunks(local_100);
  iVar6 = 0;
  if (0 < iVar2) {
    iVar8 = 0xe;
    do {
      LoadMenuEgfChunkToTextureAtlas(iVar6,&g_MenuTextureAtlasPixels);
      UpdateTexturesReference(iVar8,0,0,0x100,0x100);
      iVar6 = iVar6 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar6 < iVar2);
  }
  ResetMenuEgfState();
  return;
}


