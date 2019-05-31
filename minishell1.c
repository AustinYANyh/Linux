/*===============================================================
*   Copyright (C) 2019 All rights reserved.
*   
*   文件名称：minishell1.c
*   创 建 者：herb
*   创建日期：2019年05月31日
*   描    述：
*
================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include<ctype.h>
#include <sys/wait.h>

int main()
{
	while (1)
	{
	   printf("[luzihan@TecentCloud]$");
	   fflush(stdout);

	   char tmp[1024] = { 0  };
	   scanf("%[^\n]%*c",tmp);
	   printf("%s\n", tmp);

	   char* ptr = tmp;
	   int argc = 0;

	   char* argv[32] = { NULL  };
	   while (*ptr != '\0')
	   {
		if (!isspace(*ptr))
		{
			argv[argc] = ptr;
			argc++;
			while (!isspace(*ptr) && *ptr != '\0')
			{
			    ptr++;
			}
			*ptr = '\0';
			ptr++;
			continue;
		}
		argv[argc] = NULL;
          }
	  int pid = fork();
          if (pid == 0)
	  {
	      execvp(argv[0], argv);
	      exit(0);
	  }
	  wait(NULL);
    }
    return 0;
}
