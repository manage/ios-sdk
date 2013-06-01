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

@interface ASPopupAdController : UIViewController
@property (nonatomic, strong) NSString *zoneId;
@property (nonatomic, weak) UIViewController *parentController;
@property (nonatomic, weak) id<ASPopupAdDelegate> delegate;
@property (nonatomic, assign)BOOL testMode;

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
