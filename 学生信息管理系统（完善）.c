#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
void menu();
void input();
void add();
void del();
void display();
void find();
void sort();
void quit();
void save_total();
struct Student_information                                  //定义一个结构体 
{
	int Stuid;                                              //学生的学号
	char StuName[20];  	                                	//学生的姓名
	char sex[20];                                   		//学生的性别
	int age;                                        		//学生的年龄
	long phone;                                             //学生的电话 
	int score;	   	                                     	//学生的成绩 
	char census[20];	                                 	//学生的户籍
}StuIN[SIZE];
int total=0;                                                 
void main()
{
	char ch;
	FILE* fp;
	if((fp=fopen("ftotal.txt","r"))==NULL)
	{
		printf("无法打开文件！");
		exit(0); 
	}
	else
		fscanf(fp,"%d",&total);
	menu();
	printf("%d",total);
	do
	{
		fflush(stdin);
		if((ch=getchar())!='\n');
		{
			switch(ch)
			{
			case '1':
				input();
				break;
			case '2':
				add();
				break;
			case '3':
				del();
				break;
			case '4':
				display();
				break;
			case '5':
				find();
				break;
			case '6':
				sort();
				break;
			case '7':
				quit();
				break;
			default:
				printf("\n输入错误！按任意键继续：\n");
			}
		fclose(fp);
		system("cls");
		menu();
		}
	}while(1);
}
void menu()
{
	system("cls");
	printf("\t\t  ★☆★☆★☆★☆★☆★☆★☆★☆★☆☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");
	printf("\t\t  ★☆                                                                ☆★\n");
	printf("\t\t  ★☆                     欢迎进入学生管理系统                       ☆★\n");
	printf("\t\t  ★☆                                                                ☆★\n");
	printf("\t\t  ★☆       1.输入学生信息                 2.添加学生信息            ☆★\n");
	printf("\t\t  ★☆                                                                ☆★\n");
	printf("\t\t  ★☆       3.删除学生信息                 4.查看所有学生信息 	      ☆★\n");
	printf("\t\t  ★☆                                                                ☆★\n");
	printf("\t\t  ★☆       5.查找学生信息                 6.排序查看学生信息        ☆★\n");
	printf("\t\t  ★☆                                                                ☆★\n");
	printf("\t\t  ★☆                        7.退出系统                              ☆★\n");
	printf("\t\t  ★☆                                                                ☆★\n");
	printf("\t\t  ★☆★☆★☆★☆★☆★☆★☆★☆★☆☆★☆★☆★☆★☆★☆★☆★☆★☆★\n");
	printf("\t\t  请输入数字选择菜单：");
}
void input()
{
	char z,a[20],b[20],c[20];
	int num,i;
	FILE* fp;
	system("cls");
	printf("选择此功能将覆盖掉以前保存的成绩，确认继续(y/n):");
	fflush(stdin);
	scanf("%c",&z);
	if(z=='n')
	{
		printf("按任意键返回上一级！");
		getch();
		menu();
	}
	else if(z=='y')
	{
	if((fp=fopen("学生信息.txt","w"))==NULL)
	{
		printf("无法打开文件！");
		exit(0); 
	}
		system("cls");
		printf("请输入您要写入的学生个数：");
		scanf("%d",&num);
		for(i=0;i<num;i++)
		{
			printf("请依次输入学号、姓名、性别、年龄、电话、成绩、户籍：\n");
			fflush(stdin);
			printf("学号：");
			scanf("%d",&StuIN[i].Stuid);
			printf("姓名：");
			scanf("%s",&a);
			strcpy(StuIN[i].StuName,a);
			printf("性别：");
			scanf("%s",&b);
			strcpy(StuIN[i].sex,b);
			printf("年龄："); 
			scanf("%d",&StuIN[i].age);
			printf("电话：");
			scanf("%d",&StuIN[i].phone);
			printf("成绩：");
			scanf("%d",&StuIN[i].score);
			printf("户籍：");
			scanf("%s",&c);
			strcpy(StuIN[i].census,c);
			putchar('\n');
			fprintf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
		}
		fclose(fp);
		total=num;
		save_total(total);
		printf("输入成功！按任意键返回主菜单 ：");
		getch(); 
		menu();
	}	
	else
		printf("按任意键返回主菜单 ：");
		getch();
		menu();	
}
void add()
{
	char tem[20],a[20],b[20],c[20];
	int num,i;
	FILE* fp;
	if((fp=fopen("学生信息.txt","a"))==NULL)
	{
		printf("无法打开文件！");
		exit(0); 
	}
	system("cls");
	printf("请输入您要添加的学生个数：");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("请依次输入学号、姓名、性别、年龄、电话、成绩、户籍：\n");
		fflush(stdin);
		printf("学号：");
		scanf("%d",&StuIN[i].Stuid);
		printf("姓名：");
		scanf("%s",&a);
		strcpy(StuIN[i].StuName,a);
		printf("性别：");
		scanf("%s",&b);
		strcpy(StuIN[i].sex,b);
		printf("年龄："); 
		scanf("%d",&StuIN[i].age);
		printf("电话：");
		scanf("%d",&StuIN[i].phone);
		printf("成绩：");
		scanf("%d",&StuIN[i].score);
		printf("户籍：");
		scanf("%s",&c);
		strcpy(StuIN[i].census,c);
		putchar('\n');
		fprintf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}		
	fclose(fp);
	total+=num;
	save_total(total);
	printf("输入成功！按任意键返回主菜单：");
	getch();
	menu();
}
void del()
{
	int i,m,stu_ID,flag=0,num;
	char name[20];
	FILE* fp;
	if((fp=fopen("学生信息.txt","r+"))==NULL)
	{
		printf("无法打开文件！");
		exit(0); 
	}
	for(i=0;i<total;i++)
	{
		fscanf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}
	fclose(fp);
	system("cls");
	printf("您想以学号删除还是以姓名删除？\n");
	printf("1、以学号\n2、以姓名\n");
	printf("请输入数字选择：");
	scanf("%d",&m);
	switch(m)
	{
	case 1:
		printf("请输入学号：");
		scanf("%d",&stu_ID);
		for(i=0;i<total;i++)
		{
			if(stu_ID==StuIN[i].Stuid)
			{
				flag=1;
				num=i;
				break;
			}
		}
		if(flag!=1)
		{
			printf("无此学号！");
		}
		else
		{
			if(num==(total-1))
				total--;
			else
			{
				for(i=num;i<(total-1);i++)
				StuIN[i]=StuIN[i+1];
				total--;
			}
		}
		save_total(total);
		if((fp=fopen("学生信息.txt","r"))==NULL)
		{
			printf("无法打开文件！");
			exit(0); 
		}
		for(i=0;i<total;i++)
		{
			fprintf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
		}
		fclose(fp);
		printf("删除成功！按任意键回到主菜单：");
		getch();
		menu();
		break;
	case 2:
		printf("请输入姓名：");
		fflush(stdin);
		gets(name);
		for(i=0;i<total;i++)
		{
			if(strcmp(name,StuIN[i].StuName)==0)
			{
				flag=1;
				num=i;
				break;
			}
		}
		if(flag!=1)
		{
			printf("查无此人！");
		}
		else
		{
			if(num==(total-1))
				total--;
			else
			{
				for(i=num;i<(total-1);i++)
				StuIN[i]=StuIN[i+1];
				total--;
			}
		}
		save_total(total);
		save_total(total);
	if((fp=fopen("学生信息.txt","r"))==NULL)
	{
		printf("无法打开文件！");
		exit(0); 
	}
		for(i=0;i<total;i++)
		{
			fprintf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
		}
		fclose(fp);
		printf("删除成功！按任意键回到主菜单：");
		getch();
		menu();
		break;
	default:
		printf("输入错误！按任意键回到主菜单：");
		getch();
		menu();
	}
}
void display()
{
	int i,j;
	FILE* fp;
	if((fp=fopen("学生信息.txt","r+"))==NULL)
	{
		printf("无法打开文件！");
		exit(0); 
	}
	for(i=0;i<total;i++)
	{
		fscanf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}
	fclose(fp);
	system("cls");
//	printf("%d\n",total);
	printf("学号  \t姓名  \t性别  \t年龄  \t电话  \t成绩  \t户籍\n");
	for(j=0;j<total;j++)
	{
		printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[j].Stuid ,StuIN[j].StuName,StuIN[j].sex,StuIN[j].age,StuIN[j].phone,StuIN[j].score,StuIN[j].census);
	}
	printf("按任意键回到主菜单：");
	getch();
	menu();
}
void find()
{
	int i,m,stu_ID,flag=0,num;
	char name[20];
	FILE* fp;
	if((fp=fopen("学生信息.txt","r"))==NULL)
	{
		printf("无法打开文件！");
		exit(0); 
	}
	for(i=0;i<total;i++)
	{
		fscanf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}
	fclose(fp);
	system("cls");
	printf("查找方式：\n1、按学号查找\n2、按姓名查找\n3、返回主菜单\n");
	printf("请输入数字选择：");
	scanf("%d",&m);
	switch(m)
	{
	case 1:
		printf("请输入学号：");
		scanf("%d",&stu_ID);
		for(i=0;i<total;i++)
		{
			if(stu_ID==StuIN[i].Stuid)
			{
				flag=1;
				num=i;
				break;
			}
		}
		if(flag!=1)
		{
			printf("无此学号！按任意键回到主菜单：");
			getch();
			menu();
		}
		else
		{
			printf("学号  \t姓名  \t性别  \t年龄  \t电话  \t成绩  \t户籍\n");
			printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid ,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
			printf("查找成功！按任意键回到主菜单：");
			getch();
			menu();
		}
		break;	
	case 2:
		printf("请输入姓名：");
		fflush(stdin);
		gets(name);
		for(i=0;i<total;i++)
		{
			if(strcmp(name,StuIN[i].StuName)==0)
			{
				flag=1;
				num=i;
				break;
			}
		}
		if(flag!=1)
		{
			printf("查无此人！按任意键回到主菜单：");
			getch();
			menu();
		}
		else
		{
			printf("学号  \t姓名  \t性别  \t年龄  \t电话  \t成绩  \t户籍\n");
			printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
			printf("查找成功！按任意键回到主菜单：");
			getch();
			menu();
		}
		break;
	case 3:
		menu(); 
	default:
		printf("输入错误！按任意键回到主菜单：");
		getch();
		menu();
	}
	fclose(fp);
}
void sort()
{
	struct Student_information stu1;
	int i,j,k,temp[100];
	char ch;
	FILE* fp;
	if((fp=fopen("学生信息.txt","r"))==NULL)
	{
		printf("无法打开文件！");
		exit(0); 
	}
	for(i=0;i<total;i++)
	{
		fscanf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}
	fclose(fp);

	system("cls");
	printf("以何方式排序？\n1、学号\n2、成绩\n请输入数字选择：");
	fflush(stdin);
	scanf("%c",&ch);
	switch(ch)
	{
	case '1':
		system("cls");
		printf("按学号排序如下：\n");
		for(i=1;i<total;i++)
		{
			for(k=0;k<total-i;k++)
			{
				if(StuIN[k].Stuid > StuIN[k+1].Stuid)
				{
					stu1=StuIN[k];
					StuIN[k]=StuIN[k+1];
					StuIN[k+1]=stu1;
				}
			}
		}
		printf("学号  \t姓名  \t性别  \t年龄  \t电话  \t成绩  \t户籍\n");
		for(j=0;j<total;j++)
		{
			printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[j].Stuid,StuIN[j].StuName,StuIN[j].sex,StuIN[j].age,StuIN[j].phone,StuIN[j].score,StuIN[j].census);
		}
		printf("按任意键回到主菜单：");
		getch();
		menu();
	case '2':
		system("cls");
		printf("按成绩排序如下：\n");
		for(i=1;i<total;i++)
		{
			for(k=0;k<total-i;k++)
			{
				if(StuIN[k].score < StuIN[k+1].score)
				{
					stu1=StuIN[k];
					StuIN[k]=StuIN[k+1];
					StuIN[k+1]=stu1;
				}
			}
		}
		printf("学号  \t姓名  \t性别  \t年龄  \t电话  \t成绩  \t户籍\n");
		for(j=0;j<total;j++)
		{
			printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[j].Stuid,StuIN[j].StuName,StuIN[j].sex,StuIN[j].age,StuIN[j].phone,StuIN[j].score,StuIN[j].census);
		}
		printf("按任意键回到主菜单：");
		getch();
		menu();
	default:
		printf("输入错误！按任意键回到主菜单：\n");
		getch();
		menu();
	}
}
void quit()
{
	system("cls");
	exit(0);
}
void save_total(int total)
{
	FILE* fp;
	if((fp=fopen("ftotal.txt","w"))==NULL)
	{
		printf("无法打开文件！");
		exit(0); 
	}
	fprintf(fp,"%d",total);
	fclose(fp);
}

 


