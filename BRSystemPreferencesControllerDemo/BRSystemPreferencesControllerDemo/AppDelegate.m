//
//  AppDelegate.m
//  BRSystemPreferencesControllerDemo
//
//  Created by Yang on 5/12/16.
//  Copyright © 2016 Bokkk Rottt. All rights reserved.
//

#import "AppDelegate.h"
#import <BRSysPrefUtils/BRSysPrefUtils.h>

@interface AppDelegate ()

@property (weak) IBOutlet NSWindow *window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    
}

- (void)applicationWillTerminate:(NSNotification *)aNotification {
    // Insert code here to tear down your application
}

- (IBAction)showSystemPre:(id)sender {
    BRSystemPreferencesController * sysPrefCtl = [BRSystemPreferencesController defaultController];
    NSLog(@"%@", sysPrefCtl.paneIdentifiers);

//    [sysPrefCtl showPaneWithIdentifier:BRSysPrefIDGeneral anchorName:nil];
}

@end
