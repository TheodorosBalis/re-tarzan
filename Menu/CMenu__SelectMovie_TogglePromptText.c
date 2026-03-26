// Address: 0x004460E0

void CMenu__SelectMovie_TogglePromptText(int param_1)

{
  *(uint *)(param_1 + 0x18) = (*(int *)(param_1 + 0x18) != 0x80b3) + 0x80b2;
  TimeIDLEinMenu = 0;
  return;
}


