// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef E_LegicMobileSdkAddressingMode_h
#define E_LegicMobileSdkAddressingMode_h

/**
 * Enum value to identify the addressing mode.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkAddressingMode) {
    /**
     * SDK exposes BLE services based on the LC Project IDs of the LEGIC neon files.
     */
    E_LegicMobileSdkAddressingMode_LC_PROJECT_ID = 0,
    
    /**
     * SDK exposes BLE services based on the configured LC Mobile App ID.
     */
    E_LegicMobileSdkAddressingMode_LC_MOBILE_APP_ID = 1
    
} NS_SWIFT_NAME(AddressingMode);

#endif /* E_LegicMobileSdkAddressingMode_h */
