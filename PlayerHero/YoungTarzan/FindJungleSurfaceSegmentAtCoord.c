// 0x00448800
int FindJungleSurfaceSegmentAtCoord(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 0x4c;
  iVar1 = *(int *)(param_1 + 0x58);
  while( true ) {
    if (param_2 < iVar1) {
      return iVar2 + -0x1c;
    }
    if ((*(uint *)(iVar2 + 0x14) & 0x2000) != 0) break;
    iVar1 = *(int *)(iVar2 + 0x28);
    iVar2 = iVar2 + 0x1c;
  }
  return iVar2;
}