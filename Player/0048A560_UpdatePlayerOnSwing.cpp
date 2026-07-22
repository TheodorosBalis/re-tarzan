#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A560
// Label: UpdatePlayerOnSwing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 UpdatePlayerOnSwing(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  int value2;
  int value3;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  
  if ((*(short *)(arg1 + 0x46) == 10) && (value3 = entity->sceneObjects, value3 != 0)) {
    value2 = CEntities::FindEntityAttachmentByFlags(arg1,0x8000000);
    if (value2 != 0) {
      _g_PlayerSwingReleaseQueued = value2;
      if (*(short *)(value2 + 0xe) == 2) {
        if (g_PlayerCurrentAnimationId == 0) {
          value = g_ActiveSwingMotionTable + (uint)*(ushort *)(value2 + 0x10) * 0xc;
          if (*(char *)(value + 6) == '\x0e') {
            *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = *(undefined1 *)(value + 4);
            g_PlayerMoveHeadingAngle = *(ushort *)(g_PlayerEntitySceneObject + 0x132);
            if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
              g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle ^ 0x800;
            }
            *(ushort *)(g_PlayerEntitySceneObject + 0xa2) = g_PlayerMoveHeadingAngle;
          }
          else {
            *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = 0;
            g_PlayerMoveHeadingAngle = *(ushort *)(g_PlayerEntitySceneObject + 0x132) ^ 0x800;
            *(ushort *)(g_PlayerEntitySceneObject + 0xa2) = g_PlayerMoveHeadingAngle;
          }
          *g_PlayerEntitySceneObjectData =
               *(undefined2 *)(g_ActiveSwingMotionTable + (uint)*(ushort *)(value2 + 0x10) * 0xc);
          g_PlayerAnimationSurfaceSide =
               *(undefined1 *)(g_ActiveSwingMotionTable + 5 + (uint)*(ushort *)(value2 + 0x10) * 0xc)
          ;
          g_PlayerFacingBeforeSwing =
               *(byte *)(g_ActiveSwingMotionTable + 4 + (uint)*(ushort *)(value2 + 0x10) * 0xc) ^
               *(byte *)(g_PlayerEntitySceneObject + 0x75);
          g_PlayerSwingPumpVelocity =
               *(byte *)(g_ActiveSwingMotionTable + 7 + (uint)*(ushort *)(value2 + 0x10) * 0xc) ^
               *(byte *)(g_PlayerEntitySceneObject + 0x75);
        }
        else {
          CPlayerHero::AdvanceAnimationScript();
        }
      }
      value3 = GetSceneAttachmentWorldPositionByIndex(value3,(int *)&localState3,g_CurrentSwingSegmentIndex + -1)
      ;
      if (value3 != 0) {
        *(undefined4 *)(g_PlayerEntitySceneObjectData + 4) = localState3;
        *(undefined4 *)(g_PlayerEntitySceneObjectData + 6) = localState2;
        *(undefined4 *)(g_PlayerEntitySceneObjectData + 8) = localState;
      }
      return *(undefined1 *)(g_ActiveSwingMotionTable + 6 + (uint)*(ushort *)(value2 + 0x10) * 0xc);
    }
  }
  return 0;
}

