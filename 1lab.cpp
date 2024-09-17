#include <iostream>
#include <cmath>
#include <utility>

using namespace std;


bool is_perfect_square(int x) {
    int root = static_cast<int>(sqrt(x));
    return root * root == x;
}


pair<int, int> closest_pair_tonum(int upper_limit) {
    pair<int, int> best_pair = {-1, -1};

    
    for (int m = upper_limit - 1; m > 0; --m) {
        
        for (int n = m - 1; n > 0; --n) {
            int sum_mn = m + n;
            int diff_mn = m - n;

            
            if (is_perfect_square(sum_mn) && is_perfect_square(diff_mn)) {
                pair<int, int> current_pair = {m, n};

                
                if (current_pair > best_pair) {
                    best_pair = current_pair;
                }
            }
        }
    }

    return best_pair;
}

int main() {

    int lim;
    std::cout << "limit: ";
    std::cin >> lim;
    cout << "closest_pair_tonum(" << lim << "):";
    pair<int, int> result1 = closest_pair_tonum(lim);
    cout << "(" << result1.first << ", " << result1.second << ")" << endl;

    return 0;
}