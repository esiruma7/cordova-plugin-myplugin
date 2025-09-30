// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * Container for system related (description, icon, display name) or customer defined metadata
 */
NS_SWIFT_NAME(NeonFileMetaValue)
@interface LegicMobileSdkNeonFileMetaValue : NSObject

/**
 * Returns the type of the metadata.
 *
 * @return The type of the metadata, encoded as LegicMobileSdkNeonFileMetaValueType
 * @see LegicMobileSdkNeonFileMetaValueType
 */
- (E_LegicMobileSdkNeonFileMetaValueType)getType
NS_SWIFT_NAME(getType());

/**
 * Returns the metadata value as <code>String</code>.
 * If the metadata is not of type <code>String</code> nil will be returned.
 *
 * @return The metadata value as <code>String</code>
 */
- (NSString* _Nullable const)getStringValue
NS_SWIFT_NAME(getStringValue());

/**
 * Returns the metadata value as an NSNumber containing a long long (Int64) value
 * if the type is LONG_VALUE and nil otherwise.
 *
 * @return The metadata value as NSNumber
 */
- (NSNumber* _Nullable const)getLongValue
NS_SWIFT_NAME(getLongValue());

/**
 * Returns the metadata value as base64 encoded string.
 * If the type is BASE64_VALUE and nil otherwise.
 *
 * @return The meta data value as base64 encoded string.
 */
- (NSString* _Nullable const)getBase64binaryValue
NS_SWIFT_NAME(getBase64binaryValue());

@end
