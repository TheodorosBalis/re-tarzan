// Address: 0x0049AA80
// unused by the game
void ProcessPendingChunkStream(void)

{
  int iVar1;
  
  iVar1 = GetPendingEgfBytesRemaining();
  if (iVar1 != 0) {
    if ((((g_PendingEgfDestinationBuffer != 0) && (g_PendingEgfBytesRemaining != 0)) &&
        (g_PendingEgfChunkBytesPerTick != 0)) && (g_PendingEgfObjectOrFileHandle != 0)) {
      iVar1 = g_PendingEgfChunkBytesPerTick;
      if (g_PendingEgfBytesRemaining < g_PendingEgfChunkBytesPerTick) {
        iVar1 = g_PendingEgfBytesRemaining;
      }
      iVar1 = ReadVirtualGameFileIntoBuffer
                        (g_PendingEgfDestinationBuffer,1,iVar1,g_PendingEgfObjectOrFileHandle);
      g_PendingEgfDestinationBuffer = g_PendingEgfDestinationBuffer + iVar1;
      g_PendingEgfBytesRemaining = g_PendingEgfBytesRemaining - iVar1;
      if (((0 < iVar1) && (g_PendingEgfChunkBytesPerTick <= iVar1)) &&
         (0 < g_PendingEgfBytesRemaining)) {
        return;
      }
    }
    ResetPendingChunkStream();
  }
  return;