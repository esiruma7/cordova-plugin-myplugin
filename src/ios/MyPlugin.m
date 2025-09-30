#import <Cordova/CDV.h>

@interface MyPlugin : CDVPlugin
@end

@implementation MyPlugin

- (void)sayHello:(CDVInvokedUrlCommand*)command {
    NSString* name = [command.arguments objectAtIndex:0] ?: @"World";
    NSString* msg = [NSString stringWithFormat:@"Hello, %@", name];
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:msg];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)testLegic:(CDVInvokedUrlCommand*)command {
    // Stub only
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"LEGIC test stub (iOS)"];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

- (void)initLegic:(CDVInvokedUrlCommand*)command {
    // Stub only
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:@"LEGIC init stub (iOS)"];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

@end
