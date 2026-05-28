
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CEntities__CanStartPickupCollection(void)

{
  uint uVar1;
  
  uVar1 = _g_PlayerSequenceFlags;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     (uVar1 = g_PlayerInteractionLockFlags, g_PlayerInteractionLockFlags == 0)) {
    return 1;
  }
  return uVar1 & 0xffffff00;
}

