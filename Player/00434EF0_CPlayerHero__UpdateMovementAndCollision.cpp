#include "tarzan_ghidra_types.hpp"

// Address: 0x00434EF0
// Label: CPlayerHero::UpdateMovementAndCollision
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateMovementAndCollision(char arg1)

{
  int value;
  char resultFlag;
  int value2;
  uint value3;
  undefined2 value4;
  uint value5;
  uint value6;
  
  if (g_PlayerCurrentCollisionMode == 1) {
    *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = 0;
  }
  if (arg1 == '\0') {
    value3 = *(uint *)(g_PlayerMotionState + 0x10);
    value6 = value3;
    goto LAB_00434f78;
  }
  value2 = *(int *)(g_PlayerMotionState + 0x10);
  if (value2 != *(int *)(g_PlayerMotionState + 0x1c)) {
    if (*(int *)(g_PlayerMotionState + 0x1c) < value2) {
      *(int *)(g_PlayerMotionState + 0x10) = value2 - *(int *)(g_PlayerMotionState + 0x18);
      value2 = *(int *)(g_PlayerMotionState + 0x1c);
      if (*(int *)(g_PlayerMotionState + 0x10) < value2) {
LAB_00434f4e:
        *(int *)(g_PlayerMotionState + 0x10) = value2;
      }
    }
    else {
      *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerMotionState + 0x14) + value2;
      value2 = *(int *)(g_PlayerMotionState + 0x1c);
      if (value2 < *(int *)(g_PlayerMotionState + 0x10)) goto LAB_00434f4e;
    }
  }
  value3 = *(uint *)(g_PlayerMotionState + 0x10);
  value6 = value3;
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) != '\0') {
    value6 = ~value3 + 1;
  }
LAB_00434f78:
  switch(_g_PlayerCurrentCollisionMode & 0xffff) {
  case 0:
    value5 = 0;
    break;
  default:
    value5 = 0;
    ComputeEntitySceneObjectCollisionMoveDelta
              (value6,_g_PlayerMoveHeadingAngle & 0xffff,g_PlayerEntitySceneObject);
    if (value6 == 0) {
      CPlayerHero::RefreshIdleCollisionContact();
    }
    break;
  case 3:
    value5 = 0;
    ComputeEntitySceneObjectCollisionMoveDelta
              (value6,_g_PlayerMoveHeadingAngle & 0xffff,g_PlayerEntitySceneObject);
    break;
  case 4:
    value5 = (int)((int)(short)(&g_SinCosTable12Bit)
                              [(_g_PlayerAirMovePitchAngle & 0xffff) - 0x400 & 0xfff] * value3) >>
            0xc;
    ComputeEntitySceneObjectCollisionMoveDelta
              ((int)((int)(short)(&g_SinCosTable12Bit)[_g_PlayerAirMovePitchAngle & 0xfff] * value3)
               >> 0xc,g_PlayerAirMoveHeadingAngle,g_PlayerEntitySceneObject);
    break;
  case 6:
    value3 = (uint)g_PlayerSurfaceSideMoveAngle;
    value5 = ((int)((int)(short)(&g_SinCosTable12Bit)[value3 - 0x400 & 0xfff] * value6) >> 0xc) +
            g_PlayerLateralSurfaceOffset;
    g_PlayerLateralSurfaceOffset = value5;
    if ((int)g_PlayerCollisionLateralLimit <=
        (int)((value5 ^ (int)value5 >> 0x1f) - ((int)value5 >> 0x1f))) {
      g_PlayerLateralSurfaceOffset = g_PlayerCollisionLateralLimit;
      if ((int)value5 < 0) {
        g_PlayerLateralSurfaceOffset = -g_PlayerCollisionLateralLimit;
      }
      g_PlayerSurfaceSideMoveAngle = 0;
    }
    ComputeEntitySceneObjectCollisionMoveDelta
              ((int)((int)(short)(&g_SinCosTable12Bit)[value3 & 0xfff] * value6) >> 0xc,
               _g_PlayerMoveHeadingAngle & 0xffff,g_PlayerEntitySceneObject);
  }
  if (*(int *)(g_PlayerEntitySceneObject + 0x108) == 1) {
    value2 = *(int *)(g_PlayerEntitySceneObject + 0x110) * 4 + 4;
    g_PlayerActiveSurfaceDefinition =
         *(int *)(value2 + g_CollisionSurfaceTable) + value2 + g_CollisionSurfaceTable;
    _g_PlayerCollisionSnapRange =
         (-(ushort)((*(uint *)(g_PlayerActiveSurfaceDefinition + 8) & 0x10) != 0) & 0x40) + 0x40;
    if ((*(byte *)(g_PlayerActiveSurfaceDefinition + 8) & 0x20) != 0) {
      _g_PlayerCollisionSnapRange = 0x400;
    }
  }
  else {
    _g_PlayerCollisionSnapRange = 0x80;
    g_PlayerActiveSurfaceDefinition = 0;
  }
  value2 = *(int *)(g_PlayerEntitySceneObject + 0x108);
  if (g_PlayerPreviousCollisionMode == value2) {
    if (value2 == 1) {
      if ((g_PlayerActiveSurfaceDefinition != 0) &&
         (*(int *)(g_PlayerActiveSurfaceDefinition + 0x18) != 0)) {
        g_CameraFollowMode = (undefined2)*(int *)(g_PlayerActiveSurfaceDefinition + 0x18);
      }
    }
    else if ((value2 == 2) &&
            (value2 = *(int *)(*(int *)(g_PlayerEntitySceneObject + 0x10c) + 0x1c), value2 != 0)) {
      g_CameraFollowMode = (undefined2)value2;
    }
  }
  else {
    g_CameraFollowFlags = 0;
    g_CameraRelativeTurnInputMask = 0;
    if (*(int *)(g_PlayerEntitySceneObject + 0x108) == 1) {
      resultFlag = ShouldMirrorCameraFollowSideForActiveAnchor();
      if (resultFlag == '\0') {
        g_CameraRelativeTurnInputMask = 0x20;
        g_CameraFollowFlags = 0x90;
      }
      else {
        g_CameraRelativeTurnInputMask = 0x80;
        g_CameraFollowFlags = 0x30;
      }
      if (g_PlayerActiveSurfaceDefinition != 0) {
        g_PlayerCurrentCollisionMode = (short)*(int *)(g_PlayerActiveSurfaceDefinition + 0x14);
        if (*(int *)(g_PlayerActiveSurfaceDefinition + 0x14) == 0) {
          g_PlayerCurrentCollisionMode = 2;
        }
        g_CameraFollowMode = (undefined2)*(int *)(g_PlayerActiveSurfaceDefinition + 0x18);
        if (*(int *)(g_PlayerActiveSurfaceDefinition + 0x18) == 0) {
          g_CameraFollowMode = 1;
        }
      }
      _g_PlayerMoveHeadingAngle =
           CONCAT22(_g_PlayerMoveTiltAngle,*(undefined2 *)(g_PlayerEntitySceneObject + 0x132));
      if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
        _g_PlayerMoveHeadingAngle =
             CONCAT22(_g_PlayerMoveTiltAngle,*(undefined2 *)(g_PlayerEntitySceneObject + 0x132)) ^
             0x800;
      }
      value2 = GetWrappedAngleDistance12Bit
                        ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                         _g_PlayerMoveHeadingAngle & 0xffff);
      if (0x400 < value2) {
        *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
      }
    }
    else if (*(int *)(g_PlayerEntitySceneObject + 0x108) == 2) {
      value2 = *(int *)(*(int *)(g_PlayerEntitySceneObject + 0x10c) + 0x18);
      g_PlayerCurrentCollisionMode = (short)value2;
      if (value2 == 0) {
        g_PlayerCurrentCollisionMode = 1;
      }
      value2 = *(int *)(*(int *)(g_PlayerEntitySceneObject + 0x10c) + 0x1c);
      g_CameraFollowMode = (undefined2)value2;
      if (value2 == 0) {
        g_CameraFollowMode = 2;
      }
      *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = 0;
    }
    else {
      _g_PlayerCurrentCollisionMode = CONCAT22(_g_PlayerHeroMode,2);
      g_CameraFollowMode = 1;
    }
  }
  g_PlayerContactSurfaceThisFrame = 0;
  g_PlayerCollisionContactFlags = g_PlayerCollisionContactFlags & 0xffff0000;
  g_PlayerTriggeredCollisionEntry = 0;
  *( undefined2 *)((int)&g_PlayerCurrentCollisionSurfaceFlags + 0) = 0;
  *( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 0) = 0;
  switch(_g_PlayerCurrentCollisionMode & 0xffff) {
  case 1:
  case 3:
    if (g_PlayerGroundShadowProbeEntitySceneObject != 0) {
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x14) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
      if (30000 < *(int *)(g_PlayerEntitySceneObject + 0x58)) {
        *(undefined4 *)(g_PlayerEntitySceneObject + 0x58) = 30000;
      }
      value2 = CPlayerHero::FindNearestGroundCollisionOffset
                        (*(undefined4 *)(g_PlayerEntitySceneObject + 0x58));
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) =
           value2 + *(int *)(g_PlayerEntitySceneObject + 0x18);
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x1c) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x6c) = 0xffffffe0;
    }
    g_PlayerCollisionFacingFlags = 0;
    if (arg1 != '\0') {
      *(int *)(g_PlayerEntitySceneObjectData + 8) =
           *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
      *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
           *(int *)(g_PlayerEntitySceneObjectData + 0x10) +
           *(int *)(g_PlayerEntitySceneObject + 0x5c);
      *(uint *)(g_PlayerEntitySceneObjectData + 0xc) =
           *(int *)(g_PlayerEntitySceneObjectData + 0xc) - value5;
      return;
    }
    break;
  case 2:
    g_PlayerContactSurfaceThisFrame = *(int *)(g_PlayerEntitySceneObject + 0x114);
    if (g_PlayerContactSurfaceThisFrame != 0) {
      *( undefined2 *)((int)&g_PlayerCurrentCollisionSurfaceFlags + 0) =
           *(undefined2 *)(g_PlayerContactSurfaceThisFrame + 0x14);
      *( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 0) =
           (undefined2)((uint)*(undefined4 *)(g_PlayerContactSurfaceThisFrame + 0x14) >> 0x10);
      for (value2 = g_CollisionTriggerEntryListHead; value2 != 0; value2 = *(int *)(value2 + 0x20)) {
        *(ushort *)(value2 + 0x42) = *(ushort *)(value2 + 0x42) & 0xff3f;
        if (*(char *)(value2 + 0x3d) == (char)g_PlayerSurfaceTriggerPacket) {
          g_PlayerTriggeredCollisionEntry = value2;
          *(byte *)(value2 + 0x42) = *(byte *)(value2 + 0x42) | 0x40;
          break;
        }
      }
    }
    g_PlayerCollisionContactFlags =
         g_PlayerCollisionContactFlags | *(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0xffff;
    g_PlayerMoveHeadingAngle = *(undefined2 *)(g_PlayerEntitySceneObject + 0x132);
    if (arg1 != '\0') {
      *(int *)(g_PlayerEntitySceneObjectData + 8) =
           *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
      *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
           *(int *)(g_PlayerEntitySceneObjectData + 0x10) +
           *(int *)(g_PlayerEntitySceneObject + 0x5c);
    }
    if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
      _g_PlayerMoveHeadingAngle =
           CONCAT22(0x400 - *(short *)(g_PlayerEntitySceneObject + 0x130),g_PlayerMoveHeadingAngle)
           ^ 0x800;
    }
    else {
      _g_PlayerMoveHeadingAngle =
           CONCAT22(*(short *)(g_PlayerEntitySceneObject + 0x130) + -0x400,g_PlayerMoveHeadingAngle)
      ;
    }
    _g_PlayerMoveHeadingAngle = _g_PlayerMoveHeadingAngle & 0xfffffff;
    g_PlayerCollisionFacingFlags = (byte)(*(uint *)(g_PlayerEntitySceneObject + 0x13c) >> 1) & 1;
    if (g_PlayerGroundShadowProbeEntitySceneObject != 0) {
      if (g_CurrentSwingEntity != 0) {
        *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
             *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) & 0x7fff;
        return;
      }
      *(byte *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xf) =
           *(byte *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xf) | 0x80;
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x108) = 1;
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x110) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x10c) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x18);
      if (_g_PlayerHeroMode == 2) {
        value2 = (-(uint)(*(char *)(g_PlayerEntitySceneObject + 0x75) != '\0') & 0x10) - 8;
      }
      else {
        value2 = (-(uint)(*(char *)(g_PlayerEntitySceneObject + 0x75) != '\0') & 0x40) - 0x20;
      }
      ComputeEntitySceneObjectCollisionMoveDelta(value2,0,g_PlayerGroundShadowProbeEntitySceneObject)
      ;
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x14) =
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x14) +
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x54);
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) =
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) +
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x58);
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x1c) =
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x1c) +
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x5c);
      *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xa0) =
           0x400U - *(short *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x130) & 0xfff;
      *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xa2) =
           *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x132) ^ 0x800;
      value2 = (*(int *)(g_PlayerEntitySceneObjectData + 0xc) -
               *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) >> 1) + 0x400;
      if (value2 < 0) {
        value2 = 0;
      }
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x30) = value2;
      if ((*(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x114) != 0) &&
         ((*(uint *)(*(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x114) + 0x14) & 0x900)
          != 0)) {
        *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
             *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) & 0x7fff;
        return;
      }
    }
    break;
  case 4:
    g_PlayerCollisionFacingFlags = 0;
    if (arg1 != '\0') {
      *(int *)(g_PlayerEntitySceneObjectData + 8) =
           *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
      *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
           *(int *)(g_PlayerEntitySceneObjectData + 0x10) +
           *(int *)(g_PlayerEntitySceneObject + 0x5c);
      *(int *)(g_PlayerEntitySceneObject + 0x58) =
           *(int *)(g_PlayerEntitySceneObject + 0x58) + -0x80;
      value3 = *(uint *)(g_PlayerEntitySceneObject + 0x58);
      if ((int)value3 < 0) {
        *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
             *(int *)(g_PlayerEntitySceneObjectData + 0xc) + value3;
      }
      else {
        if ((int)value3 < (int)value5) {
          value5 = value3;
        }
        *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
             *(int *)(g_PlayerEntitySceneObjectData + 0xc) + value5;
      }
      if (*(int *)(g_PlayerEntitySceneObjectData + 0xc) < 0x101) {
        *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc) = 0x100;
        return;
      }
    }
    break;
  case 5:
    g_PlayerContactSurfaceThisFrame = *(int *)(g_PlayerEntitySceneObject + 0x114);
    if (g_PlayerContactSurfaceThisFrame != 0) {
      *( undefined2 *)((int)&g_PlayerCurrentCollisionSurfaceFlags + 0) =
           *(undefined2 *)(g_PlayerContactSurfaceThisFrame + 0x14);
      *( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 0) =
           (undefined2)((uint)*(undefined4 *)(g_PlayerContactSurfaceThisFrame + 0x14) >> 0x10);
      for (value2 = g_CollisionTriggerEntryListHead; value2 != 0; value2 = *(int *)(value2 + 0x20)) {
        *(ushort *)(value2 + 0x42) = *(ushort *)(value2 + 0x42) & 0xff3f;
        if (*(char *)(value2 + 0x3d) == (char)g_PlayerSurfaceTriggerPacket) {
          g_PlayerTriggeredCollisionEntry = value2;
          *(byte *)(value2 + 0x42) = *(byte *)(value2 + 0x42) | 0x40;
          break;
        }
      }
    }
    g_PlayerCollisionContactFlags =
         g_PlayerCollisionContactFlags | *(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0xffff;
    g_PlayerMoveHeadingAngle = *(undefined2 *)(g_PlayerEntitySceneObject + 0x132);
    if (arg1 != '\0') {
      *(int *)(g_PlayerEntitySceneObjectData + 8) =
           *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
      *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
           *(int *)(g_PlayerEntitySceneObjectData + 0x10) +
           *(int *)(g_PlayerEntitySceneObject + 0x5c);
    }
    if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
      _g_PlayerMoveHeadingAngle =
           CONCAT22(0x400 - *(short *)(g_PlayerEntitySceneObject + 0x130),g_PlayerMoveHeadingAngle)
           ^ 0x800;
    }
    else {
      _g_PlayerMoveHeadingAngle =
           CONCAT22(*(short *)(g_PlayerEntitySceneObject + 0x130) + -0x400,g_PlayerMoveHeadingAngle)
      ;
    }
    _g_PlayerMoveHeadingAngle = _g_PlayerMoveHeadingAngle & 0xfffffff;
    g_PlayerCollisionFacingFlags = (byte)(*(uint *)(g_PlayerEntitySceneObject + 0x13c) >> 1) & 1;
    value2 = (int)(g_PlayerSurfaceLeanScale * g_PlayerLateralSurfaceOffset) / 0xf;
    value3 = *(ushort *)(g_PlayerEntitySceneObject + 0xa2) + 0x400 & 0xfff;
    *(int *)(g_PlayerEntitySceneObject + 0x3c) =
         -((short)(&g_SinCosTable12Bit)[value3 - 0x400 & 0xfff] * value2) >> 0xc;
    *(int *)(g_PlayerEntitySceneObject + 0x44) =
         -((short)(&g_SinCosTable12Bit)[value3] * value2) >> 0xc;
    value2 = value2 + value2 / 2;
    value3 = -value2 & 0xfff;
    *(int *)(g_PlayerEntitySceneObject + 0x40) =
         -((short)(&g_SinCosTable12Bit)[value3 - 0x400 & 0xfff] * value2) >> 0xc;
    value4 = (undefined2)value3;
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4) = value4;
    if (g_PlayerGroundShadowProbeEntitySceneObject != 0) {
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x108) = 1;
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x110) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x10c) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
      ComputeEntitySceneObjectCollisionMoveDelta
                ((-(uint)(*(char *)(g_PlayerEntitySceneObject + 0x75) != '\0') & 0x40) - 0x20,0,
                 g_PlayerGroundShadowProbeEntitySceneObject);
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x14) =
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x14) +
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x54);
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) =
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) +
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x58);
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x1c) =
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x1c) +
           *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x5c);
      *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xa0) =
           0x400U - *(short *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x130) & 0xfff;
      *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xa2) =
           *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x132) ^ 0x800;
      *(undefined2 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xa4) = value4;
      value = g_PlayerGroundShadowProbeEntitySceneObject;
      value2 = g_PlayerEntitySceneObject;
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x3c) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x3c);
      *(undefined4 *)(value + 0x40) = *(undefined4 *)(value2 + 0x40);
      *(undefined4 *)(value + 0x44) = *(undefined4 *)(value2 + 0x44);
      value2 = (*(int *)(g_PlayerEntitySceneObjectData + 0xc) -
               *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x18) >> 1) + 0x400;
      if (value2 < 0) {
        value2 = 0;
      }
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x30) = value2;
      return;
    }
    break;
  case 6:
    g_PlayerContactSurfaceThisFrame = *(int *)(g_PlayerEntitySceneObject + 0x114);
    g_PlayerCollisionContactFlags =
         g_PlayerCollisionContactFlags | *(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) & 0xffff;
    _g_PlayerMoveHeadingAngle =
         CONCAT22(_g_PlayerMoveTiltAngle,*(undefined2 *)(g_PlayerEntitySceneObject + 0x132));
    if (arg1 != '\0') {
      *(int *)(g_PlayerEntitySceneObjectData + 8) =
           *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
      *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
           *(int *)(g_PlayerEntitySceneObjectData + 0x10) +
           *(int *)(g_PlayerEntitySceneObject + 0x5c);
      value3 = _g_PlayerMoveHeadingAngle & 0xffff;
      *(int *)(g_PlayerEntitySceneObjectData + 8) =
           *(int *)(g_PlayerEntitySceneObjectData + 8) +
           ((int)((int)(short)(&g_SinCosTable12Bit)[_g_PlayerMoveHeadingAngle & 0xfff] *
                 g_PlayerLateralSurfaceOffset) >> 0xc);
      *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
           *(int *)(g_PlayerEntitySceneObjectData + 0x10) +
           ((int)((int)(short)(&g_SinCosTable12Bit)[value3 + 0x400 & 0xfff] *
                 g_PlayerLateralSurfaceOffset) >> 0xc);
    }
    g_PlayerCollisionLateralLimit =
         GetJungleSurfaceLateralLimit
                   (*(undefined4 *)(g_PlayerEntitySceneObject + 0x10c),
                    *(undefined4 *)(g_PlayerEntitySceneObject + 0x114));
    _g_PlayerMoveHeadingAngle =
         (CONCAT22(0x400 - *(short *)(g_PlayerEntitySceneObject + 0x130),
                   g_PlayerSurfaceSideMoveAngle + g_PlayerMoveHeadingAngle) ^ 0x800) & 0xfffffff;
    g_PlayerCollisionFacingFlags =
         (byte)(*(uint *)(g_PlayerContactSurfaceThisFrame + 0x14) >> 0xd) & 1;
    return;
  default:
    g_PlayerCollisionFacingFlags = 0;
    if (arg1 != '\0') {
      *(int *)(g_PlayerEntitySceneObjectData + 8) =
           *(int *)(g_PlayerEntitySceneObjectData + 8) + *(int *)(g_PlayerEntitySceneObject + 0x54);
      *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
           *(int *)(g_PlayerEntitySceneObjectData + 0x10) +
           *(int *)(g_PlayerEntitySceneObject + 0x5c);
      *(uint *)(g_PlayerEntitySceneObjectData + 0xc) =
           *(int *)(g_PlayerEntitySceneObjectData + 0xc) - value5;
    }
    _g_PlayerMoveHeadingAngle =
         CONCAT22(0x400 - *(short *)(g_PlayerEntitySceneObject + 0x130),g_PlayerMoveHeadingAngle) &
         0xfffffff;
  }
  return;
}

