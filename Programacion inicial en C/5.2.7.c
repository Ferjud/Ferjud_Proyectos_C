
#include<stdio.h>

int main()
{

    int n1,n2,n3,n4,n5, capicuaTriple=0, capicuaQuintuple=0;
    
    printf("QUINTETOS\n");
    printf("\ingrese 1er numero:");
    scanf("%d,&n1");
    printf("\ingrese 2do numero:");
    scanf("%d,&n2");
    printf("\ingrese 3er numero:");
    scanf("%d,&n3");
    printf("\ingrese 4to numero:");
    scanf("%d,&n4");
    printf("\ingrese 5to numero:");
    scanf("%d,&n5");
    
    while (n1 != 0 || n2 != 0 || n3 != 0 || n4 != 0 || n5 != 0)
    {
    
      if((n1 == n3 && n3 == n5) && (n1 != n2) && (n2==n4))
      {
        capicuaTriple++;
        
      }
      else   
        {
           if(n1 == n2 && n2 == n3 && n3 == n4 && n4 == n5)
           {
             capicuaQuintuple++;
           }
           
       }
       
      printf("\ingrese 1er numero:");
      scanf("%d,&n1");
      printf("\ingrese 2do numero:");
      scanf("%d,&n2");
      printf("\ingrese 3er numero:");
      scanf("%d,&n3");
      printf("\ingrese 4to numero:");
      scanf("%d,&n4");
      printf("\ingrese 5to numero:");
      scanf("%d,&n5");
   } 
}   