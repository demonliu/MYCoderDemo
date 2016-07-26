//
//  MYCoderKit.h
//  tsetDemo
//
//  Created by liumengyao on 16/7/26.
//  Copyright © 2016年 58. All rights reserved.
//

#ifndef MYCoderKit_h
#define MYCoderKit_h


#endif /* MYCoderKit_h */

//NSCoding协议方法initWithCoder与encodeWithCoder
#define MY_ENCODER_DECODER() \
\
- (instancetype)initWithCoder:(NSCoder *)aDecoder\
{\
    NSLog(@"%s",__func__);\
    self = [super init];\
    if (self)\
    {\
        /*创建class变量,并赋初始值为self类*/ \
        Class class = [self class];\
        objc_property_t *propList = nil;\
        /*while循环,遍历self及父类的属性*/  \
        while (class != [NSObject class])\
        {\
            /*runtime获取属性列表*/ \
            unsigned int propertyCount;\
            propList = class_copyPropertyList(class, &propertyCount);\
            /*遍历属性列表,decoded当前类class的属性*/ \
            for (int i = 0; i < propertyCount; i++)\
            {\
                /*获取当前属性名称*/ \
                const char *propertyChar = property_getName(propList[i]);\
                /*将属性转为string*/ \
                NSString *propertyName = [NSString stringWithFormat:@"%s",propertyChar];\
                /*decode*/\
                id decodeValue = [aDecoder decodeObjectForKey:propertyName];\
                if (decodeValue)\
                {\
                    [self setValue:decodeValue forKey:propertyName];\
                }\
            }\
            /*获取父类,重置class值*/\
            class = class_getSuperclass(class);\
        }\
        free(propList);\
    }\
    return self;\
}\
\
\
- (void)encodeWithCoder:(NSCoder *)aCoder\
{\
    NSLog(@"%s",__func__);\
    /*创建class变量,并赋初始值为self类*/ \
    Class class = [self class];\
    objc_property_t *propList = nil;\
    /*while循环,遍历self及父类的属性*/\
    while (class != [NSObject class])\
    {\
        /*runtime获取属性列表*/ \
        unsigned int propertyCount;\
        propList = class_copyPropertyList(class, &propertyCount);\
        /*遍历属性列表,decoded当前类class的属性*/ \
        for (int i = 0; i < propertyCount; i++)\
        {\
            /*获取当前属性名称*/ \
            const char *propertyChar = property_getName(propList[i]);\
            /*将属性转为string*/\
            NSString *propertyName = [NSString stringWithFormat:@"%s",propertyChar];\
            /*encode*/ \
            id encodeValue = [self valueForKey:propertyName];\
            if (encodeValue)\
            {\
                [aCoder encodeObject:encodeValue forKey:propertyName];\
            }\
        }\
        /*获取父类,重置class值*/ \
        class = class_getSuperclass(class);\
    }\
    free(propList);\
}


#pragma mark -- ARCHIVE

/**
 *  序列化NSKeyedArchiver操作,存储到指定路径
 *
 *  @param __object__ 待处理数据
 *  @param __file__   存储地址
 *
 */
#define MY_ARCHIVE_TOFILE(__object__,__file__) \
[NSKeyedArchiver archiveRootObject:__object__ toFile:__file__];

/**
 *  序列化NSKeyedArchiver操作,存储到NSUserDefaults
 *
 *  @param __object__ 待处理数据
 *  @param __key__    存储键值key
 *
 */
#define MY_ARCHIVE_TOUSERDEFAULTS(__object__,__key__)\
NSData *data = [NSKeyedArchiver archivedDataWithRootObject:__object__];\
if (data) {\
    [[NSUserDefaults standardUserDefaults] setObject:data forKey:__key__];\
}



#pragma mark -- UNARCHIVE

/**
 *  反序列化NSKeyedUnarchiver操作,解码指定路径数据
 *
 *  @param __file__   文件路径
 *  @param __object__ 解码得到的数据
 *
 */
#define MY_UNARCHIVE_WITHFILE(__file__,__object__)\
__object__ = [NSKeyedUnarchiver unarchiveObjectWithFile:__file__];


/**
 *  反序列化NSKeyedUnarchiver操作,解码NSUserDefaults指定key的数据
 *
 *  @param __key__    文件key值
 *  @param __object__ 解码得到的数据
 *
 */
#define MY_UNARCHIVE_WITHUSERDEFAULTS(__key__,__object__)\
NSData *unarchiveData = [[NSUserDefaults standardUserDefaults] objectForKey:__key__];\
if (unarchiveData)\
{\
    __object__ = [NSKeyedUnarchiver unarchiveObjectWithData:unarchiveData];\
}\







