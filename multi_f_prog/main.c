#include<stdio.h>
#include"enc_dec_showfile.h"

enum menu_options{ EXIT, ENCRYPT, DECRYPT, SHOWFILE };

int menu(void)
{
		int choice;
		printf("Char File encryption and decryption\n");
		printf("0. EXIT\n");
		printf("1. ENCRYPT\n");
		printf("2. DECRYPT\n");
		printf("3. SHOWFILE\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);

		return choice;

}

int main(void)
{
		while(1)
		{
				int choice = menu();
				switch(choice)
				{
						case EXIT: return -1;

						case ENCRYPT:
								   encrypt_1();
								   break;

						case DECRYPT:
								   decrypt_1();
								   break;

						case SHOWFILE:
								   showfile();
								   break;

						default:
								   printf("invalid choice \n");
								   break;

				}

		}

		return 0;

}




