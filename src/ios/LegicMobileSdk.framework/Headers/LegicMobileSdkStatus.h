// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * Container for information about the result of a call that was processed in the SDK.
 */
NS_SWIFT_NAME(SdkStatus)
@interface LegicMobileSdkStatus : NSObject

//-----------------------------------------------------------------------------|

/**
 * This method returns the SDK error field of the current <code>LegicMobileSdkStatus</code>
 *
 * @return  Enum describing the error.
 * @see LegicMobileSdkError
 */
- (E_LegicMobileSdkErrorCode)getError
NS_SWIFT_NAME(getError());

//-----------------------------------------------------------------------------|

/**
 * This method returns a classification of the error status.
 *
 * @return  Enum describing the reason of the error.
 */
- (LegicMobileSdkErrorReason* _Nonnull const)getReason
NS_SWIFT_NAME(getReason());

//-----------------------------------------------------------------------------|

/**
 * Helper method to distinguish errors from OK status.
 *
 * @return  <li><code>true</code>  status represents a successful operation</li>
 *          <li><code>false</code> status represents an unsuccessful operation</li>
 */
- (BOOL)isSuccess
NS_SWIFT_NAME(isSuccess());

@end
