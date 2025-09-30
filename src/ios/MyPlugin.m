#import <Cordova/CDV.h>
// Import only if SDK is present; otherwise leave stubbed
// #import <LegicMobileSdk/LegicMobileSdk.h>

@interface MyPlugin : CDVPlugin
- (void)pluginInitialize;
- (void)sayHello:(CDVInvokedUrlCommand*)command;
@end

@implementation MyPlugin

- (void)pluginInitialize {
    NSLog(@"[MyPlugin] iOS plugin loaded ✅");
    // Stub init (avoids crashing if SDK symbols not available)
    NSLog(@"[MyPlugin] LEGIC SDK init stub (waiting for unobfuscated SDK)");
}

- (void)sayHello:(CDVInvokedUrlCommand*)command {
    NSString* name = [command.arguments objectAtIndex:0];

    CDVPluginResult* result;
    if (name != nil && [name length] > 0) {
        NSString* message = [NSString stringWithFormat:@"Hello, %@", name];
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:message];
    } else {
        result = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR messageAsString:@"Expected a non-empty string argument."];
    }

    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}

@end
