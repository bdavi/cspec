#include <stdio.h>
#include "toTest.h"
#include "../src/cspec.h"

void testInt2Char();
void testInt2CharValidValues();
void testInt2CharDigits();
void testInt2CharLetters();

int main (int argc, char* argv[]) {
  testInt2Char();
  printTestSummary();
  return 0;
}

void testInt2Char() {
  printHeader("Testing `int2char`");
  testInt2CharValidValues();
  testInt2CharDigits();
  testInt2CharLetters();
}

void testInt2CharValidValues() {
  printSubHeader("Values are valid");

  printf("  When the radix is too low, it should return '?':");
  assertEqualChar(int2char(0, 33), '?');

  printf("  When the radix is too high, it should return '?':");
  assertEqualChar(int2char(37, 33), '?');

  printf("  When the values is too low, it should return '?':");
  assertEqualChar(int2char(37, -1), '?');

  printf("  When the values is higher than (radix-1), it should return '?':");
  assertEqualChar(int2char(37, 88), '?');
}

void testInt2CharDigits() {
  printSubHeader("Digits");
  printf("  When the radix is 2 and the value is 1, it should return '1':");
  assertEqualChar(int2char(2, 1), '1');

  printf("  When the radix is 5 and the value is 4, it should return '4':");
  assertEqualChar(int2char(5, 4), '4');

  printf("  When the radix is 10 and the value is 9, it should return '9':");
  assertEqualChar(int2char(10, 9), '9');
}

void testInt2CharLetters() {
  printSubHeader("Letters");
  printf("  When the radix is 16 and the value is 10, it should return 'A':");
  assertEqualChar(int2char(16, 10), 'A');

  printf("  When the radix is 16 and the value is 11, it should return 'B':");
  assertEqualChar(int2char(16, 11), 'B');

  printf("  When the radix is 20 and the value is 15, it should return 'F':");
  assertEqualChar(int2char(20, 15), 'F');
}
