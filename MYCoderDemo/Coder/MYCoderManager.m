//
//  MYCoderManager.m
//  tsetDemo
//
//  Created by liumengyao on 16/7/26.
//  Copyright © 2016年 58. All rights reserved.
//

#import "MYCoderManager.h"

@implementation MYCoderManager

#pragma mark --  archiveObject

+ (BOOL)archiveObject:(id)object toFile:(NSString *)file
{
    if (object && file)
    {
        return  [NSKeyedArchiver archiveRootObject:object toFile:file];
    }
    return NO;
}


+ (BOOL)archiveObjectToUserDefaults:(id)object forKey:(NSString *)key
{
    if (object && key)
    {
        NSData *data = [NSKeyedArchiver archivedDataWithRootObject:object];
        if (data) {
            
            [[NSUserDefaults standardUserDefaults] setObject:data forKey:key];
            return YES;
        }
    }
    return NO;
}

#pragma mark --  unarchiveObject

+ (id)unarchiveObjectWithFile:(NSString *)file
{
    if (file)
    {
        return  [NSKeyedUnarchiver unarchiveObjectWithFile:file];
    }
    return nil;
}


+ (id)unarchiveObjectFromUserDefaultsWithKey:(NSString *)key
{
    if (key)
    {
        NSData *data = [[NSUserDefaults standardUserDefaults] objectForKey:key];
        if (data)
        {
            return  [NSKeyedUnarchiver unarchiveObjectWithData:data];
        }
    }
    return nil;
}




@end
