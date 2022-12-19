//to add two algebraic polynomials using linked lists
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node* next;
    float coeff;
    int exp;
}node;//end of structure definition
node* insert_term(node* head,float co,int ex){
    node* temp;
    node* term=(node*)malloc(sizeof(node));
    term->coeff=co;
    term->exp=ex;
    term->next=NULL;
    if(head==NULL||term->exp>head->exp){
        term->next=head;
        head=term;
    }//end of if block
    else
    {
        temp=head;
        while(temp->next!=NULL&&temp->next->exp>=ex)
        temp=temp->next;
        term->next=temp->next;
        temp->next=term;
    }//end of else block
    return(head);
}//end of fn.
node* create_polynomial(node*head){
    int n,i,ex;
    float co;
    printf("\nEnter the number of terms in the polynomial: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the coefficient and the exponential for term %d separated by spaces: ",i+1);
        scanf("%f %d",&co,&ex);
        head=insert_term(head,co,ex);
    }//end of for loop
    return(head);
}//end of fn.
void display_polynomial(node* head){
    node* temp=head;
    if(head==NULL)
    printf("No polynomial i.e. 0");
    else{
        while(temp!=NULL){
            printf(" %0.1fx^%d ",temp->coeff,temp->exp);
            temp=temp->next;
            (temp==NULL)?(printf("\n")):(printf("+"));
        }//end of while loop
    }//end of else block
}//end of fn.
node* add_polynomials(node* head1,node* head2,node* head_result){
    node* ptr1=head1;
    node* ptr2=head2;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->exp==ptr2->exp){
            head_result=insert_term(head_result,ptr1->coeff+ptr2->coeff,ptr1->exp);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }//end of if block
        else if(ptr1->exp<ptr2->exp){
            head_result=insert_term(head_result,ptr2->coeff,ptr2->exp);
            ptr2=ptr2->next;
        }//end of else-if block
        else if(ptr1->exp>ptr2->exp){
            head_result=insert_term(head_result,ptr1->coeff,ptr1->exp);
            ptr1=ptr1->next;
        }//end of else-if block
    }//end of while loop
    while(ptr1!=NULL){
        head_result=insert_term(head_result,ptr1->coeff,ptr1->exp);
        ptr1=ptr1->next;
    }//end of while loop
    while(ptr2!=NULL){
        head_result=insert_term(head_result,ptr2->coeff,ptr2->exp);
        ptr2=ptr2->next;
    }//end of while loop
    return(head_result);
}//end of fn.
void main(){
    node* head1,*head2,*head_result;
    head1=head2=head_result=NULL;
    printf("For Polynomial 1:");
    head1=create_polynomial(head1);
    printf("For Polynomial 2:");
    head2=create_polynomial(head2);
    head_result=add_polynomials(head1,head2,head_result);
    printf("The result of Addition is as follows:");
    printf("\nThe Resultant Polynomial:");
    display_polynomial(head_result);
}//end of main