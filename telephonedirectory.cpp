#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct node{
	struct node *pre,*next; 
		char number[50];
        char gmail[40];
        char name[30];
        char address[30];
        
};  
struct node *head,*temp,*ptr;
struct node *ptr1, *ptr2, *dup; 
  
void insert();
void sort();
void deletecontact(char n[20]);
void searchbyname(char p[20]);
void searchbynumber(char no[30]);
void searchbygmail(char g[20]);
void searchbyaddress(char a[20]);
 void accept();
void display();
void update(char ch[10]);
void insert(){
	accept();
}
void accept(){
	
	 char num[50];
        char mail[40];
        char nam[30];
        char addre[30];
   int ans;
      
    printf("ENTER NAME      :");
    scanf("%s",nam);
   
	
    printf("ENTER NUMBER    :");
    scanf("%s",num);
  
	
    while(strlen(num)!=10)
    {
    printf("ENTER VALID NUMBER  :");
     scanf("%s",num);
     
	
    }
    printf("ENTER G-MAIL    :");
    scanf("%s",mail);
    printf("ENTER Address    :");
    scanf("%s",addre);
    
	
     ptr = (struct node *)malloc(sizeof(struct node)); 
	    
    if(head==NULL)
    {
    	ptr->next = NULL;  
        ptr->pre = NULL;  
        strcpy(ptr->name,nam);
    strcpy(ptr->number,num);
    strcpy(ptr->gmail,mail); 
    strcpy(ptr->address,addre); 
        head=ptr;
    }
    else
    {
    	strcpy(ptr->name,nam);
    strcpy(ptr->number,num);
    strcpy(ptr->gmail,mail); 
    strcpy(ptr->address,mail); 
    strcpy(ptr->address,addre);
       ptr->pre=NULL;  
       ptr->next = head;  
       head->pre=ptr;  
       head=ptr;  

    }
 printf("DO YOU WANT TO CONTINUE?????????");
 scanf("%d",&ans);
if(ans==1){
	accept();
}

}

void sort(){
	 struct node *i,*j;
        int temp;
        char n[10];
        for(i=head;i->next!=NULL;i=i->next)
        {
            for(j=i->next;j!=NULL;j=j->next)
            {
                temp=strcmp(i->name,j->name);
                if(temp>0)
                {
                   strcpy(n,i->name);
                   strcpy(i->name,j->name);
                   strcpy(j->name,n);
                }
            }
        }
}
void display(){
	ptr=head;//start the node
	printf("\n\n\n\t\t\t\tCONTACT INFORMATION\n\n");
	while(ptr!=NULL)//traverse till last
	{
			printf("\n\nNAME  ::\t %s",ptr->name);
			printf("\nNUMBER::\t %s",ptr->number);
			printf("\nG-MAIL::\t %s",ptr->gmail);
			printf("\nAddress::\t %s",ptr->address);
			ptr=ptr->next;
	}
}
void update(char n[20]){
	int ans;
        int c;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(n,ptr->name)==0)
            {
                
                do
                {
                    printf("\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n4.address\n");
                scanf("%d",&c);
                switch(c)
                {
                    case 1:
                    printf("ENTER NEW-NAME=");
                    scanf("%s",ptr->name);
                    break;
                    case 2:
                    printf("ENTER NEW PHONE-NUMBER?");
                    scanf("%s",ptr->number);
    
                    break;
                    case 3:
                    printf("ENTER NEW G-MAIL");
                    scanf("%s",ptr->gmail);
                    break;
                    case 4:
                    printf("ENTER NEW Address");
                    scanf("%s",ptr->address);
                    break;
                }
                printf("\n\n\nDO YOU WANT TO CONTINUE UPDATING?");
                scanf("%d",&ans);
                }while(ans==1);
            }
            ptr=ptr->next;
        }
    }

void deletecontact(char s[20])
    {
        int c=0;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(s,ptr->name)==0)
            {
                c=1;
                break;
            }
            else
            {
                c=2;
            }
            ptr=ptr->next;
        }
        if(c==1 && ptr!=head && ptr->next!=NULL)
        {
            ptr->pre->next=ptr->next;
           ptr->next->pre=ptr->pre;
           free(ptr);
           printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");
        }
        if(ptr==head)
        {
            head=head->next;
            head->pre=NULL;
            delete(ptr);
           printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");
        }
        if(ptr->next==NULL)
        {
            ptr->pre->next=NULL;
            ptr->pre=NULL;
            free(ptr);
           printf("YOUR CONTACT IS SUCCESSFULLY DELETED\n\n");
        }
        if(c==2)
        {
            printf("YOUR ENTERED NAME IS NOT IN THE LIST...");
        }
    }
 void searchbyname(char na[10])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->name)==0)
            {
                printf("NAME FOUND\n");
                printf("CONTACT DETAILS ARE BELOW:\n");
        	printf("\n\nNAME  ::\t %s",ptr->name);
			printf("\nNUMBER::\t%s",ptr->number);
			printf("\nG-MAIL::\t %s",ptr->gmail);
			printf("\nAddress::\t %s",ptr->address);
		        
            }
            ptr=ptr->next;
        }
    }
void searchbynumber(char na[10])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->number)==0)
            {
                printf("Number FOUND\n");
                printf("CONTACT DETAILS ARE BELOW:\n");
        	printf("\n\nNAME  ::\t %s",ptr->name);
			printf("\nNUMBER::\t%s",ptr->number);
			printf("\nG-MAIL::\t %s",ptr->gmail);
		   	printf("\nAddress::\t %s",ptr->address);
            }
            ptr=ptr->next;
        }
    }
    void searchbygmail(char na[10])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->gmail)==0)
            {
                printf("Gmail FOUND\n");
                printf("CONTACT DETAILS ARE BELOW:\n");
        	printf("\n\nNAME  ::\t %s",ptr->name);
			printf("\nNUMBER::\t%s",ptr->number);
			printf("\nG-MAIL::\t %s",ptr->gmail);
		    printf("\nAddress::\t %s",ptr->address);
            }
            ptr=ptr->next;
        }
    }
    void searchbyaddress(char na[10])
    {
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(na,ptr->address)==0)
            {
                printf("Address FOUND\n");
                printf("CONTACT DETAILS ARE BELOW:\n");
        	printf("\n\nNAME  ::\t %s",ptr->name);
			printf("\nNUMBER::\t%s",ptr->number);
			printf("\nG-MAIL::\t %s",ptr->gmail);
		    printf("\nAddress::\t %s",ptr->address); 
            }
            ptr=ptr->next;
        }
    }
int main()
{
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char gmail[20];
    char address[30];
    int ans;
    int ch,a;
    printf("\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME ""   !!!!!!!!!!!!!!!!!!!!!");
    printf("\n\n\nLET'S CREATE OUR PHONEBOOK \n\n");
	accept();
    sort();
     do{
    printf("\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) SEARCH\n");
    scanf("%d",&ch);
   
	switch(ch)
    {
    case 2:
    insert();
    sort();
    break;
     case 1:
	display();
    break;
    case 3:
    
        printf("\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n");
        scanf("%s",name);
    update(name);
    sort();
    break;
    case 4:
    printf("\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n");
    scanf("%s",name);
    deletecontact(name);
    break;
    case 5:
    do
    {
    printf("1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL\n4.SEARCH BY ADDRESS");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        printf("ENTER THE NAME TO BE SEARCHED\n");
        scanf("%s",name);
        searchbyname(name);
        break;
        case 2:
        printf("ENTER THE number TO BE SEARCHED\n");
        scanf("%s",number);
        searchbynumber(number);
        break;
        case 3:
        printf("ENTER THE gmail TO BE SEARCHED\n");
        scanf("%s",gmail);
        searchbygmail(gmail);
        break;

        case 4:
        printf("ENTER THE address TO BE SEARCHED\n");
        scanf("%s",address);
        searchbyaddress(address);
        break;
        default:
		printf("\nNO PROPER INPUT GIVEN.....\n");
    }
    printf("DO YOU WANT TO CONTINUE SEARCHING?????????");
  scanf("%d",&ans);
}while(ans==1);

    break;
    
    default:
	printf("\nNO PROPER INPUT GIVEN..\n");
    }
    printf("\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????");
    scanf("%d",&ans);
}while(ans==1);
}
