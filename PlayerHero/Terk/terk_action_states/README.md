# Terk Action States

Generated from `0050C148 g_TerkActionStateHandlerTable`. `CPlayerHero::UpdateTerk` dispatches the update column at `0050C14C`.

Each state has a readable hex-numbered folder with `enter` and `update` decompiled C files. Shared handlers are copied into every state folder that uses them.

## Dispatcher
- `UpdateTerk - 0x00476A70.c`

## States
- 0x00: TerkIdle
- 0x01: TerkMoveForward
- 0x02: TerkStopForwardMovement
- 0x03: TerkTurnAround
- 0x04: TerkAirborneMovement
- 0x05: TerkMovingJump
- 0x06: TerkStandingJump
- 0x07: TerkBounce
- 0x08: TerkAirborneDamage
- 0x09: TerkLongJump
- 0x0A: TerkFalling
- 0x0B: TerkFalling
- 0x0C: TerkLandingRecovery
- 0x0D: TerkBlock
- 0x0E: TerkSoftGroundDamage
- 0x0F: TerkGroundDamage
- 0x10: TerkEdgeBalance
- 0x11: TerkCrouch
- 0x12: TerkCrouchLook
- 0x13: TerkPound
- 0x14: TerkClimbableSurfaceGrab
- 0x15: TerkClimbableSurfaceHang
- 0x16: TerkClimbableSurfacePullUp
- 0x17: TerkClimbableSurfaceHopOff
- 0x18: TerkClimbableWallGrab
- 0x19: TerkClimbableWallIdle
- 0x1A: TerkClimbableWallMoveUp
- 0x1B: TerkClimbableWallMoveDown
- 0x1C: TerkClimbableWallJumpOff
- 0x1D: TerkClimbableWallTopOut
- 0x1E: TerkClimbableFall

