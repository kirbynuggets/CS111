#include <stdio.h>

int u;
int m;
void input_random_values(int *ptr,int * ptr_2,int *ptr_3,int *ptr_4,int u,int m)
{
    for(int i=0;i<u;i++)
      {
        for(int j=0;j<m;j++)
          {
           int random_value=random_value_generator();
            *(ptr+i*m+j)=random_value;
            *(ptr_2+i*m+j)=random_value;
            *(ptr_3+i*m+j)=random_value;
             *(ptr_4+i*m+j)=random_value;
          }

      }
}


int random_value_generator()
{
    int highest=5;
    int lowest=0;
    int random_number=rand()%(highest-lowest+1)+lowest;
    return random_number;

}


void row_average_mapping(int *ptr,int u ,int m)
{
    for(int i=0;i<u;i++)
    {  double row_sum =0;
      int count_non_zero_element=0;

     for(int j=0;j<m;j++)
      {

     //    printf("%d \n",*(ptr+i*m+j));
       if (*(ptr+i*m+j)!=0)
        {
          row_sum+=*(ptr+i*m+j);
          count_non_zero_element+=1;
        }
      }
      double row_average=round(row_sum/count_non_zero_element);
      for(int j=0;j<m;j++)
      {
       if (*(ptr+i*m+j)==0)

        {
          *(ptr+i*m+j)=row_average;
        }
      }

    }
}


void column_average_mapping(int *ptr,int u ,int m)
{
    for(int i=0;i<u;i++)
    {  double column_sum =0;
      int count_non_zero_element=0;

     for(int j=0;j<m;j++)
      { //  printf("%d \n",*(ptr+i+j*u));
       if (*(ptr+i+j*u)!=0)
        {
           column_sum+=*(ptr+i+j*u);
          count_non_zero_element+=1;
        }
      }
      double column_average=round(column_sum/count_non_zero_element);
      for(int j=0;j<u;j++)
      {
       if (*(ptr+i+j*u)==0)
        {
          *(ptr+i+j*u)=(int)column_average;
        }
      }

    }
}

void column_and_row_average_combination_mapping(int *randomvalues,int *row_average_mapping,int *column_average_mapping,int * column_and_row_average_combination_mapping,int u,int m)
{

   for(int i=0;i<u;i++)
    {
     for(int j=0;j<m;j++)
         {
          if(*(randomvalues+i*m+j)==0)
          {
          int row_average_mapping_value=(*(row_average_mapping+i*m+j));
          double column_average_mapping_value=(*(column_average_mapping+i*m+j));
          int required_value =round((row_average_mapping_value+column_average_mapping_value)/2);

          *(column_and_row_average_combination_mapping+i*m+j)=required_value;
         }
         else
               *(column_and_row_average_combination_mapping+i*m+j)=*(randomvalues+i*m+j);
        }
    }


}
void deviation_matrix_finder(int *ptr_random_values,int *ptr_after_mapping,int *ptr_deviation_matrix,int u,int m)
{
   for(int i=0;i<u;i++)
      {
        for(int j=0;j<m;j++)
        {
            *(ptr_deviation_matrix+i*m+j)=*(ptr_after_mapping+i*m+j)-*(ptr_random_values+i*m+j);
        }
      }
}



void show_matrix(int * ptr)
{
  for(int i=0;i<u;i++)
   { for(int j=0;j<m;j++)
      {
        printf("%d ",*(ptr+i*m+j));
      }
    printf("\n");
   }
  printf("\n---------------\n");
}
void main()
{

  scanf("%d",&u);
  scanf("%d",&m);
  int * ptr_random_values=(int *)calloc(u*m,sizeof(int));
  int * ptr_row_average_mapping=(int *)calloc(u*m,sizeof(int));
  int * deviation_row_average_mapping=(int *)calloc(u*m,sizeof(int));
  int * ptr_column_average_mapping=(int *)calloc(u*m,sizeof(int));
  int * deviation_column_average_mapping=(int *)calloc(u*m,sizeof(int));
  int * ptr_row_and_columnn_average_mapping_combination=(int *)calloc(u*m,sizeof(int));
  int * deviation_row_and_column_average_combination_mapping=(int *)calloc(u*m,sizeof(int));
input_random_values(ptr_random_values,ptr_row_average_mapping,ptr_column_average_mapping,ptr_row_and_columnn_average_mapping_combination,u,m);
  printf("users and their ratings matrix-\n");
    show_matrix(ptr_random_values);
      row_average_mapping(ptr_row_average_mapping,u,m);
       printf("Row wise average mapping- \n");
      show_matrix(ptr_row_average_mapping);
    printf("The deviation matrix- \n");
   deviation_matrix_finder(ptr_random_values,ptr_row_average_mapping,deviation_row_average_mapping,u,m);
  show_matrix(deviation_row_average_mapping);
column_average_mapping(ptr_column_average_mapping,u,m);
  printf("Column wise average mapping- \n");
    show_matrix(ptr_column_average_mapping);
    printf("The deviation matrix- \n");
   deviation_matrix_finder(ptr_random_values,ptr_column_average_mapping,deviation_column_average_mapping,u,m);
show_matrix(deviation_column_average_mapping);
column_and_row_average_combination_mapping(ptr_random_values,ptr_row_average_mapping,ptr_column_average_mapping,ptr_row_and_columnn_average_mapping_combination,u,m);
  printf("Row and cloumn wise average combinatiion mapping- \n");
    show_matrix(ptr_row_and_columnn_average_mapping_combination);
    printf("The deviation matrix- \n");
  deviation_matrix_finder(ptr_random_values,ptr_row_and_columnn_average_mapping_combination,deviation_row_and_column_average_combination_mapping,u,m);
show_matrix(deviation_row_and_column_average_combination_mapping);
}
