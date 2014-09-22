//
//  GoogAnalytics.m
//  SETNews
//
//  Created by Eden on 9/16/14.
//  Copyright (c) 2014 SET. All rights reserved.
//

#import "GoogAnalytics.h"


@implementation GoogAnalytics

static GoogAnalytics *GAInstance = nil;
static NSString *const kTrackingId = @"UA-52595319-1";
static NSString *const kAllowTracking = @"TestGA";

@synthesize eventCategory;
@synthesize eventAction;
@synthesize eventLabel;
@synthesize eventValue;

+(GoogAnalytics *)shareInstance
{
    if (!GAInstance) {
        GAInstance = [[GoogAnalytics alloc] init];
    }
    
    return GAInstance;
}

- (void)GAIEventInstance:(NSString *)category Action:(NSString *)action Label:(NSString *)label Value:(NSNumber *)value
{
    NSMutableDictionary *event =
    [[GAIDictionaryBuilder createEventWithCategory:category
                                            action:action
                                             label:label
                                             value:value] build];
    [[GAI sharedInstance].defaultTracker send:event];
    [[GAI sharedInstance] dispatch];

}

- (void)GAIEventCategory:(NSString *)category
{
    eventCategory = category ;
    [self GAIEventInstance:eventCategory Action:nil Label:nil Value:nil];
}

- (void)GAIEventAction:(NSString *)action
{
    eventAction = action;
    [self GAIEventInstance:eventCategory Action:eventAction Label:nil Value:nil];
}

- (void)GAIEventLabel:(NSString *)label LabelValue:(NSNumber *)value
{
    eventValue = value;
    eventLabel = label;
    
    [self GAIEventInstance:eventCategory Action:eventAction Label:eventLabel Value:eventValue];
    [self GAIScreen:label];
}


- (void)GAIDelegateSetting{
    //GA
    NSDictionary *appDefaults = @{kAllowTracking: @(YES)};
    [[NSUserDefaults standardUserDefaults] registerDefaults:appDefaults];
    // User must be able to opt out of tracking
    [GAI sharedInstance].optOut = ![[NSUserDefaults standardUserDefaults] boolForKey:kAllowTracking];
    // Initialize Google Analytics with a 120-second dispatch interval. There is a
    // tradeoff between battery usage and timely dispatch.
    [GAI sharedInstance].dispatchInterval = 120;
    [GAI sharedInstance].trackUncaughtExceptions = YES;
    self.tracker = [[GAI sharedInstance] trackerWithName:kAllowTracking
                                              trackingId:kTrackingId];
}

- (void)GAIScreen:(NSString *)ScreenName{
    
    [self.tracker set:kGAIScreenName value:ScreenName];
    [self.tracker send:[[GAIDictionaryBuilder createScreenView] build]];
}

@end
