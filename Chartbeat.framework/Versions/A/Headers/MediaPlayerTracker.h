//
//  MediaPlayerTracker.h
//  Chartbeat-iOS-SDK-Example
//
//  Created by eytan on 2/28/14.
//
//

#import <MediaPlayer/MediaPlayer.h>
#import <Foundation/Foundation.h>

@interface MediaPlayerTracker : NSObject

enum {
    CBUnknown = 0,
    CBUnstarted = 1,
    CBPlaying = 2,
    CBPaused = 3,
    CBEnded = 4,
};
typedef NSInteger CBVideoState;

enum {
  CBContent = 1,
  CBAd = 2
};
typedef NSInteger CBVideoType;

- (id)initWithMediaPlayer:(MPMoviePlayerController *)movieController_ title:(NSString *)title_ thumbnail:(NSString *)thumbnail_;
- (CBVideoState) getState;
- (int) getCurrentPlayTime;
- (int) getTotalDuration;
- (CGFloat) getBitRate;
- (NSString *) getThumbnailPath;
- (NSURL *) getVideoPath;
- (NSString *) getTitle;
- (CBVideoType) getVideoType;

@end
