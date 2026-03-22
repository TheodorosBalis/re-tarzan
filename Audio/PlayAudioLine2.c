/* Address: 0x004A8EA0 */

void PlayAudioLine2(void)

{
  DWORD DVar1;
  int iVar2;
  
  if ((AudioLinesPTR != (int *)0x0) && (DAT_009e4a7c != 0)) {
    (**(code **)(*AudioLinesPTR + 0x30))(AudioLinesPTR,0,0,1);
    DVar1 = timeGetTime();
    iVar2 = DVar1 - DAT_009e4a7c;
    DAT_009e4a7c = 0;
    DAT_009e4a70 = DAT_009e4a70 + iVar2;
  }
  return;
}

