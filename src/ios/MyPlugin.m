#import <Cordova/CDV.h>

@interface MyPlugin : CDVPlugin
- (void)sayHello:(CDVInvokedUrlCommand*)command;
@end

@implementation MyPlugin

- (void)sayHello:(CDVInvokedUrlCommand*)command {
    NSString* msg = [command.arguments objectAtIndex:0];
    NSString* response = [NSString stringWithFormat:@"Hello from iOS: %@", msg];

    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:response];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}
@end
