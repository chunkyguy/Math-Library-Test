//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#import "GraphView.h"

@implementation GraphView
{
  std::vector<TestResult> _testResults;
}

- (void)setResults:(const std::vector<TestResult> &)results;
{
  _testResults = results;
  [self setNeedsDisplay];
}

- (void)drawRect:(CGRect)rect
{
  CGContextRef context = UIGraphicsGetCurrentContext();
  CGFloat width = CGRectGetWidth(rect);
  CGFloat height = CGRectGetHeight(rect);
  UIFont *font = [UIFont systemFontOfSize:12.f];

  CGFloat maxY = 0;
  for (TestResult t : _testResults) {
    maxY = fmax(maxY, fmax(t.additions, t.multiplications));
  }

  CGFloat textDrawOffsetY = 20;
  CGFloat dx = width / _testResults.size();
  for (int i = 0; i < _testResults.size(); ++i) {
    TestResult tr = _testResults[i];

    CGFloat xMin = i * dx;
    CGFloat xMax = (i + 1) *dx;
    CGFloat barWidth = ((xMax - xMin) / 2.f) - 4.0f;
    CGFloat yMin = 20.f;

    {
      CGFloat barHeight = (tr.additions / maxY) * (height - yMin - textDrawOffsetY);
      CGRect rect = CGRectMake(xMin, yMin, barWidth, barHeight);
      UIColor *color = [UIColor colorWithHue:0.3f saturation:0.8 brightness:0.7 alpha:1.0];
      CGContextSetFillColorWithColor(context, [color CGColor]);
      CGContextFillRect(context, rect);
      [self drawText:@"Add"
             atPoint:CGPointMake(xMin, yMin)
               width:barWidth
                font:font
               color:[UIColor whiteColor]];
      [self drawText:[NSString stringWithFormat:@"%.2f ms",tr.additions]
             atPoint:CGPointMake(xMin, barHeight + textDrawOffsetY)
               width:barWidth
                font:font
               color:[UIColor blackColor]];
    }

    {
      CGFloat barHeight = (tr.multiplications / maxY) * (height - yMin - textDrawOffsetY);
      CGRect rect = CGRectMake(xMin + barWidth, yMin, barWidth, barHeight);
      UIColor *color = [UIColor colorWithHue:0.7f saturation:0.8 brightness:0.7 alpha:1.0];
      CGContextSetFillColorWithColor(context, [color CGColor]);
      CGContextFillRect(context, rect);
      [self drawText:@"Multiply"
             atPoint:CGPointMake(xMin + barWidth, yMin)
               width:barWidth
                font:font
               color:[UIColor whiteColor]];
      [self drawText:[NSString stringWithFormat:@"%.2f ms",tr.multiplications]
             atPoint:CGPointMake(xMin + barWidth, barHeight + textDrawOffsetY)
               width:barWidth
                font:font
               color:[UIColor blackColor]];
    }

    [self drawText:[NSString stringWithCString:tr.name.c_str() encoding:NSUTF8StringEncoding]
           atPoint:CGPointMake(xMin, 0)
             width:xMax - xMin
              font:font
             color:[UIColor blackColor]];
  }
}

- (void)drawText:(NSString *)text
         atPoint:(CGPoint)point
           width:(CGFloat)width
            font:(UIFont *)font
           color:(UIColor *)color
{
  NSDictionary *attributes = [NSDictionary dictionaryWithObjectsAndKeys:
                              font, NSFontAttributeName,
                              color, NSForegroundColorAttributeName, nil];
  CGSize size = [text sizeWithAttributes:attributes];
  point.x = point.x + (width - size.width)/2.f;
  [text drawAtPoint:point withAttributes:attributes];
}

@end

