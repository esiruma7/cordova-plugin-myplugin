// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef LegicMobileSdkError_h
#define LegicMobileSdkError_h

#import <Foundation/Foundation.h>

/**
 * Information if any communication error occurred in the SDK
 */
NS_SWIFT_NAME(SdkError)
@interface LegicMobileSdkError : NSError

/**
 * Returns the status of the error
 *
 * @return The status, containing further information of the error
 */
- (LegicMobileSdkStatus* _Nonnull const)getStatus
NS_SWIFT_NAME(getStatus());

@end

#endif /* LegicMobileSdkError_h */
