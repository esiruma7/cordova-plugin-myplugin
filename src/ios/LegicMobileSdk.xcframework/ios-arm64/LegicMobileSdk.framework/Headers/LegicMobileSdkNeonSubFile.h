// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

/**
 * A LEGIC neon subfile is a generic representation of a subfile within the SDK.
 * Such a file can be deployed by LEGIC Connect (LC) and modified by a LEGIC reader chip.
 */
NS_SWIFT_NAME(NeonSubFile)
@interface LegicMobileSdkNeonSubFile : NSObject

/**
 * Returns the neon file ID of the current subfile.
 * This neon file ID is only available if the file is deployed.
 *
 * @return  byte array representation of the file ID (12 bytes), if object represents a deployed file.
 *          (If object represents a non-deployed file, an empty data object will be returned.)
 */
- (NSData* _Nonnull const)getFileId
NS_SWIFT_NAME(getFileId());

//-----------------------------------------------------------------------------|

/**
 * Gets the LC Project ID of the current subfile.
 *
 * @return  The LC Project ID to which the subfile belongs
 */
- (NSUInteger)getLcProjectId
NS_SWIFT_NAME(getLcProjectId());

@end
