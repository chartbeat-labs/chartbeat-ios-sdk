// -*- mode: objc -*-
//
// Copyright (C) 2012 Chartbeat Inc. All Rights Reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreGraphics/CoreGraphics.h>

extern NSString * const kCBPingHost;
extern NSString * const kCBPongHost;



/*
 * Deprecated: these constants already include a trailing "?" in their value ("https://{ping|pong}.chartbeat.net/ping?")
 * which prevents appending custom path components before the query string (meaning before ?).
 * Use kCBPingHost / kCBPongHost instead, which expose the host only (https://{ping|pong}.chartbeat.net)
 * and lets callers dynamically construct the full URL path themselves
 * by appending additional path-params like /ping and sometimes /conversion-event and plus "?" at the end before url params
 *
 * NOTE: we are not yet deleting these variables because it is possible (but highly unlikely) that someone might be using them direcly
 * We can fully remove them on major version update (e.g X.Y.Z -> when X position gets bumped in pods version number for chartbeat SDK)
 */
extern NSString * const kCBPingURLBase __attribute__((deprecated("Use kCBPingHost instead.")));
extern NSString * const kCBPongURLBase __attribute__((deprecated("Use kCBPongHost instead.")));



extern NSString * const kCBPagePathKeyForVideo;
extern NSString * const kCBPageDomainKeyForVideo;
extern NSString * const kCBPageAppIdKeyForVideo;
extern NSString * const kCBPageTitleKeyForVideo;
extern NSString * const kCBContentEngagementKeyForVideo;

/* Video Related Keys on Page */
extern NSString * const kCBVideoPathKeyForPage;
extern NSString * const kCBVideoTitleKeyForPage;
extern NSString * const kCBVideoHostKeyForPage;

/* Common Keys */
extern NSString * const kCBPathKey;
extern NSString * const kCBTitleKey;
extern NSString * const kCBHostKey;
extern NSString * const kCBVideoTypeKey;
extern NSString * const kCBVideoDurationKey;
extern NSString * const kCBVideoStateKey;
extern NSString * const kCBVideoThumbnailKey;

extern const NSNotificationName kCBDidSendPingRequestNotification;
extern const NSNotificationName kCBWillSendPingRequestNotification;
extern NSString * const kCBDidSendPingRequestNotificationURLKey;

@interface CBPing : NSObject {
  /**
   * Did last ping result in an error?
   */
  BOOL lastWasError;
  NSMutableDictionary *previousRequests;

  /**
   * If not null, don't send pings until the given date.
   */
  NSDate* lockOutEnd;
}

@property (nonatomic) BOOL referrerSent;
@property (nonatomic, assign) BOOL usePong;

- (void)trackAccountID:(uint)accountId 
             firstPing:(BOOL)firstPing
                domain:(NSString *)domain 
             subDomain:(NSString *)subDomain
                  path:(NSString *)path
                 title:(NSString *)title 
                   new:(BOOL)new
                 decay:(uint)decay 
             userToken:(NSString *)userToken 
          sessionToken:(NSString *)sessionToken 
             dwellTime:(uint)dwell 
         contentHeight:(CGFloat)height
          contentWidth:(CGFloat)contentWidth
        scrollPosition:(CGFloat)scrollPosition
     maxScrollPosition:(uint)maxScrollPosition
              lastPath:(NSString *)lastPath
               authors:(NSArray *)authors
              sections:(NSArray *)sections
                 zones:(NSArray *)zones
           appReferrer:(NSString *)appReferrer
                 appid:(NSString *)appid
             userAgent:(NSString *)userAgent
          screenHeight:(float)screenHeight
           screenWidth:(float)screenWidth
              location:(CLLocation *)location
             frequency:(NSString *)frequency
              userRead:(BOOL)userRead
             userWrote:(BOOL)userWrote
        engagedSeconds:(uint)engagedSeconds
engagedSecondsSinceLastPing:(uint)engagedSecondsSinceLastPing
    pingEndpointVersion:(uint)pingEndpointVersion
            sdkVersion:(NSString *)sdkVersion
        siteVisitDepth:(long)siteVisitDepth
     siteVisitReferrer:(NSString *)siteVisitReferrer
          siteVisitUid:(NSString *)siteVisitUid
     subscriptionState:(NSString *)subscriptionState
  previousSessionToken:(NSString *)previousSessionToken
                idSync:(NSDictionary<NSString *, NSString *> *)idSync
                videoParams:(NSDictionary *)videoParams;

- (void)sendConversionPing:(NSDictionary *)params userAgent:(NSString *)userAgent;

+ (NSString *)urlEncode:(NSString *)str;

@end
