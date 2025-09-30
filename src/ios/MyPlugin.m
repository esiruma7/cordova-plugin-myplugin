#import <Cordova/CDV.h>
#import <LegicMobileSdk/LegicMobileSdk.h>

@interface MyPlugin : CDVPlugin
- (void)sayHello:(CDVInvokedUrlCommand*)command;
@end

@implementation MyPlugin

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
