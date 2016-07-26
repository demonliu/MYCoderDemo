//
//  MYCoderManager.h
//  tsetDemo
//
//  Created by liumengyao on 16/7/26.
//  Copyright © 2016年 58. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MYCoderManager : NSObject

+ (BOOL)archiveObject:(id)object toFile:(NSString *)file;

+ (BOOL)archiveObjectToUserDefaults:(id)object forKey:(NSString *)key;

+ (id)unarchiveObjectWithFile:(NSString *)file;

+ (id)unarchiveObjectFromUserDefaultsWithKey:(NSString *)key;



@end
