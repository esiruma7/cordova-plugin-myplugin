// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * Main SDK API,
 * LEGIC Mobile SDK enables customer-created mobile apps to communicate with<br>
 * the LEGIC Connect backend system and with LEGIC reader chips.<br>
 * Furthermore, it provides some functionality to interact with certain features<br>
 * of the mobile device (e.g. its BLE functionality)
 */
NS_SWIFT_NAME(LegicMobileSdkManager)
@interface LegicMobileSdkManager : NSObject

/**
 * Returns if the SDK is already started or not.
 *
 * @param error   If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       the SDK is started</li>
 *          <li> <code>false</code>     the SDK is not started</li>
 */
- (BOOL)isStarted:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(isStarted());


/**
 * Starts the SDK with the indicated parameters from the LEGIC Connect project.
 * Most of the required parameters are generated and displayed in LEGIC Connect ControlCenter,
 * the URL specifies the LEGIC Connect environment.
 * After the start, the SDK is fully functional.
 *
 * @param lcMobileAppId       Mobile app ID as generated in LEGIC Connect: The identification of your mobile app
 * @param lcTechUsername     Mobile app tech username as generated in LEGIC Connect
 * @param lcTechPassword     Mobile app tech user password generated as generated in LEGIC Connect
 * @param lcUrl                         The LEGIC Connect (LC) server URL
 * @param error                         If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 *
 * @return  <li><code>true</code>       the SDK started successfully</li>
 *          <li> <code>false</code>     the SDK did not start successfully</li>
 */
- (BOOL)start:(NSUInteger)lcMobileAppId
lcTechUsername:(NSString* _Nonnull const)lcTechUsername
lcTechPassword:(NSString* _Nonnull const)lcTechPassword
        lcUrl:(NSString* _Nonnull const)lcUrl
        error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(start(lcMobileAppId:lcTechUsername:lcTechPassword:lcUrl:));

/**
 * Returns the version of the SDK as <code>String</code> with format a.b.c.d.
 *
 * @return Version of the SDK as <code>String</code> with format a.b.c.d.
 *          <li>a = Major Version</li>
 *          <li>b = Minor Version 1</li>
 *          <li>c = Minor Version 2</li>
 *          <li>d = Minor Version 3</li>
 */
- (NSString* _Nonnull const)getVersion
NS_SWIFT_NAME(getVersion());

/**
 * Returns the current backend registration status of the SDK.
 *
 * @param error If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       the SDK is registered</li>
 *          <li> <code>false</code>     the SDK is not registered</li>
 */
- (BOOL)isRegisteredToBackend:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(isRegisteredToBackend());

/**
 * Enables / disables the LC project addressing mode,
 * This allows to also access the mobile app or LEGIC neon files with the given
 * LC Project ID only (if a file matching the LC Project ID is active in the mobile app).
 *
 * @note Mobile app addressing is active per default and allows accessing a mobile app independent of files.
 * See Mobile SDK User Guide for more details.
 *
 * @param active    Indicates whether the project addressing mode shall be enabled or disabled
 * @param error If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       set LC project addressing mode successful</li>
 *          <li> <code>false</code>     set LC project addressing mode failed</li>
 */
- (BOOL)setLcProjectAddressingModeActive:(BOOL)active
                                   error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(setLcProjectAddressingModeActive(active:));

/**
 * Returns if LC project addressing mode is active.
 *
 * @param error If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       the LC project addressing mode is active</li>
 *          <li><code>false</code>      the LC project addressing mode is not active</li>
 */
- (BOOL)isLcProjectAddressingModeActive:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(isLcProjectAddressingModeActive());

/**
 * Enables or disables certificate pinning for SSL connections.
 *
 * @note Important: The SSL certificate pinning is enabled by default without any interaction from the mobile app.
 *
 * @param error If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @param active    Indicates whether the certificate pinning shall be activated or deactivated
 * @return  <li><code>true</code>       set certificate pinning successful</li>
 *          <li><code>false</code>      set certificate pinning failed</li>
 */
- (BOOL)setCertificatePinningActive:(BOOL)active
                              error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(setCertificatePinningActive(active:));

/**
 * Returns if the certificate pinning functionality is active.
 *
 * @param error If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       SSL certificate pinning is enabled (default)</li>
 *          <li><code>false</code>      SSL certificate pinning is disabled</li>
 */
- (BOOL)isCertificatePinningActive:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(isCertificatePinningActive());

/**
 * Returns the currently used security category.
 * The <code>LegicMobileSdkSecurityCategory</code> forms the basis for SDK encryption key handling.
 *
 * @param error If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return <code>LegicMobileSdkSecurityCategory</code>  on which SDK encryption key management is based.
 */
- (E_LegicMobileSdkSecurityCategory) getCurrentSecurityCategory:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(getCurrentSecurityCategory());

/**
 * Starts the registration process with LEGIC Connect (LC).
 * If the push token is not present at registration time, it can be updated later when it is available.

 *
 * @param publicRegistrationId     ID which - together with the LC Mobile App ID - identifies the installation of the mobile app.
 *                              This can be a phone number, an email address or a custom identifier. LEGIC only allows one
 *                              active combination of <code>publicRegistrationId</code> and LC Mobile App ID.
 *                              When the same parameters are used in another installation, the old installation will be disconnected.
 * @param method                                    Identifies the method to send out confirmation token.
 *                              This value must match the format of the <code>publicRegistrationId</code>.
 * @see LegicMobileSdkBackendEventDelegate
 */
- (void)initiateRegistrationWithBackend:(NSString* _Nonnull const)publicRegistrationId
                                 method:(E_LegicMobileSdkLcConfirmationMethod) method
NS_SWIFT_NAME(initiateRegistrationWithBackend(publicRegistrationId:method:));

/**
 * Starts the registration process with LEGIC Connect (LC).
 * If the push token is not present at registration time, it can be updated later when it is available.
 *
 * @param publicRegistrationId     ID which - together with the LC Mobile App ID - identifies the installation of the mobile app.
 *                              This can be a phone number, an email address or a custom identifier. LEGIC only allows one
 *                              active combination of <code>publicRegistrationId</code> and LC Mobile App ID.
 *                              When the same parameters are used in another installation, the old installation will be disconnected.
 * @param method                                    Identifies the method to send out confirmation token.
 *                              This value must match the format of the <code>publicRegistrationId</code>.
 * @param pushToken                             The APNS (Apple Push Notification Service) push token to send out push notifications. This value may be null.
 *                              To update a pushToken after registration, use the function setPushToken
 * @param pushType                               Type of <code>pushToken</code> submitted.
 * @see LegicMobileSdkBackendEventDelegate
 */
- (void)initiateRegistrationWithBackend:(NSString* _Nonnull const)publicRegistrationId
                                 method:(E_LegicMobileSdkLcConfirmationMethod)method
                              pushToken:(NSData* _Nullable const)pushToken
                               pushType:(E_LegicMobileSdkPushType)pushType
NS_SWIFT_NAME(initiateRegistrationWithBackend(publicRegistrationId:method:pushToken:pushType:));

/**
 * Finalizes the registration by submitting the received registrationCode back to LEGIC Connect.
 * Existing registrations remain valid until subsequent registrations are successfully finalized.
 *
 * @param registrationCode     Registration code as <code>String</code> received via the requested confirmation method
 *                          after calling function initiateRegistrationWithBackend
 * @see LegicMobileSdkBackendEventDelegate
 */
- (void)registerWithBackendRegistrationCode:(NSString* _Nonnull const)registrationCode
NS_SWIFT_NAME(registerWithBackendRegistrationCode(registrationCode:));

/**
 * Finalizes the registration by submitting the received token back to LEGIC Connect.
 * Existing registrations remain valid until subsequent registrations are successfully finalized.
 *
 * @param token     Registration token as <code>String</code> received via the requested confirmation method
 *               after calling function initiateRegistrationWithBackend
 *
 * @deprecated As of release 3.1.x.x replaced with registerWithBackendRegistrationCode using
 * registrationCode as parameter instead of token. This is to avoid confusion with the push token.
 * @see LegicMobileSdkBackendEventDelegate
 */
- (void)registerWithBackend:(NSString* _Nonnull const)token
NS_SWIFT_NAME(registerWithBackend(token:))
DEPRECATED_ATTRIBUTE;

/**
 * Unregisters the SDK.
 * All corresponding information (e.g. available or deployed files) is deleted from the mobile device.
 *
 * @note Unregister is successful if the callback returns <code>SdkErrorReason</code> "OK" and even on "BACKEND_ERROR".
 * @see LegicMobileSdkBackendEventDelegate
 */
- (void)unregisterWithBackend
NS_SWIFT_NAME(unregisterWithBackend());

/**
 * Synchronizes the Mobile SDK with LEGIC Connect server.
 * Subsequently performs open operations (such as deployment or removal of files, update of meta information).
 * 
 * @see LegicMobileSdkBackendEventDelegate
 */
- (void)synchronizeWithBackend
NS_SWIFT_NAME(synchronizeWithBackend());

/**
 * Informs LC that the user requests the deployment of a LEGIC neon file.
 *
 * @note Only valid for LEGIC neon files in <code>LegicMobileSdkNeonFileState</code> "AVAILABLE" or "REJECTED".
 *
 * @param file  LEGIC neon file that shall be deployed (requested by the user)
 * @see LegicMobileSdkNeonFileEventDelegate
 */
- (void)requestAddNeonFile:(LegicMobileSdkNeonFile* _Nonnull const)file
NS_SWIFT_NAME(requestAddNeonFile(file:));

/**
 * Informs LC that the user requests the deployment of a LEGIC neon file.
 *
 * @note Only valid for LEGIC neon files in <code>LegicMobileSdkNeonFileState</code> "AVAILABLE" or "REJECTED".
 *
 * @param file                  LEGIC neon file that shall be deployed (requested by the user)
 * @param parameters    Parameters (key/value pairs) that shall be passed to LC server
 *                    with the requestAddNeonFile request. These parameters are passed through
 *                    to the customer backend server, the values are neither validated nor handled by LC.
 * @see LegicMobileSdkNeonFileEventDelegate
 */
- (void)requestAddNeonFile:(LegicMobileSdkNeonFile* _Nonnull const)file
                parameters:(NSArray< LegicMobileSdkNeonFileParameter* >* _Nullable const)parameters
NS_SWIFT_NAME(requestAddNeonFile(file:parameters:));

/**
 * Informs LC that the user requests the removal of a currently deployed LEGIC neon file.
 *
 * @note Only works for LEGIC neon files in <code>LegicMobileSdkNeonFileState</code> "DEPLOYED".
 *
 * @param file  LEGIC neon file that shall be removed (requested by the user)
 * @see LegicMobileSdkNeonFileEventDelegate
 */
- (void)requestRemoveNeonFile:(LegicMobileSdkNeonFile* _Nonnull const)file
NS_SWIFT_NAME(requestRemoveNeonFile(file:));

/**
 * Returns a list of all neon files, independent of the current file state.
 *
 * @param error If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  List (array) of all neon files.
 */
- (NSArray<LegicMobileSdkNeonFile*>* _Nullable const)getAllNeonFiles:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(getAllNeonFiles());

/**
 * Returns a list of all known neon files which have a certain file state.
 *
 * @param fileState     State value to filter the neon files
 * @param error If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return           List of all neon files with the requested state.
 */
- (NSArray<LegicMobileSdkNeonFile*>* _Nullable const)getAllNeonFilesWithState:(E_LegicMobileSdkNeonFileState)fileState
                                                                        error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(getAllNeonFilesWithState(fileState:));


/**
 * Activates or deactivates a specific neon file.
 * By activating a neon file, it becomes accessible to a LEGIC reader chip via the registered interfaces.
 *
 * @note Only works for LEGIC neon files in <code>LegicMobileSdkNeonFileState</code> "DEPLOYED".
 *
 * @param file         File to be activated / deactivated
 * @param active    Indicates whether the file shall be activated or deactivated.
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       set neon file successful</li>
 *          <li><code>false</code>      set neon file failed</li>
 */
- (BOOL)setNeonFileActive:(LegicMobileSdkNeonFile* _Nonnull const)file
                   active:(BOOL) active
                    error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(setNeonFileActive(file:active:));


/**
 * Activates or deactivates a default marker on the given neon file.
 * Depending on the <code>mode</code> parameter, the passed file becomes the <code>"</code>LC mobile app<code>"</code> default file or <br>
 * the <code>"</code>LC project<code>"</code> default file.
 * The default files can be selected as follows:<br>
 * <ul>
 *     <li>MOBILE_APP_DEFAULT files can be selected with project ID and file ID consisting of all zeros (16 bytes).</li>
 *     <li>LC_PROJECT_DEFAULT files can be selected with the project ID (first 4 bytes) followed by zeros for the file ID (12 bytes).</li>
 * </ul>
 *
 * @note Please note:
 * <ul>
 *      <li>Only one file can be set as "MOBILE_APP_DEFAULT" file.</li>
 *      <li>Only one file within a project can be set as "LC_PROJECT_DEFAULT" file.</li>
 *      <li>Any other file that previously had the requested default mode will loose this status if another file is set to that same default mode.</li>
 *      <li>"MOBILE_APP_DEFAULT" and “LC_PROJECT_DEFAULT” status are orthogonal,  therefore any combination is allowed.</li>
 * </ul>
 *
 * @param file      File on which the default marker shall be activated/deactivated
 * @param mode      Mode to change
 *               (either <code>MOBILE_APP_DEFAULT</code> or <code>LC_PROJECT_DEFAULT</code>)
 * @param active    Indicates whether the default mode shall be enabled or disabled.
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       set neon file default successful</li>
 *          <li><code>false</code>      set neon file default failed</li>
 */
- (BOOL)setNeonFileDefaultActive:(LegicMobileSdkNeonFile* _Nonnull const)file
                            mode:(E_LegicMobileSdkNeonFileDefaultMode)mode
                          active:(BOOL)active
                           error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(setNeonFileDefaultActive(file:mode:active:));

/**
 * Retrieves the current default status for the given file and mode.
 *
 * @param file  File to be queried
 * @param mode  Mode to check
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return   <li><code>true</code>      the file is marked as default file for the given mode.</li>
 *           <li><code>false</code>     the file is not marked as default file for the given mode.</li>
 */
- (BOOL)isNeonFileDefaultActive:(LegicMobileSdkNeonFile* _Nonnull const)file
                           mode:(E_LegicMobileSdkNeonFileDefaultMode)mode
                          error:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(isNeonFileDefaultActive(file:mode:));

/**
 * Allows to query whether an RF interface is supported by the platform.
 *
 * @param rfInterface   RF interface to be queried
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>   RF interface is supported.</li>
 *          <li><code>false</code>  RF interface is not supported.</li>
 * @note If the RF interface on the phone is not enabled, this check can't get performed due to OS limitations. An SDK error INTERFACE_NOT_HW_ENABLED gets thrown. Before calling isRfInterfaceHardwareSupported make sure, that the Rf Interface is enabled.
 */
- (BOOL)isRfInterfaceHardwareSupported:(LegicMobileSdkRfInterface* _Nonnull)rfInterface
                                 error:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(isRfInterfaceHardwareSupported(rfInterface:));

/**
 * Allows to query the current status of the RF interface.
 * The response depends on the status of the interface on operating system level
 * (can be influenced by the user, e.g. by switching BLE off).
 *
 * @param rfInterface   RF interface to be queried
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>   RF interface has been enabled by the user.</li>
 *          <li><code>false</code>  RF interface has not been enabled by the user.</li>
 */
- (BOOL)isRfInterfaceHardwareEnabled:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
                               error:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(isRfInterfaceHardwareEnabled(rfInterface:));

/**
 * Activates or deactivates the requested RF interface on the mobile app.
 * RF interfaces can only be activated after successful registration.
 *
 * @param rfInterface   RF interface to be activated/deactivated
 * @param active    Indicates whether the RF interface shall be enabled or disabled.
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       set RF interface successful</li>
 *          <li><code>false</code>      set RF interface failed</li>
 * @see LegicMobileSdkEventDelegate
 */
- (BOOL)setRfInterfaceActive:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
                      active:(BOOL)active
                       error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(setRfInterfaceActive(rfInterface:active:));

/**
 * Allows to query the current status of the RF interface within the mobile app.
 * The status can be changed by calling setRFInterfaceActive.
 *
 * @param rfInterface RF interface to be queried
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       RF interface has been activated in the mobile app.</li>
 *          <li><code>false</code>      RF interface has not been activated in the mobile app.</li>
 */
- (BOOL)isRfInterfaceActive:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
                      error:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(isRfInterfaceActive(rfInterface:));

/**
 * Sends a message to the host system (via the LEGIC reader chip) using the LC message channel.
 *
 * @note Please note:
 * <ul>
 *      <li>The message can be arbitrarily formatted as this is a contract between  the host system (connected to the reader) and the mobile app.</li>
 *      <li>The message is transported as-is, no validation takes place.</li>
 *      <li>The message can be sent encrypted or plain.</li>
 *      <li>The <code>LcMessageMode</code> parameter controls how the message should be sent/received by the SDK/reader</li>
 *      <li>Maximum length of the message is 200 bytes.</li>
 *      <li>Messages are received within the <code>LegicMobileSdkLcMessageEventDelegate</code> (callback <code>readerLcMessageEvent</code>).</li>
 * </ul>
 *
 * @param message               Message to transmit to host system (via the reader chip).
 * @param mode                      The message is sent via the given mode.
 *                      Usually, the mode corresponds to the previously received message.
 * @param rfInterface       The message is sent via the given interface.
 *                      Usually, the interface corresponds to the previously received message.
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       send message to reader successful</li>
 *          <li><code>false</code>      send message to reader failed</li>
 * @see LegicMobileSdkReaderEventDelegate
 */
- (BOOL)sendLcMessageToReader:(NSData* _Nonnull const)message
                         mode:(E_LegicMobileSdkLcMessageMode)mode
                  rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
                        error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(sendLcMessageToReader(message:mode:rfInterface:));

/**
 * Queues a message that is scoped to the LEGIC Connect project the specified file belongs to.
 *
 * @note Note that in order to send queued messages, the SDK needs to synchronize with the backend.
 * @note The message is sent plain.
 *
 * @param message     Message to transmit to the LEGIC Connect project
 * @param file            The file defines the project the message is intended for
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       send message to backend project successful</li>
 *          <li><code>false</code>     send message to backend project failed</li>
 */
- (BOOL)sendLcMessageToBackendProject:(NSData* _Nonnull const)message
                                 file:(LegicMobileSdkNeonFile* _Nonnull  const) file
                                error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(sendLcMessageToBackendProject(message:file:));

/**
 * Queues a message that is scoped to the registered LEGIC Connect mobile app.
 *
 * @note Note that in order to send queued messages, the SDK needs to synchronize with the backend.
 * @note The message is sent plain.
 *
 * @param message     Message to transmit to the LEGIC Connect mobile app.
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       send message to backend mobile app successful</li>
 *          <li><code>false</code>      send message to backend mobile app failed</li>
 */
- (BOOL)sendLcMessageToBackendMobileApp:(NSData* _Nonnull const)message
                                  error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(sendLcMessageToBackendMobileApp(message:));

/**
 * Returns the number of messages that are queued for the backend.
 *
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return Number of messages that are queued for the backend
 */
- (NSUInteger) getNumberOfLcMessagesToBackend:(NSError* _Nullable __autoreleasing * _Nullable)error
__attribute__((swift_error(nonnull_error)))
NS_SWIFT_NAME(getNumberOfLcMessagesToBackend());


/**
 * Sends an entered password back to the host system (via the LEGIC reader chip) using the LC message channel.
 * This call can be used to exchange a password (e.g. a VCP password) between host system and mobile app.
 *
 * @note Please note:
 * <ul>
 *      <li>The mode to transmit the password is predefined (always <code>ENCRYPTED_MACED_FILE_KEYS</code>),
 *      therefore, an authenticated session is required.</li>
 *      <li>Password requests are received within the <code>LegicMobileSdkLcMessageEventDelegate</code>
 *      (callback <code>readerPasswordRequestEvent</code>).</li>
 *      <li>Maximum length of the password is 200 bytes.</li>
 * </ul>
 *
 * @param password          Password to transmit to host system (via the reader chip)
 * @param rfInterface   The password is sent via the indicated RF interface.
 *                     Usually, the interface corresponds with the previously received password request.
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       send password to reader successful</li>
 *          <li><code>false</code>      send password to reader failed</li>
 * @see LegicMobileSdkLcMessageEventDelegate
 */
- (BOOL)sendPasswordToReader:(NSData* _Nonnull const)password
                 rfInterface:(LegicMobileSdkRfInterface* _Nonnull const)rfInterface
                       error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(sendPasswordToReader(password:rfInterface:));

/**
 * Passes a push token to LEGIC Connect.
 * This token is required/used to notify the mobile app about pending operations.
 * The function can be used to set or update the push token after registration with the backend.
 *
 * @param pushToken New or updated push token that needs to be sent to LEGIC Connect
 * @param pushType  Type of <code>pushToken</code> provided (depends on project used to register)
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       set push token successful</li>
 *          <li><code>false</code>      set push token failed</li>
 */
- (BOOL)setPushToken:(NSData* _Nonnull const)pushToken
            pushType:(E_LegicMobileSdkPushType)pushType
               error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(setPushToken(pushToken:pushType:));

/**
 * Handles received push messages from APNS (Apple Push Notification Service).
 * This method should be called when a APNS (Apple Push Notification Service) push notification is received.
 * If the push message contains a certain key/value pair which is set by LC, the SDK starts synchronizing with the backend.
 *
 * @note Please note:
 * <ul>
 *      <li>If the push message does not contain the expected payload, the synchronize
 *      process with the backend is not started and the message is ignored.</li>
 *      <li>If any other object than an <code>Intent</code> or <code>RemoteMessage</code> is
 *      passed into the function, the synchronize process with the backend is not started and the message is ignored. </li>
 *      <li>A synchronization with LC can also be achieved by directly calling synchronizeWithBackend.</li>
 * </ul>
 *
 * @param userInfo    UserInfo received with push notification must be passed as parameter
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       handle push message successful</li>
 *          <li><code>false</code>      handle push message failed</li>
 */
- (BOOL)handlePushMessage:(NSDictionary* _Nonnull const)userInfo
                    error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(handlePushMessage(userInfo:));


/**
 *  Connects to a LEGIC reader chip.
 *  The function returns before the connection is established and will generate either a <code>readerConnectEvent</code>
 *  or a <code>readerConnectFailedEvent</code>.
 *  The timeout parameter restricts the connection attempt (which would never time out) to a specific timeframe in milliseconds.
 *  If the timeout is exceeded, the SDK generates a <code>readerConnectFailedEvent</code> with a corresponding timeout
 *  error reason in a LegicMobileSdkStatus code.
 *
 *  It is not mandatory to use the <code>readerFoundReport</code> with the most current timestamp.
 *  A connection can also be established using an older <code>readerFoundReport</code>.
 *  However, if a reader has not been seen by the SDK, a successful connection is unlikely.
 *  All errors during the connection establishment are reported with the SDK Event readerConnectFailedEvent.
 *
 * @param readerFoundReport     reader found report
 * @param timeout                           Timeout in milliseconds
 * @see LegicMobileSdkReaderEventDelegate
 */
- (void)connectToReader:(LegicMobileSdkReaderFoundReport* _Nonnull const)readerFoundReport
                timeout:(NSUInteger) timeout
NS_SWIFT_NAME(connectToReader(readerFoundReport:timeout:));


/**
 * Registers a delegate to receive callbacks whenever a backend related operation occurs in the SDK
 *
 * @param delegate  Delegate to receive events regarding backend related operations.
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       register for backend events successful</li>
 *          <li><code>false</code>      register for backend events failed</li>
 * @see LegicMobileSdkBackendEventDelegate
 */
- (BOOL)registerForBackendEvents:(id<LegicMobileSdkBackendEventDelegate> _Nonnull)delegate
                           error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(registerForBackendEvents(delegate:));

/**
 * Removes a previously registered delegate for backend events from the SDK.
 * Callbacks for backend related events will no longer occur.
 *
 * @param delegate  Delegate to be removed from the SDK <code>LegicMobileSdkBackendEventDelegate</code> list.
 * @see LegicMobileSdkBackendEventDelegate
 */
- (void)unregisterForBackendEvents:(id<LegicMobileSdkBackendEventDelegate> _Nonnull)delegate
NS_SWIFT_NAME(unregisterForBackendEvents(delegate:));

/**
 * Registers a delegate to receive callbacks whenever a LC message related operation occurs in the SDK.
 *
 * @param delegate  Delegate to receive events regarding LC message related operations.
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       register for LC message events successful</li>
 *          <li><code>false</code>      register for LC message events failed</li>
 * @see LegicMobileSdkLcMessageEventDelegate
 */
- (BOOL)registerForLcMessageEvents:(id<LegicMobileSdkLcMessageEventDelegate> _Nonnull)delegate
                             error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(registerForLcMessageEvents(delegate:));

/**
 * Removes a previously registered delegate for LC message events from the SDK.
 * Callbacks for LC message related events will no longer occur.
 *
 * @param delegate  Delegate to be removed from the SDK <code>LegicMobileSdkLcMessageEventDelegate</code> list.
 * @see LegicMobileSdkLcMessageEventDelegate
 */
- (void)unregisterForLcMessageEvents:(id<LegicMobileSdkLcMessageEventDelegate> _Nonnull)delegate
NS_SWIFT_NAME(unregisterForLcMessageEvents(delegate:));

/**
 * Registers a delegate to receive callbacks whenever a LEGIC neon file related operation occurs in the SDK.
 *
 * @param delegate  Delegate to receive events regarding LEGIC neon file operations
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       register for neon file events successful</li>
 *          <li><code>false</code>      register for neon file events failed</li>
 * @see LegicMobileSdkNeonFileEventDelegate
 */
- (BOOL)registerForNeonFileEvents:(id<LegicMobileSdkNeonFileEventDelegate> _Nonnull)delegate
                            error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(registerForNeonFileEvents(delegate:));

/**
 * Removes a previously registered delegate for neon file events from the SDK.
 * Callbacks for neon file related events will no longer occur.
 *
 * @param delegate  Delegate to be removed from the SDK <code>LegicMobileSdkNeonFileEventDelegate</code> list.
 * @see LegicMobileSdkNeonFileEventDelegate
 */
-(void)unregisterForNeonFileEvents:(id<LegicMobileSdkNeonFileEventDelegate> _Nonnull)delegate
NS_SWIFT_NAME(unregisterForNeonFileEvents(delegate:));

/**
 * Registers a delegate to receive callbacks whenever a LEGIC reader chip related operation occurs in the SDK.
 *
 * @param delegate  Delegate to receive events regarding reader chip operations
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       register for reader events successful</li>
 *          <li><code>false</code>      register for reader events failed</li>
 * @see LegicMobileSdkReaderEventDelegate
 */
- (BOOL)registerForReaderEvents:(id<LegicMobileSdkReaderEventDelegate> _Nonnull)delegate
                          error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(registerForReaderEvents(delegate:));

/**
 * Removes a previously registered delegate for reader chip events from the SDK.
 * Callbacks for reader chip related events will no longer occur.
 *
 * @param delegate  Delegate to be removed from the SDK <code>LegicMobileSdkReaderEventDelegate</code> list.
 * @see LegicMobileSdkReaderEventDelegate
 */
- (void)unregisterForReaderEvents:(id<LegicMobileSdkReaderEventDelegate> _Nonnull)delegate
NS_SWIFT_NAME(unregisterForReaderEvents(delegate:));


/**
 * Registers a delegate to receive callbacks whenever a SDK related operation occurs in the SDK.
 *
 * @param delegate  Delegate to receive events regarding SDK operations.
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code> that describes the problem
 * @return  <li><code>true</code>       register for SDK events successful</li>
 *          <li><code>false</code>      register for SDK events failed</li>
 * @see LegicMobileSdkEventListener
 */
- (BOOL)registerForSdkEvents:(id<LegicMobileSdkEventDelegate> _Nonnull)delegate
                       error:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(registerForSdkEvents(delegate:));

/**
 * Removes a previously registered delegate for SDK events from the SDK.
 * Callbacks for SDK related events will no longer occur.
 *
 * @param delegate  Delegate to be removed from the SDK <code>LegicMobileSdkSdkEventDelegate</code> list.
 * @see LegicMobileSdkSdkEventDelegate
 */
- (void)unregisterForSdkEvents:(id<LegicMobileSdkEventDelegate> _Nonnull)delegate
NS_SWIFT_NAME(unregisterForSdkEvents(delegate:));


/**
 * Removes a previously registered delegate from the SDK.
 * Callbacks of any kind will no longer occur.
 *
 * @param delegate  Delegate to be removed from all SDK event delegate lists.
 * @see LegicMobileSdkBaseEventListener
 */
- (void)unregisterAnyEvents:(id _Nonnull)delegate
NS_SWIFT_NAME(unregisterAnyEvents(delegate:));

@end
