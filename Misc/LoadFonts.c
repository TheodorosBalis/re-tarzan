// Address: 0x00453FA0

void LoadFonts(int param_1)

{
  g_ActiveTransitionPayload = 0;
  InitModelLoadHeap(&g_ModelLoadHeapState,&DAT_00a43a24,0x200000);
  ResetModelLoadQueue();
  ResetMenuTextureAtlasAndFontState(*(undefined4 *)(param_1 + 4));
  ResetMenuInputState();
  ResetEntitySoundSlotLists();
  LoadLanguageFontAssetSet();
  return;
}


