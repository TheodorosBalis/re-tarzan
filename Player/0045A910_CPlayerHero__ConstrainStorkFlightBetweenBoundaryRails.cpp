#include "tarzan_ghidra_types.hpp"

// Address: 0x0045A910
// Label: CPlayerHero::ConstrainStorkFlightBetweenBoundaryRails
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::ConstrainStorkFlightBetweenBoundaryRails(void)

{
  int *intCursor;
  int value;
  uint value5;
  int value2;
  int value3;
  int value4;
  
  if (g_StorkBoundaryRailsInitialized == 0) {
    value = g_StorkLeftBoundarySurfaceIndex * 4 + 4;
    g_StorkLeftBoundaryPathBase =
         (ushort *)(*(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable);
    value = g_StorkRightBoundarySurfaceIndex * 4 + 4;
    g_StorkRightBoundaryPathBase =
         (ushort *)(*(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable);
    g_StorkLeftBoundaryLastSegmentIndex = *g_StorkLeftBoundaryPathBase - 1;
    g_StorkRightBoundaryLastSegmentIndex = *g_StorkRightBoundaryPathBase - 1;
    value = FindRuntimePathSegmentForEntitySceneObject
                      (g_StorkLeftBoundaryPathBase,g_PlayerEntitySceneObject);
    g_StorkLeftBoundarySegmentStart = g_StorkLeftBoundaryPathBase + value * 0xe + 0x18;
    value = FindRuntimePathSegmentForEntitySceneObject
                      (g_StorkRightBoundaryPathBase,g_PlayerEntitySceneObject);
    g_StorkRightBoundarySegmentStart = g_StorkRightBoundaryPathBase + value * 0xe + 0x18;
    g_StorkLeftBoundaryLastSegmentStart =
         g_StorkLeftBoundaryPathBase + g_StorkLeftBoundaryLastSegmentIndex * 0xe + 0x18;
    g_StorkLeftBoundaryFirstSegmentStart = g_StorkLeftBoundarySegmentStart;
    g_StorkBoundaryRailsInitialized = 1;
    g_StorkRightBoundarySegmentEnd = g_StorkRightBoundarySegmentStart + 0xe;
    g_StorkRightBoundaryLastSegmentStart =
         g_StorkRightBoundaryPathBase + g_StorkRightBoundaryLastSegmentIndex * 0xe + 0x18;
    g_StorkLeftBoundarySegmentEnd = g_StorkLeftBoundarySegmentStart + 0xe;
    g_StorkRightBoundaryFirstSegmentStart = g_StorkRightBoundarySegmentStart;
  }
  _g_StorkLeftBoundaryClampActive = 0;
  _g_StorkRightBoundaryClampActive = 0;
  if (*(int *)(g_StorkLeftBoundarySegmentEnd + 4) < *(int *)(g_PlayerEntitySceneObjectData + 0x10))
  {
    g_StorkLeftBoundarySegmentStart = g_StorkLeftBoundarySegmentStart + 0xe;
  }
  if (*(int *)(g_PlayerEntitySceneObjectData + 0x10) < *(int *)(g_StorkLeftBoundarySegmentStart + 4)
     ) {
    g_StorkLeftBoundarySegmentStart = g_StorkLeftBoundarySegmentStart + -0xe;
  }
  if (g_StorkLeftBoundaryLastSegmentStart < g_StorkLeftBoundarySegmentStart) {
    g_StorkLeftBoundarySegmentStart = g_StorkLeftBoundaryFirstSegmentStart;
  }
  g_StorkLeftBoundarySegmentEnd = g_StorkLeftBoundarySegmentStart + 0xe;
  value4 = *(int *)g_StorkLeftBoundarySegmentStart - *(int *)g_StorkLeftBoundarySegmentEnd;
  value2 = *(int *)(g_StorkLeftBoundarySegmentStart + 2) -
          *(int *)(g_StorkLeftBoundarySegmentStart + 0x10);
  value3 = *(int *)(g_StorkLeftBoundarySegmentStart + 4) -
          *(int *)(g_StorkLeftBoundarySegmentStart + 0x12);
  SqrtToInt(value2 * value2 + value4 * value4 + value3 * value3);
  value = SqrtToInt(value4 * value4 + value3 * value3);
  GetAngleFromXZVector12Bit(value2,value >> 6);
  _g_StorkLeftBoundaryFacingAngle = GetAngleFromXZVector12Bit(value4,value3);
  _g_StorkLeftBoundaryFacingAngle = _g_StorkLeftBoundaryFacingAngle & 0xfff;
  if (value3 != 0) {
    value = (*(int *)(g_PlayerEntitySceneObjectData + 0x10) -
            *(int *)(g_StorkLeftBoundarySegmentStart + 4)) * ((value4 * 0x10000) / value3) +
            *(int *)g_StorkLeftBoundarySegmentStart * 0x10000 >> 0x10;
    if (*(int *)(g_PlayerEntitySceneObjectData + 8) <= value) {
      if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
        _g_StorkLeftBoundaryClampActive = 1;
      }
      value2 = *(int *)(g_PlayerEntitySceneObjectData + 8);
      intCursor = (int *)(g_PlayerEntitySceneObjectData + 8);
      value5 = GetWrappedSignedAngleDelta12Bit
                        ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                         _g_StorkLeftBoundaryFacingAngle);
      *intCursor = *intCursor + ((int)(short)(&g_SinCosTable12Bit)[value5 & 0xfff] * (value - value2) >> 0xc
                          );
    }
    if (*(int *)(g_StorkRightBoundarySegmentEnd + 4) <
        *(int *)(g_PlayerEntitySceneObjectData + 0x10)) {
      g_StorkRightBoundarySegmentStart = g_StorkRightBoundarySegmentStart + 0xe;
    }
    if (*(int *)(g_PlayerEntitySceneObjectData + 0x10) <
        *(int *)(g_StorkRightBoundarySegmentStart + 4)) {
      g_StorkRightBoundarySegmentStart = g_StorkRightBoundarySegmentStart + -0xe;
    }
    if (g_StorkRightBoundaryLastSegmentStart < g_StorkRightBoundarySegmentStart) {
      g_StorkRightBoundarySegmentStart = g_StorkRightBoundaryFirstSegmentStart;
    }
    g_StorkRightBoundarySegmentEnd = g_StorkRightBoundarySegmentStart + 0xe;
    value4 = *(int *)g_StorkRightBoundarySegmentStart - *(int *)g_StorkRightBoundarySegmentEnd;
    value2 = *(int *)(g_StorkRightBoundarySegmentStart + 2) -
            *(int *)(g_StorkRightBoundarySegmentStart + 0x10);
    value3 = *(int *)(g_StorkRightBoundarySegmentStart + 4) -
            *(int *)(g_StorkRightBoundarySegmentStart + 0x12);
    SqrtToInt(value2 * value2 + value4 * value4 + value3 * value3);
    value = SqrtToInt(value4 * value4 + value3 * value3);
    GetAngleFromXZVector12Bit(value2,value >> 6);
    _g_StorkRightBoundaryFacingAngle = GetAngleFromXZVector12Bit(value4,value3);
    _g_StorkRightBoundaryFacingAngle = _g_StorkRightBoundaryFacingAngle & 0xfff;
    if (value3 != 0) {
      value = *(int *)(g_PlayerEntitySceneObjectData + 8);
      value2 = (*(int *)(g_PlayerEntitySceneObjectData + 0x10) -
              *(int *)(g_StorkRightBoundarySegmentStart + 4)) * ((value4 * 0x10000) / value3) +
              *(int *)g_StorkRightBoundarySegmentStart * 0x10000 >> 0x10;
      if (value2 <= value) {
        if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
          _g_StorkRightBoundaryClampActive = 1;
        }
        intCursor = (int *)(g_PlayerEntitySceneObjectData + 8);
        value5 = GetWrappedSignedAngleDelta12Bit
                          ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                           _g_StorkRightBoundaryFacingAngle);
        *intCursor = *intCursor + ((int)(short)(&g_SinCosTable12Bit)[value5 & 0xfff] * (value2 - value) >>
                            0xc);
      }
    }
  }
  return;
}

