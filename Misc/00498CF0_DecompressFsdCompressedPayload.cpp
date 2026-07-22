#include "tarzan_ghidra_types.hpp"

// Address: 0x00498CF0
// Label: DecompressFsdCompressedPayload
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DecompressFsdCompressedPayload(uint *arg1)

{
  ushort value3;
  uint value4;
  uint value5;
  uint value6;
  uint value7;
  int value;
  sbyte shortValue;
  int value2;
  uint scratchBuffer14;
  uint scratchBuffer13;
  uint scratchBuffer12;
  uint *scratchBuffer11;
  char *scratchBuffer10;
  uint scratchBuffer9;
  ushort scratchBuffer8 [1536];
  uint scratchBuffer7 [287];
  uint *scratchBuffer6;
  ushort *scratchBuffer5;
  uint scratchBuffer4;
  byte scratchBuffer [1024];
  uint scratchBuffer25;
  int scratchBuffer24;
  ushort *scratchBuffer23;
  uint scratchBuffer22;
  uint scratchBuffer21 [33];
  uint scratchBuffer20;
  int scratchBuffer19;
  uint scratchBuffer3 [287];
  char *scratchBuffer17;
  uint scratchBuffer16;
  ushort scratchBuffer15 [768];
  uint scratchBuffer2 [287];
  uint scratchBuffer18;
  
  SafeCheckStackPtr();
  value4 = arg1[1];
  scratchBuffer6 = (uint *)(value4 + 0xc);
  value7 = *arg1;
  if ((value7 <= value4 + 0xb + arg1[2]) && (value4 + 0xb + arg1[2] <= (value7 - 1) + arg1[3]))
  {
    value5 = arg1[3];
    value6 = arg1[2];
    scratchBuffer13 = 0;
    do {
      *(undefined1 *)(((value7 + value5) - value6) + scratchBuffer13) =
           *(undefined1 *)((int)(value4 + 0xc) + scratchBuffer13);
      scratchBuffer13 = scratchBuffer13 + 1;
    } while (scratchBuffer13 < arg1[2]);
    scratchBuffer6 = (uint *)((value7 + arg1[3]) - arg1[2]);
  }
  scratchBuffer25 = *scratchBuffer6;
  scratchBuffer24 = 0x20;
  scratchBuffer11 = scratchBuffer6 + 2;
  scratchBuffer4 = scratchBuffer6[1];
  scratchBuffer17 = (char *)*arg1;
  scratchBuffer22 = 0;
  do {
    value4 = scratchBuffer4;
    value2 = scratchBuffer24 + -1;
    if (value2 < 0) {
      scratchBuffer4 = *scratchBuffer11;
      scratchBuffer11 = scratchBuffer11 + 1;
      value7 = value4 >> (-(char)value2 & 0x1fU);
      scratchBuffer24 = scratchBuffer24 + 0x1f;
      scratchBuffer16 = scratchBuffer25 + (value4 << ((char)value2 + 1U & 0x1f));
    }
    else {
      value7 = scratchBuffer25 >> 1;
      scratchBuffer24 = value2;
      scratchBuffer16 = scratchBuffer25;
    }
    scratchBuffer25 = value7;
    value4 = scratchBuffer4;
    scratchBuffer16 = scratchBuffer16 & 1;
    if (scratchBuffer16 == 0) {
      value2 = scratchBuffer24 + -0xf;
      if (value2 < 0) {
        scratchBuffer4 = *scratchBuffer11;
        scratchBuffer11 = scratchBuffer11 + 1;
        value7 = scratchBuffer25 + (value4 << ((char)value2 + 0xfU & 0x1f));
        scratchBuffer25 = value4 >> (-(char)value2 & 0x1fU);
        scratchBuffer13 = value7 & 0x7fff;
        scratchBuffer24 = scratchBuffer24 + 0x11;
      }
      else {
        scratchBuffer13 = scratchBuffer25 & 0x7fff;
        scratchBuffer25 = scratchBuffer25 >> 0xf;
        scratchBuffer24 = value2;
      }
      while (value4 = scratchBuffer4, scratchBuffer13 != 0) {
        value2 = scratchBuffer24 + -8;
        *( undefined1 *)((int)&scratchBuffer16 + 0) = (char)scratchBuffer25;
        if (value2 < 0) {
          scratchBuffer4 = *scratchBuffer11;
          scratchBuffer11 = scratchBuffer11 + 1;
          *( undefined1 *)((int)&scratchBuffer16 + 0) = (char)scratchBuffer16 + (char)(value4 << ((char)value2 + 8U & 0x1f));
          scratchBuffer25 = value4 >> (-(char)value2 & 0x1fU);
          scratchBuffer24 = scratchBuffer24 + 0x18;
        }
        else {
          scratchBuffer25 = scratchBuffer25 >> 8;
          scratchBuffer24 = value2;
        }
        *scratchBuffer17 = (char)scratchBuffer16;
        scratchBuffer17 = scratchBuffer17 + 1;
        scratchBuffer13 = scratchBuffer13 - 1;
      }
    }
    else {
      scratchBuffer19 = 1;
      do {
        value = scratchBuffer19;
        value2 = scratchBuffer24;
        value4 = scratchBuffer4;
        scratchBuffer5 = scratchBuffer15;
        scratchBuffer14 = 8;
        scratchBuffer19 = scratchBuffer19 + -1;
        if (value != 0) {
          scratchBuffer5 = scratchBuffer8;
          scratchBuffer14 = 10;
        }
        scratchBuffer24 = scratchBuffer24 + -9;
        if (scratchBuffer24 < 0) {
          scratchBuffer4 = *scratchBuffer11;
          scratchBuffer11 = scratchBuffer11 + 1;
          scratchBuffer16 = scratchBuffer25 + (value4 << ((char)scratchBuffer24 + 9U & 0x1f)) & 0x1ff;
          scratchBuffer25 = value4 >> (-(char)scratchBuffer24 & 0x1fU);
          scratchBuffer24 = value2 + 0x17;
        }
        else {
          scratchBuffer16 = scratchBuffer25 & 0x1ff;
          scratchBuffer25 = scratchBuffer25 >> 9;
        }
        value4 = scratchBuffer16;
        if (scratchBuffer16 != 0) {
          scratchBuffer6 = (uint *)0x1;
          do {
            scratchBuffer21[(int)scratchBuffer6] = 0;
            scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1);
          } while (scratchBuffer6 < 0x21);
          scratchBuffer6 = (uint *)0x0;
          do {
            value2 = scratchBuffer24;
            value7 = scratchBuffer4;
            scratchBuffer24 = scratchBuffer24 + -1;
            if (scratchBuffer24 < 0) {
              scratchBuffer4 = *scratchBuffer11;
              scratchBuffer11 = scratchBuffer11 + 1;
              scratchBuffer16 = scratchBuffer25 + (value7 << ((char)scratchBuffer24 + 1U & 0x1f)) & 1;
              scratchBuffer25 = value7 >> (-(char)scratchBuffer24 & 0x1fU);
              scratchBuffer24 = value2 + 0x1f;
            }
            else {
              scratchBuffer16 = scratchBuffer25 & 1;
              scratchBuffer25 = scratchBuffer25 >> 1;
            }
            value2 = scratchBuffer24;
            value7 = scratchBuffer4;
            if (scratchBuffer16 == 1) {
              scratchBuffer24 = scratchBuffer24 + -4;
              if (scratchBuffer24 < 0) {
                scratchBuffer4 = *scratchBuffer11;
                scratchBuffer11 = scratchBuffer11 + 1;
                scratchBuffer22 = scratchBuffer25 + (value7 << ((char)scratchBuffer24 + 4U & 0x1f)) & 0xf;
                scratchBuffer25 = value7 >> (-(char)scratchBuffer24 & 0x1fU);
                scratchBuffer24 = value2 + 0x1c;
              }
              else {
                scratchBuffer22 = scratchBuffer25 & 0xf;
                scratchBuffer25 = scratchBuffer25 >> 4;
              }
            }
            scratchBuffer7[(int)scratchBuffer6] = scratchBuffer22;
            scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1);
            scratchBuffer21[scratchBuffer22] = scratchBuffer21[scratchBuffer22] + 1;
          } while (scratchBuffer6 < value4);
          scratchBuffer21[0] = 0;
          value2 = 0;
          for (scratchBuffer6 = (uint *)0x1; scratchBuffer6 < 0x10;
              scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1)) {
            for (scratchBuffer9 = 0; scratchBuffer9 < value4; scratchBuffer9 = scratchBuffer9 + 1) {
              if ((uint *)scratchBuffer7[scratchBuffer9] == scratchBuffer6) {
                scratchBuffer3[value2] = scratchBuffer9;
                value2 = value2 + 1;
              }
            }
          }
          value2 = 0;
          for (scratchBuffer13 = 1; scratchBuffer13 < 0x10; scratchBuffer13 = scratchBuffer13 + 1) {
            for (scratchBuffer6 = (uint *)0x1; scratchBuffer6 <= scratchBuffer21[scratchBuffer13];
                scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1)) {
              scratchBuffer7[value2] = scratchBuffer13;
              value2 = value2 + 1;
            }
          }
          scratchBuffer7[value2] = 0;
          scratchBuffer6 = (uint *)0x0;
          scratchBuffer12 = scratchBuffer7[0];
          value2 = 0;
          while (scratchBuffer7[value2] != 0) {
            for (; scratchBuffer7[value2] == scratchBuffer12; value2 = value2 + 1) {
              scratchBuffer9 = (uint)scratchBuffer6 | 1 << ((byte)scratchBuffer12 & 0x1f);
              scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1);
              scratchBuffer2[value2] = 0;
              do {
                scratchBuffer2[value2] = (scratchBuffer9 & 1) + scratchBuffer2[value2] * 2;
                scratchBuffer9 = scratchBuffer9 >> 1;
              } while (scratchBuffer9 != 1);
            }
            scratchBuffer6 = (uint *)((int)scratchBuffer6 << 1);
            scratchBuffer12 = scratchBuffer12 + 1;
          }
          scratchBuffer6 = (uint *)0x0;
          do {
            scratchBuffer[(int)scratchBuffer6] = 0;
            scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1);
            shortValue = (sbyte)scratchBuffer14;
          } while (scratchBuffer6 < (uint)(1 << shortValue));
          value2 = 0;
          for (scratchBuffer13 = 1; value = value2, scratchBuffer13 < scratchBuffer14; scratchBuffer13 = scratchBuffer13 + 1)
          {
            for (scratchBuffer6 = (uint *)0x1; scratchBuffer6 <= scratchBuffer21[scratchBuffer13];
                scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1)) {
              scratchBuffer16 = scratchBuffer2[value2];
              do {
                scratchBuffer5[scratchBuffer16] = (short)(scratchBuffer3[value2] << 7) + (short)scratchBuffer13;
                scratchBuffer16 = scratchBuffer16 + (1 << ((byte)scratchBuffer13 & 0x1f));
              } while (scratchBuffer16 < (uint)(1 << shortValue));
              value2 = value2 + 1;
            }
          }
          for (; scratchBuffer13 < 0x10; scratchBuffer13 = scratchBuffer13 + 1) {
            for (scratchBuffer6 = (uint *)0x1; scratchBuffer6 <= scratchBuffer21[scratchBuffer13];
                scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1)) {
              scratchBuffer16 = scratchBuffer2[value];
              if ((uint)scratchBuffer[scratchBuffer16 & (1 << shortValue) - 1U] < scratchBuffer7[value]) {
                *( undefined1 *)((int)&scratchBuffer9 + 0) = (byte)scratchBuffer7[value];
                scratchBuffer[scratchBuffer16 & (1 << shortValue) - 1U] = (byte)scratchBuffer9;
              }
              value = value + 1;
            }
          }
          scratchBuffer16 = 0;
          scratchBuffer6 = (uint *)0x0;
          do {
            if (scratchBuffer[(int)scratchBuffer6] != 0) {
              if (7 < scratchBuffer[(int)scratchBuffer6] - scratchBuffer14) {
                arg1[7] = 0xfffffff7;
                return;
              }
              scratchBuffer5[(int)scratchBuffer6] =
                   (short)(scratchBuffer16 << 7) +
                   ((ushort)scratchBuffer[(int)scratchBuffer6] - (short)scratchBuffer14) * 0x10;
              scratchBuffer16 = scratchBuffer16 + (1 << (scratchBuffer[(int)scratchBuffer6] - shortValue & 0x1f));
            }
            scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1);
          } while (scratchBuffer6 < (uint)(1 << shortValue));
          if (0x1ff < scratchBuffer16) {
            arg1[7] = 0xfffffff7;
            return;
          }
          for (scratchBuffer13 = scratchBuffer14; scratchBuffer13 < 0x10; scratchBuffer13 = scratchBuffer13 + 1) {
            for (scratchBuffer6 = (uint *)0x1; scratchBuffer6 <= scratchBuffer21[scratchBuffer13];
                scratchBuffer6 = (uint *)((int)scratchBuffer6 + 1)) {
              value4 = scratchBuffer2[value2];
              value3 = scratchBuffer5[value4 & (1 << shortValue) - 1U];
              scratchBuffer23 = scratchBuffer5 + ((int)(uint)value3 >> 7) + (1 << shortValue);
              scratchBuffer9 = value4 >> shortValue;
              scratchBuffer16 = (int)(uint)scratchBuffer5[value4 & (1 << shortValue) - 1U] >> 4 & 7;
              do {
                (scratchBuffer5 + ((int)(uint)value3 >> 7) + (1 << shortValue))[scratchBuffer9] =
                     (short)(scratchBuffer3[value2] << 7) + (short)scratchBuffer7[value2];
                scratchBuffer9 = scratchBuffer9 + (1 << ((char)scratchBuffer7[value2] - shortValue & 0x1fU));
              } while (scratchBuffer9 < (uint)(1 << (sbyte)scratchBuffer16));
              value2 = value2 + 1;
            }
          }
        }
      } while (-1 < scratchBuffer19);
      while( true ) {
        while( true ) {
          value4 = scratchBuffer4;
          if (scratchBuffer24 < 0xf) {
            scratchBuffer20 = scratchBuffer25 + (scratchBuffer4 << ((byte)scratchBuffer24 & 0x1f));
          }
          else {
            scratchBuffer20 = scratchBuffer25;
          }
          value3 = scratchBuffer8[scratchBuffer20 & 0x3ff];
          if ((value3 & 0xf) == 0) {
            value3 = scratchBuffer8
                    [(value3 >> 7) + 0x400 + (scratchBuffer20 >> 10 & (1 << ((byte)(value3 >> 4) & 7)) - 1U)
                    ];
          }
          scratchBuffer13 = (uint)value3;
          scratchBuffer24 = scratchBuffer24 - (scratchBuffer13 & 0xf);
          if (scratchBuffer24 < 0) {
            scratchBuffer4 = *scratchBuffer11;
            scratchBuffer11 = scratchBuffer11 + 1;
            scratchBuffer25 = value4 >> (-(char)scratchBuffer24 & 0x1fU);
            scratchBuffer24 = scratchBuffer24 + 0x20;
          }
          else {
            scratchBuffer25 = scratchBuffer25 >> ((byte)value3 & 0xf);
          }
          value4 = scratchBuffer4;
          value7 = (uint)(value3 >> 7);
          if (0xff < value7) break;
          *( undefined1 *)((int)&scratchBuffer13 + 0) = (char)(value3 >> 7);
          *scratchBuffer17 = (char)scratchBuffer13;
          scratchBuffer17 = scratchBuffer17 + 1;
        }
        if (value7 == 0x100) break;
        scratchBuffer16 = 0;
        if ((&g_FsdCopyWindowBuffer)[value7] != '\0') {
          scratchBuffer24 = scratchBuffer24 - (uint)(byte)(&g_FsdCopyWindowBuffer)[value7];
          if (scratchBuffer24 < 0) {
            scratchBuffer4 = *scratchBuffer11;
            scratchBuffer11 = scratchBuffer11 + 1;
            scratchBuffer16 = scratchBuffer25 +
                        (value4 << ((char)scratchBuffer24 + (&g_FsdCopyWindowBuffer)[value7] & 0x1fU)) &
                        (1 << ((&g_FsdCopyWindowBuffer)[value7] & 0x1f)) - 1U;
            scratchBuffer25 = value4 >> (-(char)scratchBuffer24 & 0x1fU);
            scratchBuffer24 = scratchBuffer24 + 0x20;
          }
          else {
            scratchBuffer16 = scratchBuffer25 & (1 << ((&g_FsdCopyWindowBuffer)[value7] & 0x1f)) - 1U;
            scratchBuffer25 = scratchBuffer25 >> ((&g_FsdCopyWindowBuffer)[value7] & 0x1f);
          }
        }
        value4 = scratchBuffer4;
        scratchBuffer13 = (byte)(&g_FsdDecompressFlagByte)[value7] + 3 + scratchBuffer16;
        if (scratchBuffer24 < 0xf) {
          scratchBuffer20 = scratchBuffer25 + (scratchBuffer4 << ((byte)scratchBuffer24 & 0x1f));
        }
        else {
          scratchBuffer20 = scratchBuffer25;
        }
        value3 = scratchBuffer15[scratchBuffer20 & 0xff];
        scratchBuffer18 = (uint)value3;
        if ((value3 & 0xf) == 0) {
          scratchBuffer18 = (uint)scratchBuffer15[(value3 >> 7) + 0x100 +
                                    (scratchBuffer20 >> 8 & (1 << ((byte)(value3 >> 4) & 7)) - 1U)];
        }
        scratchBuffer24 = scratchBuffer24 - (scratchBuffer18 & 0xf);
        if (scratchBuffer24 < 0) {
          scratchBuffer4 = *scratchBuffer11;
          scratchBuffer11 = scratchBuffer11 + 1;
          scratchBuffer25 = value4 >> (-(char)scratchBuffer24 & 0x1fU);
          scratchBuffer24 = scratchBuffer24 + 0x20;
        }
        else {
          scratchBuffer25 = scratchBuffer25 >> ((byte)scratchBuffer18 & 0xf);
        }
        value4 = scratchBuffer4;
        scratchBuffer18 = scratchBuffer18 >> 7;
        scratchBuffer16 = 0;
        if ((&g_FsdDecompressScratchBuffer)[scratchBuffer18] != '\0') {
          scratchBuffer24 = scratchBuffer24 - (char)(&g_FsdDecompressScratchBuffer)[scratchBuffer18];
          if (scratchBuffer24 < 0) {
            scratchBuffer4 = *scratchBuffer11;
            scratchBuffer11 = scratchBuffer11 + 1;
            scratchBuffer16 = scratchBuffer25 +
                        (value4 << ((char)scratchBuffer24 + (&g_FsdDecompressScratchBuffer)[scratchBuffer18] &
                                  0x1fU)) &
                        (1 << ((&g_FsdDecompressScratchBuffer)[scratchBuffer18] & 0x1f)) - 1U;
            scratchBuffer25 = value4 >> (-(char)scratchBuffer24 & 0x1fU);
            scratchBuffer24 = scratchBuffer24 + 0x20;
          }
          else {
            scratchBuffer16 = scratchBuffer25 & (1 << ((&g_FsdDecompressScratchBuffer)[scratchBuffer18] & 0x1f)) - 1U;
            scratchBuffer25 = scratchBuffer25 >> ((&g_FsdDecompressScratchBuffer)[scratchBuffer18] & 0x1f);
          }
        }
        scratchBuffer18 = *(ushort *)(&g_FsdDecompressOutputByte + scratchBuffer18 * 2) + scratchBuffer16;
        scratchBuffer10 = scratchBuffer17 + (-1 - scratchBuffer18);
        if (scratchBuffer18 == 0) {
          do {
            *scratchBuffer17 = *scratchBuffer10;
            scratchBuffer17 = scratchBuffer17 + 1;
            scratchBuffer13 = scratchBuffer13 + -1;
          } while (scratchBuffer13 != 0);
        }
        else {
          do {
            *scratchBuffer17 = *scratchBuffer10;
            scratchBuffer17 = scratchBuffer17 + 1;
            scratchBuffer10 = scratchBuffer10 + 1;
            scratchBuffer13 = scratchBuffer13 + -1;
          } while (scratchBuffer13 != 0);
        }
      }
    }
    value4 = scratchBuffer4;
    value2 = scratchBuffer24 + -1;
    if (value2 < 0) {
      scratchBuffer4 = *scratchBuffer11;
      scratchBuffer11 = scratchBuffer11 + 1;
      value7 = value4 >> (-(char)value2 & 0x1fU);
      scratchBuffer24 = scratchBuffer24 + 0x1f;
      scratchBuffer16 = scratchBuffer25 + (value4 << ((char)value2 + 1U & 0x1f));
    }
    else {
      value7 = scratchBuffer25 >> 1;
      scratchBuffer24 = value2;
      scratchBuffer16 = scratchBuffer25;
    }
    scratchBuffer25 = value7;
    scratchBuffer16 = scratchBuffer16 & 1;
    if (scratchBuffer16 != 0) {
      return;
    }
  } while( true );
}

