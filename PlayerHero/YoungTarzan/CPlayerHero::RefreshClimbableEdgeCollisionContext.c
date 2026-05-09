// 0x00434c10
void CPlayerHero_RefreshClimbableEdgeCollisionContext(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  _g_PlayerLinkedCollisionSurface = 0;
  _g_PlayerLinkedCollisionSurfaceIndex = 0xffffffff;
  g_PlayerInteractionCollisionSurface = 0;
  g_PlayerInteractionCollisionSurfaceIndex = 0xffffffff;
  g_PlayerPreviousCollisionMode = *(int *)(g_PlayerSceneEntry + 0x108);
  if (_g_PlayerHeroMode == 2) {
    g_PlayerCollisionStepHeight = 0x70;
    iVar2 = (*(short *)(g_PlayerSceneEntry + 0x142) * 3) / 2;
  }
  else if (_g_PlayerHeroMode == 6) {
    g_PlayerCollisionStepHeight = 0xa0;
    iVar2 = 0;
  }
  else {
    g_PlayerCollisionStepHeight = 0xb0;
    iVar2 = *(short *)(g_PlayerSceneEntry + 0x142) + 0x20;
  }
  if (g_PlayerPreviousCollisionMode == 1) {
    g_PlayerCollisionLateralLimit =
         GetJungleSurfaceLateralLimit(*(undefined4 *)(g_PlayerSceneEntry + 0x10c),
                    *(undefined4 *)(g_PlayerSceneEntry + 0x114));
    if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
      uVar3 = 1;
    }
    else {
      uVar3 = 0xffffffff;
    }
    UpdateSceneEntryCollisionSurfaceRef(uVar3,0,g_PlayerSceneEntry);
    g_PlayerCurrentCollisionSurface = *(int *)(g_PlayerSceneEntry + 0x114);
    if (g_PlayerCurrentCollisionSurface != 0) {
      bVar1 = CPlayerHero_IsFacingCurrentCollisionSurface();
      g_PlayerCollisionFacingFlags = g_PlayerCollisionFacingFlags | bVar1;
      if ((*(uint *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x8000) != 0) {
        _g_PlayerLinkedCollisionSurfaceIndex =
             (uint)*(ushort *)(g_PlayerCurrentCollisionSurface + 0x18);
        _g_PlayerLinkedCollisionSurface =
             *(int *)(g_JungleSurfaceTableBase + 4 + _g_PlayerLinkedCollisionSurfaceIndex * 4) +
             0x34 + ((uint)*(ushort *)(g_PlayerCurrentCollisionSurface + 0x1a) * 7 +
                    _g_PlayerLinkedCollisionSurfaceIndex) * 4 + g_JungleSurfaceTableBase;
        if ((*(uint *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x8000) == 0) {
          g_PlayerInteractionCollisionSurfaceIndex = *(uint *)(g_PlayerSceneEntry + 0x110);
          g_PlayerInteractionCollisionSurface = g_PlayerCurrentCollisionSurface;
        }
        else {
          g_PlayerInteractionCollisionSurfaceIndex =
               (uint)*(ushort *)(_g_PlayerLinkedCollisionSurface + 0x18);
          g_PlayerInteractionCollisionSurface =
               *(int *)(g_JungleSurfaceTableBase + 4 + g_PlayerInteractionCollisionSurfaceIndex * 4)
               + 0x34 + ((uint)*(ushort *)(_g_PlayerLinkedCollisionSurface + 0x1a) * 7 +
                        g_PlayerInteractionCollisionSurfaceIndex) * 4 + g_JungleSurfaceTableBase;
        }
        if ((*(byte *)(g_PlayerInteractionCollisionSurface + 0x14) & 0x80) != 0) {
          g_PlayerInteractionCollisionBaseY = *(int *)(g_PlayerCurrentCollisionSurface + 4);
          g_PlayerInteractionCollisionHeightRange =
               ((((*(int *)(_g_PlayerLinkedCollisionSurface + 4) + g_PlayerCollisionStepHeight * -2)
                 - *(int *)(g_PlayerCurrentCollisionSurface + 4)) - iVar2) /
               g_PlayerCollisionStepHeight) * g_PlayerCollisionStepHeight;
          return;
        }
        if ((*(byte *)(_g_PlayerLinkedCollisionSurface + 0x14) & 0x80) != 0) {
          g_PlayerInteractionCollisionSurface = _g_PlayerLinkedCollisionSurface;
          g_PlayerInteractionCollisionSurfaceIndex = _g_PlayerLinkedCollisionSurfaceIndex;
          g_PlayerInteractionCollisionBaseY = *(int *)(_g_PlayerLinkedCollisionSurface + 4);
          g_PlayerInteractionCollisionHeightRange =
               ((((*(int *)(g_PlayerCurrentCollisionSurface + 4) + g_PlayerCollisionStepHeight * -2)
                 - *(int *)(_g_PlayerLinkedCollisionSurface + 4)) - iVar2) /
               g_PlayerCollisionStepHeight) * g_PlayerCollisionStepHeight;
          return;
        }
        g_PlayerInteractionCollisionSurface = 0;
        g_PlayerInteractionCollisionSurfaceIndex = 0xffffffff;
      }
    }
  }
  return;