#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        string phone[10000];
        for (int i=0; i<n; i++) {
            cin >> phone[i];
        }
        sort(phone, phone+n);
        
        bool phone_list = true;
        int curr = 0;
        do {
            for (int i=curr+1; i<n; i++) {
                size_t found = phone[i].find(phone[curr]);
                if (found == 0) {
                    cout << "NO" << endl;
                    phone_list = false;
                    break;
                } else if (found == string::npos) {
                    break;
                }
            }
            curr++;
            if (!phone_list)
                break;
        } while (curr <=n);
        
        if (phone_list)
            cout << "YES" << endl;
    }
    return 0;
}
