#include<stdio.h>

void swap(int *p, int *q){
    int temp;

    temp=*p;
    *p=*q;
    *q=temp;
}
int main()
{
  int name[20],a[20],b[20],i=0,j,activity_num[100],start_time[100],end_time[100],n=0,ending_time;

  FILE *file;
  file = fopen("activity_selection.txt","r");
  if(file == NULL)
  printf("File not exist");
  else
  {
    
    while(fscanf(file,"%d %d",&start_time[i],&end_time[i])!=EOF)
    {
      n++;
      activity_num[i]=i+1;
      i++;
    }
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(end_time[j]<end_time[i])
            {
                swap(&end_time[j],&end_time[i]);
                swap(&start_time[j],&start_time[i]);
                swap(&activity_num[j],&activity_num[i]);
            }
        }
    }

    printf("Seclected Activity Number: %d ",activity_num[0]);
    ending_time=end_time[0];
    for(i=1;i<n;i++)
       {
           if(start_time[i]<ending_time)
            continue;
           else{
            printf("%d ",activity_num[i]);
            ending_time=end_time[i];
           }
       }
  fclose(file);}

}