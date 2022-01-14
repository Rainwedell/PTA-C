// #include <stdio.h>
// #include <stdlib.h>
// #include <ctype.h>
// // 定义栈
// typedef struct stack
// {
// 	int data;
// 	struct stack *next;
// } stack;
// stack *push(stack *, int);	//数的入栈操作
// stack *calc(stack *, char); //计算
// int main(void)
// {

// 	stack *top = (stack *)malloc(sizeof(stack *)); //创建先进后出的链表
// 	top->data = 0;
// 	top->next = NULL;
// 	// c读取输入
// 	char c;
// 	int t = 0;
// 	while ((c = getchar()) != '\n')
// 	{
// 		// 这里 isspace忽略是否是空格，isdigit锁定10进制数字字符
// 		if (c == ',' || isspace(c))
// 		{ //跳过逗号与空格
// 			continue;
// 		}
// 		if (isdigit(c))
// 		{
// 			// 转换为数字
// 			t = c - '0';
// 			//处理多位数
// 			while (isdigit(c = getchar()))
// 			{
// 				t = t * 10 + c - '0';
// 			}
// 			// 至此，一个数字字符转换完成
// 			top = push(top, t); //此数入栈
// 		}
// 		else
// 		{
// 			top = calc(top, c); //用该符号进行运算
// 		}
// 	}
// 	printf("%d", top->data);
// 	return 0;
// }
// stack *push(stack *n, int x)
// {
// 	stack *p = (stack *)malloc(sizeof(stack));
// 	p->next = n; //将此单元接在链表最后一个单元之后
// 	p->data = x; //将此单元的数据域赋值
// 	return p;
// }
// stack *calc(stack *n, char c)
// {
// 	stack *p1 = n, *p2 = n->next; //用指针指向链表最后两位
// 	switch (c)
// 	{
// 	case ('+'):
// 		p2->data = p1->data + p2->data;
// 		break;
// 	case ('-'):
// 		p2->data = p2->data - p1->data;
// 		break;
// 	case ('*'):
// 		p2->data = p2->data * p1->data;
// 		break;
// 	case ('/'):
// 		p2->data = p2->data / p1->data;
// 		break;
// 	}
// 	free(p1);  //将栈顶空间释放
// 	return p2; // p2所指为新的栈顶
// }

#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
int pop(void);
/* 逆波兰计算器,实现了对负数的支持 */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op2 = pop();
			if (op2 == 0.0)
				printf("error: zero divesor\n");
			else
				push(pop() / op2);
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '%':
			op2 = pop();
			if (op2 == 0.0)
				printf("error: zero divesor\n");
			else
				push((int)pop() % (int)op2);
			break;
		case '\n':
			printf("%d\n", pop());
			break;
		default:
			printf("error: unknown command %s", s);
			break;
		}
	}
	return 0;
}
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

/* push 函数：把f压入到值栈中 */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

int pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0;
	}
}
#include <ctype.h>
int getch(void);
void ungetch(int);
/*getop 函数：获取下一个运算符或数值操作数 */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '(') /* 引入“(” 作为符号位：标识负数*/
		return c;							 /* 不是数 */
	i = 0;
	if (c == '(')
	{
		if ((c = getch()) == '-')
			s[i++] = c;

		if (c == '-' || c == '+')
			c = getch();
	}

	if (isdigit(c))
	{
		s[i] = c;
		while (isdigit(s[++i] = c = getch()))
			;
	}
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = 0;
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}