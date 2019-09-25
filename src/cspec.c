#include <stdio.h>
#include "cspec.h"

// *******************************************************************
// Globals
// *******************************************************************

// Index matches color enum from header
const char *TERMINAL_COLOR_CODES[3] = {
  "\x1B[37m",
  "\x1B[31m",
  "\x1B[32m"
};

int failedTests = 0;
int runTests = 0;

// *******************************************************************
// Helpers
// *******************************************************************
int passedTests() {
  return runTests - failedTests;
}

// *******************************************************************
// Terminal & Printing
// *******************************************************************
void switchToTerminalColor(color color) {
  printf("%s", TERMINAL_COLOR_CODES[(int) color]);
}

void printPass() {
  switchToTerminalColor(GREEN);
  puts(" Pass");
  switchToTerminalColor(WHITE);
}

void printFail() {
  switchToTerminalColor(RED);
  puts(" FAIL");
  switchToTerminalColor(WHITE);
}

void printHeader(char* title) {
  puts("************************************************************************");
  printf("* %s\n", title);
  puts("************************************************************************");
}

void printSubHeader(char* title) {
  printf("\n  %s\n", title);
  puts("  ----------------------------------------------------------------------");
}

void printTestSummary() {
  puts("");
  printHeader("Summary");

  printf("  Run   : %d\n", runTests);
  printf("  Passed: %d\n", passedTests());

  if (failedTests > 0) {
    switchToTerminalColor(RED);
  }
  printf("  Failed: %d\n", failedTests);

  if (failedTests == 0) {
    switchToTerminalColor(GREEN);
    puts("\n  ALL SPECS PASS\n");
    switchToTerminalColor(WHITE);
  }
  puts("");
}

// *******************************************************************
// Assertions
// *******************************************************************
void assertEqualChar(val1, val2) {
  runTests++;

  if (val1 == val2) {
    printPass();
  } else {
    printFail();
    switchToTerminalColor(RED);
    printf("    %c does not equal %c\n", val1, val2);
    switchToTerminalColor(WHITE);
    failedTests++;
  }
}
