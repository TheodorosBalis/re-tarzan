// Address: 0x004AC3C0

char * GetAndLoadBlankECMfile(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = s_blank_ecm_005179ec;
  if (-1 < param_1) {
    pcVar2 = (&PTR_s_disney_ecm_0051779c)[param_1];
  }
  iVar1 = GetFileAttributes(pcVar2,0);
  if (iVar1 == 0) {
    return pcVar2;
  }
  pcVar2 = (char *)LoadECMfile(pcVar2);
  return pcVar2;
}


