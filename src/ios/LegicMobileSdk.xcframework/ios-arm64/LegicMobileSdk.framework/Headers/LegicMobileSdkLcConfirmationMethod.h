// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef E_LegicMobileSdkLcConfirmationMethod_h
#define E_LegicMobileSdkLcConfirmationMethod_h

/**
 * Enum value to define the required confirmation method in the initiateRegistrationWithBackend call.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkLcConfirmationMethod) {
    /**
     * Confirmation token is sent via email.
     * To be used when using an email address as public registration ID in the initiateRegistrationWithBackend call.
     */
    E_LegicMobileSdkLcConfirmationMethod_EMAIL = 0,
    
    /**
     * Confirmation token is sent via SMS.
     * To be used when using a phone number as public registration ID in the initiateRegistrationWithBackend call.
     */
    E_LegicMobileSdkLcConfirmationMethod_SMS = 1,
    
    /**
     * Confirmation token is NOT sent from LEGIC Connect.
     * To be used when using custom registration ID in the initiateRegistrationWithBackend call.
     */
    E_LegicMobileSdkLcConfirmationMethod_NONE = 2
    
} NS_SWIFT_NAME(LcConfirmationMethod);

#endif /* E_LegicMobileSdkConfirmationMethod_h */
