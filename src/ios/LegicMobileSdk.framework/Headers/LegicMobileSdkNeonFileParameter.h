// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * This class wraps custom key/value pairs.
 */
NS_SWIFT_NAME(NeonFileParameter)
@interface LegicMobileSdkNeonFileParameter : NSObject

//-----------------------------------------------------------------------------|
- (instancetype _Nonnull)initWithKey:(NSString* _Nonnull const)key
                               value:(NSString* _Nonnull const)value;

//-----------------------------------------------------------------------------|

/**
 * This method returns the currently set key
 *
 * @return The key as <code>String</code>.
 */
- (NSString* _Nonnull const)getKey
NS_SWIFT_NAME(getKey());

//-----------------------------------------------------------------------------|

/**
 * This method returns the currently set value.
 *
 * @return The value as <code>String</code>.
 */
- (NSString* _Nonnull const)getValue
NS_SWIFT_NAME(getValue());

@end
