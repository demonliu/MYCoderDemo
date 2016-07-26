//
//  ViewController.m
//  MYCoderDemo
//
//  Created by liumengyao on 16/7/26.
//  Copyright © 2016年 58. All rights reserved.
//

#import "ViewController.h"
#import "ChildModel.h"
#import "MYCoderKit.h"
#import "MYCoderManager.h"


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //testData
    ChildModel *model = [[ChildModel alloc]init];
    model.p1 = @"p1";
    model.p2 = @"p2";
    model.p3 = YES;
    model.p4 = 4;
    model.p5 = [NSNumber numberWithInt:5];
    
    NSString *key = @"childModel";
    
    //ARCHIVE
    MY_ARCHIVE_TOFILE(model, [self filePath:key]);
    MY_ARCHIVE_TOUSERDEFAULTS(model, key);
    
    //    BOOL b = [MYCoderManager archiveObject:model toFile:[self filePath:key]];
    //    BOOL b1 = [MYCoderManager archiveObjectToUserDefaults:model forKey:key];
    
    
    //UNARCHIVE
    ChildModel *model1 = nil;
    ChildModel *model2 = nil;
    MY_UNARCHIVE_WITHFILE([self filePath:key], model1);
    MY_UNARCHIVE_WITHUSERDEFAULTS(key, model2);
    
    //    model1 = [MYCoderManager unarchiveObjectWithFile:[self filePath:key]];
    //    model2 = [MYCoderManager unarchiveObjectFromUserDefaultsWithKey:key];
    
    NSLog(@"model1 -- %@",model1);
    NSLog(@"model2 -- %@",model2);
}


- (NSString *)filePath:(NSString *)key
{
    NSString *file =  [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject]  stringByAppendingPathComponent:key];
    
    return file;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
