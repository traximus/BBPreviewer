//
// Copyright 2013 BiasedBit
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

//  Created by Bruno de Carvalho (@biasedbit, http://biasedbit.com)
//
//  Copyright (c) 2013 BiasedBit. All rights reserved.
//

#pragma mark - Protocols

@class BBPreviewController;

@protocol BBPreviewControllerDelegate <NSObject>

@required
- (void)previewControllerDidFinishLoadingContent:(BBPreviewController*)controller;
- (void)previewController:(BBPreviewController*)controller didFailLoadingContentWithError:(NSError*)error;

@optional
- (void)previewControllerDidStartLoadingWebPage:(BBPreviewController*)controller;
- (void)previewControllerDidFinishLoadingWebPage:(BBPreviewController*)controller;
- (void)previewController:(BBPreviewController*)controller didFailLoadingWebPageWithError:(NSError*)error;

@end



#pragma mark -

@interface BBPreviewController : UIViewController


#pragma mark Properties

@property(weak, nonatomic) id<BBPreviewControllerDelegate> delegate;

@property(assign, nonatomic, readonly) BOOL hasContent;


#pragma mark Interface

- (BOOL)loadImage:(UIImage*)image;
- (BOOL)loadImageAtPath:(NSString*)pathToImage;
- (BOOL)loadMediaAtPath:(NSString*)path;
- (BOOL)loadDocumentAtPath:(NSString*)path;
- (BOOL)loadWebPageAtUrl:(NSString*)url;
- (BOOL)hasContent;

// For subclasses
- (UIView*)contentView;

@end