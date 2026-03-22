/* Address: 0x004A4CF0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetAppTime_FillGraphicsBuffer(void)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  DVar1 = timeGetTime();
  _DAT_009cf120 = _DAT_009cf120 - DVar1;
  FUN_004a9380();
  DVar1 = timeGetTime();
  _DAT_009cf120 = _DAT_009cf120 + DVar1;
  DVar1 = timeGetTime();
  _appUpTime = _appUpTime - DVar1;
  iVar2 = ReadFromGlobal722994();
  if (iVar2 != DAT_00517618) {
    DAT_00517618 = ReadFromGlobal722994();
    _DAT_009cef10 = 0x1010101;
    _DAT_009cef14 = 0x1010101;
    _DAT_009cef18 = 0x1010101;
    _DAT_009cef1c = 0x1010101;
    FUN_004a4b20();
  }
  iVar2 = 0;
  iVar3 = 0;
  do {
    if ((&DAT_009cef10)[iVar2] != '\0') {
      FUN_0049cc60(iVar2,iVar3 + DAT_009cf104);
      (&DAT_009cef10)[iVar2] = 0;
    }
    iVar3 = iVar3 + 0x20000;
    iVar2 = iVar2 + 1;
  } while (iVar3 < 0x200000);
  WriteToGraphicsBufferIfGraphicsInitialized_stub(unused0,&DAT_009cf128,&DAT_009cf12c);
  iVar2 = CurrentGraphicsMode();
  if (iVar2 == 1) {
    iVar2 = FUN_004a9430();
    while (iVar2 != 0) {
      if ((*(ushort *)(iVar2 + 0x38) & 0x1800) == 0x1000) {
        *(undefined1 *)(iVar2 + 0x26) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x26)];
        *(undefined1 *)(iVar2 + 0x25) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x25)];
        *(undefined1 *)(iVar2 + 0x24) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x24)];
        *(undefined1 *)(iVar2 + 0x2a) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2a)];
        *(undefined1 *)(iVar2 + 0x29) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x29)];
        *(undefined1 *)(iVar2 + 0x28) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x28)];
        *(undefined1 *)(iVar2 + 0x2e) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2e)];
        *(undefined1 *)(iVar2 + 0x2d) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2d)];
        *(undefined1 *)(iVar2 + 0x2c) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2c)];
      }
      if ((DAT_009cf148 == 0) && ((*(ushort *)(iVar2 + 0x38) & 0x20) == 0)) {
        *(undefined1 *)(iVar2 + 0x26) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x26)];
        *(undefined1 *)(iVar2 + 0x25) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x25)];
        *(undefined1 *)(iVar2 + 0x24) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x24)];
        *(undefined1 *)(iVar2 + 0x2a) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2a)];
        *(undefined1 *)(iVar2 + 0x29) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x29)];
        *(undefined1 *)(iVar2 + 0x28) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x28)];
        *(undefined1 *)(iVar2 + 0x2e) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2e)];
        *(undefined1 *)(iVar2 + 0x2d) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2d)];
        *(undefined1 *)(iVar2 + 0x2c) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2c)];
      }
      FUN_0049d970(iVar2);
      iVar2 = FUN_004a9430();
    }
  }
  else {
    iVar2 = CurrentGraphicsMode();
    if (iVar2 == 2) {
      iVar2 = FUN_004a9430();
      while (iVar2 != 0) {
        if ((*(ushort *)(iVar2 + 0x38) & 0x1800) == 0x1000) {
          *(undefined1 *)(iVar2 + 0x26) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x26)];
          *(undefined1 *)(iVar2 + 0x25) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x25)];
          *(undefined1 *)(iVar2 + 0x24) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x24)];
          *(undefined1 *)(iVar2 + 0x2a) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2a)];
          *(undefined1 *)(iVar2 + 0x29) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x29)];
          *(undefined1 *)(iVar2 + 0x28) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x28)];
          *(undefined1 *)(iVar2 + 0x2e) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2e)];
          *(undefined1 *)(iVar2 + 0x2d) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2d)];
          *(undefined1 *)(iVar2 + 0x2c) = (&DAT_009cf004)[*(byte *)(iVar2 + 0x2c)];
        }
        if ((DAT_009cf148 == 0) && ((*(ushort *)(iVar2 + 0x38) & 0x20) == 0)) {
          *(undefined1 *)(iVar2 + 0x26) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x26)];
          *(undefined1 *)(iVar2 + 0x25) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x25)];
          *(undefined1 *)(iVar2 + 0x24) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x24)];
          *(undefined1 *)(iVar2 + 0x2a) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2a)];
          *(undefined1 *)(iVar2 + 0x29) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x29)];
          *(undefined1 *)(iVar2 + 0x28) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x28)];
          *(undefined1 *)(iVar2 + 0x2e) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2e)];
          *(undefined1 *)(iVar2 + 0x2d) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2d)];
          *(undefined1 *)(iVar2 + 0x2c) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2c)];
        }
        FUN_00497050(iVar2);
        iVar2 = FUN_004a9430();
      }
    }
    else {
      DAT_009cf130 = GetWindowWidth();
      DAT_009cf134 = GetWindowHeight();
      _DAT_009cf138 = (float)DAT_009cf130 * _DAT_004ba2e4;
      _DAT_009cf13c = (float)DAT_009cf134 * _DAT_004ba2e4;
      if (DAT_009cf128 != 0) {
        iVar2 = FUN_004a9430();
        while (iVar2 != 0) {
          if ((DAT_009cf148 == 0) && ((*(byte *)(iVar2 + 0x38) & 0x20) == 0)) {
            *(undefined1 *)(iVar2 + 0x26) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x26)];
            *(undefined1 *)(iVar2 + 0x25) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x25)];
            *(undefined1 *)(iVar2 + 0x24) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x24)];
            *(undefined1 *)(iVar2 + 0x2a) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2a)];
            *(undefined1 *)(iVar2 + 0x29) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x29)];
            *(undefined1 *)(iVar2 + 0x28) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x28)];
            *(undefined1 *)(iVar2 + 0x2e) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2e)];
            *(undefined1 *)(iVar2 + 0x2d) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2d)];
            *(undefined1 *)(iVar2 + 0x2c) = (&arrayofnumbers255)[*(byte *)(iVar2 + 0x2c)];
          }
          FUN_004a5160(iVar2);
          iVar2 = FUN_004a9430();
        }
      }
    }
  }
  DAT_009cf128 = 0;
  DAT_009cf12c = 0;
  ConfirmGraphicsInitialized();
  return;
}

