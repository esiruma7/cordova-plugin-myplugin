// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef E_LegicMobileSdkError_h
#define E_LegicMobileSdkError_h

/**
 * Enum value to identify the error status.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkErrorCode) {
    /**
     * Signals success (no error)
     */
    E_LegicMobileSdkErrorCode_OK = 0,
    
    /**
     * This status is returned whenever no specific status code is available
     */
    E_LegicMobileSdkErrorCode_GENERAL_ERROR = 1,
    
    
    // Registration related errors
    /**
     * Call <code>initiateRegistrationWithBackend</code> or <code>registerWithBackendRegistrationCode</code> was not completed successfully
     */
    E_LegicMobileSdkErrorCode_REGISTRATION_WITH_BACKEND_FAILED = 10,
    
    /**
     * Call <code>unregisterWithBackend</code> was not completed successfully
     */
    E_LegicMobileSdkErrorCode_UNREGISTER_WITH_BACKEND_FAILED = 11,
    
    
    // File related errors
    /**
     * Call <code>requestAddNeonFile</code> was not completed successfully
     */
    E_LegicMobileSdkErrorCode_REQUEST_ADD_NEON_FILE_FAILED = 31,
    
    /**
     * Call <code>requestRemoveNeonFile</code> was not completed successfully
     */
    E_LegicMobileSdkErrorCode_REQUEST_REMOVE_NEON_FILE_FAILED = 32,
    
    /**
     * Call <code>synchronizeWithBackend</code> was not completed successfully
     */
    E_LegicMobileSdkErrorCode_SYNCHRONIZE_WITH_BACKEND_FAILED = 33,
    
    /**
     * LEGIC neon file could not be activated / deactivated
     */
    E_LegicMobileSdkErrorCode_SET_NEON_FILE_ACTIVE_FAILED = 34,
    
    
    // Interface related errors
    /**
     * RF interface could not be activated / deactivated
     */
    E_LegicMobileSdkErrorCode_SET_RF_INTERFACE_ACTIVE_FAILED = 50,
    
    /**
     * Connection to LEGIC reader chip could not be established
     */
    E_LegicMobileSdkErrorCode_CONNECT_TO_READER_FAILED = 60,
    
    // Message or Password related errors
    /**
     * LC message could not be sent to the LEGIC reader chip
     */
    E_LegicMobileSdkErrorCode_LC_MESSAGE_SEND_FAILED = 70,
    
    /**
     * Password could not be sent to the LEGIC reader chip
     */
    E_LegicMobileSdkErrorCode_PASSWORD_SEND_FAILED = 71,
    
    /**
     * LC Message for backend could not be stored
     */
    E_LegicMobileSdkErrorCode_LC_MESSAGE_TO_BACKEND_FAILED = 72,
    
} NS_SWIFT_NAME(SdkErrorCode);


#endif /* E_LegicMobileSdkError_h */
