//
//  NHViewController.m
//  Math Library Test
//
//  Created by David Wagner on 23/09/2012.
//  Copyright (c) 2012 Noise & Heat. All rights reserved.
//

#import "NHViewController.h"

#import "Driver.h"

@interface NHViewController ()
{
  UIActivityIndicatorView *_activityView;
  dispatch_queue_t _taskQueue;
}
@end

@implementation NHViewController

- (void)viewDidLoad
{
  [super viewDidLoad];

  _taskQueue = dispatch_queue_create("com.wl.math.tests", DISPATCH_QUEUE_SERIAL);
  UIActivityIndicatorView *_activityVw = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleLarge];
  [_activityVw setHidden:YES];
  [self.view addSubview:_activityVw];

  self.outputText.text = @"Tap the button to run tests.";
  self.outputText.textAlignment = NSTextAlignmentCenter;
}

- (IBAction)runTests:(id)sender
{
  [_activityView setHidden:NO];
  [_activityView startAnimating];
  self.button.hidden = YES;
  self.outputText.text = @"Running ...";

  [self.view setUserInteractionEnabled:NO];
  dispatch_async(_taskQueue, ^{
    TestResults tr = testLibraries(10);
    dispatch_async(dispatch_get_main_queue(), ^{
      [self.view setUserInteractionEnabled:YES];
      [self completeTestsWithResult:tr];
    });
  });
}

- (void)completeTestsWithResult:(TestResults)tr {
  self.button.hidden = NO;
  [_activityView setHidden:YES];
  [_activityView stopAnimating];
  [_activityView removeFromSuperview];

  NSString *results = [NSString stringWithFormat:
                       @"| Eigen | %.2f | %.2f |\n"
                       @"| GLM | %.2f | %.2f |\n"
                       @"| CML | %.2f | %.2f |\n"
                       @"| GLKMath | %.2f | %.2f |\n"
                       @"| kazmath | %.2f | %.2f |\n"
                       @"| bullet | %.2f | %.2f |\n"
                       ,
                       tr.eigen.additions, tr.eigen.multiplications,
                       tr.glm.additions, tr.glm.multiplications,
                       tr.cml.additions, tr.cml.multiplications,
                       tr.glkMath.additions, tr.glkMath.multiplications,
                       tr.kazmath.additions, tr.kazmath.multiplications,
                       tr.bullet.additions, tr.bullet.multiplications
                       ];

  self.outputText.text = [NSString stringWithFormat:@"%@", results];
  NSLog(@"\n%@", results);
}

@end
