// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * Handles SDK related events
 */
NS_SWIFT_NAME(SdkEventDelegate)
@protocol LegicMobileSdkEventDelegate <LegicMobileSdkBaseEventDelegate>
@optional
/**
 * Callback is invoked when the SDK activates a service on any RF interface
 *
 * @param identifier    Identification of the activated service.
 *                    This is either a LC mobile app ID or a LC project ID depending on the LegicMobileSdkAddressingMode
 * @param mode                  Parameter that indicates whether the reported identifier is a LC Mobile App ID or a LC Project ID.
 * @param rfInterface   RF interface on which the service was activated.
 */
- (void)rfInterfaceActivatedEvent:(NSUInteger)identifier
                             mode:(E_LegicMobileSdkAddressingMode)mode
                      rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(rfInterfaceActivatedEvent(identifier:mode:rfInterface:));

/**
 * Callback is invoked when the SDK deactivates a service on any RF interface.
 *
 * @param identifier    Identification of the activated service.
 *                    This is either a LC mobile app ID or a LC project ID depending on the LegicMobileSdkAddressingMode
 * @param mode                  Indicates whether the reported identifier is a LC Mobile App ID or a LC Project ID.
 * @param rfInterface   RF interface on which the service was deactivated.
 */
- (void)rfInterfaceDeactivatedEvent:(NSUInteger)identifier
                               mode:(E_LegicMobileSdkAddressingMode)mode
                        rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(rfInterfaceDeactivatedEvent(identifier:mode:rfInterface:));

/**
 * Callback is invoked when the SDK detects changes on any RF interface.
 *
 * @note State changes can be triggered by different sources:
 * <ul>
 *      <li>By the SDK when activating/deactivating interfaces.</li>
 *      <li>By the phone user when enabling/disabling interfaces (operating system level).</li>
 * </ul>
 *
 * @param rfInterface    RF interface on which the state change was detected.
 * @param state                 New state of the reported RF interface.
 */
- (void)rfInterfaceChangeEvent:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
                         state:(E_LegicMobileSdkRfInterfaceState)state
NS_SWIFT_NAME(rfInterfaceChangeEvent(rfInterface:state:));

@end
