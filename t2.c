#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#include<string.h>
int main()
{
  char str1[] = "wo zui xihuan lubaobao!";
  char str2[] = "#######################";
  int left = 0;
  int right = strlen(str2) - 1;
  while (left <= right)
  {
    printf("%s\n",str2);
    str2[left] = str1[left];
    str2[right] = str1[right];
    ++left;
    --right;
    usleep(500);
  }
  system("pause");
  return 0;
}
