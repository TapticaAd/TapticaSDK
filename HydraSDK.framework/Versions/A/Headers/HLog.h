//
//  QLog.h
//  QadabraSDK
//
//  Created by Nissim Pardo on 3/25/14.
//  Copyright (c) 2014 Marimedia LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "HLogManager.h"


extern NSString *const HLoggingNotification;
extern NSString *const HLogMessageKey;
extern NSString *const HLogMessageLevelKey;


void _HLog(HLogLevel logLevel, NSString *methodName, int lineNumber, NSString *format, ...);
void notifyListener(NSString *message, NSInteger messageLevel);

#define __FileName__ [[NSString stringWithUTF8String:__FILE__] lastPathComponent]
#define __LineNumber__ __LINE__
#define __MethodName__ [[NSString stringWithUTF8String:__func__] lastPathComponent]



#define HLogTrace(...) HLogManager.HLogLevel <= HLogLevelTrace ? _HLog(HLogLevelTrace,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#define HLogDebug(...) HLogManager.HLogLevel <= HLogLevelDebug ? _HLog(HLogLevelDebug,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#define HLogInfo(...) HLogManager.HLogLevel <= HLogLevelInfo ? _HLog(HLogLevelInfo,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#define HLogWarn(...) HLogManager.HLogLevel <= HLogLevelWarn ? _HLog(HLogLevelWarn,__MethodName__,__LineNumber__,__VA_ARGS__):nil
#define HLogError(...) HLogManager.HLogLevel <= HLogLevelError ? _HLog(HLogLevelError,__MethodName__,__LineNumber__,__VA_ARGS__):nil

