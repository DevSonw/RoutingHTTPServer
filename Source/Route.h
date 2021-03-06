#import <Foundation/Foundation.h>

@class RouteResponse, RouteRequest;
typedef void (^RequestHandler)(RouteRequest *request, RouteResponse *response);

@interface Route : NSObject

@property (nonatomic) NSRegularExpression *regex;
@property (nonatomic, copy) RequestHandler handler;

#if __has_feature(objc_arc_weak)
@property (nonatomic, weak) id target;
#else
@property (nonatomic, assign) id target;
#endif

@property (nonatomic, assign) SEL selector;
@property (nonatomic) NSArray *keys;

@end
