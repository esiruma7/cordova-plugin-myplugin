// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

NS_SWIFT_NAME(LegicMobileSdkManagerFactory)
@interface LegicMobileSdkManagerFactory : NSObject

/**
 * Factory function that returns a reference to an LegicMobileSdkManager singleton.
 *
 * @param error      If there is an error, upon return contains a <code>LegicMobileSdkError</code> object
 * containing a <code>LegicMobileSdkStatus</code>  that describes the problem
 * @return Reference to a LegicMobileSdkManager singleton
 */
+ (LegicMobileSdkManager* _Nullable const)getInstance:(NSError* _Nullable __autoreleasing * _Nullable)error
NS_SWIFT_NAME(getInstance());

@end
