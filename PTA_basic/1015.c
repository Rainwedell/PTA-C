//本题要完美ac需要至少复杂度低于快排的排序算法，自己造的冒泡轮子时间上跑不过
//在stl上直接套用 ，注意cmp的写法即可 详见
//https://blog.csdn.net/qq_38851937/article/details/89260263
//https://blog.csdn.net/yzl_rex/article/details/7874513
//https://blog.csdn.net/yzl_rex/article/details/7874513?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-0.no_search_link&spm=1001.2101.3001.4242
//有关函数指针：http://c.biancheng.net/view/228.html
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct AStudent
    {
        long number;
        int a;
        int b;

    }Student;
void StructSort(Student p[],int N);
void StructSwap(Student* p,Student* q);
void StructSwap(Student* p,Student* q)
{
    Student x;
    x = *p;
    *p = *q;
    *q = x; 
}
void StructSort(Student p[],int N)//这里是冒泡写的
{
    int P,i;
    bool flag;
    for (P = N-1; P>= 0; P--)
    {
        flag = false;
        for ( i = 0; i < P; i++)
        {
            if ((p[i].a+p[i].b)<=(p[i+1].a+p[i+1].b))
            {
                if ((p[i].a+p[i].b)==(p[i+1].a+p[i+1].b))//总分一样
                {
                    if(p[i].a<=p[i+1].a)//讨论德分
                    {
                        if(p[i].a==p[i+1].a)//德分一样
                        {
                            if (p[i].number>p[i+1].number)//讨论考号
                            {
                                StructSwap(&(p[i]),&(p[i+1]));
                            }
                        }
                        else StructSwap(&(p[i]),&(p[i+1]));
                    }
                }
                else StructSwap(&(p[i]),&(p[i+1]));
                /*Student x;
                x = p[i];
                p[i] = p[i+1];
                p[i+1] = x;*/ 
                flag = true;
            }
            
        }
        if(flag == false) break;
    }
    
}
void PRINT(Student p[],int N);
void PRINT(Student p[],int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%ld %d %d\n",p[i].number,p[i].a,p[i].b);
    }
    
}
int cmp(const void *a, const void *b)
{
	Student *s1, *s2;
	int sum1, sum2;
	s1 = (Student *)a;
	s2 = (Student *)b;
	sum1 = s1->a + s1->b;
	sum2 = s2->a + s2->b;
	//考生按输入中说明的规则从高到低排序。
	//当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
	//返回值小于0，p1(a)所指向的元素会被排在p2(b)所指向的元素前面。
    //返回值等于0，p1所指向的元素与p2所指向的元素的顺序不确定。
    //返回值大于0，p1所指向的元素会被排在p2所指向的元素后面。
    if(sum1 != sum2) return sum2-sum1;//降序排列，大到小
	else if(s1->a != s2->a) return s2->a-s1->a;//降序排列，大到小
	else return s1->number-s2->number;//升序排列，小到大
}
int main(void)
{
    int N;
    int L,H;
    int i1,i2,i3,i4;
    i1=i2=i3=i4=0;
    scanf("%d %d %d",&N,&L,&H);
    Student x[N];
    Student s[N],t[N],p[N],q[N];
    
    for (int i = 0; i < N; i++)
    {
        scanf("%ld %d %d",&x[i].number,&x[i].a,&x[i].b);
        if (x[i].a>=L && x[i].b>=L)
        {
            if (x[i].a>=H && x[i].b>=H)
            {
                s[i1++]=x[i];
            }
            else if (x[i].a>=H)
            {
                t[i2++] = x[i];
            }
            else if (x[i].a>=x[i].b)
            {
                p[i3++] = x[i];
            }
            else
            {
                q[i4++] = x[i];
            }    
        }
    }
    //StructSort(x,N);
    //StructSort(s,i1);
    //StructSort(t,i2);
    //StructSort(p,i3);
    //StructSort(q,i4);
    qsort(s,i1,sizeof(Student),cmp);
    qsort(t,i2,sizeof(Student),cmp);
    qsort(p,i3,sizeof(Student),cmp);
    qsort(q,i4,sizeof(Student),cmp);
    printf("%d\n",i1+i2+i3+i4);
    PRINT(s,i1);
    PRINT(t,i2);
    PRINT(p,i3);
    PRINT(q,i4);
   
    return 0;

}