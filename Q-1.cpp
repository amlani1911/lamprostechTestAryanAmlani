#include<bits/stdc++.h>

using namespace std;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list to represent the graph
        unordered_map<int, vector<int>> adjList;
        
        // Create an array to store the in-degrees of each node
        vector<int> inDegree(numCourses, 0);
        
        // Populate the adjacency list and in-degrees
        for (auto& pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        
        // Perform topological sort using a queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            
            for (int neighbor : adjList[curr]) {
                // Decrement in-degree of the neighbor
                inDegree[neighbor]--;
                // If in-degree becomes 0, add to the queue
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Check if all courses can be taken
        if (result.size() == numCourses) {
            return result;
        } else {
            // If not all courses can be taken, return an empty vector
            return {};
        }
    }

int main() {

    // Input the number of courses
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Input the prerequisites
    int numPrerequisites;
    cout << "Enter the number of prerequisites: ";
    cin >> numPrerequisites;

    vector<vector<int>> prerequisites;
    cout << "Enter prerequisites as pairs (e.g., 1 0 for course 1 requiring course 0):" << endl;
    for (int i = 0; i < numPrerequisites; ++i) {
        int course, prerequisite;
        cin >> course >> prerequisite;
        prerequisites.push_back({course, prerequisite});
    }

    vector<int> result = findOrder(numCourses, prerequisites);

    // Print the result
    if (!result.empty()) {
        cout << "Valid Course Order: ";
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    } else {
        cout << "No valid course order found. There is a cycle in the prerequisites." << endl;
    }

    return 0;
}