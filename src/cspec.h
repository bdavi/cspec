// *******************************************************************
// Types
// *******************************************************************
typedef enum {
    WHITE = 0,
    RED = 1,
    GREEN = 2,
} color;

// *******************************************************************
// Function Declarations
// *******************************************************************
void assertEqualChar();
void printTestSummary();
void printPass();
void printFail();
void printHeader(char* title);
void printSubHeader(char* title);
void switchToTerminalColor(color color);
int passedTests();
