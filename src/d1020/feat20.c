#include <stdbool.h>  
#include <string.h>   
#include <stdlib.h>   
bool isValid(char* s) {
    int len=strlen(s);
    char *temp=malloc(len*sizeof(char));
    int top=0;
    for(int i=0;i<len;i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            temp[top]=s[i];
            top++;  
        }else{
            if(top==0){
                free(temp);
                return false;
            }else{
                if(temp[top-1]=='(' && s[i]==')'){
                    top--;
                }else if(temp[top-1]=='[' && s[i]==']'){
                    top--;
                }else if(temp[top-1]=='{' && s[i]=='}'){
                    top--;
                }else{
                    free(temp);
                    return false;
                }
                    
            }
        }
    }
    free(temp);
    return top==0;
}