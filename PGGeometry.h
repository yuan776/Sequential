/* Copyright © 2007-2008 The Sequential Project. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal with the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:
1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimers.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimers in the
   documentation and/or other materials provided with the distribution.
3. Neither the name of The Sequential Project nor the names of its
   contributors may be used to endorse or promote products derived from
   this Software without specific prior written permission.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
THE CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS WITH THE SOFTWARE. */
#import <Cocoa/Cocoa.h>
#import "PGGeometryTypes.h"

#pragma mark NSPoint

extern NSPoint PGOffsetPointBySize(NSPoint aPoint, NSSize aSize);
extern NSPoint PGOffsetPointByXY(NSPoint aPoint, float x, float y);
extern NSSize PGPointDiff(NSPoint p1, NSPoint p2);

#pragma mark NSSize

extern NSSize PGScaleSizeByXY(NSSize size, float scaleX, float scaleY);
extern NSSize PGScaleSizeByFloat(NSSize size, float scale);
extern NSSize PGIntegralSize(NSSize s);

#pragma mark NSRect

extern NSRect PGCenteredSizeInRect(NSSize s, NSRect r);
extern BOOL PGIntersectsRectList(NSRect rect, NSRect const *list, unsigned count); // -needsToDrawRect: is broken in 10.3, see hxxp://developer.apple.com/technotes/tn2002/tn2107.html.
extern NSRect PGIntegralRect(NSRect r); // NSIntegralRect() expands the rectangle in all directions. It's better to round the origin and width separately.

#pragma mark PGRectEdgeMask

extern NSSize PGRectEdgeMaskToSizeWithMagnitude(PGRectEdgeMask mask, float magnitude);
extern NSPoint PGRectEdgeMaskToPointWithMagnitude(PGRectEdgeMask mask, float magnitude);
extern NSPoint PGPointOfPartOfRect(NSRect r, PGRectEdgeMask mask);
extern PGRectEdgeMask PGPointToRectEdgeMaskWithThreshhold(NSPoint p, float threshhold);
extern PGRectEdgeMask PGNonContradictoryRectEdges(PGRectEdgeMask mask);
extern BOOL PGHasContradictoryRectEdges(PGRectEdgeMask mask);

#pragma mark PGPageLocation

extern PGRectEdgeMask PGReadingDirectionAndLocationToRectEdgeMask(PGPageLocation loc, PGReadingDirection dir);

#pragma mark PGOrientation

extern PGOrientation PGAddOrientation(PGOrientation o1, PGOrientation o2);

#pragma mark PGInset

extern PGInset const PGZeroInset;

extern PGInset PGMakeInset(float minX, float minY, float maxX, float maxY);
extern PGInset PGScaleInset(PGInset i, float s);
extern PGInset PGInvertInset(PGInset inset);
extern NSPoint PGInsetPoint(NSPoint p, PGInset i);
extern NSSize PGInsetSize(NSSize s, PGInset i);
extern NSRect PGInsetRect(NSRect r, PGInset i);

#pragma mark Animation

#define PGAnimationFramesPerSecond 30.0
#define PGAnimationFramerate       (1.0 / PGAnimationFramesPerSecond)

extern NSTimeInterval PGUptime(void);
extern float PGLagCounteractionSpeedup(NSTimeInterval *timeOfFrame, float desiredFramerate); // On input, timeOfFrame should be the PGUptime() from the last frame or 0. On return, it is the current PGUptime().
