// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * Handles LEGIC neon file related events
 */
NS_SWIFT_NAME(NeonFileEventDelegate)
@protocol LegicMobileSdkNeonFileEventDelegate <LegicMobileSdkBaseEventDelegate>
@optional
/**
 * Callback is invoked whenever a new LEGIC neon file appears or
 * an existing one is updated (either content or meta data).
 *
 * @param file  LEGIC neon file updated/added during synchronize operation
 */
- (void)backendNeonFileChangedEvent:(LegicMobileSdkNeonFile* _Nonnull const)file
NS_SWIFT_NAME(backendNeonFileChangedEvent(file:));

/**
 * Callback is invoked when the backend response to a requestAddNeonFile call is received.
 *
 * @param sdkStatus Detailed information about the result of the backend call
 */
- (void)backendRequestAddNeonFileDoneEvent:(LegicMobileSdkStatus* _Nonnull const)sdkStatus
NS_SWIFT_NAME(backendRequestAddNeonFileDoneEvent(sdkStatus:));

/**
 * Callback is invoked when the backend response to a requestRemoveNeonFile call is received.
 *
 * @param sdkStatus Detailed information about the result of the backend call
 */
- (void)backendRequestRemoveNeonFileDoneEvent:(LegicMobileSdkStatus* _Nonnull const)sdkStatus
NS_SWIFT_NAME(backendRequestRemoveNeonFileDoneEvent(sdkStatus:));

/**
 * Callback is invoked when a LEGIC neon file is read by the LEGIC reader chip.
 *
 * @param file                  LEGIC neon file that was accessed (read access)
 * @param rfInterface   RF interface that was used to access the LEGIC neon file
 */
- (void)readerReadNeonFileEvent:(LegicMobileSdkNeonFile* _Nonnull const)file
                    rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerReadNeonFileEvent(file:rfInterface:));


/**
 * Callback is invoked when a LEGIC neon file is written by the LEGIC reader chip.
 *
 * @param file                  LEGIC neon file that was accessed (write access)
 * @param rfInterface   RF interface that was used to access the LEGIC neon file
 */
- (void)readerWriteNeonFileEvent:(LegicMobileSdkNeonFile* _Nonnull const)file
                     rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerWriteNeonFileEvent(file:rfInterface:));

/**
 * Callback is invoked when a LEGIC neon sub file is read by the LEGIC reader chip.
 *
 * @param subfile            LEGIC neon sub file that was accessed (read access)
 * @param mainfile          LEGIC neon main file
 * @param rfInterface   RF interface that was used to access the LEGIC neon file
 */
- (void)readerReadNeonSubFileEvent:(LegicMobileSdkNeonSubFile* _Nonnull const)subfile
                          mainfile:(LegicMobileSdkNeonFile* _Nonnull const)mainfile
                       rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerReadNeonSubFileEvent(subfile:mainfile:rfInterface:));


/**
 * Callback is invoked when a LEGIC neon sub file is written by the LEGIC reader chip.
 *
 * @param subfile            LEGIC neon sub file that was accessed (write access)
 * @param mainfile          LEGIC neon main file
 * @param rfInterface   RF interface that was used to access the LEGIC neon file
 */
- (void)readerWriteNeonSubFileEvent:(LegicMobileSdkNeonSubFile* _Nonnull const)subfile
                           mainfile:(LegicMobileSdkNeonFile* _Nonnull const)mainfile
                        rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
NS_SWIFT_NAME(readerWriteNeonSubFileEvent(subfile:mainfile:rfInterface:));


@end
