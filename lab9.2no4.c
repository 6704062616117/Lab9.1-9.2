#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checkLogin(char *login, char *passwd);
int checkValidPass(char *ps);

int main() {

    char login[64], password[64];

    printf("Enter login : ");
    gets(login);

    printf("Enter password : ");
    gets(password);

    if(checkLogin(login, password) == 1){
        printf("Welcome\n");
    }
    else{
        printf("Incorrect login or password\n");
    }

    if(checkValidPass(password)){
        printf("Accepted\n");
    }
    else{
        printf("Reject\n");
    }

    return 0;
}

int checkValidPass(char *ps){

    int len = strlen(ps);
    int digit = 0;
    int upper = 0;
    int i,j;

    for(i=0;i<len;i++){
        if(isdigit(ps[i]))
            digit++;

        if(isupper(ps[i]))
            upper++;
    }

    //4.1 Length = 5 and a number 1 or more digits
    if(len == 5 && digit >= 1)
        return 1;

    //4.2 Length 5-8 first char not number and 2 uppercase and 2 digits
    if(len>=5 && len<=8 && !isdigit(ps[0]) && upper>=2 && digit>=2)
        return 1;

    //4.3 Length 5-8 and 2 uppercase not repeat and 2 digits
    if(len>=5 && len<=8 && upper>=2 && digit>=2){

        for(i=0;i<len;i++){
            for(j=i+1;j<len;j++){
                if(isupper(ps[i]) && ps[i]==ps[j])
                    return 0;
            }
        }

        return 1;
    }

    return 0;
}

int checkLogin(char *login, char *passwd){

    if(!strcmp(login,"student1") && !strcmp(passwd,"mypass"))
        return 1;
    else
        return 0;
}
