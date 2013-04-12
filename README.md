# iOS Documentation 

## Ads

### Adding the Library 
Add the ManageSDK.framework file to the project and add to the Link Binary With Libraries Panel under the projects Targets -> Build Phases
Also add the **AdSupport** framework to the project.

Use the following import where needed:

```objective-c
#import <ManageSDK/MNGPopupAdController.h>
```

### Interface 
```objective-c
@interface MNGPopupAdController : UIViewController
@property (nonatomic, strong) NSString *zoneId;
@property (nonatomic, weak) UIViewController *parentController;
@property (nonatomic, weak) id<MNGPopupAdDelegate> delegate;
@property (nonatomic, assign)BOOL testMode;

-(MNGPopupAdController*)initWithZoneId:(NSString*)zoneId;
-(void)load;
-(void)presentAd;
```

### Presenting an ad 
```objective-c
NSString *zoneId = @"XXXXXXXXXXXXXXXXXXXXXX";
MNGPopupAdController *popupAd = [[MNGPopupAdController alloc] initWithZoneId:zoneId];
[popupAd presentAd];
```

The ad gets displayed in whatever orientation the ad is at the time it is loaded and does not rotate with the app.

The zone id can be found in [Setting up an Ad Campaign](#setting-up-an-ad-campaign).

Please note: the MNGPopupAd does not need to be added to the controller hierarchy. It overlays whatever the top controller is at the time the ad is ready to be displayed.

To ignore frequency caps set to a particular ad, enable testMode by adding the following after initializing the ad.
```objective-c
#ifdef DEBUG
    popupAd.testMode = YES;
#endif
```

### Presenting an ad on startup 

Place the ad presentation code (shown above) in the applicationDidBecomeActive method in the application delegate to present the ad on start up.

### Delegate 
```objective-c
@protocol MNGPopupAdDelegate <NSObject> 
-(void)popoverWillAppear;
-(void)popoverWillDisappear;
@optional -(void)popoverDidFailToLoadWithError:(NSError*)error;
@end
```

Hook into the delegate to manage events before and after the popovers appear.
Add <MNGPopupAdDelegate> to your class and set the popupAdController delegate to self.
```objective-c
@interface YourViewController () <MNGPopupAdDelegate>

// ...

// Your initialization code
MNGPopupAdController *popup = [[MNGPopupAdController alloc] initWithZoneId:@"xxxxxxxxxxxxxxxxxxxxxx"];
popup.delegate = self;

// ....

-(void)popoverWillAppear {
	NSLog(@"Do pre-popup code here");
}

-(void)popoverWillDisappear {
    NSLog(@"Do post-popup code here");    
}

-(void)popoverDidFailToLoadWithError:(NSError *)error {
    NSLog(@"Optionally do something when ad fails to load, or fail to show ad silently");    
}

```


Examples include Stoping music, pausing levels, etc.

### Caching 

The load method caches the ad for its current orientation. 
The ad will be cached relative to the current orientation of the screen.

```objective-c
_popup = [[MNGPopupAdController alloc] initWithZoneId:@"xxxxxxxxxxxxxxxxxxxxxx"];
[_popup load];

// Somewhere later
[_popup presentAd];
```


### Setting up an Ad Campaign 

Go to RTB.com and login.

From "My Apps", click "Create a New App" and fill in all required information.

Create a human readable Zone Name corresponding to the location of your app. For example, this could be "On App Start" if you want your ad to load at the beginning of the app. If your ad comes up after level 2, title it "After Level 2".

Select the Default Orientation of your app. This is the orientation that your app is set to be when it is first launched. Create the Zone.

After you have created the zone, "Your Zone ID" should appear. Copy the value and use that for the initWithZoneId call.
