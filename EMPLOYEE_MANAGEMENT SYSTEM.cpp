#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int main(){
	FILE *fp,*ft;
	char another,choice;
	struct emp{
		char name[100];
		int age;
		char salary[100];
		char phone[100];
		char dept[100];
	};
	struct emp e;
	char empname[100];
	long int recsize;
	fp=fopen("employee","ab+");
	recsize=sizeof(e);
	printf("\n****************EMPLOYEE MANAGEMENT SYSTEM****************\n");
	printf("1.Enter 1 to add details of a new employee.\n");
	printf("2.Enter 2 to modify the details of an existing employee.\n");
	printf("3.Enter 3 to delete an existing employee details.\n");
	printf("4.Enter 4 to display the entire list of employees.\n");
	printf("5.Enter 5 to exit.\n");
	fflush(stdin);
	choice=getche();
	switch(choice){
		case '1':
				 another='Y';
				 while(another=='Y'){
				 	printf("\nEnter name of the employee:");
				 	scanf("%s",e.name);
				 	printf("\nEnter age of employee:");
				 	scanf("%d",&e.age);
				 	printf("\nEnter salary of employee in Rupees:");
				 	scanf("%s",e.salary);
				 	printf("\nEnter phone number of employee:");
				 	scanf("%s",e.phone);
				 	printf("\nEnter Department in which the employee works:");
				 	scanf("%s",e.dept);
				 	printf("\nData has been stored successfully.");
				 	fwrite(&e,recsize,1,fp);
				 	fflush(stdin);
				 	another='n';
				 	fclose(fp);
				 }
				 break;
		case '4':rewind(fp);
				 while(fread(&e,recsize,1,fp)==1){
				 	printf("\nName:%s\nAge:%d\nSalary:%s\nPhone:%s\nDepartment:%s",e.name,e.age,e.salary,e.phone,e.dept);
				 	printf("\n*************************************************************************");
				 }
				 fclose(fp);
				 break;
		case '3':
				 printf("Enter name of employee to delete.");
				 scanf("%s",empname);
				 ft=fopen("temp","wb+");
				 fflush(stdin);
				 while(fread(&e,recsize,1,fp)==1){
				 	if(strcmp(e.name,empname)!=0){
				 		fwrite(&e,recsize,1,ft);
					 }
				 }
				 fclose(fp);
				 fclose(ft);
				 
				 remove("employee");
				 rename("temp","employee");
				 remove("temp");
				 
				 break;
		case '2':rewind(fp);
				 printf("Enter name of the employee whose details need to be modified:");
				 scanf("%s",&empname);
				 while(fread(&e,recsize,1,fp)==1){
				 	if(strcmp(e.name,empname)==0){
				 		printf("Enter new name:");
				 		scanf("%s",e.name);
				 		printf("Enter new age:");
				 		scanf("%d",&e.age);
				 		printf("Enter new salary:");
				 		scanf("%s",e.salary);
				 		printf("Enter new phone number:");
				 		scanf("%s",e.phone);
				 		printf("Enter new department:");
				 		scanf("%s",e.dept);
				 		fseek(fp,-recsize,SEEK_CUR);
				 		fwrite(&e,recsize,1,fp);
				 		break;
					}
				 }
				 fclose(fp);
				 break;
		case '5':exit(1);
		default:printf("\nPlease enter a number between 1 and 5.");
				printf("\nEnter any key to continue.");	
				getch();
				main();	 		 		 		 
	}
	
    main();
}


