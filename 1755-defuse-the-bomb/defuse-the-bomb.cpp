class Solution {
public:
   vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> result(n, 0);

    if (k == 0) return result;

    int sum = 0;
    int start, end;

    
    if (k > 0) {
        start = 1;
        end = k;

        // first window
        for (int i = start; i <= end; i++) {
            sum += code[i % n];
        }

        for (int i = 0; i < n; i++) {
            result[i] = sum;

            // slide window
            sum -= code[(i + 1) % n];
            sum += code[(i + k + 1) % n];
        }
    }

    // Case 2: k < 0 → backward window
    else {
        k = -k;
        start = n - k;
        end = n - 1;

        // first window
        for (int i = start; i <= end; i++) {
            sum += code[i];
        }

        for (int i = 0; i < n; i++) {
            result[i] = sum;

            // slide window backward
            sum -= code[(i - k + n) % n];
            sum += code[i];
        }
    }

    return result;
}
};