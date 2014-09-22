//
//  GoogAnalytics.h
//
//  Created by Eden on 9/17/14.
//  Copyright (c) 2014 SET. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleAnalytics-iOS-SDK/GAI.h>
#import <GoogleAnalytics-iOS-SDK/GAITrackedViewController.h>
#import <GoogleAnalytics-iOS-SDK/GAIDictionaryBuilder.h>
#import <GoogleAnalytics-iOS-SDK/GAIFields.h>

@interface GoogAnalytics : NSObject

@property (nonatomic, strong) NSString *eventCategory;
@property (nonatomic, strong) NSString *eventAction;
@property (nonatomic, strong) NSString *eventLabel;
@property (nonatomic, strong) NSNumber *eventValue;
@property(nonatomic, strong) id<GAITracker> tracker;

+ (GoogAnalytics *)shareInstance;

/**
 * @brief Google Analytics Events
 *
 * @param Category : 事件類別
 *
 * @return void
 *
 * @exception
 *
 * @see
 *
 * @warning 
 *
 * @bug
 */
- (void)GAIEventCategory:(NSString *)category;

/**
 * @brief Google Analytics Event Action
 *
 * @param action : 事件動作
 *
 * @return void
 *
 * @exception
 *
 * @see
 *
 * @warning
 *
 * @bug 
 */
- (void)GAIEventAction:(NSString *)action;

/**
 * @brief Google Analytics Event Label
 *
 * @param label : 活動標籤 
 * @param Value:單一事件價值
 *
 * @return void
 *
 * @exception
 *
 * @see
 *
 * @warning
 *
 * @bug 
 */
- (void)GAIEventLabel:(NSString *)label LabelValue:(NSNumber *)value;

/**
 * @brief Google Analytics Complete Event
 *
 * @param category : 事件類別 
 * @param action : 事件活動 
 * @param label : 活動標籤
 * @param value : 單一事件價值
 *
 * @return void
 *
 * @exception
 *
 * @see
 *
 * @warning
 *
 * @bug 
 */
- (void)GAIEventInstance:(NSString *)category Action:(NSString *)action Label:(NSString *)label Value:(NSNumber *)value;

/**
 * @brief Google Analytics AppDelegate Setting.
 
 *        Google Analytics 初始化設定.
 *
 * @param
 *
 * @return void
 *
 * @exception 
 *
 * @warning Before Use Check kTrackingId is Set.
 *
 * @bug
 */
- (void)GAIDelegateSetting;

/**
 * @brief Google Analytics Screen
 *
 * @param ScreenName : 畫面名稱
 *
 * @return nil
 *
 * @exception
 *
 * @see
 *
 * @warning
 *
 * @bug 
 */
- (void)GAIScreen:(NSString *)ScreenName;

@end