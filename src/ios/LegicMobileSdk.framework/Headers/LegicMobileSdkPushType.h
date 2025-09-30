// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef E_LegicMobileSdkPushType_h
#define E_LegicMobileSdkPushType_h

/**
 * Enum value to classify the type of push token passed to the SDK.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkPushType) {
    /**
     * Push token of type APNS (Apple Push Notification Service)
     */
    E_LegicMobileSdkPushType_APNS = 0
    
} NS_SWIFT_NAME(PushType);

#endif /* E_LegicMobileSdkPushType_h */
