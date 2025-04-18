# Changelog
All notable changes to the Chartbeat iOS SDK  will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).
## [1.5.12] - 2025-04-16
### Added
- Added conversion ping tracking

## [1.5.11] - 2025-04-09
### Added
- Added video ping tracking

## [1.5.10] - 2025-03-06
### Added
- Same as 1.5.9 but need to codesign Chartbeat.xcframework

## [1.5.9] - 2025-02-21
### Added
- Xcode 16 update and bitwise issue

## [1.5.8] - 2024-09-04
### Added
- Updated code signature and privacy manifest file.

## [1.5.7] - 2024-05-28
### Added
- Addressed source tag issue

## [1.5.6] - 2024-05-23
### Added
- Added idsync and video ping(pong) features from 1.5.1-rc4 beta version

## [1.5.5] - 2024-05-07
### Added
- Added signature for Chartbeat.xcframework file

## [1.5.4] - 2024-04-30
- Incorrect push, ignore this version

## [1.5.3] - 2024-04-24
### Added
- Added Privacy Manifest references to podspec file

## [1.5.2] - 2024-01-24
### Added
- Added Privacy Manifest
- Bump minimum supported IOS version to 12

## [1.5.0] - 2022-09-08
### Added
- Switch to XCFramework
- Add support for arm64 iOS Simulator
- Does not include id-sync and video pong work from 1.5.1-rc versions

## [1.4.9] - 2021-07-29
### Added
- Only exclude arm64 i386 in simulator

## [1.4.8] - 2021-07-22
### Added
- Remove arm64 restraint in simulator

## [1.4.7] - 2021-07-08
### Added
- Remove file MediaPlayerTracker.h to suppress warning "'MPMoviePlayerController' is deprecated: first deprecated in iOS 9.0 - Use AVPlayerViewController in AVKit"

## [1.4.6] - 2021-06-01
### Added
- Removed video support from ios sdk

## [1.4.5] - 2021-02-26
### Added
- Addressed build issue with arm64 from 1.4.4 update

## [1.4.4] - 2021-02-25
### Added
- Addressed build issue with arm64 from 1.4.3 update

## [1.4.3] - 2021-02-18
### Added
- Addressed issue CI-1236 with prepending slash on viewId.

## [1.4.1] - 2019-02-21
### Added
- Addressed issue with collision between CB SDK and 3rd party namespace.

## [1.4.0] - 2019-02-21
### Added
- Add subscription support to sdk.

## [1.3.1] - 2019-01-31
### Addressed
- Addressed issues with names of library enums colliding with other standard libraries.

## [1.3.0] - 2018-10-16
### Added
- Added support for tracking site visits (depth, ids and engagement)
- Added support for push alert referrer tracking.
