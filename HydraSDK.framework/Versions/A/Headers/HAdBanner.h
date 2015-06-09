//
//  HAdView.h
//  HydraSDK
//
//  Created by Nissim Pardo on 3/12/15.
//  Copyright (c) 2015 Hydra. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HRequestParams.h"

extern NSString *const BannerTypeNotification;

@class HAdBanner;
@protocol HAdBannerDelegate <NSObject>

@optional

#pragma mark Ad Request Lifecycle Notifications

/// Called when an ad request loaded an ad. This is a good opportunity to add this view to the
/// hierarchy if it has not been added yet.
- (void)adViewDidReceiveAd:(HAdBanner *)adView;

/// Called when an ad request failed. Normally this is because no network connection was available
/// or no ads were available (i.e. no fill).
- (void)adView:(HAdBanner *)adView didFailToReceiveAdWithError:(NSError *)error;

#pragma mark Click-Time Lifecycle Notifications

/// Called just before presenting the user a full screen view, such as a browser, in response to
/// clicking on an ad. Use this opportunity to stop animations, time sensitive interactions, etc.
///
/// Normally the user looks at the ad, dismisses it, and control returns to your application by
/// calling adViewDidDismissScreen:. However if the user hits the Home button or clicks on an App
/// Store link your application will end. On iOS 4.0+ the next method called will be
/// applicationWillResignActive: of your UIViewController
/// (UIApplicationWillResignActiveNotification). Immediately after that adViewWillLeaveApplication:
/// is called.
- (void)adViewWillPresentScreen:(HAdBanner *)adView;

/// Called just before dismissing a full screen view.
- (void)adViewWillDismissScreen:(HAdBanner *)adView;

/// Called just after dismissing a full screen view. Use this opportunity to restart anything you
/// may have stopped as part of adViewWillPresentScreen:.
- (void)adViewDidDismissScreen:(HAdBanner *)adView;

/// Called just before the application will background or terminate because the user clicked on an
/// ad that will launch another application (such as the App Store). The normal
/// UIApplicationDelegate methods, like applicationDidEnterBackground:, will be called immediately
/// before this.
- (void)adViewWillLeaveApplication:(HAdBanner *)adView;

@end


#pragma mark Standard Sizes

/// iPhone and iPod Touch ad size. Typically 320x50.
extern CGSize const kHAdSizeBanner;

/// Medium Rectangle size for the iPad (especially in a UISplitView's left pane). Typically 300x250.
extern CGSize const kHAdSizeMediumRectangle;

/// Full Banner size for the iPad (especially in a UIPopoverController or in
/// UIModalPresentationFormSheet). Typically 468x60.
extern CGSize const kHAdSizeFullBanner;

/// Leaderboard size for the iPad. Typically 728x90.
extern CGSize const kHAdSizeLeaderboard;

/// Skyscraper size for the iPad. Mediation only. AdMob/Google does not offer this size. Typically
/// 120x600.
extern CGSize const kHAdSizeSkyscraper;



@interface HAdBanner : UIView {
    @protected
    CGSize size;
    CGPoint origin;
}
- (instancetype)initWithAdSize:(CGSize)size origin:(CGPoint)origin;

@property (nonatomic, copy) NSString *unitAdID;
@property (nonatomic, weak) id<HAdBannerDelegate> delegate;
@property (nonatomic, weak) UIViewController *rootViewController;
@property (nonatomic, strong) HRequestParams *requestParams;
- (void)loadAd;
@end
