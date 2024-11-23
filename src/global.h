#ifndef GLOBAL_H
#define GLOBAL_H
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 24
#define APP_NAME "G.B.M.S. Bank"
#define ADM_CODE "123"
#define ADM_PASSWORD "123"
#define YIELD_ACCOUNT_NUMBER "000000-0"
#define YIELD 0.005
#define UNUSED(x) (void)(x)

typedef void *GenericType;

/**
 * @brief Writes text at a specified position on the terminal.
 * 
 * @param text The text to be written.
 * @param x The x position on the terminal.
 * @param y The y position on the terminal.
 * @param disableProporcion Flag to disable proportional spacing.
 */
void writeText(char *text, int x, int y, int disableProporcion);

/**
 * @brief Reads a command from the user.
 * 
 * @return The command entered by the user.
 */
char command();

/**
 * @brief Clears the input buffer.
 */
void clearInputBuffer();

/**
 * @brief Utility function to get an input from the user and validate it.
 * 
 * @param mask The mask to be used on `scanf`.
 * @param input The input to be stored.
 * @param err The error message to be displayed if the input is invalid.
 * @param x The x position on the terminal.
 * @param y The y position on the terminal.
 * @param validation The validation function to be used.
 * @param args Additional arguments for the validation function.
 * 
 * @example
 * int input;
 * getInput("%d", &input, "Por favor digite um numero valido", 0, 0, noValid, NULL);
 */
void getInput(char mask[], GenericType input, char err[], int x,
              int y, int validation(GenericType i, GenericType a), GenericType args);

/**
 * @brief Prints a message on the footer of the terminal.
 * 
 * @param msg The message to be displayed.
 */
void printMessage(char msg[], int clearBuffer);

/**
 * @brief Clears the footer of the terminal.
 */
void clearFooter();

/**
 * @brief Confirms a message with a 'S' or 'N' input.
 * 
 * @param msg The message to be displayed.
 * @return The input of the user.
 */
char confirm(char msg[]);

/**
 * @brief Moves the cursor to a specific position on the terminal.
 * 
 * @param x The x position.
 * @param y The y position.
 */
void goTo(int x, int y);

/**
 * @brief Clears the terminal.
 */
void cls();

/**
 * @brief Waits for the user to press any key.
 * 
 * @param clearBuffer Flag to clear the input buffer.
 * @return The key pressed by the user.
 */
char awaitPressAnyKey(int clearBuffer);

void changeBackgroundColor(int r, int g, int b);
void changeForegroundColor(int r, int g, int b);
void setDefaultColor() ;

#endif