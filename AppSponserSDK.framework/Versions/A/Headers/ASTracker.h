//
//  ASTracker.h
//  ManageSDK
//
//  Created by Manage on 4/5/13.
//  Copyright (c) 2013 Manage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ASTracker : NSObject
@property(nonatomic, strong)NSString* userId;
@property(nonatomic, strong)NSDictionary* parameters;

/*
 * Logs an event to the manage tracking servers. The eventKey should be 22 characters long.
 */
-(void)logEvent:(NSString*)eventKey;

/*
 * Same as logEvent: but only occurs first install of device.
 */
-(void)logOnFirstInstallEvent:(NSString*)eventKey;

@end

NSString *ASSHA1Digest(NSString *string);
BOOL ASAdvertisingTrackingEnabled();
NSString *ASAdvertisingIdentifier();

