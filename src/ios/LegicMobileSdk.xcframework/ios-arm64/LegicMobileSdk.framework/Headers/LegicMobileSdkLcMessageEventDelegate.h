// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * Handles LC message related events
 */
NS_SWIFT_NAME(LcMessageEventDelegate)
@protocol LegicMobileSdkLcMessageEventDelegate <LegicMobileSdkBaseEventDelegate>
@optional
/**
 * Callback is invoked when the LEGIC reader chip sends a regular LC_MESSAGE command to the mobile app.
 *
 * @note Please note:
 * <ul>
 *      <li>The received data can be arbitrary formatted as this is a contract between
 *      the host system (connected to the reader) and the mobile application.</li>
 *      <li>The data is transported as-is, no validation takes place.</li>
 * </ul>
 *
 * @param data                   Data that was sent within the LC_MESSAGE command
 * @param mode                   Mode used to transmit the LC_MESSAGE command
 * @param rfInterface   RF interface on which the LC_MESSAGE command was received
 */
- (void)readerLcMessageEvent:(NSData* _Nonnull const)data
                        mode:(E_LegicMobileSdkLcMessageMode)mode
                 rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerLcMessageEvent(data:mode:rfInterface:));

/**
 * Callback is invoked when the LEGIC reader chip polls for responses to its last LC_MESSAGE command.
 *
 * @param mode                   Mode used to transmit the LC_MESSAGE command
 * @param rfInterface   RF interface on which the LC_MESSAGE command was received
 */
- (void)readerLcMessagePollingEvent:(E_LegicMobileSdkLcMessageMode)mode
                        rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerLcMessagePollingEvent(mode:rfInterface:));

/**
 * Callback is invoked when the SDK has stored a complete message received from the LEGIC reader chip.
 *
 * @param messageCount  Number of stored messages in the buffer
 * @param rfInterface    RF interface on which the LC_MESSAGE command was received
 */
- (void)readerAddedLcMessageEvent:(NSUInteger)messageCount
                      rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerAddedLcMessageEvent(messageCount:rfInterface:));

/**
 * Callback is invoked when the LEGIC reader chip requests a password entry via an LC_MESSAGE command.
 *
 * @note Please note:
 * <ul>
 *      <li>The received data can be arbitrary formatted as this is a contract between
 *      the host system (connected to the reader) and the mobile application.</li>
 *      <li>The data is transported as-is, no validation takes place.</li>
 * </ul>
 *
 * @param data                  Data sent within the LC_MESSAGE command
 * @param rfInterface   RF interface on which the LC_MESSAGE command was received
 */
- (void)readerPasswordRequestEvent:(NSData* _Nullable const)data
                       rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerPasswordRequestEvent(data:rfInterface:));

@end
