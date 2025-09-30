// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef E_LegicMobileSdkNeonFileMetaValueType_h
#define E_LegicMobileSdkNeonFileMetaValueType_h

/**
 * Enum value to identity the value type of a <code>LegicNeonFileMetaValue</code>.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkNeonFileMetaValueType) {
    /**
     * The value type of the <code>LegicNeonFile</code> meta is unknown.
     * This type should not occur in normal operation, but might occur to handle future value types on older SDK versions.
     */
    E_LegicMobileSdkNeonFileMetaValueType_UNKNOWN_VALUE = 0,
    
    /**
     * The meta value is a regular <code>String</code> object.
     */
    E_LegicMobileSdkNeonFileMetaValueType_STRING_VALUE = 1,
    
    /**
     * The meta value is a regular <code>Long</code> object.
     */
    E_LegicMobileSdkNeonFileMetaValueType_LONG_VALUE = 2,
    
    /**
     * The meta value contains a base64 encoded binary value (array of bytes).
     * It is represented as a <code>String</code> value. Decoding the base64 value must be done by the user.
     */
    E_LegicMobileSdkNeonFileMetaValueType_BASE64_VALUE = 3
    
} NS_SWIFT_NAME(NeonFileMetaValueType);

#endif /* E_LegicMobileSdkNeonFileMetaValueType_h */
