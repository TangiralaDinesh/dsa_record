# DSA Programs in C (with Outputs)

---

## 1. Linear Search

```c
#include<stdio.h>
int main(){
    int a[5]={2,4,1,8,6},i,f=8,found=0;
    for(i=0;i<5;i++){
        if(a[i]==f){
            found=1;
            break;
        }
    }
    if(found)
        printf("Found at %d",i);
    else
        printf("Not found");
    return 0;
}
```
**Output:**
```
Found at 3
```

---

## 2. Binary Search

```c
#include<stdio.h>
int main(){
    int a[6]={1,2,4,6,8,10},l=0,h=5,m,f=6,found=0;
    while(l<=h){
        m=(l+h)/2;
        if(a[m]==f){
            found=1;
            break;
        }
        else if(a[m]<f)
            l=m+1;
        else
            h=m-1;
    }
    if(found)
        printf("Found at %d",m);
    else
        printf("Not found");
    return 0;
}
```
**Output:**
```
Found at 3
```

---

## 3. Stack Operations

```c
#include<stdio.h>
#define S 5
int main(){
    int s[S],top=-1,c,x;
    while(1){
        printf("1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d",&c);
        if(c==1){
            if(top==S-1) printf("Overflow\n");
            else{
                scanf("%d",&x);
                s[++top]=x;
            }
        }else if(c==2){
            if(top==-1) printf("Underflow\n");
            else printf("Pop %d\n",s[top--]);
        }else if(c==3){
            for(int i=0;i<=top;i++) printf("%d ",s[i]);
            printf("\n");
        }else break;
    }
    return 0;
}
```
**Sample Output:**
```
1.Push 2.Pop 3.Display 4.Exit: 1
5
1.Push 2.Pop 3.Display 4.Exit: 1
8
1.Push 2.Pop 3.Display 4.Exit: 3
5 8 
1.Push 2.Pop 3.Display 4.Exit: 2
Pop 8
1.Push 2.Pop 3.Display 4.Exit: 3
5 
1.Push 2.Pop 3.Display 4.Exit: 4
```

---

## 4. Queue Operations

```c
#include<stdio.h>
#define S 5
int main(){
    int q[S],f=0,r=-1,c,x,k=0;
    while(1){
        printf("1.Enq 2.Deq 3.Display 4.Exit: ");
        scanf("%d",&c);
        if(c==1){
            if(r==S-1) printf("Full\n");
            else{
                scanf("%d",&x);
                q[++r]=x;
                k++;
            }
        }else if(c==2){
            if(k==0) printf("Empty\n");
            else{
                printf("Deq %d\n",q[f++]);
                k--;
            }
        }else if(c==3){
            for(int i=f;i<=r;i++) printf("%d ",q[i]);
            printf("\n");
        }else break;
    }
    return 0;
}
```
**Sample Output:**
```
1.Enq 2.Deq 3.Display 4.Exit: 1
10
1.Enq 2.Deq 3.Display 4.Exit: 1
20
1.Enq 2.Deq 3.Display 4.Exit: 3
10 20 
1.Enq 2.Deq 3.Display 4.Exit: 2
Deq 10
1.Enq 2.Deq 3.Display 4.Exit: 3
20 
1.Enq 2.Deq 3.Display 4.Exit: 4
```

---

## 5. String Reversal (Using Stack)

```c
#include<stdio.h>
#include<string.h>
int main(){
    char s[50],r[50];
    int top=-1,i;
    gets(s);
    int n=strlen(s);
    for(i=0;i<n;i++) r[++top]=s[i];
    for(i=0;i<n;i++) s[i]=r[top--];
    puts(s);
    return 0;
}
```
**Input:**  
`hello`  
**Output:**  
`olleh`

---

## 6. Infix to Postfix Conversion

```c
#include<stdio.h>
#include<string.h>
#define S 20
int p(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}
int main(){
    char inf[S],post[S],s[S];
    int i,j=0,top=-1;
    gets(inf);
    for(i=0;inf[i];i++){
        if((inf[i]>='a'&&inf[i]<='z')||(inf[i]>='A'&&inf[i]<='Z')||(inf[i]>='0'&&inf[i]<='9'))
            post[j++]=inf[i];
        else if(inf[i]=='(')
            s[++top]=inf[i];
        else if(inf[i]==')'){
            while(top>-1 && s[top]!='(') post[j++]=s[top--];
            if(top>-1) top--;
        }
        else{
            while(top>-1 && p(s[top])>=p(inf[i])) post[j++]=s[top--];
            s[++top]=inf[i];
        }
    }
    while(top>-1) post[j++]=s[top--];
    post[j]='\0';
    puts(post);
    return 0;
}
```
**Input:**  
`a+b*c`  
**Output:**  
`abc*+`

---

## 7. Single Linked List (All Ops in One Program)

```c
#include<stdio.h>
#include<stdlib.h>
struct n{int d;struct n* next;};
int main(){
    struct n *h=0,*t,*p; int c,x;
    while(1){
        printf("1.Add 2.Del head 3.Display 4.Exit: ");
        scanf("%d",&c);
        if(c==1){
            p=malloc(sizeof(struct n));
            scanf("%d",&x); p->d=x; p->next=0;
            if(!h) h=t=p;
            else{t->next=p;t=p;}
        }else if(c==2){
            if(!h) printf("Empty\n");
            else{p=h; h=h->next; free(p);}
        }else if(c==3){
            p=h;
            while(p){printf("%d ",p->d);p=p->next;}
            printf("\n");
        }else break;
    }
    return 0;
}
```
**Sample Output:**
```
1.Add 2.Del head 3.Display 4.Exit: 1
11
1.Add 2.Del head 3.Display 4.Exit: 1
22
1.Add 2.Del head 3.Display 4.Exit: 3
11 22 
1.Add 2.Del head 3.Display 4.Exit: 2
1.Add 2.Del head 3.Display 4.Exit: 3
22 
1.Add 2.Del head 3.Display 4.Exit: 4
```

---

## 8. Doubly Linked List (All Ops in One Program)

```c
#include<stdio.h>
#include<stdlib.h>
struct n{int d;struct n* p,*n;};
int main(){
    struct n *h=0,*t,*x; int c,y;
    while(1){
        printf("1.Add 2.Del head 3.Display 4.Exit: ");
        scanf("%d",&c);
        if(c==1){
            x=malloc(sizeof(struct n));
            scanf("%d",&y); x->d=y; x->n=0; x->p=t;
            if(!h) h=t=x;
            else{t->n=x; t=x;}
        }else if(c==2){
            if(!h) printf("Empty\n");
            else{x=h; h=h->n; if(h) h->p=0; free(x);}
        }else if(c==3){
            x=h;
            while(x){printf("%d ",x->d);x=x->n;}
            printf("\n");
        }else break;
    }
    return 0;
}
```
**Sample Output:**
```
1.Add 2.Del head 3.Display 4.Exit: 1
9
1.Add 2.Del head 3.Display 4.Exit: 1
8
1.Add 2.Del head 3.Display 4.Exit: 3
9 8 
1.Add 2.Del head 3.Display 4.Exit: 2
1.Add 2.Del head 3.Display 4.Exit: 3
8 
1.Add 2.Del head 3.Display 4.Exit: 4
```

---

## 9. Stack using Linked List

```c
#include<stdio.h>
#include<stdlib.h>
struct n{int d;struct n* n;};
int main(){
    struct n *t=0,*p; int c,x;
    while(1){
        printf("1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d",&c);
        if(c==1){
            p=malloc(sizeof(struct n));
            scanf("%d",&x); p->d=x; p->n=t; t=p;
        }else if(c==2){
            if(!t) printf("Empty\n");
            else{p=t; printf("Pop %d\n",t->d); t=t->n; free(p);}
        }else if(c==3){
            p=t;
            while(p){printf("%d ",p->d);p=p->n;}
            printf("\n");
        }else break;
    }
    return 0;
}
```
**Sample Output:**
```
1.Push 2.Pop 3.Display 4.Exit: 1
15
1.Push 2.Pop 3.Display 4.Exit: 1
7
1.Push 2.Pop 3.Display 4.Exit: 3
7 15 
1.Push 2.Pop 3.Display 4.Exit: 2
Pop 7
1.Push 2.Pop 3.Display 4.Exit: 3
15 
1.Push 2.Pop 3.Display 4.Exit: 4
```

---

## 10. Queue using Linked List

```c
#include<stdio.h>
#include<stdlib.h>
struct n{int d;struct n* n;};
int main(){
    struct n *f=0,*r=0,*p; int c,x;
    while(1){
        printf("1.Enq 2.Deq 3.Display 4.Exit: ");
        scanf("%d",&c);
        if(c==1){
            p=malloc(sizeof(struct n));
            scanf("%d",&x); p->d=x; p->n=0;
            if(!f) f=r=p;
            else{r->n=p;r=p;}
        }else if(c==2){
            if(!f) printf("Empty\n");
            else{p=f; printf("Deq %d\n",p->d); f=f->n; free(p);}
        }else if(c==3){
            p=f; while(p){printf("%d ",p->d); p=p->n;}
            printf("\n");
        }else break;
    }
    return 0;
}
```
**Sample Output:**
```
1.Enq 2.Deq 3.Display 4.Exit: 1
12
1.Enq 2.Deq 3.Display 4.Exit: 1
20
1.Enq 2.Deq 3.Display 4.Exit: 3
12 20 
1.Enq 2.Deq 3.Display 4.Exit: 2
Deq 12
1.Enq 2.Deq 3.Display 4.Exit: 3
20 
1.Enq 2.Deq 3.Display 4.Exit: 4
```

---