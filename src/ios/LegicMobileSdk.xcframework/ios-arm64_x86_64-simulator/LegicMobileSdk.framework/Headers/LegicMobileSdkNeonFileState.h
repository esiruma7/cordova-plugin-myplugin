// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef E_LegicMobileSdkNeonFileState_h
#define E_LegicMobileSdkNeonFileState_h

/**
 * Enum value to identify the state of a LegicMobileSdkNeonFile.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkNeonFileState) {
    /**
     * Status for file definitions that are available for deployment
     */
    E_LegicMobileSdkNeonFileState_AVAILABLE = 0,
    
    /**
     * Temporary status during deployment of a LEGIC neon file
     */
    E_LegicMobileSdkNeonFileState_DEPLOY_IN_PROGRESS = 1,
    
    /**
     * Status of a file after successful deployment
     */
    E_LegicMobileSdkNeonFileState_DEPLOYED = 2,
    
    /**
     * Temporary status during removal of a LEGIC neon file
     */
    E_LegicMobileSdkNeonFileState_REMOVE_IN_PROGRESS = 3,
    
    /**
     * Temporary status after successful removal of a LEGIC neon file
     */
    E_LegicMobileSdkNeonFileState_REMOVED = 4,
    
    /**
     * Status to confirm that REQUEST_ADD request for an available file definition has been received by LEGIC Connect.
     * Deployment needs to be triggered by the server.
     */
    E_LegicMobileSdkNeonFileState_REQUEST_ADD = 5,
    
    /**
     * Confirmation that a REQUEST_REMOVE request for a available LEGIC neon file has been received by LEGIC Connect.
     * Deployment of the file needs to be triggered by the server.
     */
    E_LegicMobileSdkNeonFileState_REQUEST_REMOVE = 6,
    
    /**
     * Status to notify the application that a REQUEST_ADD request was denied by the backend
     */
    E_LegicMobileSdkNeonFileState_REJECTED = 7
    
} NS_SWIFT_NAME(NeonFileState);

#endif /* E_LegicMobileSdkNeonFileState_h */
