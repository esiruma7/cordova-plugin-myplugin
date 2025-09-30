// -----------------------------------------------------------------------------
// Copyright (C) LEGIC (R) Identsystems AG, CH-8620 Wetzikon
// Confidential. All rights reserved!
// -----------------------------------------------------------------------------

#ifndef E_LegicMobileSdkReaderOperationMode_h
#define E_LegicMobileSdkReaderOperationMode_h

//**
// * Enum value indicating in which mode the reader chip is currently operating.
// * The reader communicates its current operation mode using advertising data.
// */
typedef NS_CLOSED_ENUM(NSInteger, E_LegicMobileSdkReaderOperationMode) {
    /**
     * The reader operates in <code>CONNECTABLE</code> mode
     */
    E_LegicMobileSdkReaderOperationMode_CONNECTABLE = 0,
    
    /**
     * The reader operates in <code>SLEEP</code> mode
     */
    E_LegicMobileSdkReaderOperationMode_SLEEP = 1
    
} NS_SWIFT_NAME(ReaderOperationMode);

#endif /* E_LegicMobileSdkReaderOperationMode_h */
