#import <Cordova/CDV.h>

@interface MyPlugin : CDVPlugin
- (void)sayHello:(CDVInvokedUrlCommand*)command;
@end

@implementation MyPlugin
- (void)sayHello:(CDVInvokedUrlCommand*)command {
    NSString* msg = [command.arguments objectAtIndex:0];
    CDVPluginResult* result = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK
                                               messageAsString:[@"Hello " stringByAppendingString:msg]];
    [self.commandDelegate sendPluginResult:result callbackId:command.callbackId];
}
@end
