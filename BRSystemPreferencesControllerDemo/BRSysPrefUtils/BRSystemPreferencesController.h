//
//  BRSystemPreferencesController.h
//  BRSystemPreferencesControllerDemo
//
//  Created by Yang on 5/12/16.
//  Copyright © 2016 Bokkk Rottt. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for BRSysPrefUtils.
FOUNDATION_EXPORT double BRSysPrefUtilsVersionNumber;

//! Project version string for BRSysPrefUtils.
FOUNDATION_EXPORT const unsigned char BRSysPrefUtilsVersionString[];

NS_ASSUME_NONNULL_BEGIN

//Default Identifiers
extern NSString * const BRSysPrefIDUniversalAccessl;
extern NSString * const BRSysPrefIDAppstore;
extern NSString * const BRSysPrefIDBluetooth;
extern NSString * const BRSysPrefIDDateTime;
extern NSString * const BRSysPrefIDDesktopScreenEffect;
extern NSString * const BRSysPrefIDSpeech;
extern NSString * const BRSysPrefIDDisplays;
extern NSString * const BRSysPrefIDDock;
extern NSString * const BRSysPrefIDEnergySaver;
extern NSString * const BRSysPrefIDExtensions;
extern NSString * const BRSysPrefIDGeneral;
extern NSString * const BRSysPrefIDIcloud;
extern NSString * const BRSysPrefIDInternetAccounts;
extern NSString * const BRSysPrefIDKeyboard;
extern NSString * const BRSysPrefIDLocalization;
extern NSString * const BRSysPrefIDExpose;
extern NSString * const BRSysPrefIDMouse;
extern NSString * const BRSysPrefIDNetwork;
extern NSString * const BRSysPrefIDNotifications;
extern NSString * const BRSysPrefIDParentalcontrols;
extern NSString * const BRSysPrefIDPrintfax;
extern NSString * const BRSysPrefIDSecurity;
extern NSString * const BRSysPrefIDSharing;
extern NSString * const BRSysPrefIDSound;
extern NSString * const BRSysPrefIDSpotlight;
extern NSString * const BRSysPrefIDStartupdisk;
extern NSString * const BRSysPrefIDBackup;
extern NSString * const BRSysPrefIDTrackpad;
extern NSString * const BRSysPrefIDUsers;

@interface BRSystemPreferencesController : NSObject

+ (instancetype)defaultController;

@property (readonly, nullable) NSArray <NSString *> * paneIdentifiers;//!<getter will launch System Preference

- (BOOL)showPaneWithIdentifier:(NSString *)identifier
                    anchorName:(NSString  * _Nullable)anchorName;//!<You will pass nil.

@end
NS_ASSUME_NONNULL_END
