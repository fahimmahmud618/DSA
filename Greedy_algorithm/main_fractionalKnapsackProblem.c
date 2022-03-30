#include<stdio.h>
void swap1(double *p, double *q){
    double temp;

    temp=*p;
    *p=*q;
    *q=temp;
}

void swap2(int *p, int *q){
    int temp;

    temp=*p;
    *p=*q;
    *q=temp;
}

int main(){
    int n,weight[100],benefit[100],item_num[100],i=0,j=0,w,w1=0,ww;

    double benefit_per_weight[100],ben=0.0;

    FILE *file;
    file = fopen("fractional_knapsack_problem.txt","r");
    if(file == NULL)
    printf("File not exist");
    else
    {
    fscanf(file,"%d %d",&w,&n);

    while(fscanf(file,"%d %d",&weight[i],&benefit[i])!=EOF)
    {
      item_num[i]=i+1;
      benefit_per_weight[i]=(double)benefit[i]/(double)weight[i];
      i++;
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(benefit_per_weight[j]>benefit_per_weight[i])
            {
                swap1(&benefit_per_weight[j],&benefit_per_weight[i]);
                swap2(&weight[j],&weight[i]);
                swap2(&item_num[j],&item_num[i]);
                swap2(&benefit[j],&benefit[i]);
            }
        }
    }

    for(i=0;i<n;i++){
        w1=w1+weight[i];
        if(w1<w)
        {
            printf("\n%d no item is %d percent added\n",item_num[i],100);
            ben=ben+benefit[i];
        }
        else
        {
            printf("\n%d no item is %2f percent added\n",item_num[i],((double)(weight[i]+w-w1)/weight[i])*100);
            ben=ben+((double)(weight[i]+w-w1)/weight[i])*benefit[i];
            printf("\nTotal benefit count = %f",ben);
            break;
        }

    }
    
    fclose(file);
  }
  //printf("\nTotal benefit count = %f",ben);
}