//----------------------------------------------------------
// Name: Hassan Shahzad										|
// Class: BSCS-7C											|
// CMS ID: 211798                                           |
// ---------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// declaring variables and arrays
char message[100];
void encoding(); // function prototype
void decoding(); // function prototype
char alpha;
int key;
char user_choice;
void decodemanually(); // function prototype

int main()
{
	printf("Welcome to Caesar Cipher!!\n");
	printf("Enter 'E' for encoding, 'D' for decoding and 'B' for decode manually by brute force\n");
	// Asking the user to enter a specific choice
	scanf("%c", &user_choice);
	// if choice is equivalent to e or E then function encoding is called
	if (user_choice == 'e' || user_choice == 'E')
		encoding();
	// else if choice is equivalent to d or D then function decoding is called
	else if (user_choice == 'd' || user_choice == 'D')
		decoding();
	// else if choice is quivalent to b or B then function decodemanually is called
	else if (user_choice == 'b' || user_choice == 'B')
		decodemanually();

	// prints error if the entered value was not given and asks for user's choice again.
	while (!(user_choice == 'd' || user_choice == 'D' || user_choice == 'E' || user_choice == 'e' || user_choice == 'b' || user_choice == 'B'))
	{
		printf("ERROR!!! Wrong choice.\nEnter your choice again.");
		scanf("%c", &user_choice);
		if (user_choice == 'e' || user_choice == 'E')
		{
			encoding();
			break;
		}
		else if (user_choice == 'd' || user_choice == 'D')
		{
			decoding();
			break;
		}
		else if (user_choice == 'dm' || user_choice == 'DM')
		{
			decodemanually();
			break;
		}
	}

}

void encoding() // function prototype
{
	// Asks the user to enter key
	printf("Enter your key(1 to 25): ");
	scanf("%d", &key);

	// Checks the range of the key if key is beyond the range then prints error and asks for key again.
	while (key > 25 || key < 1){
		printf("ERROR!!! Wrong entry of keys detected. Enter Number of keys again!\n");
		scanf("%d", &key);
		if (key >= 1 && key <= 25)
		{
			break; // if key is in the limits then escape from the loop
		}
	}

	// Asks the user to enter the message
	printf("Enter your message: ");
	scanf(" %[^\n]", &message);

	// displays encoded message
	printf("Encoded Message: ");
	// declaring variable i 
	int i;
	// the loop runs till the last character of the sentence is entered.
	for (i = 0; i < strlen(message); i++)
	{
		if (message[i] >= 'a' && message[i] <= 'z')
		{
			// checks if the sum of key and message is less than the ascii value of z
			if (key + message[i] <= 'z')
			{
				message[i] = key + message[i];
				printf("%c", message[i]);
			}
			// checks if the sum of key and message is greater tan ascii value of z than subtract 26 inorder to wrap the alphabets
			else if (key + message[i]> 'z')
			{
				message[i] = key + message[i] - 26;
				printf("%c", message[i]);
			}
		}
		else if (message[i] >= 'A' && message[i] <= 'Z')
		{
			alpha = key + message[i];
			// checks if the sum of key and message is less than the ascii value of z
			if (alpha <= 'Z')
			{
				printf("%c", alpha);
			}
			// checks if the sum of key and message is greater tan ascii value of Z than subtract 26 inorder to wrap the alphabets
			else if (alpha > 'Z')
			{
				alpha = alpha - 26;
				printf("%c", alpha);
			}
		}
		// if the entered character is other than alphabet then prints the character as it is
		else
			printf("%c", message[i]);
	}
	printf("\n\n");
}

void decoding() // function prototype
{
	// Asks the user to enter key
	printf("Enter your key(1 to 25): ");
	scanf("%d", &key);

	// Checks the range of the key if key is beyond the range then prints error and asks for key again.
	while (key > 25 || key < 1){
		printf("ERROR!!! Wrong entry of keys detected. Enter Number of keys again!\n");
		scanf("%d", &key);
		if (key >= 1 && key <= 25){
			break; // if key is in the limits then escape from the loop
		}
	}
	// Asks the user to enter the message
	printf("Enter your message: ");
	scanf(" %[^\n]", &message);

	int i; // declaring i
	// displaying Decoded message
	printf("\nDecoded Message: ");

	// the loop runs till the last character of the sentence is entered.
	for (i = 0; i < strlen(message); i++)
	{
		// condition checking wheteher entered alphabet is witin the range of a and z
		if (message[i] >= 'a' && message[i] <= 'z')
		{
			// checks whether the subtracted value of current message character and key is less than a
			if (message[i] - key < 'a')
			{
				// wrapping the alphabets, adding 26 to restrict the ascii values within small letters
				message[i] = message[i] - key + 26;
				printf("%c", message[i]);
			}
			else
			{
				// prints the subtracted value of current message character and key
				message[i] = message[i] - key;
				printf("%c", message[i]);
			}
		}
		// checks whether entered character is within the range of A and Z
		else if (message[i] >= 'A' && message[i] <= 'Z')
		{
			alpha = message[i] - key;
			if (alpha < 'A')
			{
				alpha = alpha + 26; // wraps the alphabets if alpha greater than A
				printf("%c", alpha);
			}
			else
			{
				printf("%c", alpha);
			}
		}
		// if the entered character is other than alphabet then prints the character as it is.
		else
			printf("%c", message[i]); //
	}
	printf("\n\n");
}

void decodemanually() // function prototype
{
	printf("Enter your message: ");
	scanf(" %[^\n]", &message);
	int i; // declaring i
	// runs the loop with values of key from 1 to 25
	for (key = 1; key <= 25; key++)
	{
		// displays decoded message
		printf("\nDecoded Message key %d: ", key);
		// runs in the inner loop until the last character of the sentence
		for (i = 0; i < strlen(message); i++)
		{
			// checks the entered letter is within the range of lower case alphabets
			if (message[i] >= 'a' && message[i] <= 'z')
			{
				// wraps the alphabets if the subtraction of current message character and key is lesser than ascii value of 'a' 
				alpha = message[i] - key;
				if (alpha < 'a')
				{
					// wrapping of alphabets if decoded message character is lesser than ascii value of A
					alpha = alpha + 26;
					printf("%c", alpha);
				}
				else
				{
					printf("%c", alpha);
				}
			}
			else if (message[i] >= 'A' && message[i] <= 'Z')
			{
				// checks the entered letter is within the range of upper case alphabets
				alpha = message[i] - key;
				if (alpha < 'A')
				{
					// wrapping of alphabets if decoded message character is lesser than ascii value of A
					alpha = alpha + 26;
					printf("%c", alpha);
				}
				else
				{
					printf("%c", alpha);
				}
			}
			else
				// if the entered character is other than alphabet then prints the character as it is.
				printf("%c", message[i]);
		}
	}
	printf("\n");
}