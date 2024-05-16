// id:322530080 mail:avishb1213@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
using namespace ariel;
vector<vector<int>> big_graph()
{
    long unsigned int rows = 30;
    long unsigned int cols = 30;
    vector<vector<int>> big_g(rows, vector<int>(cols));
    for (long unsigned int i = 0; i < rows; ++i)
    {
        for (long unsigned int j = 0; j < cols; ++j)
        {
            if (i != j)
            {
                big_g[i][j] = 1;
            }
            else
            {
                big_g[i][j] = 0;
            }
        }
    }
    big_g[0][11] = -1;
    return big_g;
}

bool matrix_eq(const vector<vector<int>> &m1, const vector<vector<int>> &m2)
{
    for (size_t i = 0; i < m1.size(); i++)
    {
        for (size_t j = 0; j < m1.size(); j++)
        {
            if (m1[i][j] != m2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

vector<vector<int>> big_cycle()
{
    long unsigned int rows = 30;
    long unsigned int cols = 30;
    vector<vector<int>> big_cycle(rows, vector<int>(cols));
    for (long unsigned int i = 0; i < rows - 1; ++i)
    {
        big_cycle[i][i + 1] = -1;
    }
    big_cycle[rows - 1][0] = -1;
    return big_cycle;
}

vector<vector<int>> big_cycle2()
{
    long unsigned int rows = 31;
    long unsigned int cols = 31;
    vector<vector<int>> big_cycle(rows, vector<int>(cols));
    for (long unsigned int i = 0; i < rows - 1; ++i)
    {
        big_cycle[i][i + 1] = -1;
    }
    big_cycle[rows - 1][0] = -1;
    return big_cycle;
}
vector<vector<int>> lot_of_componnents()
{
    vector<vector<int>> ans = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    return ans;
}

// will
TEST_CASE("Test graphClass")
{
    // will check that not square matrix throws an excepetion.
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g1.loadGraph(graph1, true));

    // will check that matrix with self cycels throws an excepetion.
    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0}};
    CHECK_THROWS(g2.loadGraph(graph2, true));

    // will check that undiracted and not symmetric matrix throws an excepetion.
    Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 2, 1},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 1, 4, 1}};
    CHECK_THROWS(g3.loadGraph(graph3, false));

    Graph big_g;
    vector<vector<int>> matrix = big_graph();
    big_g.loadGraph(matrix, true);
    CHECK(big_g.get_adjacencyMatrix() == matrix);
}

// tests for the isConnected function.
TEST_CASE("Test isConnected")
{
    // will test that the isConnected reutrns o for undirected and unconnected graph.
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g1.loadGraph(graph, false);
    CHECK(Algorithms::isConnected(g1) == false);

    // will test that the isConnected reutrns 1 for undirected and connected graph.
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}};
    g2.loadGraph(graph2, false);
    CHECK(Algorithms::isConnected(g2) == true);

    // will test that the isConnected reutrns 1 for directed and connected graph.
    Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0},
    };
    g3.loadGraph(graph3, true);
    CHECK(Algorithms::isConnected(g3) == true);

    // will test that the isConnected reutrns 0 for directed and unconnected graph.
    Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {0, 0, 1},
        {0, 1, 0},
    };
    g4.loadGraph(graph4, true);
    CHECK(Algorithms::isConnected(g4) == false);

    // will check is connected with more comlex directed graph that should return 0.
    Graph g5;
    vector<vector<int>> graph5 =
        {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
         {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    g5.loadGraph(graph5, true);
    CHECK(Algorithms::isConnected(g5) == false);

    // will check is connected with more comlex directed graph that should return 0.
    Graph g6;
    vector<vector<int>> graph6 =
        {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
         {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
         {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
         {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
         {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0}};
    g6.loadGraph(graph6, true);
    CHECK(Algorithms::isConnected(g6) == true);

    // will test that the isConnected reutrns o for directed 0 matrix.
    Graph g7;
    vector<vector<int>> graph7 = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};
    g7.loadGraph(graph7, true);
    CHECK(Algorithms::isConnected(g7) == false);

    // will check graph with one vertex. expected- true.
    Graph g8;
    vector<vector<int>> graph8 = {{0}};
    g8.loadGraph(graph8, true);
    CHECK(Algorithms::isConnected(g8) == true);

    // will check the function with a big connected graph.
    Graph big_g;
    vector<vector<int>> matrix = big_graph();
    big_g.loadGraph(matrix, true);
    CHECK(Algorithms::isConnected(big_g) == true);

    // will test a graph with a lot of diffrent components.
    Graph lot_of_c;
    vector<vector<int>> lot = lot_of_componnents();
    lot_of_c.loadGraph(lot, true);
    CHECK(Algorithms::isConnected(lot_of_c) == false);
}

TEST_CASE("Test isContainsCycle")
{
    // will test a directed graph that contains a cycle.
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}};
    g1.loadGraph(graph1, true);
    string cycle1 = "0->1->2->10->8->7->0";
    CHECK(Algorithms::isContainsCycle(g1) == cycle1);

    // will test a directed graph that not contain a cycle.
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    g2.loadGraph(graph2, true);
    CHECK(Algorithms::isContainsCycle(g2) == "0");

    // will test a undirected graph that not contain a cycle.
    Graph g3;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 0}};
    g3.loadGraph(graph3, false);
    CHECK(Algorithms::isContainsCycle(g3) == "0");

    // will test a undirected graph that contains a cycle.
    Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0}};
    g4.loadGraph(graph4, false);
    string cycle = "0->1->2->3->4->5->6->7->8->0";
    CHECK(Algorithms::isContainsCycle(g4) == cycle);

    // test that for big graph with negative cycle the fucntion will return the cycle.
    Graph big_c;
    vector<vector<int>> bc = big_cycle();
    big_c.loadGraph(bc, true);
    string cycle2;
    for (int i = 0; i < 30; i++)
    {
        cycle2 += to_string(i);
        cycle2 += "->";
    }
    cycle2 += "0";
    CHECK(Algorithms::isContainsCycle(big_c) == cycle2);

    // will test a graph with a lot of diffrent components, will check that the
    // first component is the one the the function reutrns.
    Graph lot_of_c;
    vector<vector<int>> loc = lot_of_componnents();
    lot_of_c.loadGraph(loc, true);
    CHECK(Algorithms::isContainsCycle(lot_of_c) == "0->1->2->3->0");
}

TEST_CASE("Test shortestPath")
{
    // will test that if we ask to calculate from vertex
    // that is out side the graph will throw an exception.
    Graph g0;
    vector<vector<int>> graph0 = {
        {1, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0}};
    CHECK_THROWS(Algorithms::shortestPath(g0, 0, 5));

    // note that the next 4 tests are to test the dijkstra method without negative edges.

    // will test directed and unconnected graph with no negative edges that have a path from a to b.
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 12, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 1, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 5, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0}};
    g1.loadGraph(graph1, true);
    CHECK(Algorithms::shortestPath(g1, 3, 7) == "3->4->8->7");

    // will test directed and unconnected graph with no negative edges that dont have a path from a to b.
    CHECK(Algorithms::shortestPath(g1, 0, 7) == "-1");

    // will test undirected and connected graph with no negative edges that have a path from a to b.
    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 50, 0, 0, 0, 0, 0, 1},
        {50, 0, 0, 0, 0, 0, 50, 0},
        {0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 50, 0, 0, 0, 0, 0, 50},
        {1, 0, 1, 0, 0, 0, 50, 0}};
    g2.loadGraph(graph2, false);
    CHECK(Algorithms::shortestPath(g2, 0, 3) == "0->7->2->5->3");

    // will test undirected and unconnected graph with no negative edges that have a path from a to b.
    Graph g3;
    vector<vector<int>> graph3 = {
        {0, 50, 0, 0, 0, 0, 0, 1},
        {50, 0, 0, 0, 0, 0, 50, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 1, 0, 0, 0},
        {0, 50, 0, 0, 0, 0, 0, 50},
        {1, 0, 0, 0, 0, 0, 50, 0}};
    g3.loadGraph(graph3, false);
    CHECK(Algorithms::shortestPath(g3, 0, 3) == "-1");

    // the next tests will test the bellman ford algorithm with negative edges.

    // will test directed connected graph with path from a to b.
    Graph g4;
    vector<vector<int>> graph4 = {
        {0, -5, 0, 0, -10},
        {0, 0, -5, 0, 0},
        {0, 0, 0, -5, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0}};
    g4.loadGraph(graph4, true);
    CHECK(Algorithms::shortestPath(g4, 0, 3) == "0->1->2->3");

    // will test directed unconnected graph with no path from a to b.
    Graph g5;
    vector<vector<int>> graph5 = {
        {0, 0, 0, 0, -10},
        {0, 0, -5, 0, 0},
        {0, 0, 0, -5, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    g5.loadGraph(graph5, true);
    CHECK(Algorithms::shortestPath(g5, 0, 3) == "-1");

    // test bellman ford with directed  negtive cycle - no path between each vertex.
    Graph g6;
    vector<vector<int>> graph6 = {
        {0, -5, 0, 0, -10},
        {0, 0, -5, 0, 0},
        {0, 0, 0, -5, 0},
        {0, 0, 0, 0, -1},
        {-1, 0, 0, 0, 0}};
    g6.loadGraph(graph6, true);
    CHECK(Algorithms::shortestPath(g6, 0, 3) == "-1");
    CHECK(Algorithms::shortestPath(g6, 1, 3) == "-1");
    CHECK(Algorithms::shortestPath(g6, 2, 3) == "-1");

    // will test bellman ford with undirected graph with path from a to b.
    Graph g7;
    vector<vector<int>> graph7 = {
        {0, 1, 0, 0, 1},
        {1, 0, 13, 0, 0},
        {0, 13, 0, -1, 0},
        {0, 0, -1, 0, -1},
        {1, 0, 0, -1, 0}};
    g7.loadGraph(graph7, false);
    CHECK(Algorithms::shortestPath(g7, 0, 3) == "0->4->3");

    // will test bellman ford on undirected graph with negative cycle.
    Graph g8;
    vector<vector<int>> graph8 =
        {{0, 1, 0, 5, 0, 0, 0, 0, 0, 0},
         {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, -1, 0, -1, 0, 0, 0, 0},
         {0, 0, 0, 0, 5, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, -1, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, -1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
         {0, 0, -1, 0, 0, 0, 0, 0, 0, 0}};
    g8.loadGraph(graph8, true);
    CHECK(Algorithms::shortestPath(g8, 0, 3) == "-1");

    // will test bellman ford with undirected graph without path from a to b.
    Graph g9;
    vector<vector<int>> graph9 = {
        {0, 0, 0, 0, 0},
        {1, 0, 13, 0, 0},
        {0, 13, 0, -1, 0},
        {0, 0, -1, 0, -1},
        {1, 0, 0, -1, 0}};
    g9.loadGraph(graph9, true);
    CHECK(Algorithms::shortestPath(g9, 0, 3) == "-1");
}

TEST_CASE("Test isBipartite")
{
    // test that for big even cycle with negative edges the fucntion will return the righ parttion.
    Graph big_c1;
    vector<vector<int>> bc1 = big_cycle();
    big_c1.loadGraph(bc1, true);
    CHECK(Algorithms::isBipartite(big_c1) != "0");

    // test that for big uneven cycle with negative edges the fucntion will return the righ parttion.
    Graph big_c2;
    vector<vector<int>> bc2 = big_cycle2();
    big_c2.loadGraph(bc2, true);
    CHECK(Algorithms::isBipartite(big_c2) == "0");

    // will test directed small graph that should return 0.
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 1},
        {0, 0, 1},
        {1, 0, 0}};
    g1.loadGraph(graph1, true);
    CHECK(Algorithms::isBipartite(g1) == "0");

    // this test will test undirected graph with more than one connected component that should return the parttion.
    Graph g2;
    vector<vector<int>> graph2 = {{0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                                  {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}};
    g2.loadGraph(graph2, false);
    CHECK(Algorithms::isBipartite(g2) == "vertexes on first side-( 10 8 6 4 2 0 )   vertexes on second side- ( 11 9 7 5 3 1 )");

    // will test the funciton with undirected graph that should return false.
    Graph g3;
    vector<vector<int>> graph3 = {{0, 1, 0, 0, 1},
                                  {1, 0, 1, 0, 0},
                                  {0, 1, 0, 1, 0},
                                  {0, 0, 1, 0, 1},
                                  {1, 0, 0, 1, 0}};
    g3.loadGraph(graph3, false);
    CHECK(Algorithms::isBipartite(g3) == "0");

    // will test that the  fucntion returns one connected component for matrix that has only one edge.
    Graph g4;
    vector<vector<int>> graph4 = {
        {0}};
    g4.loadGraph(graph4, false);
    CHECK(Algorithms::isBipartite(g4) == "vertexes on first side-( 0 )   vertexes on second side- ( )");
}

TEST_CASE("Test negativeCycle")
{
    // test that the function returns the cycle for directed graph with negative cycle.
    Graph g1;
    vector<vector<int>> graph1 =
        {{0, 1, 0, 5, 0, 0, 0, 0, 0, 0},
         {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, -1, 0, -1, 0, 0, 0, 0},
         {0, 0, 0, 0, 5, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, -1, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, -1, 0, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, -1},
         {0, 0, -1, 0, 0, 0, 0, 0, 0, 0}};
    g1.loadGraph(graph1, true);
    CHECK(Algorithms::negativeCycle(g1) == "2->5->6->7->8->9->2");

    // will check that the function returns the right path for
    // directed unconnected graph with negtive cycle with length 2.
    Graph g2;
    vector<vector<int>> graph2 =
        {{0, 0, 0, 0},
         {0, 0, 0, 0},
         {0, 0, 0, 99},
         {0, 0, -100, 0}};
    g2.loadGraph(graph2, true);
    CHECK(Algorithms::negativeCycle(g2) == "2->3->2");

    // test that for big graph without negative cycle the fucntion will return false.
    Graph big_g;
    vector<vector<int>> big_m = big_graph();
    big_g.loadGraph(big_m, true);
    CHECK(Algorithms::negativeCycle(big_g) == "there is no negative cycle!");

    // will test that graph with just one vertex returns false for this function.
    Graph g3;
    vector<vector<int>> graph3 =
        {{0}};
    g3.loadGraph(graph3, true);
    CHECK(Algorithms::negativeCycle(g3) == "there is no negative cycle!");

    // test that for big graph with negative cycle the fucntion will return the cycle.
    Graph big_c;
    vector<vector<int>> graph4 = big_cycle();
    big_c.loadGraph(graph4, true);
    string cycle;
    for (int i = 0; i < 30; i++)
    {
        cycle += to_string(i);
        cycle += "->";
    }
    cycle += "0";
    CHECK(Algorithms::negativeCycle(big_c) == cycle);

    // test long path graph with last edge bigger than the whole path. expected -fales.
    Graph big_nc;
    vector<vector<int>> big_ncm = big_cycle();
    big_ncm[29][0] = 100;
    big_nc.loadGraph(big_ncm, true);
    CHECK(Algorithms::negativeCycle(big_nc) == "there is no negative cycle!");
}

TEST_CASE("Test + and unar +/-")
{
    // will test the addition operator in directed graph, will test that after addition
    // a graph with no path from a to that is added to a graph with path from a to b
    // has a path from a to b.
    Graph g1;
    vector<vector<int>> graph = {// first graph
                                 {0, 1, 1},
                                 {0, 0, 0},
                                 {0, 0, 0}};
    g1.loadGraph(graph, true);
    CHECK(Algorithms::shortestPath(g1, 2, 1) == "-1"); // no path
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 1, 0}};
    g2.loadGraph(weightedGraph, true);
    Graph g3 = g1 + g2;
    CHECK(Algorithms::shortestPath(g3, 2, 1) == "2->1"); // path after addition
    vector<vector<int>> expectedGraph = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 1, 0}};
    CHECK(matrix_eq(g3.get_adjacencyMatrix(), expectedGraph));

    // will test that the addtion of 2 graphs with diffrent amount of vertexes throws
    // an exception.
    Graph g4;
    vector<vector<int>> graph4 = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 0, 0}};
    g4.loadGraph(graph4, true);
    Graph g5;
    vector<vector<int>> graph5 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0}};
    g5.loadGraph(graph5, true);
    CHECK_THROWS(g4 + +(+(+(+(g5))))); // will test the + and the unary plus function

    // will test addtion in undircted graph. will also test that
    // after addtion the cycle algorithm works well and the
    // bellman ford cycle algorithm works well.
    Graph g6;
    vector<vector<int>> graph6 = {
        {0, 0, 0, 0},
        {0, 0, 0, -1},
        {0, 0, 0, 0},
        {0, -1, 0, 0}};
    g6.loadGraph(graph6, false);
    Graph g7;
    vector<vector<int>> graph7 = {
        {0, -1, -1, 0},
        {-1, 0, -1, 0},
        {-1, -1, 0, -1},
        {0, 0, -1, 0}};
    g7.loadGraph(graph7, false);
    Graph g8 = g6 + -((-(-(-g7)))); // will test the + and the unary - operators.
    vector<vector<int>> exp = {{0, -1, -1, 0},
                               {-1, 0, -1, -1},
                               {-1, -1, 0, -1},
                               {0, -1, -1, 0}};
    CHECK(Algorithms::negativeCycle(g8) == "1->2->3->1");
    CHECK(Algorithms::isContainsCycle(g8) == "0->1->2->0");
    CHECK(matrix_eq(exp, g8.get_adjacencyMatrix()) == true);

    // will test that the addtion of directed and undirected graphs throws an exception
    Graph g9;
    vector<vector<int>> graph9 = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 0, 0}};
    g9.loadGraph(graph9, true);
    Graph g10;
    vector<vector<int>> graph10 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g10.loadGraph(graph10, false);
    CHECK_THROWS(g9 + g10);

    // will test the + operator with checking the isBipartite algorithm.
    Graph g11;
    vector<vector<int>> graph11 = {{0, 1, 0, 0},
                                   {0, 0, 1, 0},
                                   {0, 0, 0, 1},
                                   {1, 0, 0, 0}};
    g11.loadGraph(graph11, true);
    CHECK(Algorithms::isBipartite(g11) == "vertexes on first side-( 2 0 )   vertexes on second side- ( 3 1 )");
    Graph g12;
    vector<vector<int>> graph12 = {{0, 0, 0, 0},
                                   {0, 0, 0, 1},
                                   {0, 0, 0, 0},
                                   {0, 0, 0, 0}};
    g12.loadGraph(graph12, true);
    Graph g13 = g11 + g12;
    CHECK(Algorithms::isBipartite(g13) == "0");
}

TEST_CASE("Test +=") // will test the += operator of the graph class.
{
    // will check that after using "+=" the graph that we get is the grpah that we
    // expect. the test will be on a directed graph.
    Graph g1;
    vector<vector<int>> graph = {// first graph
                                 {0, 1, 1},
                                 {0, 0, 0},
                                 {0, 0, 0}};
    g1.loadGraph(graph, true);
    CHECK(Algorithms::shortestPath(g1, 2, 1) == "-1"); // no path
    Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 1, 0}};
    g2.loadGraph(weightedGraph, true);
    g1 += g2;
    CHECK(Algorithms::shortestPath(g1, 2, 1) == "2->1"); // path after addition
    vector<vector<int>> expectedGraph = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 1, 0}};
    CHECK(matrix_eq(g1.get_adjacencyMatrix(), expectedGraph));
}

TEST_CASE("Test -") // will test the minus and unary plus and minus operators
{
    Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 1, 0}};
    g1.loadGraph(graph, true);
    Graph g2;
    CHECK(Algorithms::shortestPath(g1, 2, 1) == "2->1");
    vector<vector<int>> weightedGraph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 1, 0}};
    g2.loadGraph(weightedGraph, true);
    Graph g3 = g1 - +g2; // will test the minus and unary plus operators.
    vector<vector<int>> expectedGraph = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 0, 0}};
    CHECK(Algorithms::shortestPath(g3, 2, 1) == "-1"); // will test that after a call of the minus operator there is no path between 2 and 1 vertexes.
    CHECK(matrix_eq(g3.get_adjacencyMatrix(), expectedGraph));

    Graph g6;
    vector<vector<int>> graph6 = {
        {0, 0, 0, 0},
        {0, 0, 0, -1},
        {0, 0, 0, 0},
        {0, -1, 0, 0}};
    g6.loadGraph(graph6, false);
    Graph g7;
    vector<vector<int>> graph7 = {
        {0, -1, -1, 0},
        {-1, 0, -1, 0},
        {-1, -1, 0, -1},
        {0, 0, -1, 0}};
    g7.loadGraph(graph7, false);
    Graph g8 = g6 - -(-(-g7)); // will test the - and the unary - operators.
    vector<vector<int>> exp = {{0, -1, -1, 0},
                               {-1, 0, -1, -1},
                               {-1, -1, 0, -1},
                               {0, -1, -1, 0}};
    CHECK(Algorithms::negativeCycle(g8) == "1->2->3->1");
    CHECK(Algorithms::isContainsCycle(g8) == "0->1->2->0");
    CHECK(matrix_eq(exp, g8.get_adjacencyMatrix()));

    // will test that the minusing of directed and undirected graphs throws an exception
    Graph g9;
    vector<vector<int>> graph9 = {
        {0, 1, 1},
        {0, 0, 0},
        {0, 0, 0}};
    g9.loadGraph(graph9, true);
    Graph g10;
    vector<vector<int>> graph10 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g10.loadGraph(graph10, false);
    CHECK_THROWS(g9 - g10);
}

TEST_CASE("Test ++ and -- operators")
{
    // in this test we will test that after using the ++ operator on a graph
    // that has negtaive cycle contains only -1 edges we get an unconnected graph
    // with no negative cycle.
    Graph g1;
    vector<vector<int>> graph = {{0, -1, 0, 0, 0, -1},
                                 {-1, 0, -1, 0, 0, 0},
                                 {0, -1, 0, -1, 0, 0},
                                 {0, 0, -1, 0, 0, -1},
                                 {0, 0, 0, 0, 0, 3},
                                 {-1, 0, 0, -1, 3, 0}};
    g1.loadGraph(graph, false);
    CHECK(Algorithms::negativeCycle(g1) == "0->1->2->3->5->0");
    CHECK(Algorithms::isConnected(g1) == true);
    Graph res1 = ++g1;
    CHECK(Algorithms::isConnected(res1) == false);
    CHECK(Algorithms::negativeCycle(res1) == "there is no negative cycle!");
    g1.loadGraph(graph, false);
    Graph res2 = g1++;
    CHECK(Algorithms::negativeCycle(res2) == "0->1->2->3->5->0");
    CHECK(Algorithms::isConnected(res2) == true);

    // will test that using the -- operator on a graph that has cycle with 1 whiegh edges
    // will make the graph unconnected and will earese that cycle.
    Graph g2;
    vector<vector<int>> graph2 = {{0, 1, 0, 0, 0, 1},
                                  {1, 0, 1, 0, 0, 0},
                                  {0, 1, 0, 1, 0, 0},
                                  {0, 0, 1, 0, 0, 1},
                                  {0, 0, 0, 0, 0, 3},
                                  {1, 0, 0, 1, 3, 0}};
    g2.loadGraph(graph2, false);
    CHECK(Algorithms::isContainsCycle(g2) == "0->1->2->3->5->0");
    CHECK(Algorithms::isConnected(g2) == true);
    Graph res3 = --g2; // will test after -- operator.
    CHECK(Algorithms::isConnected(res3) == false);
    CHECK(Algorithms::isContainsCycle(res3) == "0");
    g2.loadGraph(graph2, false);
    Graph res4 = g2--; // will test before -- operator.
    CHECK(Algorithms::isContainsCycle(res4) == "0->1->2->3->5->0");
    CHECK(Algorithms::isConnected(res4) == true);
    CHECK(Algorithms::isConnected(g2) == false);
    CHECK(Algorithms::isContainsCycle(g2) == "0");

    // will test that ++ and -- operators works more than ones.
    Graph g3;
    vector<vector<int>> graph3 = {{0, 5}, {0, 0}};
    g3.loadGraph(graph3, true);
    -- -- -- -- --g3;
    CHECK(g3.get_adjacencyMatrix()[0][1] == 0);
    g3.loadGraph(graph3, true);
    ++ ++ ++ ++g3;
    CHECK(g3.get_adjacencyMatrix()[0][1] == 9);
}

TEST_CASE("Test multiplication by int")
{
    // will test that if we multiply positive cycle by -1 we will
    // get a graph with negative cycle.
    //  also will check an edge that is outside the negative cycle to check the * operator.
    Graph g1;
    vector<vector<int>> graph1 = {{0, 1, 0, 0, 0, 1},
                                  {1, 0, 1, 0, 0, 0},
                                  {0, 1, 0, 1, 0, 0},
                                  {0, 0, 1, 0, 0, 1},
                                  {0, 0, 0, 0, 0, 3},
                                  {1, 0, 0, 1, 3, 0}};
    g1.loadGraph(graph1, false);
    CHECK(Algorithms::negativeCycle(g1) == "there is no negative cycle!");
    Graph g2 = g1 * -1;
    CHECK(Algorithms::negativeCycle(g1) == "0->1->2->3->5->0");
    CHECK(g2.get_adjacencyMatrix()[5][4] == -3);

    // will test that after wi multiply a graph by 0 all the matrix will be zero meaning that
    // there are no edges and the graph is not connected.
    CHECK(Algorithms::isConnected(g2) == true);
    g2 * 0;
    size_t size = g2.get_adjacencyMatrix().size();
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
            CHECK(g2.get_adjacencyMatrix()[i][j] == 0);
    }
    CHECK(Algorithms::isConnected(g2) == false);
}

TEST_CASE("Test multiplication of 2 graphs")
{
    // will test multiplication of 2 graphs that should work.
    // notice that after the multiplication the diagonal of the matrix set to be 0.
    // also note that after you multiply 2 undirected graphs its becomes directed.
    Graph g1, g2, g3;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(weightedGraph, false);
    g2.loadGraph(weightedGraph, false);
    g3 = g1 * g2;
    CHECK(g3.get_directed() == true);
    vector<vector<int>> matrix = g3.get_adjacencyMatrix();
    vector<vector<int>> exp = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    CHECK(matrix_eq(matrix, exp) == true);

    // will check that multipling 2 graphs with not same dimantions leeds to an error
    Graph g4;
    vector<vector<int>> graph4 = {{0, 1}, {1, 0}};
    g4.loadGraph(graph4, true);
    CHECK_THROWS(g4 * g3);

    // will check multiplicatin of 2 directed graphs:
    Graph g5, g6;
    g5.loadGraph(weightedGraph, true);
    g6.loadGraph(weightedGraph, true);
    CHECK(matrix_eq((g5 * g6).get_adjacencyMatrix(), exp) == true);
}

TEST_CASE("Test == operator")
{
    // will test that 2 same graphs are equel.
    Graph g1, g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(weightedGraph, true);
    g2.loadGraph(weightedGraph, true);
    CHECK(g1 == g2);

    // will test the case when the graphs dosent have the same edges but
    // each of them is not bigger than the other.
    Graph g3, g4;
    vector<vector<int>> weightedGraph2 = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}};
    g3.loadGraph(weightedGraph2, false);
    vector<vector<int>> weightedGraph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g4.loadGraph(weightedGraph3, false);
    CHECK(g3 == g4);
}

TEST_CASE("Test < , != , >")
{
    // will check the case when onr graph contain another.
    Graph g1, g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(weightedGraph, false);
    vector<vector<int>> weightedGraph2 = {
        {0, 1},
        {1, 0}};
    g2.loadGraph(weightedGraph2, false);
    CHECK(g1 > g2);
    CHECK(g2 < g1);
    CHECK_FALSE(g1 < g2);
    CHECK(g1 != g2);

    // will check the case when one graph dosent contain the other one but
    // one graph has more edges than the other one.
    Graph g3, g4;
    vector<vector<int>> weightedGraph3 = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}};
    g3.loadGraph(weightedGraph3, false);
    vector<vector<int>> weightedGraph4 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g4.loadGraph(weightedGraph4, false);
    CHECK(g3 > g4);
    CHECK_FALSE(g3 < g4);
    CHECK(g4 < g3);
    CHECK(g1 != g2);

    // will check the case when one graph dosent contain the other one,
    // they have the same amount of edges but they dont have the same amount of
    // vertexes.
    Graph g5, g6;
    vector<vector<int>> weightedGraph5 = {
        {0, 1, 1, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0}};
    g5.loadGraph(weightedGraph5, false);
    vector<vector<int>> weightedGraph6 = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}};
    g6.loadGraph(weightedGraph6, false);
    CHECK(g5 > g6);
    CHECK(g6 < g5);
    CHECK(g5 != g6);
    CHECK_FALSE(g5 == g6);
}

TEST_CASE("Test <= >= operators")
{
    // will test that 2 same graphs.
    Graph g1, g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g1.loadGraph(weightedGraph, true);
    g2.loadGraph(weightedGraph, true);
    CHECK(g1 >= g2);
    CHECK(g1 <= g2);

    // will check 2 graphs that one graph is bigger than other returns true.
    Graph g5, g6;
    vector<vector<int>> weightedGraph5 = {
        {0, 1, 1, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0}};
    g5.loadGraph(weightedGraph5, false);
    vector<vector<int>> weightedGraph6 = {
        {0, 1, 1},
        {1, 0, 0},
        {1, 0, 0}};
    g6.loadGraph(weightedGraph6, false);
    CHECK(g5 >= g6);
    CHECK_FALSE(g6 >= g5);
    CHECK(g6 <= g5);
}
