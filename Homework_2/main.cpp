#include <exception>
#include <iostream>

const int cin_err = 1, memory_fail = 2;
int **concat_rows(const int *const *lhs, size_t n1, size_t m1, const int *const *rhs, size_t n2, size_t m2)
{
  int **concat_matrix = nullptr;
  size_t accept_rows = 0;

  if (m1 > m2 || m1 == m2)
{
    try 
    {
      concat_matrix = new int *[m1];
      for (size_t i = 0; i < m1; ++i) 
      {
        size_t row_len = (i < m2) ? (n1 + n2) : n1;

        concat_matrix[i] = new int[row_len];
        accept_rows++;
      }
    }
    catch (std::bad_alloc)
    {
      std::cerr << "bad alloc in concat_rows\n";
      if (concat_matrix != nullptr)
      {
        for (size_t i = 0; i < accept_rows; ++i)
        {
          delete[] concat_matrix[i];
        }
        delete[] concat_matrix;
      }
      return nullptr;
    }

    for (size_t i = 0; i < m1; ++i) 
    {
      for (size_t v = 0; v < n1; ++v)
      {
        concat_matrix[i][v] = lhs[i][v];
      }

      if (i < m2) 
      {
        for (size_t v = 0; v < n2; ++v) 
        {
          concat_matrix[i][n1 + v] = rhs[i][v];
        }
      }
    }
  }
  else 
   {
    try
    {
      concat_matrix = new int *[m2];
      for (size_t i = 0; i < m2; ++i)
      { 
       size_t row_len = (i<m1) ? (n1+n2) : n2;
        concat_matrix[i] = new int[row_len];
        accept_rows++;
      }
    }
    catch (std::bad_alloc) 
    {
      std::cerr << "bad alloc in concat_rows\n";
        for (size_t i = 0; i < accept_rows; ++i) 
        {
          delete[] concat_matrix[i];
        }
       delete[] concat_matrix;
      return nullptr;
    }

    for (size_t i = 0; i < m2; ++i) 
    {
      if (i < m1) 
      {
        for (size_t v = 0; v < n1; ++v) 
        {
          concat_matrix[i][v] = lhs[i][v];
        }

        for (size_t v = 0; v < n2; ++v) 
        {
          concat_matrix[i][n1 + v] = rhs[i][v];
        }
      }
      else
      {
        for (size_t v = 0; v < n2; ++v) 
        {
          concat_matrix[i][v] = rhs[i][v];
        }
      }
    }

   }


   return concat_matrix;
}

int **in_matrix(size_t n1, size_t m1) 
{
  int **matrix = new int *[m1];
  try 
  {
    for (int i = 0; i < m1; ++i) 
    {
      int *mass = new int[n1];
      matrix[i] = mass;
    }
  }
  catch (std::bad_alloc) 
  {
    std::cerr << "bad_alloc in in_matrix_2\n";
    for (int i = 0; i < n1; ++i) 
    {
      delete[] matrix[i];
    }

    delete[] matrix;
    return nullptr;
  }
  std::cout << "Введите данные первой матрицы по строчно: \n";

  for (int i = 0; i < m1; ++i) 
  {
    for (int v = 0; v < n1; ++v) 
    {
      int n = 0;
      std::cin >> n;
      matrix[i][v] = n;
    }
  }
  return matrix;
}
int main() 
{
  size_t n1 = 0, n2 = 0, m1 = 0, m2 = 0;

  std::cout << "Введите кол-во строк и столбцов первой матрицы: ";
  std::cin >> m1;
  std::cin >> n1;
  if(!std::cin)
  {
      std::cout<<"cin_err\n";
      return cin_err;
  }

  std::cout << "Введите кол-во строк и столбцов второй матрицы: ";
  std::cin >> m2;
  std::cin >> n2;

  if(!std::cin)
  {
      std::cout<<"cin_err\n";
      return cin_err;
  }

  const int **matrix_1 = (const int **)in_matrix(n1, m1);
  const int **matrix_2 = (const int **)in_matrix(n2, m2);
  int **done_matrix = concat_rows(matrix_1, n1, m1, matrix_2, n2, m2);

  if (m1 > m2 || m1 == m2)
  {
    for (int i = 0; i < m1; ++i)
    {
      for (int v = 0; v < n1 + n2; ++v)
      {
        std::cout << done_matrix[i][v] << " ";
      }
      std::cout << "\n";
    }
  }
}
