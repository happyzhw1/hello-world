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
struct Student_information                                  //����һ���ṹ�� 
{
	int Stuid;                                              //ѧ����ѧ��
	char StuName[20];  	                                	//ѧ��������
	char sex[20];                                   		//ѧ�����Ա�
	int age;                                        		//ѧ��������
	long phone;                                             //ѧ���ĵ绰 
	int score;	   	                                     	//ѧ���ĳɼ� 
	char census[20];	                                 	//ѧ���Ļ���
}StuIN[SIZE];
int total=0;                                                 
void main()
{
	char ch;
	FILE* fp;
	if((fp=fopen("ftotal.txt","r"))==NULL)
	{
		printf("�޷����ļ���");
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
				printf("\n������󣡰������������\n");
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
	printf("\t\t  �������������������������������������\n");
	printf("\t\t  ���                                                                ���\n");
	printf("\t\t  ���                     ��ӭ����ѧ������ϵͳ                       ���\n");
	printf("\t\t  ���                                                                ���\n");
	printf("\t\t  ���       1.����ѧ����Ϣ                 2.���ѧ����Ϣ            ���\n");
	printf("\t\t  ���                                                                ���\n");
	printf("\t\t  ���       3.ɾ��ѧ����Ϣ                 4.�鿴����ѧ����Ϣ 	      ���\n");
	printf("\t\t  ���                                                                ���\n");
	printf("\t\t  ���       5.����ѧ����Ϣ                 6.����鿴ѧ����Ϣ        ���\n");
	printf("\t\t  ���                                                                ���\n");
	printf("\t\t  ���                        7.�˳�ϵͳ                              ���\n");
	printf("\t\t  ���                                                                ���\n");
	printf("\t\t  �������������������������������������\n");
	printf("\t\t  ����������ѡ��˵���");
}
void input()
{
	char z,a[20],b[20],c[20];
	int num,i;
	FILE* fp;
	system("cls");
	printf("ѡ��˹��ܽ����ǵ���ǰ����ĳɼ���ȷ�ϼ���(y/n):");
	fflush(stdin);
	scanf("%c",&z);
	if(z=='n')
	{
		printf("�������������һ����");
		getch();
		menu();
	}
	else if(z=='y')
	{
	if((fp=fopen("ѧ����Ϣ.txt","w"))==NULL)
	{
		printf("�޷����ļ���");
		exit(0); 
	}
		system("cls");
		printf("��������Ҫд���ѧ��������");
		scanf("%d",&num);
		for(i=0;i<num;i++)
		{
			printf("����������ѧ�š��������Ա����䡢�绰���ɼ���������\n");
			fflush(stdin);
			printf("ѧ�ţ�");
			scanf("%d",&StuIN[i].Stuid);
			printf("������");
			scanf("%s",&a);
			strcpy(StuIN[i].StuName,a);
			printf("�Ա�");
			scanf("%s",&b);
			strcpy(StuIN[i].sex,b);
			printf("���䣺"); 
			scanf("%d",&StuIN[i].age);
			printf("�绰��");
			scanf("%d",&StuIN[i].phone);
			printf("�ɼ���");
			scanf("%d",&StuIN[i].score);
			printf("������");
			scanf("%s",&c);
			strcpy(StuIN[i].census,c);
			putchar('\n');
			fprintf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
		}
		fclose(fp);
		total=num;
		save_total(total);
		printf("����ɹ�����������������˵� ��");
		getch(); 
		menu();
	}	
	else
		printf("��������������˵� ��");
		getch();
		menu();	
}
void add()
{
	char tem[20],a[20],b[20],c[20];
	int num,i;
	FILE* fp;
	if((fp=fopen("ѧ����Ϣ.txt","a"))==NULL)
	{
		printf("�޷����ļ���");
		exit(0); 
	}
	system("cls");
	printf("��������Ҫ��ӵ�ѧ��������");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("����������ѧ�š��������Ա����䡢�绰���ɼ���������\n");
		fflush(stdin);
		printf("ѧ�ţ�");
		scanf("%d",&StuIN[i].Stuid);
		printf("������");
		scanf("%s",&a);
		strcpy(StuIN[i].StuName,a);
		printf("�Ա�");
		scanf("%s",&b);
		strcpy(StuIN[i].sex,b);
		printf("���䣺"); 
		scanf("%d",&StuIN[i].age);
		printf("�绰��");
		scanf("%d",&StuIN[i].phone);
		printf("�ɼ���");
		scanf("%d",&StuIN[i].score);
		printf("������");
		scanf("%s",&c);
		strcpy(StuIN[i].census,c);
		putchar('\n');
		fprintf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}		
	fclose(fp);
	total+=num;
	save_total(total);
	printf("����ɹ�����������������˵���");
	getch();
	menu();
}
void del()
{
	int i,m,stu_ID,flag=0,num;
	char name[20];
	FILE* fp;
	if((fp=fopen("ѧ����Ϣ.txt","r+"))==NULL)
	{
		printf("�޷����ļ���");
		exit(0); 
	}
	for(i=0;i<total;i++)
	{
		fscanf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}
	fclose(fp);
	system("cls");
	printf("������ѧ��ɾ������������ɾ����\n");
	printf("1����ѧ��\n2��������\n");
	printf("����������ѡ��");
	scanf("%d",&m);
	switch(m)
	{
	case 1:
		printf("������ѧ�ţ�");
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
			printf("�޴�ѧ�ţ�");
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
		if((fp=fopen("ѧ����Ϣ.txt","r"))==NULL)
		{
			printf("�޷����ļ���");
			exit(0); 
		}
		for(i=0;i<total;i++)
		{
			fprintf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
		}
		fclose(fp);
		printf("ɾ���ɹ�����������ص����˵���");
		getch();
		menu();
		break;
	case 2:
		printf("������������");
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
			printf("���޴��ˣ�");
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
	if((fp=fopen("ѧ����Ϣ.txt","r"))==NULL)
	{
		printf("�޷����ļ���");
		exit(0); 
	}
		for(i=0;i<total;i++)
		{
			fprintf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
		}
		fclose(fp);
		printf("ɾ���ɹ�����������ص����˵���");
		getch();
		menu();
		break;
	default:
		printf("������󣡰�������ص����˵���");
		getch();
		menu();
	}
}
void display()
{
	int i,j;
	FILE* fp;
	if((fp=fopen("ѧ����Ϣ.txt","r+"))==NULL)
	{
		printf("�޷����ļ���");
		exit(0); 
	}
	for(i=0;i<total;i++)
	{
		fscanf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}
	fclose(fp);
	system("cls");
//	printf("%d\n",total);
	printf("ѧ��  \t����  \t�Ա�  \t����  \t�绰  \t�ɼ�  \t����\n");
	for(j=0;j<total;j++)
	{
		printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[j].Stuid ,StuIN[j].StuName,StuIN[j].sex,StuIN[j].age,StuIN[j].phone,StuIN[j].score,StuIN[j].census);
	}
	printf("��������ص����˵���");
	getch();
	menu();
}
void find()
{
	int i,m,stu_ID,flag=0,num;
	char name[20];
	FILE* fp;
	if((fp=fopen("ѧ����Ϣ.txt","r"))==NULL)
	{
		printf("�޷����ļ���");
		exit(0); 
	}
	for(i=0;i<total;i++)
	{
		fscanf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}
	fclose(fp);
	system("cls");
	printf("���ҷ�ʽ��\n1����ѧ�Ų���\n2������������\n3���������˵�\n");
	printf("����������ѡ��");
	scanf("%d",&m);
	switch(m)
	{
	case 1:
		printf("������ѧ�ţ�");
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
			printf("�޴�ѧ�ţ���������ص����˵���");
			getch();
			menu();
		}
		else
		{
			printf("ѧ��  \t����  \t�Ա�  \t����  \t�绰  \t�ɼ�  \t����\n");
			printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid ,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
			printf("���ҳɹ�����������ص����˵���");
			getch();
			menu();
		}
		break;	
	case 2:
		printf("������������");
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
			printf("���޴��ˣ���������ص����˵���");
			getch();
			menu();
		}
		else
		{
			printf("ѧ��  \t����  \t�Ա�  \t����  \t�绰  \t�ɼ�  \t����\n");
			printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[i].Stuid,StuIN[i].StuName,StuIN[i].sex,StuIN[i].age,StuIN[i].phone,StuIN[i].score,StuIN[i].census);
			printf("���ҳɹ�����������ص����˵���");
			getch();
			menu();
		}
		break;
	case 3:
		menu(); 
	default:
		printf("������󣡰�������ص����˵���");
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
	if((fp=fopen("ѧ����Ϣ.txt","r"))==NULL)
	{
		printf("�޷����ļ���");
		exit(0); 
	}
	for(i=0;i<total;i++)
	{
		fscanf(fp,"%d\t %s\t %s\t %d\t %d\t %d\t %s\n",&StuIN[i].Stuid,&StuIN[i].StuName,&StuIN[i].sex,&StuIN[i].age,&StuIN[i].phone,&StuIN[i].score,&StuIN[i].census);
	}
	fclose(fp);

	system("cls");
	printf("�Ժη�ʽ����\n1��ѧ��\n2���ɼ�\n����������ѡ��");
	fflush(stdin);
	scanf("%c",&ch);
	switch(ch)
	{
	case '1':
		system("cls");
		printf("��ѧ���������£�\n");
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
		printf("ѧ��  \t����  \t�Ա�  \t����  \t�绰  \t�ɼ�  \t����\n");
		for(j=0;j<total;j++)
		{
			printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[j].Stuid,StuIN[j].StuName,StuIN[j].sex,StuIN[j].age,StuIN[j].phone,StuIN[j].score,StuIN[j].census);
		}
		printf("��������ص����˵���");
		getch();
		menu();
	case '2':
		system("cls");
		printf("���ɼ��������£�\n");
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
		printf("ѧ��  \t����  \t�Ա�  \t����  \t�绰  \t�ɼ�  \t����\n");
		for(j=0;j<total;j++)
		{
			printf("%d\t %s\t %s\t %d\t %d\t %d\t %s\n",StuIN[j].Stuid,StuIN[j].StuName,StuIN[j].sex,StuIN[j].age,StuIN[j].phone,StuIN[j].score,StuIN[j].census);
		}
		printf("��������ص����˵���");
		getch();
		menu();
	default:
		printf("������󣡰�������ص����˵���\n");
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
		printf("�޷����ļ���");
		exit(0); 
	}
	fprintf(fp,"%d",total);
	fclose(fp);
}

 


