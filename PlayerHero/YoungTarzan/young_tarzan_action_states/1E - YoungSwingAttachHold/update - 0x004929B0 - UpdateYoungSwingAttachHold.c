/*
State 0x1E Update: CPlayerHero::UpdateYoungSwingAttachHold
Address: 0x004929B0
*/


void CPlayerHero__UpdateYoungSwingAttachHold(void)

{
  if (g_CurrentSwingRuntimeEntry != 0) {
    UpdatePlayerOnSwing(g_CurrentSwingRuntimeEntry);
  }
  return;
}

