#include <stdio.h>
#include <ctype.h>
#define size 50

char stack[size];
int top=-1;

int push(char ch) {
    stack[++top]=ch;
    return 0;
}

char pop() {
    return (stack[top--]);
}

int pre(char symbol) {
    if(symbol=='^') {
        return 3;
    }
    else if(symbol=='*' || symbol=='/' || symbol=='%') {
        return 2;
    }
    else if(symbol=='+' || symbol=='-') {
        return 1;
    }
    else {
        return 0;
    }
}


int main() {
    char infix[50], postfix[50], ch;
    int i,k;
    printf("Enter the infix expression : ");
    scanf("%s",infix);
    i=0;
    k=0;
    push('#');
    while((ch=infix[i])!='\0') {
        if(ch=='(') {
            push(ch);
        }
        else if(isalnum(ch)) {
            postfix[k++]=ch;
        }
        else if(ch==')') {
            while(stack[top]!='(') {
                postfix[k++]=pop();
            }
            pop();
        }
        else {
            while(pre(stack[top])>=pre(ch)) {
                postfix[k++]=pop();
            }
            push(ch);
        }
        i++;
    }

    while(stack[top]!='#') {
        postfix[k++]=pop();
    }
    postfix[k]='\0';
    printf("The postfix expression is = %s",postfix);
    return 0;
}