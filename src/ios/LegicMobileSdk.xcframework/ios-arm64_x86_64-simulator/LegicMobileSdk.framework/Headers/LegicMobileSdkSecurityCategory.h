// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef LegicMobileSdkSecurityCategory_h
#define LegicMobileSdkSecurityCategory_h

/**
 * Enum value to classify the type of security category of the SDK.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkSecurityCategory) {
    /**
     * The application was installed with an older SDK version that did not support security categories
     */
    E_LegicMobileSdkSecurityCategory_NONE = 0x0100,
    
    /**
     * The SDK runs in an operating system emulator
     */
    E_LegicMobileSdkSecurityCategory_NO_PROTECTION = 0x0200,
    
    /**
     * Initial parts of the encryption keys are stored in the source code
     */
    E_LegicMobileSdkSecurityCategory_SW_PROTECTION = 0x0300,
    
    /**
     * The random encryption keys are generated and stored in a trusted execution environment.
     * This is a protected section of the OS in the main processor (iOS Keychain).
     */
    E_LegicMobileSdkSecurityCategory_OS_PROTECTION = 0x0400,
    
    /**
     * The random encryption keys are generated and stored in a dedicated hardware keystore on the device (Secure Enclave).
     */
    E_LegicMobileSdkSecurityCategory_HW_PROTECTION = 0x0500
    
} NS_SWIFT_NAME(SecurityCategory);


#endif /* LegicMobileSdkSecurityCategory_h */
