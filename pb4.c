#include <stdio.h>
#include <math.h>
#include <ctype.h>
#define size 50

int top=0;
int stack[size];

void push(int elem) {
    if(top>50) {
        printf("Cannot insert more limit reached!!\n");
    }
    else {
        stack[top++]=elem;
    }
}

int pop() {
    if(top==-1) {
        printf("Invalid expression!!\n");
    }
    else {
        return (stack[--top]);
    }
}

int main() {
    char a[50];
    int i=0;
    double op1,op2,res;
    printf("Enter the valid suffix expreesion : ");
    scanf("%s",a);
    while(a[i]!='\0') {
        if(isdigit(a[i])) {
            push(a[i]-'0');
        }
        else{
            op2=(double)pop();
            op1=(double)pop();
            switch (a[i])
            {
            case '+':
                res=op1+op2;
                push(res);
                break;

            case '-':
                res=op1-op2;
                push(res);
                break;
            
            case '*':
                res=op1*op2;
                push(res);
                break;
            
            case '/':
                res=op1/op2;
                push(res);
                break;
            
            case '^':
                res=pow(op1,op2);
                push(res);
                break;

            case '%':
                res=((int)op1)%((int)op2);
                push(res);
                break;

            default:
                printf("Invalid Operator!!\n");
                break;
            }
        }
        i++;
    }
    printf("The evaluation of suffix is = %.2f",res);
    return 0;
}
