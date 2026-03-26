// Address: 0x004AE9F0

void IsGameRunningOnCD(void)

{
  char cVar1;
  UINT UVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  CHAR local_8;
  char local_7 [7];
  
  GetModuleFileNameA((HMODULE)0x0,&local_8,2);
  uVar4 = 0xffffffff;
  pcVar6 = &DAT_005175ec;
  do {
    pcVar7 = pcVar6;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar7 + -uVar4;
  pcVar7 = local_7;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  UVar2 = GetDriveTypeA(&local_8);
  if (UVar2 != 3) {
    InternalError(s_The_game_can_only_be_run_from_a_l_00518e6c);
  }
  iVar3 = LoadECMFilesAndInit();
  if (iVar3 != 0) {
    iVar3 = LoadECMinChunks_stub();
    if (iVar3 == 0) {
      bGameInitSuccess = 1;
    }
  }
  return;
}


