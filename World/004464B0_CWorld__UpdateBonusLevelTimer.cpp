#include "tarzan_ghidra_types.hpp"

// Address: 0x004464B0
// Label: CWorld::UpdateBonusLevelTimer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CWorld::UpdateBonusLevelTimer(void)

{
  uint value4;
  undefined2 *dataCursor;
  short shortValue;
  ushort *dataCursor2;
  byte flagByte;
  int value3;
  short *value8;
  uint value6;
  uint value7;
  int value;
  uint value5;
  int value2;
  int localState;
  
  if (g_HudCountdownScene != 0) {
    if ((g_GameplayRuntimeFlags & 0x800) == 0) {
      if ((g_HudCountdownFlags & 0x20) != 0) {
        value6 = (uint)(char)(g_HudCountdownBcdTime >> 8);
        value7 = value6 & 0x8000000f;
        if ((int)value7 < 0) {
          value7 = (value7 - 1 | 0xfffffff0) + 1;
        }
        value4 = (uint)(char)(g_HudCountdownBcdTime >> 0x10);
        value2 = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
        value6 = value4 & 0x8000000f;
        if ((int)value6 < 0) {
          value6 = (value6 - 1 | 0xfffffff0) + 1;
        }
        value3 = value6 + ((int)(value4 + ((int)value4 >> 0x1f & 0xfU)) >> 4) * 10;
        value6 = (uint)(char)g_HudCountdownBcdTime;
        value7 = value6 & 0x8000000f;
        if ((int)value7 < 0) {
          value7 = (value7 - 1 | 0xfffffff0) + 1;
        }
        value = value7 + 2 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
        if (g_BcdTimerTicksPerSecond < value) {
          value2 = value2 + 1;
          value = value - g_BcdTimerTicksPerSecond;
        }
        if (0x3b < value2) {
          value3 = value3 + 1;
          value2 = value2 + -0x3c;
        }
        if (0x3b < value3) {
          value3 = value3 + -0x3c;
        }
        g_HudCountdownBcdTime =
             ((char)((((char)(value3 / 10) + (char)(value3 >> 0x1f)) -
                     (char)((longlong)value3 * 0x66666667 >> 0x3f)) * '\x10' + (char)(value3 % 10)) *
              0x100 + (int)(char)((((char)(value2 / 10) + (char)(value2 >> 0x1f)) -
                                  (char)((longlong)value2 * 0x66666667 >> 0x3f)) * '\x10' +
                                 (char)(value2 % 10))) * 0x100 +
             (int)(char)((((char)(value / 10) + (char)(value >> 0x1f)) -
                         (char)((longlong)value * 0x66666667 >> 0x3f)) * '\x10' +
                        (char)(value % 10));
      }
      if ((g_HudCountdownFlags & 0x40) != 0) {
        value6 = (uint)(char)(g_HudCountdownBcdTime >> 8);
        value7 = value6 & 0x8000000f;
        if ((int)value7 < 0) {
          value7 = (value7 - 1 | 0xfffffff0) + 1;
        }
        value2 = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
        value6 = (uint)(char)(g_HudCountdownBcdTime >> 0x10);
        value7 = value6 & 0x8000000f;
        if ((int)value7 < 0) {
          value7 = (value7 - 1 | 0xfffffff0) + 1;
        }
        value4 = (uint)(char)g_HudCountdownBcdTime;
        value3 = value7 + ((int)(value6 + ((int)value6 >> 0x1f & 0xfU)) >> 4) * 10;
        value6 = value4 & 0x8000000f;
        if ((int)value6 < 0) {
          value6 = (value6 - 1 | 0xfffffff0) + 1;
        }
        value = (value6 - 2) + ((int)(value4 + ((int)value4 >> 0x1f & 0xfU)) >> 4) * 10;
        if (value < 0) {
          value2 = value2 + -1;
          value = value + g_BcdTimerTicksPerSecond;
        }
        if (value2 < 0) {
          value3 = value3 + -1;
          value2 = value2 + 0x3c;
        }
        if (value3 < 0) {
          value3 = value3 + 0x3c;
        }
        g_HudCountdownBcdTime =
             ((char)((((char)(value3 / 10) + (char)(value3 >> 0x1f)) -
                     (char)((longlong)value3 * 0x66666667 >> 0x3f)) * '\x10' + (char)(value3 % 10)) *
              0x100 + (int)(char)((((char)(value2 / 10) + (char)(value2 >> 0x1f)) -
                                  (char)((longlong)value2 * 0x66666667 >> 0x3f)) * '\x10' +
                                 (char)(value2 % 10))) * 0x100 +
             (int)(char)((((char)(value / 10) + (char)(value >> 0x1f)) -
                         (char)((longlong)value * 0x66666667 >> 0x3f)) * '\x10' +
                        (char)(value % 10));
      }
    }
    value6 = g_HudCountdownBcdTime;
    value7 = g_HudCountdownBcdTime >> 8;
    flagByte = (byte)g_HudCountdownFlags;
    if (((g_HudCountdownFlags & 0x100) != 0) && (value7 == 0)) {
      *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = (ushort)g_LevelTransitionRequestFlags | 0x8001;
      *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) = *( undefined1 *)((int)&g_PlayerSequenceFlags + 1) | 0x40;
      g_HudCountdownFlags = CONCAT22(*( undefined2 *)((int)&g_HudCountdownFlags + 2),0x8000);
      flagByte = 0;
      g_HudCountdownBcdTime = 0;
    }
    if ((flagByte & 0x80) != 0) {
      if (value7 < 6) {
        if ((g_BonusTimerHudDigits & 0xffff) != value7) {
          PlayAudioById(1099,(int *)0,(undefined4 *)0);
          g_BonusTimerHudDigits = CONCAT22(*( undefined2 *)((int)&g_BonusTimerHudDigits + 2),(short)(value6 >> 8));
          flagByte = (byte)g_HudCountdownFlags;
        }
      }
      else {
        g_BonusTimerHudDigits = CONCAT22(*( undefined2 *)((int)&g_BonusTimerHudDigits + 2),99);
      }
    }
    if ((flagByte & 0x10) != 0) {
      *(ushort *)(g_HudCountdownScene + 0xe) = *(ushort *)(g_HudCountdownScene + 0xe) & 0x7fff;
      flagByte = (byte)g_HudCountdownFlags;
      if ((g_HudCountdownFlags & 2) == 0) {
        *(ushort *)(g_HudCountdownScene + 0xe) =
             *(ushort *)(g_HudCountdownScene + 0xe) |
             (-(ushort)(0x1c < ((byte)g_HudCountdownBcdTime & 0x70)) & 0x8000) + 0x8000;
        flagByte = (byte)g_HudCountdownFlags;
      }
    }
    value4 = g_HudCountdownBcdTime;
    value6 = g_HudCountdownFlags & 4;
    value5 = -(uint)((g_HudCountdownFlags & 4) != 0) & 0xfffffffe;
    localState = value5 + 4;
    if (0 < localState) {
      value8 = &DAT_005328f8;
      do {
        shortValue = (short)(value7 & 0xf);
        if (9 < (value7 & 0xf)) {
          shortValue = 0;
        }
        *value8 = shortValue + 0x200f;
        value7 = value7 >> 4;
        value8 = value8 + 0x14;
        localState = localState + -1;
      } while (localState != 0);
    }
    if ((flagByte & 1) != 0) {
      value7 = (byte)~flagByte >> 1 & 1;
      value6 = (-(uint)(value6 != 0) & 0xff10f000) + 0xf00000;
      value2 = value5 + 3;
      if ((int)value7 < value2) {
        dataCursor2 = &g_HudCountdownFirstDigitFlags + value2 * 0x14;
        while ((value6 & value4) == 0) {
          *dataCursor2 = *dataCursor2 & 0x7fff;
          dataCursor2 = dataCursor2 + -0x14;
          value6 = value6 >> 4;
          value2 = value2 + -1;
          if (value2 <= (int)value7) {
            return;
          }
        }
        if ((int)value7 < value2) {
          value3 = value2 - value7;
          dataCursor = &g_HudCountdownFirstDigitFlags + value2 * 0x14;
          do {
            *(byte *)((int)dataCursor + 1) = *(byte *)((int)dataCursor + 1) | 0x80;
            dataCursor = dataCursor + -0x14;
            value3 = value3 + -1;
          } while (value3 != 0);
        }
      }
    }
  }
  return;
}

