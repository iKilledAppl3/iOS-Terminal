// MobileTerminalViewController.h
// MobileTerminal

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import "MenuView.h"

@class TerminalGroupView;
@class TerminalKeyboard;
@class GestureResponder;
@class GestureActionRegistry;

// Protocol to get notified about when the preferences button is pressed.
// TOOD(allen): We should find a better way to do this.
@protocol MobileTerminalInterfaceDelegate
@required
- (void)preferencesButtonPressed;
- (void)rootViewDidAppear;
@end

@interface MobileTerminalViewController : UIViewController <MenuViewDelegate> {
@private
  UIView* contentView;
  TerminalGroupView* terminalGroupView;
  UIPageControl* terminalSelector;
  IBOutlet UIScrollView *fnscroller,*specialscroller;
  TerminalKeyboard* terminalKeyboard;
  BOOL shouldShowKeyboard;
  // If the keyboard is actually shown right now (not if it should be shown)
  BOOL keyboardShown;
  BOOL copyPasteEnabled;
  UIButton* preferencesButton;
  UIButton* menuButton;
  MenuView* menuView;
  id<MobileTerminalInterfaceDelegate> interfaceDelegate;
  GestureResponder* gestureResponder;
  GestureActionRegistry* gestureActionRegistry;
}

@property (nonatomic, retain) IBOutlet UIView* contentView;
@property (nonatomic, retain) IBOutlet TerminalGroupView* terminalGroupView;
@property (nonatomic, retain) IBOutlet UIPageControl* terminalSelector;
@property (nonatomic, retain) IBOutlet UIButton* preferencesButton;
@property (nonatomic, retain) IBOutlet UIButton* menuButton;
@property (nonatomic, retain) IBOutlet id<MobileTerminalInterfaceDelegate> interfaceDelegate;
@property (nonatomic, retain) IBOutlet MenuView* menuView;
@property (nonatomic, retain) IBOutlet GestureResponder* gestureResponder;
@property (nonatomic, retain) IBOutlet GestureActionRegistry* gestureActionRegistry;

- (void)terminalSelectionDidChange:(id)sender;
- (void)preferencesButtonPressed:(id)sender;
- (void)menuButtonPressed:(id)sender;
- (void)selectedCommand:(NSString*)command;
- (void)toggleKeyboard:(id)sender;
- (void)toggleCopyPaste:(id)sender;
- (IBAction)esc:(id)sender;
- (IBAction)tab:(id)sender;
- (IBAction)up:(id)sender;
- (IBAction)down:(id)sender;
- (IBAction)left:(id)sender;
- (IBAction)right:(id)sender;
- (IBAction)hidefn:(id)sender;
- (IBAction)showfn:(id)sender;
- (IBAction)fn:(id)sender;
- (IBAction)pipe:(id)sender;
- (IBAction)slash:(id)sender;
- (IBAction)hyphen:(id)sender;
- (IBAction)bar:(id)sender;
- (IBAction)semiCoron:(id)sender;
- (IBAction)keyboard:(id)sender;

@end

