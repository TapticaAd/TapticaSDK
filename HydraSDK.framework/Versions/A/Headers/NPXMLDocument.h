//
//  NPXMLDocument.h
//  Parser
//
//  Created by Nissim Pardo on 2/10/15.
//  Copyright (c) 2015 androdogs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NPXMLElement.h"

typedef void (^DocumentBlock)(NPXMLElement *document, NSError *error);


@interface NPXMLDocument : NSObject
- (void)XMLDocumentData:(NSData *)XMLData completion:(DocumentBlock)completion;
@end
