//
//  leitinglib.h
//  leitinglib
//
//  Created by 陈海青 on 16/2/26.
//  Copyright © 2016年 陈海青. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for leitinglib.
FOUNDATION_EXPORT double leitinglibVersionNumber;

//! Project version string for leitinglib.
FOUNDATION_EXPORT const unsigned char leitinglibVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <leitinglib/PublicHeader.h>


#ifdef LT_USECODE_SDK

#import "LeitingSDK.h"
//#import <leitinglib/LoginView.h>
#import "LeitingCallBack.h"

#else

#import <leitinglib/LeitingSDK.h>
//#import <leitinglib/LoginView.h>
#import <leitinglib/LeitingCallBack.h>

#endif
