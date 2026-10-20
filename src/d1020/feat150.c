int evalRPN(char** tokens, int tokensSize) {
    int *temp=malloc(tokensSize*sizeof(int));
    int top=0;
    for(int i=0;i<tokensSize;i++){
        if(tokens[i][1]=='\0'&&
            (tokens[i][0] == '+' || tokens[i][0] == '-' ||
            tokens[i][0] == '*' || tokens[i][0] == '/')){

            switch(tokens[i][0]){
                int tmp;
                case'+':
                    tmp=temp[top-1]+temp[top-2];
                    top-=2;
                    temp[top]=tmp;
                    top++;
                    break;
                case'-':
                    tmp=temp[top-2]-temp[top-1];
                    top-=2;
                    temp[top]=tmp;
                    top++;
                    break;
                case'*':
                    tmp=temp[top-1]*temp[top-2];
                    top-=2;
                    temp[top]=tmp;
                    top++;
                    break;
                case'/':
                     tmp=temp[top-2]/temp[top-1];
                    top-=2;
                    temp[top]=tmp;
                    top++;
                    break;
            }
        }else{
            temp[top]=atoi(tokens[i]);
            top++;
        }
    }
    int result = temp[top - 1];
    free(temp);
    return result;
}