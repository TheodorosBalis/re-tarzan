/* Address: 0x004B7987 */

void ConvertStringBuffersIfNeeded(void)

{
  if (DAT_00c4838c == 0) {
    StringConvertBuffersBigFunction(0xfffffffd);
    DAT_00c4838c = 1;
  }
  return;
}

