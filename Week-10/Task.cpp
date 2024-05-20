#include <bits/stdc++.h>
using namespace std;

void Task(vector<int> time, vector<int> deadLine, int n)
{
    vector<pair<int, pair<int, int>>> task(n);
    for (int i = 0; i < n; i++)
    {
        task[i] = {deadLine[i], {time[i], i + 1}};
    }

    // Sort tasks based on the deadline
    sort(task.begin(), task.end());

    vector<int> result;
    int count = 0;
    int currentTime = 0;

    for (int i = 0; i < n; i++)
    {
        int duration = task[i].second.first;
        int deadline = task[i].first;
        if (currentTime + duration <= deadline)
        {
            result.push_back(task[i].second.second);
            count++;
            currentTime += duration;
        }
    }

    sort(result.begin(), result.end());
    
    cout << endl<< "Max no of task performed: " << count << endl;
    cout << "Selected task number: ";
    for (int i : result)
    {
        cout << i << ",";
    }
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> time(n);
    vector<int> deadLine(n);

    for (int i = 0; i < n; i++)
    {
        cin >> time[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> deadLine[i];
    }

    Task(time, deadLine, n);

    return 0;
}
