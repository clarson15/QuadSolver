## float_parts.c
Same as float_parts.c in its own directory.

## float_parts_shift.c
A rewrite of float_parts, but using bit shifting rather than a typedef union.

## is_float.c
Testing user input from stdin for whether or not it is a valid float.

## is_normalized.c
Initial spike for testing float_parts implementation to test for normalization in floating point numbers.

## float_properties.c
Using fpclassify in the math.h header to test for various properties of a floating point number including zero, normalized, inf, and NaN.
