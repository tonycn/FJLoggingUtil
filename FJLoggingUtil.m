//
//  LoggingUtil.m
//  DocViewer
//
//  Created by Jianjun on 11/8/11.
//  Copyright (c) 2011 Douban Inc. All rights reserved.
//


#import "FJLoggingUtil.h"

static NSMutableArray *enableCategories = nil;
@implementation FJLoggingUtil

+ (void)addEnabledCategory:(NSString *)category {
  if (enableCategories == nil) {
    enableCategories = [[NSMutableArray alloc] initWithCapacity:7];
  }
  if ([enableCategories indexOfObject:category] == NSNotFound ) {
    [enableCategories addObject:category];
  }
}

+ (void)loggingLevel:(FJLoggingLevel)level 
                func:(const char *)funcName 
                line:(NSInteger)lineNo 
            category:(NSString *)category
       messageFormat:(NSString *)messageFormat, ... {
  if (enableCategories == nil || [enableCategories count] < 1
      || [enableCategories indexOfObject:category] == NSNotFound) {
    return;
  }
  
  NSString *levelStr = nil;
  switch (level) {
    case kFJLoggingLevelFatal:
      levelStr = @"Fatal";
      break;
      
    case kFJLoggingLevelError:
      levelStr = @"Error";
      break;
      
    case kFJLoggingLevelWarn:
      levelStr = @"Warn";
      break;
      
    case kFJLoggingLevelInfo:
      levelStr = @"Info";
      break;
      
    case kFJLoggingLevelDebug:
      levelStr = @"Debug";
      break;
      
    case kFJLoggingLevelTrace:
      levelStr = @"Trace";
      break;
      
    default:
      levelStr = @"UnknownLevel";
      break;
  }
  
  va_list argumentList;
  messageFormat = [NSString stringWithFormat:@"[%@ %s(%d) (%@)] %@", levelStr, funcName, lineNo, 
                                                                        category, messageFormat];
  va_start(argumentList, messageFormat);
  NSLogv(messageFormat, argumentList);
  va_end(argumentList);
  
}

@end