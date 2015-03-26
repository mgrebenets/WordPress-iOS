#import <Foundation/Foundation.h>
#import "LoginService.h"

@protocol LoginViewModelDelegate;
@protocol ReachabilityService;
@protocol LoginService;
@protocol AccountCreationService;
@protocol BlogSyncService;
@class RACSignal;

@interface LoginViewModel : NSObject <LoginServiceDelegate>

// Services
@property (nonatomic, strong) id<ReachabilityService> reachabilityService;
@property (nonatomic, strong) id<LoginService> loginService;
@property (nonatomic, strong) id<AccountCreationService> accountCreationService;
@property (nonatomic, strong) id<BlogSyncService> blogSyncService;

@property (nonatomic, assign) BOOL authenticating;
@property (nonatomic, assign) BOOL shouldDisplayMultifactor;
@property (nonatomic, assign) BOOL userIsDotCom;
@property (nonatomic, assign) BOOL isSiteUrlEnabled;
@property (nonatomic, assign) BOOL isUsernameEnabled;
@property (nonatomic, assign) BOOL isPasswordEnabled;
@property (nonatomic, assign) BOOL isMultifactorEnabled;
@property (nonatomic, assign) BOOL cancellable;
@property (nonatomic, assign) BOOL hasDefaultAccount;
@property (nonatomic, assign) BOOL onlyDotComAllowed;
@property (nonatomic, readonly) NSString *signInButtonTitle;

@property (nonatomic, strong) NSString *siteUrl;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *multifactorCode;

@property (nonatomic, weak) id<LoginViewModelDelegate> delegate;

- (void)signInButtonAction;
- (NSString *)baseSiteUrl;
- (void)forgotPasswordButtonAction;
- (void)toggleSignInFormAction;
- (void)displayMultifactorTextField;

@end

@protocol LoginViewModelDelegate

- (void)showActivityIndicator:(BOOL)show;

- (void)setUsernameAlpha:(CGFloat)alpha;
- (void)setPasswordAlpha:(CGFloat)alpha;
- (void)setSiteAlpha:(CGFloat)alpha;
- (void)setMultiFactorAlpha:(CGFloat)alpha;

- (void)setUsernameEnabled:(BOOL)enabled;
- (void)setPasswordEnabled:(BOOL)enabled;
- (void)setSiteUrlEnabled:(BOOL)enabled;
- (void)setMultifactorEnabled:(BOOL)enabled;
- (void)setCancelButtonHidden:(BOOL)hidden;
- (void)setForgotPasswordHidden:(BOOL)hidden;
- (void)setSendVerificationCodeButtonHidden:(BOOL)hidden;
- (void)setAccountCreationButtonHidden:(BOOL)hidden;
- (void)setSignInButtonEnabled:(BOOL)enabled;
- (void)setSignInButtonTitle:(NSString *)title;
- (void)setToggleSignInButtonTitle:(NSString *)title;
- (void)setToggleSignInButtonHidden:(BOOL)hidden;
- (void)setPasswordTextReturnKeyType:(UIReturnKeyType)returnKeyType;
- (void)setFocusToSiteUrlText;
- (void)setFocusToMultifactorText;

- (void)displayErrorMessageForInvalidOrMissingFields;
- (void)displayReservedNameErrorMessage;
- (void)reloadInterfaceWithAnimation:(BOOL)animated;
- (void)openURLInSafari:(NSURL *)url;

// Ones we forward from LoginService
- (void)displayLoginMessage:(NSString *)message;
- (void)dismissLoginMessage;
- (void)displayRemoteError:(NSError *)error;
- (void)dismissLoginView;
- (void)showJetpackAuthentication;

@end
