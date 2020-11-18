//
//  NHViewController.h
//  Math Library Test
//
//  Created by David Wagner on 23/09/2012.
//  Copyright (c) 2012 Noise & Heat. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GraphView.h"

@interface NHViewController : UIViewController

@property (strong, nonatomic) IBOutlet GraphView *graphView;
@property (strong, nonatomic) IBOutlet UIButton *button;

- (IBAction)runTests:(id)sender;

@end
