#include "enc_dec_showfile.h"
#include <stdio.h>
#include <sys/types.h>                                                                                                                                                
#include <sys/stat.h>                                                                                                                                                 
#include <fcntl.h>
#include <unistd.h>
void encrypt_1()
{
		char src_file[128],enc_file[128],ch;
		int cnt;

		printf("Enter the source file\n");
		scanf("%s",src_file);

		int fd_src = open(src_file,O_RDONLY);
		if(fd_src < 0)
		{
				perror("cannot open srource file \n");
				_exit(1);
		}

		printf("Enter the filename to save encrypted data\n");
		scanf("%s",enc_file);

		int fd_enc = open(enc_file,O_CREAT | O_TRUNC | O_RDWR, 0644 );
		if(fd_enc < 0)
		{
				perror("cannot create file to save encrypted data \n");
				_exit(2);
		}

		while((cnt=read(fd_src,&ch,1))>0)
		{
				ch = ch+1;
				write(fd_enc,&ch,1);
		}
     
		printf("encryption completed in %s file\n",enc_file);

		close(fd_src);
		close(fd_enc);

		return;
}

void decrypt_1()
{
		char enc_file[128],dec_file[128],ch;
		int cnt;

		printf("Enter the encrypted file\n");
		scanf("%s",enc_file);

		int fd_enc = open(enc_file,O_RDONLY);
		if(fd_enc < 0)
		{
				perror("cannot open encrypted file \n");
				_exit(3);
		}

		printf("Enter the filename to save decrypted data\n");
		scanf("%s",dec_file);

		int fd_dec = open(dec_file,O_CREAT | O_TRUNC | O_RDWR, 0644 );
		if(fd_dec < 0)
		{
				perror("cannot create file to save decrypted data \n");
				_exit(4);
		}

		while((cnt=read(fd_enc,&ch,1))>0)
		{
				ch= ch-1;
				write(fd_dec,&ch,1);
		}

		printf("decryption completed in %s file\n",dec_file);

		close(fd_enc);
		close(fd_dec);

		return;
}

void showfile()
{
		char file[128],ch;
		int cnt;

		printf("Enter the name of file\n");
		scanf("%s",file);

		int fd = open(file,O_RDONLY);
		if(fd < 0)
		{
				perror("cannot open the file \n");
				_exit(5);
		}

		while((cnt=read(fd,&ch,1))>0)
				write(1,&ch,1);


		close(fd);

		return;
}
