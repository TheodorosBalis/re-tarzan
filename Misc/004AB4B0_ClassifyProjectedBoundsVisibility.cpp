#include "tarzan_ghidra_types.hpp"

// Address: 0x004AB4B0
// Label: ClassifyProjectedBoundsVisibility
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ClassifyProjectedBoundsVisibility(short *arg1)

{
  float floatValue;
  float floatValue12;
  float floatValue13;
  float floatValue14;
  float floatValue15;
  float floatValue16;
  float floatValue17;
  float floatValue18;
  float floatValue19;
  float floatValue2;
  float floatValue3;
  float floatValue4;
  float floatValue5;
  float floatValue6;
  float floatValue7;
  float floatValue8;
  float floatValue9;
  float floatValue10;
  float floatValue11;
  
  if (arg1 == (short *)0x0) {
    return 1;
  }
  _g_ProjectInputX0 = (float)(int)*arg1;
  _g_ProjectInputY0 = (float)(int)arg1[1];
  _g_ProjectInputZ0 = (float)(int)arg1[2];
  _g_ProjectInputX1 = (float)(int)arg1[4];
  _g_ProjectInputY1 = (float)(int)arg1[5];
  _g_ProjectInputZ1 = (float)(int)arg1[6];
  _g_ProjectInputX2 = (float)(int)arg1[8];
  _g_ProjectInputY2 = (float)(int)arg1[9];
  _g_ProjectInputZ2 = (float)(int)arg1[10];
  ProjectBoundsVisibilityScratchVertices3Clamped();
  floatValue10 = g_ProjectScreenY2;
  floatValue8 = g_ProjectScreenY1;
  floatValue6 = g_ProjectScreenY0;
  floatValue4 = g_ProjectScreenX2;
  floatValue2 = g_ProjectScreenX1;
  floatValue18 = g_ProjectScreenX0;
  floatValue16 = g_ProjectCameraZ2;
  floatValue14 = g_ProjectCameraZ1;
  floatValue12 = g_ProjectCameraZ0;
  _g_ProjectInputX0 = (float)(int)arg1[0xc];
  _g_ProjectInputY0 = (float)(int)arg1[0xd];
  _g_ProjectInputZ0 = (float)(int)arg1[0xe];
  _g_ProjectInputX1 = (float)(int)arg1[0x10];
  _g_ProjectInputY1 = (float)(int)arg1[0x11];
  _g_ProjectInputZ1 = (float)(int)arg1[0x12];
  _g_ProjectInputX2 = (float)(int)arg1[0x14];
  _g_ProjectInputY2 = (float)(int)arg1[0x15];
  _g_ProjectInputZ2 = (float)(int)arg1[0x16];
  ProjectBoundsVisibilityScratchVertices3Clamped();
  floatValue11 = g_ProjectScreenY2;
  floatValue9 = g_ProjectScreenY1;
  floatValue7 = g_ProjectScreenY0;
  floatValue5 = g_ProjectScreenX2;
  floatValue3 = g_ProjectScreenX1;
  floatValue19 = g_ProjectScreenX0;
  floatValue17 = g_ProjectCameraZ2;
  floatValue15 = g_ProjectCameraZ1;
  floatValue13 = g_ProjectCameraZ0;
  _g_ProjectInputX0 = (float)(int)arg1[0x18];
  _g_ProjectInputY0 = (float)(int)arg1[0x19];
  _g_ProjectInputZ0 = (float)(int)arg1[0x1a];
  _g_ProjectInputX1 = (float)(int)arg1[0x1c];
  _g_ProjectInputY1 = (float)(int)arg1[0x1d];
  _g_ProjectInputX2 = 0.0;
  _g_ProjectInputZ1 = (float)(int)arg1[0x1e];
  _g_ProjectInputY2 = 0.0;
  _g_ProjectInputZ2 = 0.0;
  ProjectBoundsVisibilityScratchVertices3Clamped();
  floatValue = (float)(int)g_RenderViewportWidth;
  if ((((floatValue < floatValue18) && (floatValue < floatValue2)) && (floatValue < floatValue4)) &&
     (((floatValue < floatValue19 && (floatValue < floatValue3)) &&
      ((floatValue < floatValue5 && ((floatValue < g_ProjectScreenX0 && (floatValue < g_ProjectScreenX1)))))))) {
    return 0;
  }
  if (((((floatValue18 < _g_FloatZero) && (floatValue2 < _g_FloatZero)) && (floatValue4 < _g_FloatZero)) &&
      ((floatValue19 < _g_FloatZero && (floatValue3 < _g_FloatZero)))) &&
     ((floatValue5 < _g_FloatZero &&
      ((g_ProjectScreenX0 < _g_FloatZero && (g_ProjectScreenX1 < _g_FloatZero)))))) {
    return 0;
  }
  floatValue = (float)(int)g_RenderViewportHeight;
  if (((((floatValue < floatValue6) && (floatValue < floatValue8)) && (floatValue < floatValue10)) &&
      ((floatValue < floatValue7 && (floatValue < floatValue9)))) &&
     ((floatValue < floatValue11 && ((floatValue < g_ProjectScreenY0 && (floatValue < g_ProjectScreenY1)))))) {
    return 0;
  }
  if ((((floatValue6 < _g_FloatZero) && (floatValue8 < _g_FloatZero)) && (floatValue10 < _g_FloatZero)) &&
     (((floatValue7 < _g_FloatZero && (floatValue9 < _g_FloatZero)) &&
      ((floatValue11 < _g_FloatZero &&
       ((g_ProjectScreenY0 < _g_FloatZero && (g_ProjectScreenY1 < _g_FloatZero)))))))) {
    return 0;
  }
  if (_g_FloatZero <= floatValue12) {
    if ((((floatValue14 >= _g_FloatZero) && (_g_FloatZero <= floatValue16)) && (_g_FloatZero <= floatValue13)) &&
       (((_g_FloatZero <= floatValue15 && (_g_FloatZero <= floatValue17)) &&
        ((_g_FloatZero <= g_ProjectCameraZ0 && (_g_FloatZero <= g_ProjectCameraZ1)))))) {
      return 1;
    }
  }
  else if (((floatValue14 < _g_FloatZero) && (floatValue16 < _g_FloatZero)) &&
          ((floatValue13 < _g_FloatZero &&
           ((((floatValue15 < _g_FloatZero && (floatValue17 < _g_FloatZero)) && (g_ProjectCameraZ0 < _g_FloatZero)
             ) && (g_ProjectCameraZ1 < _g_FloatZero)))))) {
    return 0;
  }
  return 2;
}

