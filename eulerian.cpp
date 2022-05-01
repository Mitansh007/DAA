#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the eulerian graph" << endl;
    cin >> n;
    int graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    int indegree[n] = {0};
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += graph[i][j];
        }
        indegree[i] = sum;
    }
    int countodd = 0;
    int counteven = 0;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] % 2 == 0)
            counteven++;
        else
            countodd++;
    }
    if (counteven == n and countodd == 0)
        cout << "The graph is eulerian graph and circuit exists" << endl;
    else if (countodd == 2)
        cout << "The graph is semi eulerian and circuit doesn't exist" << endl;
    else
        cout << "The graph is not eulerian" << endl;
    return 0;
}