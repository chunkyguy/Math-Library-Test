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
}

- (IBAction)runTests:(id)sender
{
  [_activityView setHidden:NO];
  [_activityView startAnimating];
  self.button.hidden = YES;

  [self.view setUserInteractionEnabled:NO];
  dispatch_async(_taskQueue, ^{
    std::vector<TestResult> testResults = testLibraries(10);
    dispatch_async(dispatch_get_main_queue(), ^{
      [self.view setUserInteractionEnabled:YES];
      [self completeTestsWithResult:testResults];
    });
  });
}

- (void)completeTestsWithResult:(const std::vector<TestResult> &)testResults
{
  self.button.hidden = NO;
  [_activityView setHidden:YES];
  [_activityView stopAnimating];
  [_activityView removeFromSuperview];

  [self.graphView setResults:testResults];

  NSMutableArray *results = [NSMutableArray array];
  [results addObject:@"| Library | Additions (ms) | Multiplications (ms) |"];
  [results addObject:@"|---------|----------------|----------------------|"];
  for (TestResult t : testResults) {
    [results addObject:[NSString stringWithFormat:@"| %s | %010.2f | %010.2f |", t.name.c_str(), t.additions, t.multiplications]];
  }
  NSString *text = [results componentsJoinedByString:@"\n"];
  NSLog(@"\n%@", text);
}

@end
