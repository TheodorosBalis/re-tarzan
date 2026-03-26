// Address: 0x004A9430

undefined4 PopNextSortedRenderPacket(void)

{
  if (g_RenderPacketCount < 1) {
    return 0;
  }
  g_RenderPacketCount = g_RenderPacketCount + -1;
  return *(undefined4 *)(&DAT_00a05a84 + g_RenderPacketCount * 4);
}


