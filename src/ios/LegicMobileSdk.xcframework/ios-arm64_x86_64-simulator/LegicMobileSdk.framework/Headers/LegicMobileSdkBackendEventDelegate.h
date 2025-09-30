// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * Handles backend events
 */
NS_SWIFT_NAME(BackendEventDelegate)
@protocol LegicMobileSdkBackendEventDelegate <LegicMobileSdkBaseEventDelegate>
@optional

/**
 * Callback is invoked when the backend response to an initiateRegistrationWithBackend call is received.
 *
 * @param sdkStatus Detailed information about the result of the backend call
 */
- (void)backendRegistrationInitializedEvent:(LegicMobileSdkStatus* _Nonnull const)sdkStatus
NS_SWIFT_NAME(backendRegistrationInitializedEvent(sdkStatus:));

/**
 * Callback is invoked when the backend response to a registerWithBackendRegistrationCode call is received.
 *
 * @param sdkStatus Detailed information about the result of the backend call
 */
- (void)backendRegistrationFinishedEvent:(LegicMobileSdkStatus* _Nonnull const)sdkStatus
NS_SWIFT_NAME(backendRegistrationFinishedEvent(sdkStatus:));

/**
 * Callback is invoked when the backend response to a unregisterWithBackend call is received.
 *
 * @param sdkStatus Detailed information about the result of the backend call
 */
- (void)backendUnregisteredEvent:(LegicMobileSdkStatus* _Nonnull const)sdkStatus
NS_SWIFT_NAME(backendUnregisteredEvent(sdkStatus:));

/**
 * Callback is invoked when the SDK starts a synchronization process with the backend.
 *
 * @note Please note:
 * <ul>
 *      <li>This event can be used to signal an ongoing synchronization process with the backend (e.g. over the mobile app UI).</li>
 *      <li>This event will always be followed by a backendSynchronizeDoneEven after the synchronize process has been finished.</li>
 * </ul>
 */
- (void)backendSynchronizeStartEvent
NS_SWIFT_NAME(backendSynchronizeStartEvent());

/**
 * Callback is invoked when the backend response to a synchronizeWithBackend call is received
 * and the synchronization  process is finished.
 *
 * @param sdkStatus Detailed information about the result of the backend call.
 */
- (void)backendSynchronizeDoneEvent:(LegicMobileSdkStatus* _Nonnull const)sdkStatus
NS_SWIFT_NAME(backendSynchronizeDoneEvent(sdkStatus:));

@end
