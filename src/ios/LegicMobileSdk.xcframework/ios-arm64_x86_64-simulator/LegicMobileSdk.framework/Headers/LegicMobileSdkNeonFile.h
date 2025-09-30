// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * A LEGIC neon file (hereafter just called "file") is a generic representation of a file within the SDK.
 * Such a file can be deployed by LEGIC Connect (LC) and modified by a LEGIC reader chip.
 *
 * Such a file can have different states. Depending on the state of a file, it can be requested from the backend, modified by a LEGIC reader chip, etc.
 * @see LegicMobileSdkNeonFileState
 *
 * Beside the file state, a file further contains several system parameters (description, icon, displayName) or customer defined meta data.
 */
NS_SWIFT_NAME(NeonFile)
@interface LegicMobileSdkNeonFile : NSObject

//-----------------------------------------------------------------------------|

/**
 * Checks if the file contains a file ID
 *
 * @return  <li><code>true</code>   the file contains a neon file ID</li>
 *          <li><code>false</code>  the file does not contain a neon file ID</li>
 */
- (BOOL)hasFileId
NS_SWIFT_NAME(hasFileId());

//-----------------------------------------------------------------------------|

/**
 * Checks if the file contains a file definition name.
 *
 * @return  <li><code>true</code>    the file contains a file definition name</li>
 *          <li><code>false</code>  the file does not contain a file definition name</li>
 */
- (BOOL)hasFileDefinitionName
NS_SWIFT_NAME(hasFileDefinitionName());

//-----------------------------------------------------------------------------|

/**
 * Returns the neon file ID of the current file.
 * This file ID is only available if the file is deployed.
 *
 * @return  byte array representation of the file ID (12 bytes), if object represents a deployed file.
 *          (If object represents a non-deployed file, an empty data object will be returned.)
 */
- (NSData* _Nonnull const)getFileId
NS_SWIFT_NAME(getFileId());

//-----------------------------------------------------------------------------|

/**
 * Returns the file definition name of the file.
 * This file definition name is only available if the file is not deployed.
 *
 * @return  Name of the file definition of the file as String.
 *          Only if the object represents a non- deployed file, if object represents a deployed file,
 *          an empty String will be returned.
 */
- (NSString* _Nonnull const)getFileDefinitionName
NS_SWIFT_NAME(getFileDefinitionName());

//-----------------------------------------------------------------------------|

/**
 * Returns the LC Project ID of the current file.
 *
 * @return  The LC Project ID to which the file belongs
 */
- (NSUInteger)getLcProjectId
NS_SWIFT_NAME(getLcProjectId());

//-----------------------------------------------------------------------------|

/**
 * Returns the state of the current file.
 * @see LegicMobileSdkNeonFileState
 *
 * @return  State of the file.
 */
- (E_LegicMobileSdkNeonFileState)getFileState
NS_SWIFT_NAME(getFileState());

//-----------------------------------------------------------------------------|

/**
 * Returns the value of the system parameter <code>displayName</code>.
 * This value is optional.
 *
 * @return  Value of system parameter <code>displayName</code> or empty <code>String</code> if not defined.
 */
- (NSString* _Nonnull const)getDisplayName
NS_SWIFT_NAME(getDisplayName());

//-----------------------------------------------------------------------------|

/**
 * Returns the value of the system parameter <code>description</code>.
 * This value is optional.
 *
 * @return  Value of system parameter <code>description</code> or empty <code>String</code> if not defined.
 */
- (NSString* _Nonnull const)getDescription
NS_SWIFT_NAME(getDescription());

//-----------------------------------------------------------------------------|

/**
 * Returns the value of the system parameter <code>icon</code>.
 * This value is optional. As the icon represents an image, the String value is expected to be
 * a base64 encoded binary value. Decoding the base64-encoded data must be done by the user.
 *
 * @return  Value of system parameter <code>icon</code> or empty <code>String</code> if not defined.
 */
- (NSString* _Nonnull const)getIconData
NS_SWIFT_NAME(getIconData());

//-----------------------------------------------------------------------------|

/**
 * Checks if the current file contains a VCP.
 *
 * @return  <li><code>true</code>   the file contains a VCP</li>
 *          <li><code>false</code>  the file does not contain a VCP</li>
 */
- (BOOL)containsVcp
NS_SWIFT_NAME(containsVcp());

//-----------------------------------------------------------------------------|

/**
 * Returns all RF interfaces which are active for the current file.
 *
 * @return List of activated RF interfaces for this file
 *
 */
- (NSArray<LegicMobileSdkRfInterface*>* _Nonnull const)getActiveRfInterfaces
NS_SWIFT_NAME(getActiveRfInterfaces());


//-----------------------------------------------------------------------------|

/**
 * Checks whether a metadata parameter with the given name exists.
 *
 * @param key   Name of the metadata parameter to look for.
 * @return  <li><code>true</code>   the file contains metadata for the given key</li>
 *          <li><code>false</code>  the file does not contain metadata for the given key</li>
 */
- (BOOL)hasMetaDataValue:(NSString* _Nonnull const)key
NS_SWIFT_NAME(hasMetaDataValue(_:));

//-----------------------------------------------------------------------------|

/**
 * Returns the type of the metadata.
 *
 * @param key   Name of the metadata parameter
 * @return  LegicMobileSdkNeonFileMetaValueType
 */
- (E_LegicMobileSdkNeonFileMetaValueType)getMetaDataType:(NSString* _Nonnull const)key
NS_SWIFT_NAME(getMetaDataType(_:));

//-----------------------------------------------------------------------------|

/**
 * Returns the <code>String</code> value of the given custom parameter.
 *
 * @param key   Name of the custom parameter to be queried
 * @return  <code>String</code> value of the named custom parameter
 *          or empty <code>String</code> if the parameter type is not <code>stringValue</code>.
 */
- (NSString* _Nonnull const)getMetaDataStringValue:(NSString* _Nonnull const)key
NS_SWIFT_NAME(getMetaDataStringValue(_:));

//-----------------------------------------------------------------------------|

/**
 * Returns the <code>Long</code> value of the given custom parameter.
 *
 * @param key   Name of the custom parameter to be queried
 * @return  <code>Long</code> (Int64) value of the named custom parameter
 *          or <code>0L</code> if the parameter type is not <code>longValue</code>.
 */
- (long long)getMetaDataLongValue:(NSString* _Nonnull const)key
NS_SWIFT_NAME(getMetaDataLongValue(_:));

//-----------------------------------------------------------------------------|

/**
 * Returns the base64-encoded <code>String</code> representation of the given custom parameter.
 *
 * @param key   Name of the custom parameter to be queried
 * @return  <code>String</code> value of the named custom parameter
 *          or empty <code>String</code> if the parameter type is not <code>base64BinaryValue</code>.
 *          Decoding the base64-encoded datamust be done by the user.
 */
- (NSString* _Nonnull const)getMetaDataBase64BinaryValue:(NSString* _Nonnull const)key
NS_SWIFT_NAME(getMetaDataBase64BinaryValue(_:));

//-----------------------------------------------------------------------------|

/**
 * Returns an object containing all metadata of the current file.
 *
 * @return  All metadata for the current file.
 */
- (NSDictionary< NSString*, LegicMobileSdkNeonFileMetaValue* >* _Nonnull const)getMetaData
NS_SWIFT_NAME(getMetaData());

//-----------------------------------------------------------------------------|

/**
 * Checks if the current file is marked as <code>Mobile App Default</code> file.
 *
 * @return  <li><code>true</code>   file is marked as <code>Mobile App Default</code> file</li>
 *          <li><code>false</code>  file is not marked as <code>Mobile App Default</code> file</li>
 */
- (BOOL)isMobileAppDefault
NS_SWIFT_NAME(isMobileAppDefault());

//-----------------------------------------------------------------------------|

/**
 * Checks if the current file is marked as <code>LC project default</code> file within the project.
 *
 * @return  <li><code>true</code>   file is the default file in a LC project</li>
 *          <li><code>false</code>  file is not the default file in a LC project</li>
 */
- (BOOL)isLcProjectDefault
NS_SWIFT_NAME(isLcProjectDefault());

//-----------------------------------------------------------------------------|

/**
 * Checks if the current file is activated.
 *
 * @return  <li><code>true</code>   file is currently active and accessible by the LEGIC reader chip.</li>
 *          <li><code>false</code>  file is currently not active and not accessible by the LEGIC reader chip.</li>
 */
- (BOOL)isActivated
NS_SWIFT_NAME(isActivated());

@end
