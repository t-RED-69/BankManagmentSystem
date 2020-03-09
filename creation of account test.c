#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
// all the library included goes here
struct data{
    char data[25];
}test[100];
// this stores all the user_names.
char username[25],password[16],file_name[30];
int n=0; // (this counts the no of accounts)
//Globally declared user_name and password
char * create_account(){
    char name[15],dob[8];
    char cpass[16];
    int a,b,c,i;
    // variable declaration of the function
    new_a : // if account already exists
    printf("NAME : ");
    scanf("%s",name);
    strcpy(username,name);
    printf("\nDOB(dd/mm/yyyy) : ");
    scanf("%d/%d/%d",&a,&b,&c);
    int x=a*1000000+b*10000+c;
    itoa(x,dob,10); // conversion of integer into a string
    strcat(username,dob);
    for (i=0;i<n;i++){    // logic account already exists
        if (strcmp(test[i].data,username)==0){
            printf("\nACCOUNT ALREADY EXISTS.TRY AGAIN\n");
            goto new_a;
        }
    }
    strcpy(file_name,username);
    strcat(file_name,".txt");
    printf("\nCUSTOMER`S USERNAME : %s ",username);
    again :
    printf("\n\nCreate a Password(min_L: 8 | max_L : 16) : ");
    fflush(stdin);
    gets(password);
    if (strlen(password)<8 || strlen(password)>16){
        printf("\nINVALID LENGTH, ENTER AGAIN\n");
        goto again;
    }
    printf("\nConfirm Password : ");
    gets(cpass);
    printf("\n");
    if (strcmp(password,cpass)==0){
        system("cls");
        printf("\t\t\t\t\t\t\tACCOUNT CREATED SUCCESSFULLY with user_name : %s\n\n\n",username);
        FILE *fp,*fp1;
        fp=fopen(file_name,"w");
        fprintf(fp,"%s",password);
        fclose(fp);
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        fp1=fopen("log.txt","a");;
        fprintf(fp1,"CREATED ACCOUNT   %s   %d/%d/%d   %d:%d:%d\n",username,t->tm_mday,t->tm_mon+1,t->tm_year+1900,t->tm_hour,t->tm_min,t->tm_sec);
        fclose(fp1);
        return username;
    }
    else {
        printf("Password do not match ,please enter again\n");
        goto again;
    }
}
void delete_account(){
    char temp[16];
    printf("ENTER USERNAME : ");
    scanf("%s",username);
    for (int i=0;i<n;i++){
        if (strcmp(test[i].data,username)==0){
            enter :
            printf("ACCOUNT FOUND SUCCESFULLY\n");
            printf("\nENTER THE PASSWORD TO DELETE THIS ACCOUNT : ");
            scanf("%s",password);
            strcpy(file_name,username);
            strcat(file_name,".txt");
            FILE *fp;
            fp=fopen(file_name,"r");
            fscanf(fp,"%s",temp);
            fclose(fp);
            if (strcmp(temp,password)==0){
                int x=remove(file_name);
                if (x==0){
                    system("cls");
                    printf("\nACCOUNT WITH USERNAME %s DELETED SUCCESSFULLY\n",username);
                    FILE *fp1;
                    time_t now = time(NULL);
                    struct tm *t = localtime(&now);
                    fp1=fopen("log.txt","a");;
                    fprintf(fp1,"DELETED ACCOUNT   %s   %d/%d/%d   %d:%d:%d\n",username,t->tm_mday,t->tm_mon+1,t->tm_year+1900,t->tm_hour,t->tm_min,t->tm_sec);
                    fclose(fp1);

                }
                else{
                    printf("COULDN`T DELETE ACCOUNT OR ACCOUNT ALREADY DELETED\n");
                }

            }
            else {
                printf("\nWRONG PASSWORD\n");
                goto enter;
            }
        }
    }
}
int main (){
    FILE * FP;
    FP=fopen("usernames.txt","r");
    if (FP==NULL){
        n=0;
    }
    else {
        while (!feof(FP)){
            fscanf(FP,"%s",test[n++].data);
        }
    }
    fclose(FP);
    while(1){
        int ch; // variables declaration
        printf("1.CREATE AN ACCOUNT\n2.DELETE ACCOUNT\n3.EXIT PROGRAM");
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch (ch){
            case 1 : {
                  FILE *fp;
                  strcpy(test[n++].data,create_account()); // this is what refinement looks like
                  fp=fopen("usernames.txt","a+");
                  fprintf(fp,"%s\n",username);
                  fclose(fp);
                  break;
            }
            case 2 : {
                    delete_account();
                    char data[25];
                    FILE *fp,*fp1;
                    fp=fopen("usernames.txt","r");
                    fp1=fopen("temp.txt","w");
                    while(!feof(fp)){
                        fscanf(fp,"%s",data);
                        if (strcmp(data,username)!=0){
                            fprintf(fp1,"%s\n",data);
                        }
                    }
                    fclose(fp);
                    fclose(fp1);
                    remove("usernames.txt");
                    rename("temp.txt","usernames.txt");
                  break;
            }
            case 3 :{
                  exit(1);
                  break;
            }
            default :{
                printf("\nINVALID CHOICE\n");
                break;
            }
        }
    }
return 0;
}

