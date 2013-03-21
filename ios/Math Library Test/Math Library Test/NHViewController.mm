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

@end

@implementation NHViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
		
	self.outputText.text = @"Tap the button to run tests.";
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)runTests:(id)sender
{
//	self.button.hidden = YES;
//	self.outputText.text = @"Running...";
	TestResults tr = testLibraries(10);
    NSString *output = [NSString stringWithFormat:
                        @"Eigen\n=====\nAdditions: %ld\nMultiplications: %ld\n\nGLM\n===\nAdditions: %ld\nMultiplications: %ld\n\nCML\n===\nAdditions: %ld\nMultiplications: %ld\n\nGLKMath\n===\nAdditions: %ld\nMultiplications: %ld",
                        tr.eigen.additions, tr.eigen.multiplications,
                        tr.glm.additions, tr.glm.multiplications,
                        tr.cml.additions, tr.cml.multiplications,
                        tr.glkMath.additions, tr.glkMath.multiplications
                        ];
    NSLog(@"\n%@",output);
//	self.outputText.text = output;
}

@end
