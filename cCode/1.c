#include <stdio.h>
#include <stdlib.h>


/*例1:将输入中最长的行打印出来
 * Step1:伪代码
 * while(还存在未处理的行)
 *  if(该行比已处理的行要长)
 *    保存最长行内容；
 *    统计最长行长度；
 * 打印最长行
 * 
 * Step2:低耦合高内局，函数模块功能独立
 * getline:读取输入的下一行
 * */

/*********宏定义**********/
#define MAXLEN 100
/********全局变量*********/

/*******函数声明**********/
int _getline(char line[],int maxline);
void copy(char to[],char from[]);

/******主函数************/

int main()
{
	int len;
	int max;
	char line[MAXLEN];
	char longest[MAXLEN];
	
	max=0;
	while((len = _getline(line,MAXLEN)) > 0)
	{
		if(len>max)
		{
			max=len;
			copy(longest,line);
		}
	}
	if(max>0)
	    printf("%s",longest);
	return 0;
}

int _getline(char s[],int lim)
{
	int c,i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
	    s[i]=c;
	if(c == '\n')
	{
		s[i]=c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char s[], char t[])
{
	int i;
	
	i=0;
	while((s[i]=t[i]) != '\0')
	    ++i;
	
}

