//
//  ASPopupAdController.h
//  ManageSDK
//
//  Created by Manage on 3/20/13.
//  Copyright (c) 2013 Manage. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ASPopupAdDelegate <NSObject>
-(void)popoverWillAppear;
-(void)popoverWillDisappear;
@optional
-(void)popoverDidFailToLoadWithError:(NSError*)error;
@end

typedef enum { AS_MALE, AS_FEMALE, AS_OTHER } Gender;

@interface ASPopupAdController : UIViewController
@property (nonatomic, strong) NSString *zoneId;
@property (nonatomic, weak) UIViewController *parentController;
@property (nonatomic, weak) id<ASPopupAdDelegate> delegate;
@property (nonatomic, assign) BOOL testMode;
@property (nonatomic, assign) BOOL devMode;
@property (nonatomic, assign) BOOL interstitialView;
@property (nonatomic, assign) NSString *country;
@property (nonatomic, assign) NSString *region;
@property (nonatomic, assign) NSString *metro;
@property (nonatomic, assign) NSString *city;
@property (nonatomic, assign) NSString *zip;
@property (nonatomic, assign) Gender *gender;
@property (nonatomic, assign) NSString *yob;
@property (nonatomic, assign) NSString *u_country;
@property (nonatomic, assign) NSString *u_city;
@property (nonatomic, assign) NSString *u_zip;
@property (nonatomic, assign) NSString *keywords;
@property (nonatomic, assign) NSString *longitude;
@property (nonatomic, assign) NSString *latitude;

-(ASPopupAdController*)enableLocationSupport;
-(ASPopupAdController*)initWithZoneId:(NSString*)adId;

/*
 * Preloads the ad.
 */
-(void)load;

/*
 * Presents the ad onto the current top ViewController
 * When ad is done being presented (closed), the ad is destroyed.
 * Load will need to be called to recreate the destroyed ad.
 */
-(void)presentAd;

@end
