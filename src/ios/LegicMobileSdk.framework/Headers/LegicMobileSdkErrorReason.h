// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef E_LegicMobileSdkErrorReason_h
#define E_LegicMobileSdkErrorReason_h
/**
 * Types to specify SDK return values.
 */

/**
 * Enum value to classify the error type.
 * Used in LegicMobileSdkErrorReason.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkErrorReasonType) {
    /**
     * Signals success (no error)
     */
    E_LegicMobileSdkErrorReasonType_OK = 0,
    
    /**
     * An error occurred within the SDK
     */
    E_LegicMobileSdkErrorReasonType_SDK_ERROR = 1,
    
    /**
     * A HTTP related error occurred
     */
    E_LegicMobileSdkErrorReasonType_HTTP_ERROR = 2,
    
    /**
     * An error occurred within the used backend
     */
    E_LegicMobileSdkErrorReasonType_BACKEND_ERROR = 3
    
} NS_SWIFT_NAME(SdkErrorReasonType);

/**
 * Enum value to classify the specific SDK error.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkErrorReasonSdkError) {
    /**
     * Signals success (no error)
     */
    E_LegicMobileSdkErrorReasonSdkError_OK = 0,
    
    /**
     * An error occurred within the SDK
     */
    E_LegicMobileSdkErrorReasonSdkError_GENERAL_ERROR = 1,
    
    /**
     * SDK cannot handle the parameter
     */
    E_LegicMobileSdkErrorReasonSdkError_WRONG_PARAMETER = 2,
    
    /**
     * SDK has not been started with start()
     */
    E_LegicMobileSdkErrorReasonSdkError_NOT_STARTED = 5,
    
    /**
     * The LEGIC neon file was not found
     */
    E_LegicMobileSdkErrorReasonSdkError_NEON_FILE_NOT_FOUND = 10,
    
    /**
     * The LEGIC neon file has a wrong state for the current operation (e.g. not activated)
     */
    E_LegicMobileSdkErrorReasonSdkError_NEON_FILE_IN_WRONG_STATE = 11,
    
    /**
     * The RF interface is not registered for this LC Mobile App ID
     */
    E_LegicMobileSdkErrorReasonSdkError_RF_INTERFACE_NOT_REGISTERED = 20,
    
    /**
     * The RF interface is not active
     */
    E_LegicMobileSdkErrorReasonSdkError_RF_INTERFACE_NOT_ACTIVE = 21,
    
    /**
     * The RF interface is started too frequently
     */
    E_LegicMobileSdkErrorReasonSdkError_RF_INTERFACE_OVERLOAD = 22,
    
    /**
     * The RF interface has been disabled by the user
     */
    E_LegicMobileSdkErrorReasonSdkError_RF_INTERFACE_NOT_HW_ENABLED = 23,
    
    /**
     * The backend detected a configuration error
     */
    E_LegicMobileSdkErrorReasonSdkError_BACKEND_CONFIGURATION_ERROR = 30,
    
    /**
     * The backend had a communication error
     */
    E_LegicMobileSdkErrorReasonSdkError_BACKEND_COMMUNICATION_ERROR = 31,
    
    /**
     * The SDK is not registered to LEGIC Connect
     */
    E_LegicMobileSdkErrorReasonSdkError_SDK_NOT_REGISTERED = 40,
    
    /**
     * The SDK queue for LC message is full
     */
    E_LegicMobileSdkErrorReasonSdkError_LC_MESSAGE_QUEUE_FULL = 50,
    
    /**
     * The SDK queue for LC message for backend is full
     */
    E_LegicMobileSdkErrorReasonSdkError_LC_MESSAGE_QUEUE_FOR_BACKEND_FULL = 51,
    
    /**
     * The SDK queue for passwords is full
     */
    E_LegicMobileSdkErrorReasonSdkError_PASSWORD_QUEUE_FULL = 60,
    
    /**
     * The storage on the device is full
     */
    E_LegicMobileSdkErrorReasonSdkError_DEVICE_STORAGE_FULL = 70,
    
    /**
     * The connection could not be established, the connection attempt ran into a timeout
     */
    E_LegicMobileSdkErrorReasonSdkError_CONNECTION_FAILED_TIMEOUT = 80,
    
    /**
     * The connection could not be established, the app aborted the connection attempt
     */
    E_LegicMobileSdkErrorReasonSdkError_CONNECTION_FAILED_ABORTED_BY_APP = 81,

    /**
     * The reader found report is not valid
     */
    E_LegicMobileSdkErrorReasonSdkError_READER_FOUND_REPORT_INVALID = 90
    
    
} NS_SWIFT_NAME(SdkErrorReasonSdkError);

/**
 * Reason why an error occured.
 */
NS_SWIFT_NAME(SdkErrorReason)
@interface LegicMobileSdkErrorReason : NSObject

/**
 * This method returns the type of the error as enum.
 *
 * @return Enum describing the error reason.
 */
- (E_LegicMobileSdkErrorReasonType)getReasonType
NS_SWIFT_NAME(getReasonType());

/**
 * This method returns the actual error code as integer.
 * The error code needs to be handled depending on the type of the error.
 *
 * @return Error code as integer. Errors can be SDK error, HTTP error codes or LEGIC Connect error codes.
 */
- (NSInteger)getErrorCode
NS_SWIFT_NAME(getErrorCode());

/**
 * This helper functions tries to resolve the error code as LegicMobileSdkErrorReasonSdkError code enum
 *
 * @return SdkError enum or GENERAL_ERROR if error reason is not SDK_ERROR
 */
- (E_LegicMobileSdkErrorReasonSdkError)getSdkErrorCode
NS_SWIFT_NAME(getSdkErrorCode());

/**
 * This method provides further information about the error.
 *
 * @return Description of the error as String
 */
- (NSString* _Nonnull const)getErrorDescription
NS_SWIFT_NAME(getErrorDescription());

@end


#endif /* E_LegicMobileSdkErrorReason_h */
