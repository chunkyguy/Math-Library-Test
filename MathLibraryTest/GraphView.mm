//
// Created by Sidharth Juyal on 18/11/2020.
// Copyright © 2020 Noise & Heat. All rights reserved.
// 

#import "GraphView.h"

@implementation GraphView
{
  std::vector<TestResult> _testResults;
}

- (void)awakeFromNib
{
  [super awakeFromNib];
  [self setBackgroundColor:[UIColor whiteColor]];
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

  CGFloat maxValue = 0;
  for (TestResult t : _testResults) {
    maxValue = fmax(maxValue, fmax(t.additions, t.multiplications));
  }

  CGFloat dx = width / _testResults.size();
  for (int i = 0; i < _testResults.size(); ++i) {
    TestResult tr = _testResults[i];

    CGFloat minX = i * dx;
    CGFloat maxX = (i + 1) *dx;
    CGFloat barWidth = ((maxX - minX) / 2.f) - 4.0f;
    CGFloat textHeight = 20.f;
    CGFloat maxBarHeight = height - (textHeight * 3);

    {
      CGFloat barHeight = (tr.additions / maxValue) * maxBarHeight;
      CGRect rect = CGRectMake(minX, height - barHeight - (textHeight * 2), barWidth, barHeight);
      UIColor *color = [UIColor colorWithHue:0.3f saturation:0.8 brightness:0.7 alpha:1.0];
      CGContextSetFillColorWithColor(context, [color CGColor]);
      CGContextFillRect(context, rect);
      [self drawText:@"Add"
             atPoint:CGPointMake(minX, height - (textHeight * 2))
               width:barWidth
                font:font
               color:[UIColor blackColor]];
      [self drawText:[NSString stringWithFormat:@"%.2f ns",tr.additions]
             atPoint:CGPointMake(minX, height - barHeight - (textHeight * 3))
               width:barWidth
                font:font
               color:[UIColor blackColor]];
    }

    {
      CGFloat barHeight = (tr.multiplications / maxValue) * maxBarHeight;
      CGRect rect = CGRectMake(minX + barWidth, height - barHeight - (textHeight * 2), barWidth, barHeight);
      UIColor *color = [UIColor colorWithHue:0.7f saturation:0.8 brightness:0.7 alpha:1.0];
      CGContextSetFillColorWithColor(context, [color CGColor]);
      CGContextFillRect(context, rect);
      [self drawText:@"Multiply"
             atPoint:CGPointMake(minX + barWidth, height - (textHeight * 2))
               width:barWidth
                font:font
               color:[UIColor blackColor]];
      [self drawText:[NSString stringWithFormat:@"%.2f ns",tr.multiplications]
             atPoint:CGPointMake(minX + barWidth, height - barHeight - (textHeight * 3))
               width:barWidth
                font:font
               color:[UIColor blackColor]];
    }

    [self drawText:[NSString stringWithCString:tr.name.c_str() encoding:NSUTF8StringEncoding]
           atPoint:CGPointMake(minX, height - textHeight)
             width:maxX - minX
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

