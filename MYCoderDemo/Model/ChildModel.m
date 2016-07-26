

//
//  ChildModel.m
//  tsetDemo
//
//  Created by liumengyao on 16/7/25.
//  Copyright © 2016年 58. All rights reserved.
//

#import "ChildModel.h"
#import <objc/runtime.h>
#import "MYCoderKit.h"

@interface ChildModel ()<NSCoding>

@end

@implementation ChildModel

MY_ENCODER_DECODER();


//- (instancetype)initWithCoder:(NSCoder *)aDecoder
//{
//    self = [super init];
//    if (self) {
//       
//       self.p3 = [aDecoder decodeObjectForKey:@"p3"];
//    }
//    
//    return self;
//}
//

//- (void)encodeWithCoder:(NSCoder *)aCoder
//{
//    [aCoder encodeObject:self.p3 forKey:@"p3"];
//}



@end
