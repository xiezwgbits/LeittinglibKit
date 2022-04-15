//
//  LeitingCallBack.h
//  leitinglib
//
//  Created by 陈海青 on 15/12/15.
//  Copyright © 2015年 陈海青. All rights reserved.
//
@protocol LeitingCallBackDelegate <UITableViewDelegate>

@optional

//登录回调
- (void)loginCallBack:(NSString *)str;
//注销回调 //JSON字符串，其中，statusCode 对应的值为 1 ，则为切换 GC 账号，直接调用connect登录。
- (void)logoutCallBack:(NSString *)str;
//充值回调
- (void)payCallBack:(NSString *)str;
//充值失败回调
- (void)payFailCallBack:(NSString *)str;

/**
 绑定结果回调

 @param str 返回绑定后的结果
 {
 "status" : "0" // 0:绑定失败 ，1 绑定成功
 }
 */
- (void)bindStatueCallBack:(NSString *)str;


//绑定成功回调用户信息
-(void)userBindCallback:(NSString *)str;


//获取苹果商品回调
- (void)getProductsCallBack:(NSString *)str;


/**
 分享结果返回

 @param str 分享结果的 json 字符串  status:"1"为成功/其他为失败,message:失败原因
 */
- (void)shareCallBack:(NSString *)str;

/**
 凭证回调接口
 
 @param str ： json 字符串
 userid      账号ID
 zoneId      区组ID
 productId   商品ID
 orderId     游戏订单号
 money       购买所需要花费的 RMB 金额 单位：分(eg:100)
 extInfo     扩展信息
 
 */
- (void)receiptCallBack:(NSString *)str;


/// firebase远程推送
/// @param fcmToken  设备唯一标识token
-(void)firbaseTokenCallBack:(NSString *)fcmToken;



/// 客服工具未读消息
/// @param unReadMsg 未读消息数
-(void)unReadMsg:(NSString *)unReadMsg;


/// 获取手机系统当前使用的语言
/// @param systemLanguage 比如 @"ko"   @"ja"
-(void)getSystemLanguageCallBack:(NSString *)systemLan;


/// 获取sdk支持的多语言类型
/// @param languageTypes 返回sdk支持的多语言种类
-(void)getLanguageTypesCallBack:(NSString *)languageTypes;


@end
