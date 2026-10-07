#include <iostream>
#include <exception>

int** matrix(int i, int j)

{
    int** arr = new(std::nothrow) int* [i];
    if(arr == nullptr)
    {
        std::cout<<"Не удалось выделить память\n";
        return nullptr;
    }
    for (int a = 0;a<i;++a)
    {
        arr[a] = new(std::nothrow) int[j];
        if(arr[a] == nullptr)
        {
            std::cout<<"Не удалось выделить память\n";
            return nullptr;
        }
    }
    std::cout<<"Введите элементы масива по строчно\n ";
    for(int n = 0; n<i; ++n)
    {  
        for(int v = 0; v<j;++v)
        {   int m = 0;
            std::cin>>m;
            if(!std::cin)
            {
               std::cout<<"Некорректный ввод\n";
              for (int k = 0;k<i;++k)
              {
                  delete[] arr[k];
              }
             
              delete[] arr;
              return nullptr;

            }
            arr[n][v] = m;   
        }
    }

    std::cout<<"Матрица\n";

    for(int n = 0; n<i;++n)
    {
      for (int v = 0; v<j;++v)
      {
        std::cout<<arr[n][v]<<" ";
      }
      std::cout<<"\n";
    }
    return arr;
}



int main()
{
    int i = 0;
    int j = 0;

    std::cout<<"Введите кол-во строк\n";
    std::cin>>i;
    std::cout<<"Введите кол-во столбцов\n";
    std::cin>>j;
    if(i <= 0 || j <= 0|| (!std::cin))
    {
        std::cout<<"Некорректный ввод матрицы\n";
        return 1;
    } 
    int** arr = matrix(i,j);
    
    if(arr == nullptr)
    {
        return 1;
    }

    int **revmat = new(std::nothrow) int*[j];
    if(revmat == nullptr)
    {
        std::cout<<"Не удалось выделить память\n";
        return 2;
    }
    for (int a = 0;a<j;++a)
    {
        revmat[a] = new(std::nothrow) int[i];
        if (revmat[a] == nullptr)
        {
             std::cout<<"Не удалось выделить память\n";
             return 2;
        }
    }
    for (int m = 0;m<i;++m)
    {
        for(int v = 0; v < j; ++v)
        {
          revmat[v][m] = arr[m][v];  
        }
    
    }

    std::cout<<"транспонированная матрица::\n";
    for(int n = 0; n<j;++n)
    {
        for(int v = 0; v<i;++v)
        {
            std::cout<<revmat[n][v]<<" ";
        }
        
        std::cout<<"\n";


    }
    
    for(int a = 0; a<i; ++a)
    {
        delete[] arr[a];
    }
    delete[]  arr;

    for (int a = 0; a<j; a++)
    {
        delete[] revmat[a];
    }
    delete[] revmat;
    
    return 0;

}
