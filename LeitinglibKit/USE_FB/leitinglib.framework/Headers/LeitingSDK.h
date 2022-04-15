//
//  LeitingSDK.h
//  leitinglib
//
//  Created by 陈海青 on 15/12/15.
//  Copyright © 2015年 陈海青. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LeitingCallBack.h"

typedef void(^InitCallable)(void);

#if __IPHONE_OS_VERSION_MIN_REQUIRED < 90000
#error "LEITING SDK doesn't support iOS 8.x and lower. Please, change your minimum deployment target to iOS 9.0"
#endif

typedef enum : NSUInteger {
    LTLoginTypeFacebook = 1 << 2,
    LTLoginTypeGameCenter = 1 << 3,
    LTLoginTypeTwitter = 1 << 4,
    LTLoginTypeLeiTing = 1 << 5,
    LTLoginTypeApple = 1 << 12,
} LTLoginType;

@interface LeitingSDK : NSObject<LeitingCallBackDelegate>

@property (nonatomic, assign) id<LeitingCallBackDelegate> delegate;

@property (nonatomic, copy)NSString *leitingNo;
@property (nonatomic, copy)NSString *currency_type;//货币种类
@property (nonatomic, assign)BOOL isClickTW;//是否点击了twitter切换账号
@property InitCallable initCallable; //初始化回调


//初始化并获取静态变量
+ (LeitingSDK *)getInstance;

+ (NSString *)getChannelNo;
+ (NSString *)getLeitingGame;
+ (NSString *)getGameName;
+ (NSString *)getActivate;


#pragma mark - ---  配置所需要使用到的信息  ---
+ (void)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOption;

+ (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
            options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

+ (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation;

+ (void)applicationDidBecomeActive:(UIApplication *)application;

//用于处理twitter sdk 相关bug问题配置
- (void)applicationWillResignActive:(UIApplication *)application;


#pragma mark - ---  LeitingSDK  ---
//初始化一次，传全局的参数
+ (void)init:(NSString *)defaultLanguage callback:(void(^)(void))callback;


/// 获取设备信息  AppsFlyer ID 、mac（同国内）
+ (NSString *)getDeviceInfo;

/**
 打开个人中心界面
 */
- (void)accountCenter;

/**
 拉起账号绑定界面
 */
- (void)showBindAccountPage;


//快速充值接口
- (void)pay:(NSString *)parametersStr;


//设置 SDK 的显示语言类型(默认和系统语言一致)
-(void)setLanguage:(NSString *)languageCode callable:(void(^)(NSString *))callable;


//返回当前语言，字符串
- (NSString *) getLanguage;

/**
 调用登录,后期使用login接口
 */
- (void)loginInAuto DEPRECATED_MSG_ATTRIBUTE("use login instead");

/**
 调用登录
 */
- (void)login;

/**
 注销
 */
-(void)logout;

/**
 绑定账号,登录账号，登出账号

 @param loginType 传入绑定类型
 */
- (void)connect:(LTLoginType )loginType ;

/**
 绑定账号,登录账号，登出账号
 
 @param loginType 传入绑定类型(结果通过 logoutCallBack 返回，其中 type = loginType)
 */
- (void)disConnect:(LTLoginType )loginType ;

/**
 分享接口

 @param manager 分享方式，facebook:传入参数@"2"
 @param params 传入分享内容的参数，具体详见文档
 */
- (void)share:(NSString *)manager params:(NSString *)params;

/**
 返回 bind 的状态

 @return 返回 bind 状态 (与LTLoginType进行“与”操作，结果不为0，则不绑定过这一渠道，否则未绑定过。)
 */
- (int)getBindState;

/**
 上报kochava事件
 
 @param eventKey 事件名称(Level、watch_ad等)
 @param eventValue 事件信息
 */
- (void)eventReport:(NSString *)eventKey eventInfo:(NSString *)eventValue;

/**
 上报事件
 
 @param plugName 插件名称(Kochava、Firebase、Adjust和AF) AF表示Adjust和Firebase都可以使用
 @param eventKey 事件名称(Kochava或Firebase的事件名称)
 @param eventValue 事件信息
 */
- (void)eventReport:(NSString *)plugName
           eventKey:(NSString *)eventKey
          eventInfo:(NSString *)eventValue;

/**
 获取leitingConfig_plist中的参数接口
 
 @param parametersStr 获取需要获取的值的 key
 @return 返回游戏初始化配置的参数
 */
- (NSString *)getPropertiesValue:(NSString *)parametersStr;

//pragma mark-打开客服专区界面
- (void)helper:(NSString *)parametersStr DEPRECATED_MSG_ATTRIBUTE("use helper instead");

//pragma mark-打开客服专区界面
- (void)helper;

//获取MAC
- (NSString *)getMAC;

//pragma mark - 游戏横竖屏切换设置接口
- (void)ChangeScreen;

//打开APP内评价页面
- (void)showStoreReview;


/// 获取商品内购信息
/// @param productIds 商品ID数组
- (void)getProuctsByIds:(NSArray *)productIds;


/// 获取商品内购信息
/// @param productIdStrs 商品ID数组json字符串
- (void)getProuctsInfoByIds:(NSString *)productIdStrs;


/**
 SDK 订单结果状态查询功能,游戏通过传入订单号，查询订单是否付款状态

 @param gameOrder 游戏订单号
 @param callback 返回回调结果
 */
- (void)getPayOrderStatus:(NSString *)gameOrder callback:(void(^)(NSString*))callback;


/**
 获取配置支持的横竖屏设置
 
 @return # 0：横屏      1：竖屏     2:支持横竖屏切换
 */
+ (NSString *)getOrientation;


/// 集成firebase消息推送
/// @param data  deviceToken
-(void)updateToken:(NSData *)deviceToken;


@end

