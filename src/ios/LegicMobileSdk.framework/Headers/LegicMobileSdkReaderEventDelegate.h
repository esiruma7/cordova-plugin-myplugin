// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * Handles reader related events
 */
NS_SWIFT_NAME(ReaderEventDelegate)
@protocol LegicMobileSdkReaderEventDelegate <LegicMobileSdkBaseEventDelegate>
@optional
/**
 * Callback is invoked when the LEGIC reader chip has established a connection with a mobile app.
 *
 * @note The use of this callback is blocking! Keep any interaction with this callback as
 * short as possible to minimize communication time and current consumption.
 * If the mobile app does not return within 1 second, the connection to the LEGIC reader chip will be lost.
 *
 * @param identifier    Identifier that was used to connect to the mobile app
 * @param mode                  Mode to distinguish whether identifier is a LC Project ID or a LC Mobile App ID
 * @param readerType    Type of LEGIC reader chip connecting to the mobile app
 *                    Current values:
 *                    <li><code>1</code> SM-4300 or SM-4200</li>
 *                    <li><code>3</code> SM-6300 or SM-6310</li>
 * @param readerUuid     Unique identifier of LEGIC reader chip
 * @param rfInterface   RF interface used to connect to mobile app
 */
- (void)readerConnectEvent:(NSUInteger)identifier
                      mode:(E_LegicMobileSdkAddressingMode)mode
                readerType:(NSUInteger)readerType
                readerUuid:(NSUUID* _Nonnull const) readerUuid
               rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerConnectEvent(identifier:mode:readerType:readerUuid:rfInterface:));

/**
 * Callback is invoked when the SDK has failed to establish a connection with a LEGIC reader chip.
 *
 * @param sdkStatus           Detailed information why the connection has failed
 * @param readerUuid         Unique identifier of LEGIC reader chip
 * @param rfInterface       RF interface used to connect to mobile app
 */
- (void)readerConnectFailedEvent:(LegicMobileSdkStatus* _Nonnull const)sdkStatus
                      readerUuid:(NSUUID* _Nonnull const) readerUuid
                     rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerConnectFailedEvent(sdkStatus:readerUuid:rfInterface:));

/**
 * Callback is invoked when the SDK has disconnected from a LEGIC reader chip.
 *
 * @warning Due to technical limitations on iOS, this event will not be generated for the RF Interface BLE_PERIPHIERAL.
 *
 * @param readerUuid         Unique identifier of LEGIC reader chip
 * @param rfInterface       RF interface used to connect to mobile app
 */
- (void)readerDisconnectEvent:(NSUUID* _Nonnull const) readerUuid
                  rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerDisconnectEvent(readerUuid:rfInterface:));

/**
 * Callback is invoked when the SDK has received a reader found report.
 * The SDK generates a new event for each reader advertisement package.
 *
 * @param readerFoundReport   Reader Found Report containing details about the LEGIC reader chip, RSSI, etc.
 * @see LegicMobileSdkReaderFoundReport
 */
- (void)readerReceivedReaderFoundReportEvent:(LegicMobileSdkReaderFoundReport* _Nonnull const)readerFoundReport
NS_SWIFT_NAME(readerReceivedReaderFoundReportEvent(readerFoundReport:));

@end
