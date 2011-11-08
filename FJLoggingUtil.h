//
//  LoggingUtil.h
//  DocViewer
//
//  Created by Jianjun on 11/8/11.
//  Copyright (c) 2011 Douban Inc. All rights reserved.
//

/*
 This is a logging utility to extend the iOS NSLog() function. It contains 
 two main parts: logging level and logging category.
Logging levels: 
  FATAL, ERROR, WARN, INFO, DEBUG, TRACE
Logging category: category is used to enable logging for a particular module.
 
 */

#define FJ_LOGGINE_ERROR_ENABLE 1
#define FJ_LOGGINE_INFO_ENABLE 1


typedef enum {
  kFJLoggingLevelFatal = 1,
  kFJLoggingLevelError,
  kFJLoggingLevelWarn,
  kFJLoggingLevelInfo,
  kFJLoggingLevelDebug,
  kFJLoggingLevelTrace
} FJLoggingLevel;

@interface FJLoggingUtil : NSObject {
@private
  
}
+ (void)addEnabledCategory:(NSString *)category;
+ (void)loggingLevel:(FJLoggingLevel)level 
                func:(const char *)funcName 
                line:(NSInteger)lineNo 
            category:(NSString *)category
       messageFormat:(NSString *)format, ...;

@end


#if FJ_LOGGINE_FATAL_ENABLE
#define FJ_FATALLOG(c, f, ...) [FJLoggingUtil loggingLevel:kFJLoggingLevelFatal \
                                                            func: __PRETTY_FUNCTION__ \
                                                            line: __LINE__ \
                                                        category: c \
                                                   messageFormat: f, [NSString stringWithFormat:s, ##__VA_ARGS__]]
#else
#define FJ_FATALLOG(c, f, ...)
#endif

#if FJ_LOGGINE_ERROR_ENABLE
#define FJ_ERRORLOG(c, f, ...) [FJLoggingUtil loggingLevel:kFJLoggingLevelError \
                                                            func: __PRETTY_FUNCTION__ \
                                                            line: __LINE__ \
                                                        category: c \
                                                    messageFormat: f, ##__VA_ARGS__]
#else
#define FJ_ERRORLOG(c, f, ...)
#endif

#if FJ_LOGGINE_WARN_ENABLE
#define FJ_WARNLOG(c, f, ...) [FJLoggingUtil loggingLevel:kFJLoggingLevelWarn \
                                                            func: __PRETTY_FUNCTION__ \
                                                            line: __LINE__ \
                                                        category: c \
                                                   messageFormat: f, ##__VA_ARGS__]
#else
#define FJ_WARNLOG(c, f, ...)
#endif

#if FJ_LOGGINE_INFO_ENABLE
#define FJ_INFOLOG(c, f, ...) [FJLoggingUtil loggingLevel:kFJLoggingLevelInfo \
                                                            func: __PRETTY_FUNCTION__ \
                                                            line: __LINE__ \
                                                        category: c \
                                                   messageFormat: f, ##__VA_ARGS__]
#else
#define FJ_INFOLOG(c, f, ...)
#endif

#if FJ_LOGGINE_DEBUG_ENABLE
#define FJ_DEBUGLOG(c, f, ...) [FJLoggingUtil loggingLevel:kFJLoggingLevelDebug \
                                                             func: __PRETTY_FUNCTION__ \
                                                             line: __LINE__ \
                                                         category: c \
                                                    messageFormat: f, ##__VA_ARGS__]
#else
#define FJ_DEBUGLOG(c, f, ...)
#endif

#if FJ_LOGGINE_TRACE_ENABLE
#define FJ_TRACELOG(c, f, ...) [FJLoggingUtil loggingLevel:kFJLoggingLevelTrace \
                                                             func: __PRETTY_FUNCTION__ \
                                                             line: __LINE__ \
                                                         category: c \
                                                    messageFormat: f, ##__VA_ARGS__]
#else
#define FJ_TRACELOG(c, f, ...)
#endif
