//
//  ASPopupAd.h
//  AppSponsorSDKFramework
//
//  Copyright (c) 2015 manage. All rights reserved.
//
#define AS_SDK_VERSION                 @"3.1.1"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * Ad disappeared because the user has clicked on it
 */
static NSString * const kASReasonUserClicked = @"clicked";
/**
 * Ad disappeared because the user has closed the ad playing activity
 */
static NSString * const kASReasonUserClosed = @"close";
/**
 * Ad disappeared because of an error
 */
static NSString * const kASError = @"error";

static NSString * const kASEnableLocationSupportKey = @"enableLocationSupport";

static NSString * const kASCountryKey = @"country";
static NSString * const kASCityKey = @"city";
static NSString * const kASRegionKey = @"region";
static NSString * const kASMetroKey = @"metro";
static NSString * const kASZipKey = @"zip";

static NSString * const kASUCountryKey = @"u_country";
static NSString * const kASUCityKey = @"u_city";
static NSString * const kASUZipKey = @"u_zip";
static NSString * const kASLatitudeKey = @"latitude";
static NSString * const kASLongitudeKey = @"longitude";

static NSString * const kASGenderKey = @"gender";
static NSString * const kASYearOfBirthKey = @"yob";
static NSString * const kASKeywordsKey = @"keywords";
static NSString * const kASPublicUidKey = @"pub_uid";
static NSString * const kASPlatformKey = @"pf";

static const CGFloat kASDefaultTimeoutSeconds = 30.0f;

static NSString * const kASErrorDomain = @"com.AppSponsor.SDK";

typedef enum { AS_MALE = 1, AS_FEMALE = 2, AS_OTHER = 3 } Gender;

@protocol ASPopupAdDelegate <NSObject>
/**
 * Called when an ad is loaded and going to be presented to the user
 */
- (void)popoverWillAppear;
/**
 * Called when an ad is going to be dismissed
 * @param reason - Ad dismiss reason
 */
- (void)popoverWillDisappear:(NSString*)reason;
@optional
/**
 * Called once an ad is loaded
 */
- (void)didCacheInterstitial;
/**
 * Called if some error has happened during the ad playing cycle
 * @param exception - Error occurred
 */
- (void)popoverDidFailToLoadWithError:(NSError*)error;
/**
 * Called once a rewarded ad was completely played
 */
- (void)onRewardedAdFinished;
@end

@class ASAdContext;
@interface ASPopupAd : NSObject

@property (nonatomic, strong) UIViewController *parentController;
@property (nonatomic, weak) id<ASPopupAdDelegate> delegate;

@property (nonatomic, strong) NSString *zoneId;
@property (nonatomic, strong) NSString *country;
@property (nonatomic, strong) NSString *region;
@property (nonatomic, strong) NSString *metro;
@property (nonatomic, strong) NSString *city;
@property (nonatomic, strong) NSString *zip;
@property (nonatomic, assign) Gender* gender;
@property (nonatomic, strong) NSString *yob;
@property (nonatomic, strong) NSString *u_country;
@property (nonatomic, strong) NSString *u_city;
@property (nonatomic, strong) NSString *u_zip;
@property (nonatomic, strong) NSString *keywords;
@property (nonatomic, strong) NSString *longitude;
@property (nonatomic, strong) NSString *latitude;
@property (nonatomic, strong) NSString *pub_uid; //user id within publisher app
@property (nonatomic, strong) NSString* pf;
@property (nonatomic, strong) ASAdContext *adContext;

- (ASPopupAd*)enableLocationSupport;
- (ASPopupAd*)initWithZoneId:(NSString*)adId;
- (ASPopupAd*)initRewardedAdWithZoneId:(NSString*)adId andUserID:(NSString*)uid;

/**
 * Asynchronously loads ad. Use {@link #isReady() isReady} method to check whether the ad is loaded or not
 */
- (void)load;

/**
 * Asynchronously loads ad. Displays an ad immediately upon load
 * During a period of {@link #kASDefaultTimeoutSeconds kASDefaultTimeoutSeconds} loading either succeeds or fails with a timeout error
 */
- (void)loadAndPresentAd;

/**
 * Asynchronously loads an ad. Displays an ad immediately upon load
 * During custom timeout loading either succeeds or fails with a timeout error
 * @param seconds - custom timeout
 */
- (void)loadAndPresentAdWithTimeout:(CGFloat)seconds;

/**
 * Shows an ad in a separate activity. The call is ignored if the ad is not yet loaded.
 */
- (void)presentAd;

/**
 * @return boolean Return true if ad load is finished
 */
- (BOOL)isReady;

/**
 * @return int percentage (0 - 100) of video ad being played
 */
- (NSInteger)rewardedAdStatus;

@end
