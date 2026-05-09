// 0x00433d70
void CPlayerHero_UpdateSceneEntryFacingAngles(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = _g_PlayerCurrentCollisionMode & 0xffff;
  if (uVar1 == 1) {
    if ((int)*(short *)(g_PlayerSceneEntry + 0xa2) != (_g_PlayerMoveHeadingAngle & 0xffff)) {
      _DAT_0051cddc = 0;
      iVar2 = GetWrappedSignedAngleDelta12Bit
                        ((int)*(short *)(g_PlayerSceneEntry + 0xa2),
                         _g_PlayerMoveHeadingAngle & 0xfff);
      if ((iVar2 >> 2 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f) < 2) {
        *(undefined2 *)(g_PlayerSceneEntry + 0xa2) = g_PlayerMoveHeadingAngle;
      }
      else if (((byte)g_PlayerInputHeldMask & 0xf0) != 0) {
        *(short *)(g_PlayerSceneEntry + 0xa2) =
             *(short *)(g_PlayerSceneEntry + 0xa2) + (short)(iVar2 >> 2);
        _DAT_0051cddc = 1;
      }
      *(ushort *)(g_PlayerSceneEntry + 0xa2) = *(ushort *)(g_PlayerSceneEntry + 0xa2) & 0xfff;
    }
    if (g_PlayerTiltControlEnabled == '\0') {
      _g_PlayerMoveHeadingAngle = _g_PlayerMoveHeadingAngle & 0xffff;
    }
    if ((int)*(short *)(g_PlayerSceneEntry + 0xa0) == _g_PlayerMoveHeadingAngle >> 0x10) {
      return;
    }
    iVar2 = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerSceneEntry + 0xa0),_g_PlayerMoveHeadingAngle >> 0x10)
    ;
    uVar1 = iVar2 >> 2;
    if ((int)((uVar1 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f)) < 2) {
      *(undefined2 *)(g_PlayerSceneEntry + 0xa0) = _g_PlayerMoveTiltAngle;
      *(ushort *)(g_PlayerSceneEntry + 0xa0) = *(ushort *)(g_PlayerSceneEntry + 0xa0) & 0xfff;
      return;
    }
  }
  else {
    if (uVar1 == 3) {
      if ((int)*(short *)(g_PlayerSceneEntry + 0xa0) == (_g_PlayerAirMovePitchAngle & 0xffff)) {
        return;
      }
      iVar2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerSceneEntry + 0xa0),
                         _g_PlayerAirMovePitchAngle & 0xffff);
      if (1 < (iVar2 >> 2 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f)) {
        *(short *)(g_PlayerSceneEntry + 0xa0) =
             *(short *)(g_PlayerSceneEntry + 0xa0) + (short)(iVar2 >> 2);
        *(ushort *)(g_PlayerSceneEntry + 0xa0) = *(ushort *)(g_PlayerSceneEntry + 0xa0) & 0xfff;
        return;
      }
      *(undefined2 *)(g_PlayerSceneEntry + 0xa0) = g_PlayerAirMovePitchAngle;
      *(ushort *)(g_PlayerSceneEntry + 0xa0) = *(ushort *)(g_PlayerSceneEntry + 0xa0) & 0xfff;
      return;
    }
    uVar3 = (uint)*(short *)(g_PlayerSceneEntry + 0xa2);
    if (uVar1 == 4) {
      if (uVar3 != g_PlayerAirMoveHeadingAngle) {
        iVar2 = GetWrappedSignedAngleDelta12Bit(uVar3,(uint)g_PlayerAirMoveHeadingAngle);
        if ((iVar2 >> 2 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f) < 2) {
          *(ushort *)(g_PlayerSceneEntry + 0xa2) = g_PlayerAirMoveHeadingAngle;
        }
        else {
          *(short *)(g_PlayerSceneEntry + 0xa2) =
               *(short *)(g_PlayerSceneEntry + 0xa2) + (short)(iVar2 >> 2);
        }
        *(ushort *)(g_PlayerSceneEntry + 0xa2) = *(ushort *)(g_PlayerSceneEntry + 0xa2) & 0xfff;
      }
      if (g_PlayerTiltControlEnabled == '\0') {
        _g_PlayerAirMovePitchAngle = _g_PlayerAirMovePitchAngle & 0xffff0000;
      }
      if ((int)*(short *)(g_PlayerSceneEntry + 0xa0) == (_g_PlayerAirMovePitchAngle & 0xffff)) {
        return;
      }
      iVar2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerSceneEntry + 0xa0),
                         _g_PlayerAirMovePitchAngle & 0xffff);
      uVar1 = iVar2 >> 2;
      if ((int)((uVar1 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f)) < 2) {
        *(undefined2 *)(g_PlayerSceneEntry + 0xa0) = g_PlayerAirMovePitchAngle;
        *(ushort *)(g_PlayerSceneEntry + 0xa0) = *(ushort *)(g_PlayerSceneEntry + 0xa0) & 0xfff;
        return;
      }
    }
    else {
      if (uVar3 != (_g_PlayerMoveHeadingAngle & 0xffff)) {
        iVar2 = GetWrappedSignedAngleDelta12Bit(uVar3,_g_PlayerMoveHeadingAngle & 0xfff);
        if ((iVar2 >> 2 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f) < 2) {
          *(undefined2 *)(g_PlayerSceneEntry + 0xa2) = g_PlayerMoveHeadingAngle;
        }
        else {
          *(short *)(g_PlayerSceneEntry + 0xa2) =
               *(short *)(g_PlayerSceneEntry + 0xa2) + (short)(iVar2 >> 2);
        }
        *(ushort *)(g_PlayerSceneEntry + 0xa2) = *(ushort *)(g_PlayerSceneEntry + 0xa2) & 0xfff;
      }
      if (g_PlayerTiltControlEnabled == '\0') {
        _g_PlayerMoveHeadingAngle = _g_PlayerMoveHeadingAngle & 0xffff;
      }
      if ((int)*(short *)(g_PlayerSceneEntry + 0xa0) == _g_PlayerMoveHeadingAngle >> 0x10) {
        return;
      }
      iVar2 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerSceneEntry + 0xa0),
                         _g_PlayerMoveHeadingAngle >> 0x10);
      uVar1 = iVar2 >> 2;
      if ((int)((uVar1 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f)) < 2) {
        *(undefined2 *)(g_PlayerSceneEntry + 0xa0) = _g_PlayerMoveTiltAngle;
        *(ushort *)(g_PlayerSceneEntry + 0xa0) = *(ushort *)(g_PlayerSceneEntry + 0xa0) & 0xfff;
        return;
      }
    }
  }
  *(short *)(g_PlayerSceneEntry + 0xa0) = *(short *)(g_PlayerSceneEntry + 0xa0) + (short)uVar1;
  *(ushort *)(g_PlayerSceneEntry + 0xa0) = *(ushort *)(g_PlayerSceneEntry + 0xa0) & 0xfff;
  return;
}

//0x00489f50
uint GetWrappedSignedAngleDelta12Bit(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 - param_1 & 0xfff;
  if (0x800 < uVar1) {
    uVar1 = uVar1 - 0x1000;
  }
  return uVar1;
}