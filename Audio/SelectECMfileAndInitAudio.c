// Address: 0x004AC480

void SelectECMfileAndInitAudio(int param_1)

{
  switch(DAT_00c46068) {
  case 1:
    DAT_00c4606c = 3;
    InitAudioForECMFile(3);
    return;
  case 2:
    DAT_00c4606c = 4;
    InitAudioForECMFile(4);
    return;
  case 3:
    DAT_00c4606c = 5;
    InitAudioForECMFile(5);
    return;
  case 4:
    DAT_00c4606c = 9;
    InitAudioForECMFile(9);
    return;
  case 5:
    DAT_00c4606c = 6;
    InitAudioForECMFile(6);
    return;
  case 6:
    DAT_00c4606c = 8 - (uint)(param_1 != 0);
    InitAudioForECMFile(DAT_00c4606c);
    return;
  case 7:
    DAT_00c4606c = (param_1 != 0) + 9;
    InitAudioForECMFile(DAT_00c4606c);
    return;
  case 8:
    DAT_00c4606c = 0xb;
    InitAudioForECMFile(0xb);
    return;
  case 9:
    DAT_00c4606c = 0xc;
    InitAudioForECMFile(0xc);
    return;
  case 10:
    DAT_00c4606c = 0xd;
    InitAudioForECMFile(0xd);
    return;
  case 0xb:
    DAT_00c4606c = 0xf;
    InitAudioForECMFile(0xf);
    return;
  case 0xc:
    DAT_00c4606c = 0x10;
    InitAudioForECMFile(0x10);
    return;
  case 0xd:
    DAT_00c4606c = 0x11;
    InitAudioForECMFile(0x11);
    return;
  case 0xe:
    DAT_00c4606c = 0x12;
    InitAudioForECMFile(0x12);
    return;
  case 0xf:
  case 0x15:
    DAT_00c4606c = 0x13;
    InitAudioForECMFile(0x13);
    return;
  case 0x10:
    DAT_00c4606c = 0x14;
    InitAudioForECMFile(0x14);
    return;
  default:
    DAT_00c4606c = (-(uint)(param_1 != 0) & 0xffffffed) + 0x15;
    InitAudioForECMFile(DAT_00c4606c);
    return;
  case 0x12:
  case 0x13:
  case 0x14:
    DAT_00c4606c = 0xe;
    InitAudioForECMFile(0xe);
    return;
  }
}


