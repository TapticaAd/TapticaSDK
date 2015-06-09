//
//  HInterstitial.h
//  HydraSDK
//
//  Created by Nissim Pardo on 3/22/15.
//  Copyright (c) 2015 Hydra. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HRequestParams.h"

@class HInterstitial;

@protocol HInterstitialDelegate <NSObject>
@optional
#pragma mark Ad Request Lifecycle Notifications

/// Called when an interstitial ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)interstitialDidReceiveAd:(HInterstitial *)ad;

/// Called when an interstitial ad request completed without an interstitial to
/// show. This is common since interstitials are shown sparingly to users.
- (void)interstitial:(HInterstitial *)ad didFailToReceiveAdWithError:(NSError *)error;

#pragma mark Display-Time Lifecycle Notifications

/// Called just before presenting an interstitial. After this method finishes the interstitial will
/// animate onto the screen. Use this opportunity to stop animations and save the state of your
/// application in case the user leaves while the interstitial is on screen (e.g. to visit the App
/// Store from a link on the interstitial).
- (void)interstitialWillPresentScreen:(HInterstitial *)ad;

/// Called before the interstitial is to be animated off the screen.
- (void)interstitialWillDismissScreen:(HInterstitial *)ad;

/// Called just after dismissing an interstitial and it has animated off the screen.
- (void)interstitialDidDismissScreen:(HInterstitial *)ad;

/// Called just before the application will background or terminate because the user clicked on an
/// ad that will launch another application (such as the App Store). The normal
/// UIApplicationDelegate methods, like applicationDidEnterBackground:, will be called immediately
/// before this.
- (void)interstitialWillLeaveApplication:(HInterstitial *)ad;

@end

@interface HInterstitial : UIViewController
@property (nonatomic, copy) NSString *unitAdID;
@property (nonatomic, weak) id<HInterstitialDelegate> delegate;
@property (nonatomic, strong) HRequestParams *requestParams;
@property (nonatomic) NSTimeInterval dismissTime;

- (void)loadAd;
- (void)presentFromRootViewController:(UIViewController *)presentingViewController;
@end
