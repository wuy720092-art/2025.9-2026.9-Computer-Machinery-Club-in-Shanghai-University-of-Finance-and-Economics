/*description for the problem source:Luogu P2866
Farmer John has N cows celebrating Bad Hair Day.
All the cows are standing in a single row facing right. They are numbered from left to right as 1, 2, ..., N.
The height of cow i is h_i. Cow N is at the front of the line (rightmost), and cow 1 is at the back (leftmost).

For cow i and a cow j in front of it (j > i), cow i can see cow j if:
    h_i > h_{i+1}, h_i > h_{i+2}, ..., h_i > h_j.
In other words, cow i can see all consecutive cows in front of it that are strictly shorter,
until the first cow that is not shorter.

Let C_i be the number of cows that cow i can see.
Compute the sum C_1 + C_2 + ... + C_N.

Input Format:
The first line contains an integer N (1 ≤ N ≤ 80,000).
The next N lines each contain an integer a_i (1 ≤ a_i ≤ 1,000,000,000),
representing the height of cow 1, cow 2, ..., cow N in order.

Output Format:
A single integer, the sum C_1 + C_2 + ... + C_N.

Example:
Input:
6
10
3
7
4
12
2
Output:
5

Explanation:
Cow 1 (height 10) sees cows 2,3,4.
Cow 2 (height 3) sees no cows.
Cow 3 (height 7) sees cow 4.
Cow 4 (height 4) sees no cows.
Cow 5 (height 12) sees cow 6.
Cow 6 (height 2) sees no cows.
Sum = 3+0+1+0+1+0 = 5.
*/

#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> monotonic_stack;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        while (!monotonic_stack.empty() && monotonic_stack.top() <= height) {
            monotonic_stack.pop();
        }  
        result += monotonic_stack.size();
        monotonic_stack.push(height);
    }
    cout << result << endl;
    return 0;
}