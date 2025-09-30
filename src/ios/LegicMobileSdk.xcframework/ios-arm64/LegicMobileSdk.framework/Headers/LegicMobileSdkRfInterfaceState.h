// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef E_LegicMobileSdkRfInterfaceState_h
#define E_LegicMobileSdkRfInterfaceState_h

/**
 * Enum value to identify the state of the RF interface.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkRfInterfaceState) {
    /**
     * The RF interface state is unknown (e.g. when starting the application)
     */
    E_LegicMobileSdkRfInterfaceState_UNKNOWN = 0,
    
    /**
     * The RF interface is not supported by the operating system
     */
    E_LegicMobileSdkRfInterfaceState_NOT_SUPPORTED = 1,
    
    /**
     * The RF interface has been disabled by the user
     * (on operating system level, e.g. by disabling BLE)
     */
    E_LegicMobileSdkRfInterfaceState_NOT_HARDWARE_ENABLED = 2,
    
    /**
     * The RF interface has been enabled by the user
     * (on operating system level, e.g. by enabling BLE)
     */
    E_LegicMobileSdkRfInterfaceState_HARDWARE_ENABLED = 3,
    
    /**
     * The RF interface has been activated
     * (by calling the corresponding SDK function)
     */
    E_LegicMobileSdkRfInterfaceState_ACTIVATED = 4,
    
    /**
     * The RF interface has been deactivated
     * (by calling the corresponding SDK function)
     */
    E_LegicMobileSdkRfInterfaceState_DEACTIVATED = 5
    
} NS_SWIFT_NAME(RfInterfaceState);

#endif /* E_LegicMobileSdkRfInterfaceState_h */
