//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include "TestResult.hpp"
#include <vector>

@interface GraphView : UIView

- (void)setResults:(const std::vector<TestResult> &)results;

@end
