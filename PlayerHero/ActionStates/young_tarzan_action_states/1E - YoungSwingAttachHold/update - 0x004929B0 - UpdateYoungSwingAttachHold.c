/*
State 0x1E Update: CPlayerHero::UpdateYoungSwingAttachHold
Address: 0x004929B0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\004929B0_CPlayerHero__UpdateYoungSwingAttachHold.c
*/


void CPlayerHero__UpdateYoungSwingAttachHold(void)

{
  if (g_CurrentSwingRuntimeEntry != 0) {
    UpdatePlayerOnSwing(g_CurrentSwingRuntimeEntry);
  }
  return;
}


