//00436b60
bool CPlayerHero_IsFacingCurrentCollisionSurface(void)

{
  short sVar1;
  int iVar2;
  
  if (g_PlayerDamageContactSceneEntry != 0) {
    sVar1 = ComputeFixedAtan2Angle(*(int *)(g_PlayerSceneEntryData + 8) -
                       *(int *)(g_PlayerDamageContactSceneEntry + 0x14),
                       *(int *)(g_PlayerSceneEntryData + 0x10) -
                       *(int *)(g_PlayerDamageContactSceneEntry + 0x1c));
    ComputeFixedAtan2Angle(*(int *)(g_PlayerSceneEntryData + 8) - *g_PlayerCurrentCollisionSurface,
               *(int *)(g_PlayerSceneEntryData + 0x10) - g_PlayerCurrentCollisionSurface[2]);
    iVar2 = GetWrappedAngleDistance12Bit((int)sVar1,_g_PlayerMoveHeadingAngle & 0xffff);
    return iVar2 < 0x400;
  }
  return (bool)DAT_0051cd1c;
}

// 0x00489f90
int ComputeFixedAtan2Angle(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    if (param_2 == 0) {
      return 0;
    }
  }
  else if (param_1 == -0x80000000) {
    param_1 = -0x7fffffff;
  }
  if (param_2 == -0x80000000) {
    param_2 = -0x7fffffff;
  }
  if (param_1 < 0) {
    iVar1 = -param_1;
    if (-1 < param_2) {
      if (param_2 <= iVar1) {
        return *(short *)(&DAT_005113f8 + ((param_2 << 9) / iVar1) * 2) + 0xc00;
      }
      return 0x1000 - *(short *)(&DAT_005113f8 + ((param_1 * -0x200) / param_2) * 2);
    }
    if (iVar1 < -param_2) {
      return *(short *)(&DAT_005113f8 + ((param_1 * -0x200) / -param_2) * 2) + 0x800;
    }
    return 0xc00 - *(short *)(&DAT_005113f8 + ((param_2 * -0x200) / iVar1) * 2);
  }
  if (param_2 < 0) {
    if (-param_2 <= param_1) {
      return *(short *)(&DAT_005113f8 + ((param_2 * -0x200) / param_1) * 2) + 0x400;
    }
    return 0x800 - *(short *)(&DAT_005113f8 + ((param_1 << 9) / -param_2) * 2);
  }
  if (param_1 < param_2) {
    return (int)*(short *)(&DAT_005113f8 + ((param_1 << 9) / param_2) * 2);
  }
  return 0x400 - *(short *)(&DAT_005113f8 + ((param_2 << 9) / param_1) * 2);
}

// 00489f70
uint GetWrappedAngleDistance12Bit(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 - param_1 & 0xfff;
  if (0x800 < uVar1) {
    uVar1 = 0x1000 - uVar1;
  }
  return uVar1;
}