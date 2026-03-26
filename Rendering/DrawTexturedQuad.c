// Address: 0x004A9550

void DrawTexturedQuad(int param_1,int param_2,int param_3,int param_4,byte param_5,ushort param_6,
                     undefined2 param_7,undefined2 param_8,byte param_9,undefined4 param_10,
                     byte param_11,ushort param_12,byte param_13,byte param_14)

{
  float fVar1;
  int iVar2;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  undefined2 local_a;
  ushort local_8;
  ushort local_6;
  undefined4 local_4;
  
  if ((0 < param_3) && (0 < param_4)) {
    local_6 = param_12;
    local_24 = (float)param_12;
    local_3c = (float)param_1;
    local_30 = (float)param_2;
    local_4._0_2_ =
         param_9 & 0xff1f |
         (((short)(char)(param_14 & 1) | (short)(char)(param_11 & 3) << 5) << 1 |
         (short)(char)(param_13 & 1)) << 5;
    local_10 = param_10;
    local_14 = param_10;
    local_18 = param_10;
    local_c = (ushort)param_5 << 8 | param_6;
    local_38 = local_3c;
    local_34 = local_3c;
    local_2c = local_30;
    local_28 = local_30;
    local_20 = local_24;
    local_1c = local_24;
    local_a = local_c;
    local_8 = local_c;
    iVar2 = IsHardware3DGraphicsMode();
    fVar1 = (float)param_3;
    if (iVar2 == 0) {
      local_38 = fVar1 + local_38;
      local_a = param_7;
      local_8 = param_8;
      local_28 = (float)param_4;
      local_2c = local_28 + local_2c;
      local_4 = CONCAT22(local_4._2_2_,(ushort)local_4) & 0xfffffbff | 0x200;
      local_34 = fVar1;
      QueueRenderPacket(&local_3c);
      return;
    }
    local_38 = fVar1 + local_38;
    local_8 = CONCAT11(local_8._1_1_,(char)local_8 + (char)param_8);
    local_28 = (float)param_4 + local_28;
    local_a._1_1_ = local_a._1_1_ + (char)param_7;
    QueueRenderPacket(&local_3c);
    local_30 = local_28;
    local_3c = local_38;
    local_c = CONCAT11(local_a._1_1_,(char)local_8);
    QueueRenderPacket(&local_3c);
  }
  return;
}


