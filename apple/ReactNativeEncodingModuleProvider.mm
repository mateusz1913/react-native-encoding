#import "ReactNativeEncodingModuleProvider.h"
#import <ReactCommon/CallInvoker.h>
#import <ReactCommon/TurboModule.h>
#import "ReactNativeEncodingModule.h"

@implementation ReactNativeEncodingModuleProvider

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:(const facebook::react::ObjCTurboModule::InitParams &)params
{
    return std::make_shared<facebook::react::ReactNativeEncodingModule>(params.jsInvoker);
}

@end
