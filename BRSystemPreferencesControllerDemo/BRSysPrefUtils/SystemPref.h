/*
 * SystemPref.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class SystemPrefApplication, SystemPrefDocument, SystemPrefWindow, SystemPrefPane, SystemPrefAnchor;

enum SystemPrefSaveOptions {
	SystemPrefSaveOptionsYes = 'yes ' /* Save the file. */,
	SystemPrefSaveOptionsNo = 'no  ' /* Do not save the file. */,
	SystemPrefSaveOptionsAsk = 'ask ' /* Ask the user whether or not to save the file. */
};
typedef enum SystemPrefSaveOptions SystemPrefSaveOptions;

enum SystemPrefPrintingErrorHandling {
	SystemPrefPrintingErrorHandlingStandard = 'lwst' /* Standard PostScript error handling */,
	SystemPrefPrintingErrorHandlingDetailed = 'lwdt' /* print a detailed report of PostScript errors */
};
typedef enum SystemPrefPrintingErrorHandling SystemPrefPrintingErrorHandling;

@protocol SystemPrefGenericMethods

- (void) closeSaving:(SystemPrefSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) printWithProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.

@end



/*
 * Standard Suite
 */

// The application's top-level scripting object.
@interface SystemPrefApplication : SBApplication

- (SBElementArray<SystemPrefDocument *> *) documents;
- (SBElementArray<SystemPrefWindow *> *) windows;

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the active application?
@property (copy, readonly) NSString *version;  // The version number of the application.

- (id) open:(id)x;  // Open a document.
- (void) print:(id)x withProperties:(NSDictionary *)withProperties printDialog:(BOOL)printDialog;  // Print a document.
- (void) quitSaving:(SystemPrefSaveOptions)saving;  // Quit the application.
- (BOOL) exists:(id)x;  // Verify that an object exists.

@end

// A document.
@interface SystemPrefDocument : SBObject <SystemPrefGenericMethods>

@property (copy, readonly) NSString *name;  // Its name.
@property (readonly) BOOL modified;  // Has it been modified since the last save?
@property (copy, readonly) NSURL *file;  // Its location on disk, if it has one.


@end

// A window.
@interface SystemPrefWindow : SBObject <SystemPrefGenericMethods>

@property (copy, readonly) NSString *name;  // The title of the window.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Does the window have a close button?
@property (readonly) BOOL miniaturizable;  // Does the window have a minimize button?
@property BOOL miniaturized;  // Is the window minimized right now?
@property (readonly) BOOL resizable;  // Can the window be resized?
@property BOOL visible;  // Is the window visible right now?
@property (readonly) BOOL zoomable;  // Does the window have a zoom button?
@property BOOL zoomed;  // Is the window zoomed right now?
@property (copy, readonly) SystemPrefDocument *document;  // The document whose contents are displayed in the window.


@end



/*
 * System Preferences
 */

// System Preferences top level scripting object
@interface SystemPrefApplication (SystemPreferences)

- (SBElementArray<SystemPrefPane *> *) panes;

@property (copy) SystemPrefPane *currentPane;  // the currently selected pane
@property (copy, readonly) SystemPrefWindow *preferencesWindow;  // the main preferences window
@property BOOL showAll;  // Is SystemPrefs in show all view. (Setting to false will do nothing)

@end

// a preference pane
@interface SystemPrefPane : SBObject <SystemPrefGenericMethods>

- (SBElementArray<SystemPrefAnchor *> *) anchors;

- (NSString *) id;  // locale independent name of the preference pane; can refer to a pane using the expression: pane id "<name>"
@property (copy, readonly) NSString *localizedName;  // localized name of the preference pane
@property (copy, readonly) NSString *name;  // name of the preference pane as it appears in the title bar; can refer to a pane using the expression: pane "<name>"

- (id) reveal;  // Reveals an anchor within a preference pane or preference pane itself
- (SystemPrefPane *) authorize;  // Prompt authorization for given preference pane

@end

// an anchor within a preference pane
@interface SystemPrefAnchor : SBObject <SystemPrefGenericMethods>

@property (copy, readonly) NSString *name;  // name of the anchor within a preference pane

- (id) reveal;  // Reveals an anchor within a preference pane or preference pane itself

@end

