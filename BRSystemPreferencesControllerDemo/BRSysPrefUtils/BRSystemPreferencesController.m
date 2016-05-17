//
//  BRSystemPreferencesController.m
//  BRSystemPreferencesControllerDemo
//
//  Created by Yang on 5/12/16.
//  Copyright © 2016 Bokkk Rottt. All rights reserved.
//

#import "BRSystemPreferencesController.h"
#import "SystemPref.h"

NSString * const BRSysPrefIDUniversalAccessl = @"com.apple.preference.universalaccess";
NSString * const BRSysPrefIDAppstore = @"com.apple.preferences.appstore";
NSString * const BRSysPrefIDBluetooth = @"com.apple.preferences.Bluetooth";
NSString * const BRSysPrefIDDateTime = @"com.apple.preference.datetime";
NSString * const BRSysPrefIDDesktopScreenEffect = @"com.apple.preference.desktopscreeneffect";
NSString * const BRSysPrefIDSpeech = @"com.apple.preference.speech";
NSString * const BRSysPrefIDDisplays = @"com.apple.preference.displays";
NSString * const BRSysPrefIDDock = @"com.apple.preference.dock";
NSString * const BRSysPrefIDEnergySaver = @"com.apple.preference.energysaver";
NSString * const BRSysPrefIDExtensions = @"com.apple.preferences.extensions";
NSString * const BRSysPrefIDGeneral = @"com.apple.preference.general";
NSString * const BRSysPrefIDIcloud = @"com.apple.preferences.icloud";
NSString * const BRSysPrefIDInternetAccounts = @"com.apple.preferences.internetaccounts";
NSString * const BRSysPrefIDKeyboard = @"com.apple.preference.keyboard";
NSString * const BRSysPrefIDLocalization = @"com.apple.Localization";
NSString * const BRSysPrefIDExpose = @"com.apple.preference.expose";
NSString * const BRSysPrefIDMouse = @"com.apple.preference.mouse";
NSString * const BRSysPrefIDNetwork = @"com.apple.preference.network";
NSString * const BRSysPrefIDNotifications = @"com.apple.preference.notifications";
NSString * const BRSysPrefIDParentalcontrols = @"com.apple.preferences.parentalcontrols";
NSString * const BRSysPrefIDPrintfax = @"com.apple.preference.printfax";
NSString * const BRSysPrefIDSecurity = @"com.apple.preference.security";
NSString * const BRSysPrefIDSharing = @"com.apple.preferences.sharing";
NSString * const BRSysPrefIDSound = @"com.apple.preference.sound";
NSString * const BRSysPrefIDSpotlight = @"com.apple.preference.spotlight";
NSString * const BRSysPrefIDStartupdisk = @"com.apple.preference.startupdisk";
NSString * const BRSysPrefIDBackup = @"com.apple.prefs.backup";
NSString * const BRSysPrefIDTrackpad = @"com.apple.preference.trackpad";
NSString * const BRSysPrefIDUsers = @"com.apple.preferences.users";

@interface BRSystemPreferencesController ()
@property (readonly, nullable) SystemPrefApplication * application;

@end

@implementation BRSystemPreferencesController
{
    SystemPrefApplication * _application;
}

+ (instancetype)defaultController
{
    static BRSystemPreferencesController * defaultInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        defaultInstance = [BRSystemPreferencesController new];
    });
    return defaultInstance;
}

- (SystemPrefApplication *)application
{
    if (!_application) {
        _application = (SystemPrefApplication *)[SBApplication applicationWithBundleIdentifier:@"com.apple.systempreferences"];
    }
    return _application;
}

- (NSArray <NSString *> *)paneIdentifiers
{
    NSArray * arrResult = nil;
    arrResult = [self.application.panes valueForKeyPath:@"id"];
    return arrResult;
}

- (BOOL)showPaneWithIdentifier:(NSString *)identifier anchorName:(NSString *)anchorName
{
    if (!self.application) {
        return NO;
    }
    [self.application activate];
    
    __block BOOL bResult = NO;
    
    [self.application.panes enumerateObjectsUsingBlock:^(SystemPrefPane * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSString * objId = obj.id;
        if ([objId isEqualToString:identifier]) {
            if (anchorName.length) {
                [obj.anchors enumerateObjectsUsingBlock:^(SystemPrefAnchor * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
                    if ([obj.name isEqualToString:anchorName]) {
                        [obj reveal];
                        bResult = YES;
                        *stop = YES;
                    }
                }];
            }
            else {
                [obj reveal];
                bResult = YES;
            }
            *stop = YES;
        }
    }];
    
    return bResult;
}

@end
