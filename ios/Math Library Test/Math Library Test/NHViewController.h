//
//  NHViewController.h
//  Math Library Test
//
//  Created by David Wagner on 23/09/2012.
//  Copyright (c) 2012 Noise & Heat. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NHViewController : UIViewController

@property (strong, nonatomic) IBOutlet UITextView *outputText;
@property (strong, nonatomic) IBOutlet UIButton *button;

- (IBAction)runTests:(id)sender;

@end
