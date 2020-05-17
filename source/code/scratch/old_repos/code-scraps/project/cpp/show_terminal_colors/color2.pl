#!/usr/bin/perl
# Author: Todd Larason <jtl@molehill.org>
# $XFree86: xc/programs/xterm/vttests/256colors2.pl,v 1.2 2002/03/26 01:46:43 dickey Exp $

# use the resources for colors 0-15 - usually more-or-less a
# reproduction of the standard ANSI colors, but possibly more
# pleasing shades

# colors 16-231 are a 6x6x6 color cube

# now the grayscale ramp
for ( $i = 0 ; $i < 38 ; $i ++ ){
    for ($color = 232; $color < 256; $color++) {
print "\x1b[48;5;${color}m ";
    }
    for ($color = 232; $color < 256; $color++) {
print "\x1b[48;5;${color}m ";
    }
    for ($color = 232; $color < 256; $color++) {
print "\x1b[48;5;${color}m ";
    }
    for ($color = 232; $color < 256; $color++) {
print "\x1b[48;5;${color}m ";
    }
    print "\x1b[0m";
    print "\n";
}
print "\x1b[0m";
