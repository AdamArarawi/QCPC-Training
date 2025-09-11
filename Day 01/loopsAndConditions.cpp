#include <bits/stdc++.h>
using namespace std;


int q1 () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    cout <<( n % 2 == 0 ?  "even": "odd") ;

    return 0;
}


int q2 () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int three_multi = n / 3;
    int five_multi = n / 5;
    int fivteen_multi = n / 15;

    cout << three_multi + five_multi - fivteen_multi;;
    return 0;
}


int q3 () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (i < 2) continue; // نتجاهل 0 و 1

        bool prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            cout << i << '\n';
        }
    }

    return 0;
}


int q4 () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    if (n == 0) {
        cout << "Zero";    
    }
    else if (n  > 0) {
        cout << "Positive";
    }

    else if (n < 0 ) { 
        cout << "Negative";
    }
    return 0;
}

int q5 () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    for (int i = 1; i <= 10; i++) {
        cout << n << " x " << i << " = " << n * i;
    }

    return 0;
}

int q6 () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int result = 0;
    while (n > 0)
    {
        int last_num = n % 10;
        result += last_num;
        n /= 10;
    }
    cout << result;
    
    return 0;
}

int q7 () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long factorial = 1.0;

    int n;
    cin >> n;

    
    if (n < 0)
        cout << "Error! Factorial of a negative number doesn't exist.";
    else {
        for(int i = 1; i <= n; ++i) {
            factorial *= i;
        }
        cout << factorial;    
    }
    return 0;
}    


int q8 () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int result = 0;

    while (n > 0)
    {
        result = result * 10 + (n % 10);

        n /= 10;
    }
    cout << result;

    return 0;
}    

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int first_num = n;
    int result = 0;

    int digits = to_string(n).size();

    while (n > 0)
    {
        result += pow((n % 10),digits);
        n /= 10;
    }
    
    if (result == first_num) {
        cout << "true";
    } else cout << "false";
    return 0;
}