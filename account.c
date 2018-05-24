#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int login=0;
typedef struct useraccount{
  char *pusername;
  char *ppassword;
  char *pmail;
  int phone;
  int usermoney;
  int (*ppfun)(int);
}User;

int sign(void){
    int count;
    label:
    printf("1. sign in \n");
    printf("2. sign up \n");
    printf("=====>>> ");
    scanf("%d",&count);
    if (count>2||count<1){
        goto label;
    }else{
        return count;
    }
}

int main(int argc,char *argv[]){
    srand(time(NULL));
    int money=0,save=0;
	int count=0;
    int forget=0;
    int threetime=3;
    int ok=0;
    int yes=0;
    int input=0,again=0,code=0;
    char cc;
    int (*pfunc)(void);
    User *puser=(User *)malloc(sizeof(User));
    User *pcheck=(User *)malloc(sizeof(User));
    pfunc=sign;
    puser->pmail=(char *)malloc(sizeof(char)*80);
    puser->ppassword=(char *)malloc(sizeof(char)*80);
    puser->pusername=(char *)malloc(sizeof(char)*80);
    pcheck->pmail=(char *)malloc(sizeof(char)*80);
    pcheck->ppassword=(char *)malloc(sizeof(char)*80);
    pcheck->pusername=(char *)malloc(sizeof(char)*80);
    count=pfunc();
    if (count==1){
        printf("enter your username: ");
        scanf("%s",puser->pusername);
        printf("enter your password: ");
        scanf("%s",puser->ppassword);
        if (login==0){
            printf("unregistered\n");
            printf("you need to sign up (1 to sign up) (0 to overthe program): ");
            scanf("%d",&yes);
            if (yes){
                system("CLS");
                printf("enter your username: ");
                scanf("%s",puser->pusername);
                printf("enter your password: ");
                scanf("%s",puser->ppassword);
                printf("enter your gmail: ");
                scanf("%s",puser->pmail);
                printf("enter your phone number: ");
                scanf("%d",&puser->phone);
                printf("thank you for your sign up\n");
                printf("Do you want to sign in (1 to sign in) (0 to over the program): ");
                scanf("%d",&ok);
                if (ok){
                    again1:
                    system("CLS");
                    printf("enter your username: ");
                    scanf("%s",pcheck->pusername);
                    printf("enter your password: ");
                    scanf("%s",pcheck->ppassword);
                    if (!strcmp(puser->pusername,pcheck->pusername)&&!strcmp(puser->ppassword,pcheck->ppassword)){
                        printf("welcome!\n");
                        printf("Do you want to save money or Pick up the money (0 to over the program 1 to save 2 to pick up): ");
                        scanf("%d",&money);
                        if (money==1){
                            again2:
                            system("CLS");
                            printf("enter you want to save amount: ");
                            scanf("%d",&save);
                            puser->usermoney+=save;
                            printf("now your account have %d dollers\n",puser->usermoney);
                            printf("(0 to over the program 1 to save 2 to pick up): ");
                            scanf("%d",&again);
                            if (again==1){
                                goto again2;
                            }else if (again==2){
                                again3:
                                printf("enter you want to pick up: ");
                                scanf("%d",&save);
                                if (puser->usermoney<save){
                                    printf("money not enough\n");
                                    printf("you need to save money\n");
                                    goto again2;
                                }else{
                                    puser->usermoney-=save;
                                    printf("you pick up %d dollars now you have %d dollers\n",save,puser->usermoney);
                                    printf("(0 to over the program 1 to save 2 to pick up): ");
                                    scanf("%d",&again);
                                }
                                if (again==1){
                                    goto again2;
                                }else if (again==2){
                                    goto again3;
                                }else{
                                    printf("thank you for your use\n");
                                }
                            }else{
                                printf("thank for your use\n");
                            }
                        }else if (money==2){
                            again4:
                            printf("enter you want to pick up: ");
                            scanf("%d",&save);
                            if (puser->usermoney<save){
                                printf("money not enough\n");
                                printf("you need to save money\n");
                                goto again2;
                            }else{
                                puser->usermoney-=save;
                                printf("you pick up %d dollars now you have %d dollers\n",save,puser->usermoney);
                                printf("(0 to over the program 1 to save 2 to pick up): ");
                                scanf("%d",&again);
                            }
                            if (again==1){
                                again5:
                                system("CLS");
                                printf("enter you want to save amount: ");
                                scanf("%d",&save);
                                puser->usermoney+=save;
                                printf("now your account have %d dollers\n",puser->usermoney);
                                printf("(0 to over the program 1 to save 2 to pick up): ");
                                scanf("%d",&again);
                                if (again==1){
                                    goto again5;
                                }else if (again==2){
                                    goto again4;
                                }
                            }else if (again==2){
                                goto again4;
                            }
                        }else{
                            printf("thank for your use\n");
                        }
                    }else{
                        printf("input error\n");
                        printf("Do you want to input again? (1 to sign in) (0 to over the program): ");
                        scanf("%d",&input);
                        if (input){
                            goto again1;
                        }else{
                            printf("thank you for your use\n");
                            login=3;
                        }
                    }
                }
            }
        }
    }else if (count==2){
        printf("enter your username: ");
        scanf("%s",puser->pusername);
        printf("enter your password: ");
        scanf("%s",puser->ppassword);
        printf("enter your gmail: ");
        scanf("%s",puser->pmail);
        printf("enter your phone number: ");
        scanf("%d",&puser->phone);
        printf("thank you for your sign up\n");
        printf("Do you want to sign in (1 to sign in) (0 to over the program): ");
        scanf("%d",&login);
        if (login){
            can1:
            system("CLS");
            printf("enter your username: ");
            scanf("%s",pcheck->pusername);
            printf("enter your password: ");
            scanf("%s",pcheck->ppassword);
            if (!strcmp(puser->pusername,pcheck->pusername)&&!strcmp(puser->ppassword,pcheck->ppassword)){
                input1:
                printf("welcome!\n");
                printf("Do you want to save money or Pick up the money (0 to over the program 1 to save 2 to pick up): ");
                scanf("%d",&money);
                if (money==1){
                    again6:
                    system("CLS");
                    printf("enter you want to save amount: ");
                    scanf("%d",&save);
                    puser->usermoney+=save;
                    printf("now your account have %d dollers\n",puser->usermoney);
                    printf("(0 to over the program 1 to save 2 to pick up): ");
                    scanf("%d",&again);
                    if (again==1){
                        goto again6;
                    }else if (again==2){
                        again7:
                        printf("enter you want to pick up: ");
                        scanf("%d",&save);
                        if (puser->usermoney<save){
                            printf("money not enough\n");
                            printf("you need to save money\n");
                            goto again6;
                        }else{
                            puser->usermoney-=save;
                            printf("you pick up %d dollars now you have %d dollers\n",save,puser->usermoney);
                            printf("(0 to over the program 1 to save 2 to pick up): ");
                            scanf("%d",&again);
                        }
                        if (again==1){
                            goto again6;
                        }else if (again==2){
                            goto again7;
                        }else{
                            printf("thank you for your use\n");
                        }
                    }else{
                        printf("thank you for your use\n");
                    }
                }
            }else{
                printf("your input is error\n");
                printf("Do you want to try again (1 to try 0 to over the game): ");
                scanf("%d",&yes);
                if (yes){
                    error1:
                    system("CLS");
                    printf("enter your username: ");
                    scanf("%s",pcheck->pusername);
                    printf("enter your password: ");
                    scanf("%s",pcheck->ppassword);
                    threetime--;
                    if (!strcmp(puser->pusername,pcheck->pusername)&&!strcmp(puser->ppassword,pcheck->ppassword)&&threetime>=0){
                        goto input1;
                    }else{
                        printf("your input is error\n");
                        printf("you have %d time to try again\n",threetime);
                        printf("Do you want to try again (1 to try 0 to over the game): ");
                        scanf("%d",&yes);
                        if (yes&&threetime>=0){
                            goto error1;
                        }else{
                            printf("thank you for your use\n");
                            login=3;
                        }
                    }
                }
            }
        }
    }else{
        printf("thank you for your use\n");
    }
    if (login==3){
        fflush(stdin);
        printf("Do you forget your username or password 'y'or'n': ");
        scanf("%c",&cc);
        if (cc=='Y'||cc=='y'){
            check1:
            printf("enter your gamil: ");
            scanf("%s",pcheck->pmail);
            printf("enter your phonenumber: ");
            scanf("%d",&pcheck->phone);
            if (!strcmp(puser->pmail,pcheck->pmail)&&(puser->phone==pcheck->phone)){
                printf("now we send a Verification code to you \n");
                code=rand()%10000;
                printf("your Verification code is %d\n",code);
                printf("enter your Verification code: ");
                scanf("%d",&input);
                if (input==code){
                    system("CLS");
                    printf("enter your user name: ");
                    scanf("%s",puser->pusername);
                    printf("enter you password: ");
                    scanf("%s",puser->ppassword);
                    printf("now you can sign in\n");
                    goto can1;
                }
            }else{
                goto check1;
            }
        }
    }
    return 0;
}
