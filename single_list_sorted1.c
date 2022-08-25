#include<stdio.h>
#include <stdlib.h>
typedef struct employee
{
	int eno;
	char name[20];
	double salary;
	struct employee *next;
}emp;
int  add();
int  edit();
int  del();
int  view();
int file_to_list();
int list_to_file();
void rview(emp *);

emp *start,*new,*ptr,*prev;
int main()
{
	start=new=ptr=prev=NULL;
	int ch=0;
	file_to_list();
	while(ch!=6)
	{
		printf("\n1. Add Data to List\n2. Edit Data\n3. Delete Data\n4. View List\n5. Rev View\n6. Exit");
		printf("\nEnter choice-");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: add();
				break;
			case 2: edit();
				break;
			case 3: del();
				break;
			case 4: view();
				break;
			case 5:rview(start);
			       break;
			case 6: break;
			default: printf("\nInvalid Choice\n");
		}
	}
	list_to_file();
}

int add()
{
	new=(emp*)malloc(sizeof(emp));
	printf("Enter empno-");
	scanf("%d",&new->eno);
	printf("Enter name-");
	scanf("%s",new->name);
	printf("Enter salary-");
	scanf("%lf",&new->salary);
	if(start==NULL)
	{
		start=new;
		new->next=NULL;
	}
	else if(new->eno<start->eno)
	{
		new->next=start;
		start=new;
	}
	else
	{
		for(ptr=start;(ptr) && ptr->eno<new->eno;prev=ptr,ptr=ptr->next);
		prev->next=new;
		new->next=ptr;
	}
}

int view()
{
	if(!start)
	{
		printf("\nEmpty List\n");
		return(1);
	}
	printf("\nEMPNO         NAME       SALARY\n");

	for(ptr=start;(ptr);ptr=ptr->next)
	{
		printf("\n%5d   %30s   %7.2lf\n",ptr->eno,ptr->name,ptr->salary);
	}
}

int edit()
{
	if(!start)
	{
		printf("\nEmpty List\n");
		return(1);
	}
	int meno;
	printf("Enter empno to edit-");
	scanf("%d",&meno);
	for(ptr=start;(ptr) && ptr->eno!=meno;ptr=ptr->next);
	if(ptr==NULL)
	{
		printf("\n%d Empno.  not found",meno);
		return(1);
	}
	printf("Old name is %s and salary %lf\n",ptr->name,ptr->salary);
	printf("\nEnter new name and salary-");
	scanf("%s",ptr->name);
	scanf("%lf",&ptr->salary);
}

int del()
{
	if(!start)
	{
		printf("\nEmpty List\n");
		return(1);
	}
	int meno;
	printf("Enter empno to delete-");
	scanf("%d",&meno);
	if(meno==start->eno)
	{
		ptr=start;
		start=start->next;
		free(ptr);
	}
	else
	{
		for(ptr=start;(ptr) && ptr->eno!=meno;prev=ptr,ptr=ptr->next);
		if(ptr==NULL)
		{
			printf("\n%d Empno.  not found",meno);
			return(1);
		}
		prev->next=ptr->next;
		free(ptr);
	}
}
void rview(emp *p)
{
	if(p!=NULL)
	{
		rview(p->next);
		printf("\n%5d   %30s   %7.2lf\n",p->eno,p->name,p->salary);
	}
}

int list_to_file()
{
	if(start==NULL)
	{
		return(1);
	}
	FILE *fp;
	fp=fopen("employee","wb");
	for(ptr=start;(ptr);ptr=ptr->next)
	{
		fwrite(ptr,sizeof(emp),1,fp);
	}
	fclose(fp);
}

int file_to_list()
{
	emp *last;
	FILE *fp;
	if((fp=fopen("employee","rb"))==NULL)
	{
		return(1);
	}
	new=(emp *)malloc(sizeof(emp));
	fread(new,sizeof(emp),1,fp);
	while(!feof(fp))
	{
		if(start==NULL)
		{	
			start=last=new;
			new->next=NULL;
		}
		else
		{	
			last->next=new;
			last=new;
			new->next=NULL;
		}	
		new=(emp *)malloc(sizeof(emp));
		fread(new,sizeof(emp),1,fp);
	}
}

			
