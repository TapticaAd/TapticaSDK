//
//  QLogManager.h
//  QadabraSDK
//
//  Created by Nissim Pardo on 3/25/14.
//  Copyright (c) 2014 Marimedia LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

#define KP_DEBUG_MODE				1

typedef NS_ENUM(NSInteger, HLogLevel) {
    HLogLevelAll		= 0,
	HLogLevelTrace		= 10,
	HLogLevelDebug		= 20,
	HLogLevelInfo		= 30,
	HLogLevelWarn		= 40,
	HLogLevelError		= 50,
	HLogLevelOff		= 60
};

// use the `QLogManager` methods to set the desired level of log filter
@interface HLogManager : NSObject

// gets the current log filter level
+ (HLogLevel)HLogLevel;

// set the log filter level
+ (void)setHLogLevel:(HLogLevel)level;

+ (NSArray *)levelNames;
@end
