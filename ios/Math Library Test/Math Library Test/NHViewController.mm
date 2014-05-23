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
	self.button.hidden = YES;
	self.outputText.textAlignment = NSTextAlignmentCenter;
	TestResults tr = testLibraries(10);
    
//	const NSString *verEigen = @"eigen-8311f0d8ecd0-2012_09_22-11_11_26";
//	const NSString *verGLM = @"glm-c588e9fa1-2012)09_05-15_03_27";
//	const NSString *verCML = @"cml-1_0_3";
//	const NSString *verGLKMath = @"?";
	
    //	NSString *versions = [NSString stringWithFormat:
    //						  @"Eigen version: %@\nGLM version: %@\nCML Version: %@\nGLKMath Version: %@",
    //						  verEigen, verGLM, verCML, verGLKMath];
	
	NSString *results = [NSString stringWithFormat:
                         @"\n\nEigen\n=====\nAdditions: %.2f\tMultiplications: %.2f\n\n"
                         @"GLM\n===\nAdditions: %.2f\tMultiplications: %.2f\n\n"
                         @"CML\n===\nAdditions: %.2f\tMultiplications: %.2f\n\n"
                         @"GLKMath\n===\nAdditions: %.2f\tMultiplications: %.2f\n\n"
                         @"kazmath\n===\nAdditions: %.2f\tMultiplications: %.2f\n\n"
                         ,
                         tr.eigen.additions, tr.eigen.multiplications,
                         tr.glm.additions, tr.glm.multiplications,
                         tr.cml.additions, tr.cml.multiplications,
                         tr.glkMath.additions, tr.glkMath.multiplications,
                         tr.kazmath.additions, tr.kazmath.multiplications
                         ];
    
	self.outputText.text = [NSString stringWithFormat:@"%@", results];
    
}

@end
