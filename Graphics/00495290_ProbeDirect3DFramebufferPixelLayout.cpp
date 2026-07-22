#include "tarzan_ghidra_types.hpp"

// Address: 0x00495290
// Label: ProbeDirect3DFramebufferPixelLayout
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ProbeDirect3DFramebufferPixelLayout(void)

{
  bool flagByte;
  byte flagByte2;
  DWORD directXResult;
  uint value5;
  int value3;
  int value4;
  uint value6;
  uint value7;
  uint value8;
  int value;
  int value2;
  int scratchRect28;
  int scratchRect27;
  int scratchRect26;
  int scratchRect25;
  int scratchRect24;
  undefined4 scratchRect23;
  int scratchRect22;
  int scratchRect21;
  int scratchRect20;
  uint scratchRect19;
  uint scratchRect18;
  uint scratchRect17;
  undefined4 scratchRect16;
  int scratchRect15;
  int scratchRect14;
  undefined4 scratchRect12;
  undefined4 scratchRect11;
  undefined4 scratchRect10;
  undefined4 scratchRect9;
  undefined4 scratchRect8;
  undefined4 scratchRect7;
  undefined4 scratchRect6;
  undefined4 scratchRect5;
  undefined4 scratchRect4;
  undefined4 scratchRect3;
  undefined4 scratchRect2;
  undefined4 scratchRect;
  undefined2 scratchRect31;
  undefined2 scratchRect30;
  undefined2 scratchRect29;
  undefined2 scratchRect13;
  
  scratchRect28 = 0;
  scratchRect26 = 0;
  scratchRect16 = 0;
  scratchRect23 = 0;
  scratchRect17 = 0;
  flagByte = false;
  scratchRect19 = 0;
  scratchRect18 = 0;
  g_Direct3DBackBufferPixelFormat = 1;
  _g_Direct3DTextureBlendModeMap = 0;
  _g_Direct3DFramebufferProbeFlags = 1;
  g_Direct3DDisableBlackTransparency = 2;
  _g_Direct3DProbePixelLayoutState = 3;
  CreateOrUploadDirect3DTexturePage(0,0);
  BeginDirect3DFrameAndClearBackBuffer(0);
  scratchRect12 = 0;
  scratchRect9 = 0;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0x101;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0x101;
  scratchRect2 = 0xffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x41200000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0x101;
  scratchRect = 0xffffffff;
  scratchRect13 = 0;
  QueueDirect3DTriangleDraw(&scratchRect12);
  scratchRect12 = 0;
  scratchRect9 = 0x41200000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0x101;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x41200000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0x101;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x41a00000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0x101;
  scratchRect = 0xffffffff;
  scratchRect13 = 0x800;
  QueueDirect3DTriangleDraw(&scratchRect12);
  scratchRect12 = 0;
  scratchRect9 = 0x41200000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0x101;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x41200000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0x101;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x41a00000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0x101;
  scratchRect = 0xffffffff;
  scratchRect13 = 0x800;
  QueueDirect3DTriangleDraw(&scratchRect12);
  scratchRect12 = 0;
  scratchRect9 = 0x41a00000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0x101;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x41a00000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0x101;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x41f00000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0x101;
  scratchRect = 0xffffffff;
  scratchRect13 = 0;
  QueueDirect3DTriangleDraw(&scratchRect12);
  scratchRect12 = 0;
  scratchRect9 = 0x41a00000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0x101;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x41a00000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0x101;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x41f00000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0x101;
  scratchRect = 0xffffffff;
  scratchRect13 = 0x1800;
  QueueDirect3DTriangleDraw(&scratchRect12);
  scratchRect12 = 0;
  scratchRect9 = 0x41f00000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0xfdfd;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x41f00000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0xfdfd;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x42200000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0xfdfd;
  scratchRect = 0xffffffff;
  scratchRect13 = 0;
  QueueDirect3DTriangleDraw(&scratchRect12);
  g_Direct3DModulatedColorLookupTable = (undefined *)&DAT_0053acf4;
  scratchRect12 = 0;
  scratchRect9 = 0x42200000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0xf5;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x42200000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0xaf5;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x42480000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0xff;
  scratchRect = 0xffffffff;
  scratchRect13 = 0x40;
  QueueDirect3DTriangleDraw(&scratchRect12);
  g_Direct3DModulatedColorLookupTable = (undefined *)&DAT_0053a808;
  scratchRect12 = 0;
  scratchRect9 = 0x42480000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0xf5;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x42480000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0xaf5;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x42700000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0xff;
  scratchRect = 0xffffffff;
  scratchRect13 = 0x40;
  QueueDirect3DTriangleDraw(&scratchRect12);
  scratchRect12 = 0;
  scratchRect9 = 0x42700000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0x101;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x42700000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0x101;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x428c0000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0x101;
  scratchRect = 0xffffffff;
  scratchRect13 = 0;
  QueueDirect3DTriangleDraw(&scratchRect12);
  scratchRect12 = 0;
  scratchRect9 = 0x42700000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0x101;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x42700000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0x101;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x428c0000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0x101;
  scratchRect = 0xffffffff;
  scratchRect13 = 0x1000;
  QueueDirect3DTriangleDraw(&scratchRect12);
  scratchRect12 = 0;
  scratchRect9 = 0x428c0000;
  scratchRect6 = 0x3f800000;
  scratchRect31 = 0x101;
  scratchRect3 = 0xffffffff;
  scratchRect11 = 0x41200000;
  scratchRect8 = 0x428c0000;
  scratchRect5 = 0x3f800000;
  scratchRect30 = 0x101;
  scratchRect2 = 0xffffffff;
  scratchRect10 = 0;
  scratchRect7 = 0x42a00000;
  scratchRect4 = 0x3f800000;
  scratchRect29 = 0x101;
  scratchRect = 0xffffffff;
  scratchRect13 = 0;
  QueueDirect3DTriangleDraw(&scratchRect12);
  FlushPendingDirect3DFrame();
  LockDirect3DFrameBuffer(0,&scratchRect28,&scratchRect26,&scratchRect16);
  if (scratchRect28 != 0) {
    directXResult = timeGetTime();
    value5 = timeGetTime();
    while ((value5 < directXResult + 500 &&
           (value3 = scratchRect26 / 2,
           (byte)((*(byte *)(scratchRect28 + 4 + value3 * 0x8e) & 0x1f) +
                  (*(byte *)(scratchRect28 + 2 + value3 * 0x8e) & 0x1f) +
                  (*(byte *)(scratchRect28 + 4 + value3 * 0x90) & 0x1f) +
                 (*(byte *)(scratchRect28 + 2 + value3 * 0x90) & 0x1f)) == '\0'))) {
      Sleep(10);
      value5 = timeGetTime();
    }
    value3 = scratchRect26 / 2;
    flagByte2 = (*(byte *)(scratchRect28 + 8 + value3 * 4) & 0x1f) +
            (*(byte *)(scratchRect28 + 6 + value3 * 4) & 0x1f) +
            (*(byte *)(scratchRect28 + 8 + value3 * 2) & 0x1f) +
            (*(byte *)(scratchRect28 + 6 + value3 * 2) & 0x1f);
    if (((byte)((*(byte *)(scratchRect28 + 4 + value3 * 4) & 0x1f) +
                (*(byte *)(scratchRect28 + 2 + value3 * 4) & 0x1f) +
                (*(byte *)(scratchRect28 + 4 + value3 * 2) & 0x1f) +
               (*(byte *)(scratchRect28 + 2 + value3 * 2) & 0x1f)) <= flagByte2) ||
       (scratchRect23 = 1,
       flagByte2 <= (byte)((*(byte *)(scratchRect28 + 0xc + value3 * 4) & 0x1f) +
                       (*(byte *)(scratchRect28 + 10 + value3 * 4) & 0x1f) +
                       (*(byte *)(scratchRect28 + 0xc + value3 * 2) & 0x1f) +
                      (*(byte *)(scratchRect28 + 10 + value3 * 2) & 0x1f)))) {
      scratchRect23 = 0;
    }
    scratchRect15 = value3 * 0x48;
    scratchRect14 = value3 * 0x47;
    flagByte2 = (*(byte *)(scratchRect28 + 2 + value3 * 0x90) & 0x1f) +
            (*(byte *)(scratchRect28 + 2 + value3 * 0x8e) & 0x1f) +
            (*(byte *)(scratchRect28 + 4 + value3 * 0x90) & 0x1f) +
            (*(byte *)(scratchRect28 + 4 + value3 * 0x8e) & 0x1f);
    scratchRect17 = (uint)(flagByte2 < (byte)((*(byte *)(scratchRect28 + 4 + value3 * 0x18) & 0x1f) +
                                     (*(byte *)(scratchRect28 + 2 + value3 * 0x18) & 0x1f) +
                                     (*(byte *)(scratchRect28 + 4 + value3 * 0x16) & 0x1f) +
                                    (*(byte *)(scratchRect28 + 2 + value3 * 0x16) & 0x1f)));
    scratchRect19 = (uint)((byte)((*(byte *)(scratchRect28 + 4 + value3 * 0x2a) & 0x1f) +
                             (*(byte *)(scratchRect28 + 2 + value3 * 0x2a) & 0x1f) +
                             (*(byte *)(scratchRect28 + 4 + value3 * 0x2c) & 0x1f) +
                            (*(byte *)(scratchRect28 + 2 + value3 * 0x2c) & 0x1f)) < flagByte2);
    scratchRect18 = (uint)((byte)((*(byte *)(scratchRect28 + 4 + value3 * 0x3e) & 0x1f) +
                             (*(byte *)(scratchRect28 + 2 + value3 * 0x3e) & 0x1f) +
                             (*(byte *)(scratchRect28 + 4 + value3 * 0x40) & 0x1f) +
                            (*(byte *)(scratchRect28 + 2 + value3 * 0x40) & 0x1f)) < 9);
    scratchRect24 = 0;
    scratchRect22 = 0;
    scratchRect20 = 0;
    do {
      value2 = 0;
      scratchRect21 = value3 * 10;
      scratchRect27 = (scratchRect20 + 0x28) * value3;
      value = (scratchRect20 + 0x29) * value3;
      do {
        value8 = *(byte *)(scratchRect28 + (scratchRect27 + value2) * 2) & 0x1f;
        value5 = value8 - (*(byte *)(scratchRect28 + (value2 + value) * 2) & 0x1f);
        value6 = (int)value5 >> 0x1f;
        value8 = value8 - (*(byte *)(scratchRect28 + 2 + (scratchRect27 + value2) * 2) & 0x1f);
        value7 = (int)value8 >> 0x1f;
        scratchRect24 = ((value8 ^ value7) - value7) + scratchRect24 + ((value5 ^ value6) - value6);
        value4 = scratchRect27 + scratchRect21 + value2;
        value8 = *(byte *)(scratchRect28 + value4 * 2) & 0x1f;
        value5 = value8 - (*(byte *)(scratchRect28 + (value2 + value + scratchRect21) * 2) & 0x1f);
        value6 = (int)value5 >> 0x1f;
        scratchRect25 = (value5 ^ value6) - value6;
        value8 = value8 - (*(byte *)(scratchRect28 + 2 + value4 * 2) & 0x1f);
        value5 = (int)value8 >> 0x1f;
        scratchRect22 = ((value8 ^ value5) - value5) + scratchRect22 + scratchRect25;
        value = value + scratchRect21 + value3 * -10;
        scratchRect27 = scratchRect27 + scratchRect21 + value3 * -10;
        value2 = value2 + 1;
      } while (value2 < 3);
      scratchRect20 = scratchRect20 + 1;
    } while (scratchRect20 < 3);
    g_Direct3DModulatedColorLookupTable = (undefined *)&DAT_0053acf4;
    if (scratchRect24 < scratchRect22) {
      g_Direct3DModulatedColorLookupTable = (undefined *)&DAT_0053a808;
    }
    flagByte = (byte)((*(byte *)(scratchRect28 + 4 + value3 * 0x7a) & 0x1f) +
                   (*(byte *)(scratchRect28 + 2 + value3 * 0x7a) & 0x1f) +
                   (*(byte *)(scratchRect28 + 4 + value3 * 0x7c) & 0x1f) +
                  (*(byte *)(scratchRect28 + 2 + value3 * 0x7c) & 0x1f)) <
            (byte)((*(byte *)(scratchRect28 + 2 + value3 * 0x90) & 0x1f) +
                   (*(byte *)(scratchRect28 + 2 + value3 * 0x8e) & 0x1f) +
                   (*(byte *)(scratchRect28 + 4 + value3 * 0x90) & 0x1f) +
                  (*(byte *)(scratchRect28 + 4 + value3 * 0x8e) & 0x1f));
  }
  UnlockDirect3DFrameBuffer();
  g_Direct3DBackBufferPixelFormat = scratchRect23;
  if (!flagByte) {
    g_Direct3DDisableBlackTransparency = 0;
  }
  if (scratchRect19 == 0) {
    _g_Direct3DProbePixelLayoutState = 0;
  }
  if ((scratchRect18 != 0) && (scratchRect17 != 0)) {
    return 1;
  }
  return 0;
}

