// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef LegicMobileSdkRfInterface_h
#define LegicMobileSdkRfInterface_h

/**
 * Enum value to identify a RF interface.
 */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkRfInterface) {
    /**
     * The interface is identified as Bluetooth (BLE) interface in peripheral mode
     */
    E_LegicMobileSdkRfInterface_BLE_PERIPHERAL = 0,
    /**
     * The interface is identified as Bluetooth (BLE) interface in central mode
     */
    E_LegicMobileSdkRfInterface_BLE_CENTRAL = 2
    
} NS_SWIFT_NAME(E_RfInterface);

/**
 * Object that encapsulates E_LegicMobileSdkRfInterface so that it can be
 * used inside containers
 */
NS_SWIFT_NAME(RfInterface)
@interface LegicMobileSdkRfInterface : NSObject

- (instancetype _Nonnull)initWithValue:(E_LegicMobileSdkRfInterface)value;

/**
 * The interface identified is a Bluetooth (BLE) interface
 */
@property (readonly) E_LegicMobileSdkRfInterface value
NS_SWIFT_NAME(value);

/**
 * The interface identified is a Bluetooth (BLE) interface
 * @return an object that symbolizes a BLE_PERIPHERAL value
 */
@property (class, readonly) LegicMobileSdkRfInterface* _Nonnull BLE_PERIPHERAL
NS_SWIFT_NAME(BLE_PERIPHERAL);

/**
 * The interface identified is a Bluetooth (BLE) interface
 * @return an object that symbolizes a BLE_CENTRAL value
 */
@property (class, readonly) LegicMobileSdkRfInterface* _Nonnull BLE_CENTRAL
NS_SWIFT_NAME(BLE_CENTRAL);

@end

#endif /* LegicMobileSdkRfInterface_h */
